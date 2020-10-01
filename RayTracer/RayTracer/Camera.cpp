#include "Header/Camera.h"
#include <fstream>



Camera::Camera()
{
	cameraPlaneVrtx[0][0] = vec3(0.0f,-1.0f,-1.0f);
	cameraPlaneVrtx[1][0] = vec3(0.0f, 1.0f, -1.0f);
	cameraPlaneVrtx[0][1] = vec3(0.0f, -1.0f, 1.0f);
	cameraPlaneVrtx[1][1] = vec3(0.0f, 1.0f, 1.0f);

	for (int i = 0; i < 800; ++i) {
		viewPlane[i] = new Pixel[800];
	}

}

void Camera::ShootShadowRay(Ray& ray)
{

}

colorDbl Camera::ShootRay(Ray& ray, Scene &scene) {

	vec3 rayEnd = vec3(0.0f);

	//Ta fram den triangeln som har blivit träffad och ge rayen den färgen
	Triangle hit = scene.whichIsHit(ray, rayEnd);
	vec3 intersectionPoint = rayEnd;
	
	if (hit.getReflModel() == DIFFUSE) {

		//shoot shadow ray towards light
		Ray shadowRay = Ray(rayEnd, vec3(5, 0, 5) - rayEnd);
		Triangle shadowHit = scene.whichIsHit(shadowRay, rayEnd);


		if (length(rayEnd - vec3(5, 0, 5)) < length(intersectionPoint - vec3(5, 0, 5)) && length(rayEnd - vec3(5, 0, 5)) > 0.5f) //(shadow rayens intersektionpunkt -> ljus) < (orginalray -> ljus) 
		{
			ray.setColor(hit.getColor() * colorDbl(0.2f));
		}
		else {

			ray.setColor(hit.getColor());
		}

	} 
	else if (hit.getReflModel() == MIRROR) {
		//calculate new dir
	
		Ray reflectedRay = ray.Bounce(intersectionPoint, hit.getNormal(), true, 0);

		//keep shooting & return what was returned later on
		return ShootRay(reflectedRay, scene);
	}
	/**/

	return ray.GetColor();
}

void Camera::Render(Scene& scene)
{

	for (int i = 0; i < 800; ++i) {
		for (int j = 0; j < 800; ++j)
		{
			//skjut en ray i riktning mot pixeln
			Pixel p;
			vec3 rayEnd = p.getMidOfPixel(j, i);
			Ray shotRay = Ray(eye1, rayEnd - eye1);
			//shotRay.SetDirection(rayEnd-eye1);

			shotRay.setColor(ShootRay(shotRay, scene));

			

			p.addRay(shotRay);
			viewPlane[j][i] = p;
		}
	}

}

void Camera::CreateImage(Scene &theScene)
{

	const int width = 800, height = 800;
	std::ofstream img("renderad.ppm");
	img << "P3" << std::endl;
	img << width << " " << height << std::endl;
	img << "255" << std::endl;

	Render(theScene);
	//sätt in våra pixel värden på ett coolt sätt
	for (int y = 0; y < height; ++y) {
		for (int x = 0; x < width; ++x) {
			vec3 unscaledColor = viewPlane[x][y].GetColor();
			int r = floor(unscaledColor[0] * 255);
			int g = floor(unscaledColor[1] * 255);
			int b = floor(unscaledColor[2] * 255);

			img << r << " " << g << " " << b << std::endl;
		}
	}

}
