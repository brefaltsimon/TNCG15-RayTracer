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

bool Camera::InShade(vec3& rayEnd, Scene& scene)
{
	bool inShade = false;
	//check for triangle hit
	Ray shadowRay = Ray(rayEnd, vec3(5, 0, 5) - rayEnd);
	Triangle shadowHit = scene.whichIsHit(shadowRay, rayEnd);
	if (length(rayEnd - vec3(5, 0, 5)) < length(shadowRay.GetStart() - vec3(5, 0, 5)) && length(rayEnd - vec3(5, 0, 5)) > 0.5f) {
		inShade = true;
	}
	//check sphere hit
	Sphere hitSphere{};
	float distanceToIntersecion = 100.0f;
	vec3 intersection = shadowRay.GetStart();
	if (scene.SphereHit(shadowRay, distanceToIntersecion, intersection, hitSphere) && glm::dot(vec3(shadowRay.GetStart() - vec3(5.0f, 0.0f, 5.0f)), vec3(shadowRay.GetStart() - hitSphere.getCenter())) > 0 ) {
		inShade = true;
	}

	return inShade;
}

colorDbl Camera::ShootRay(Ray& ray, Scene &scene) {

	vec3 rayEnd = vec3(0.0f);
	vec3 intersectionPoint;
	//if hit a sphere, we dont check for triangle hits from origin ray because we dont need to find whats behind the sphere
	float distanceToIntersecion = 100.0f;
	//else we check for triangle hits
	//Ta fram den triangeln som har blivit träffad och ge rayen den färgen
	Sphere hitSphere{};
	if(scene.SphereHit(ray, distanceToIntersecion, intersectionPoint, hitSphere)) {
		
	}

	Triangle hitTriangle = scene.whichIsHit(ray, rayEnd);
	if (length(ray.GetStart() - rayEnd) < distanceToIntersecion) {
		intersectionPoint = rayEnd;
		if (hitTriangle.getReflModel() == DIFFUSE) {
			//shoot shadow ray towards light
			//direction lightNormal = vec3(0, 0, -1);
			 //(shadow rayens intersektionpunkt -> ljus) < (orginalray -> ljus) 
			//if(glm::dot(rayEnd, shadowHit.getNormal()) > 0)
			if(InShade(intersectionPoint, scene)) 
			{
				ray.setColor(hitTriangle.getColor() * colorDbl(0.15f));
			}
			else {
				ray.setColor(hitTriangle.getColor());
			}
		}
		else if (hitTriangle.getReflModel() == MIRROR) {
			//calculate new dir
			Ray reflectedRay = ray.Bounce(intersectionPoint, hitTriangle.getNormal(), true, 0);

			//keep shooting & return what was returned later on
			return ShootRay(reflectedRay, scene);
		}
	}
	else {
		if (hitSphere.getSurface().GetRefl() == DIFFUSE) {

			if (InShade(intersectionPoint, scene))
			{
				ray.setColor(hitSphere.getSurface().GetColor() * colorDbl(0.1f));
			}

		} else if (hitSphere.getSurface().GetRefl() == MIRROR) {
		//calculate new dir
			Ray reflectedRay = ray.Bounce(intersectionPoint, vec3(intersectionPoint - hitSphere.getCenter()) + hitSphere.getRadius()*1.003f, true, 0);

		//keep shooting & return what was returned later on
			return ShootRay(reflectedRay, scene);
		}
	}

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
