#include "Header/Camera.h"
#include <fstream>



Camera::Camera()
{
	cameraPlaneVrtx[0][0] = vec3(0.0f, -1.0f, -1.0f);
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

bool Camera::InShade(const vec3& rayEnd, Scene& scene)
{
	bool inShade = false;
	//check for triangle hit
	vec3 end = rayEnd;
	Ray shadowRay = Ray(end, vec3(5, 0, 5) - end);
	Triangle shadowHit = scene.whichIsHit(shadowRay, end);

	if (length(end - vec3(5, 0, 5)) < length(shadowRay.GetStart() - vec3(5, 0, 5)) && length(end - vec3(5, 0, 5)) > 0.5f && shadowHit.getReflModel() != LIGHTSOURCE) {
		inShade = true;
	}

	//check sphere hit
	Sphere hitSphere{};
	float distanceToIntersecion = 100.0f;
	vec3 intersection = shadowRay.GetStart();
	if (scene.SphereHit(shadowRay, distanceToIntersecion, intersection, hitSphere)) {
		if (glm::dot(vec3(shadowRay.GetStart() - vec3(5.0f, 0.0f, 5.0f)), vec3(shadowRay.GetStart() - hitSphere.getCenter())) > 0) {
			inShade = true;
		}
	}

	return inShade;
}

colorDbl Camera::ShootRay(Ray& ray, Scene& scene) {

	vec3 rayEnd = vec3(0.0f);
	vec3 intersectionPoint;
	//if hit a sphere, we dont check for triangle hits from origin ray because we dont need to find whats behind the sphere
	float distanceToIntersecion = 100.0f;
	//else we check for triangle hits
	//Ta fram den triangeln som har blivit träffad och ge rayen den färgen
	Sphere hitSphere{};

	Triangle hitTriangle = scene.whichIsHit(ray, rayEnd);
	if (length(ray.GetStart() - rayEnd) < distanceToIntersecion) {
		intersectionPoint = rayEnd;
		distanceToIntersecion = length(ray.GetStart() - rayEnd);
		if (hitTriangle.getReflModel() == DIFFUSE) {
			//shoot shadow ray towards light
			//direction lightNormal = vec3(0, 0, -1);
			 //(shadow rayens intersektionpunkt -> ljus) < (orginalray -> ljus) 
			//if(glm::dot(rayEnd, shadowHit.getNormal()) > 0)
			//displace the pos so it guaranteed is on the right side of the triangle
			if (InShade(intersectionPoint, scene))
			{
				ray.setColor(hitTriangle.getColor() * colorDbl(0.0f));
				//ruski rouletti decide wether we sample hemisphere or no
			}
			else {
				ray.setColor(hitTriangle.getColor());
				//Not in shade so we need to add the emission of the light times the angle of cos
				//times the lost light from the length of the shadow ray times the color of the point
				//then use ruski rouletti to decide wether we sample hemi or not
				//then sample hemisphere and get the light from that point and add a bit of that to the point
			}

			if (RuskiRouletti(hitTriangle.getColor()))
			{
				Ray newRay = getNewRandDir(ray.GetDirection(), hitTriangle.getNormal(), intersectionPoint);

				colorDbl sampledClr = ShootRay(newRay, scene);
				ray.AddColor(sampledClr * colorDbl(0.01f)); 
			}
		}
		else if (hitTriangle.getReflModel() == MIRROR) {
			//calculate new dir
			Ray reflectedRay = ray.Bounce(intersectionPoint + INTERSECTION_MARGIN * hitTriangle.getNormal(), hitTriangle.getNormal(), true, 0);

			//keep shooting & return what was returned later on
			return ShootRay(reflectedRay, scene);
		}
		else if (hitTriangle.getReflModel() == LIGHTSOURCE)
		{
			ray.setColor(hitTriangle.getColor());
		}
	}

	if (scene.SphereHit(ray, distanceToIntersecion, intersectionPoint, hitSphere)) {
		if (hitSphere.getSurface().GetRefl() == DIFFUSE) {

			if (InShade(intersectionPoint, scene))
			{
				ray.setColor(hitSphere.getSurface().GetColor() * colorDbl(0.1f));
			}
			else {
				ray.setColor(hitSphere.getSurface().GetColor());
			}

		}
		else if (hitSphere.getSurface().GetRefl() == MIRROR) {
			//calculate new dir
			Ray reflectedRay = ray.Bounce(intersectionPoint + INTERSECTION_MARGIN * hitSphere.getNormal(intersectionPoint), hitSphere.getNormal(intersectionPoint), true, 0);

			//keep shooting & return what was returned later on
			return ShootRay(reflectedRay, scene);
		}
	}
	return ray.GetColor();
}

//decides wether we sample hemisphere or not depending on the color
bool Camera::RuskiRouletti(const colorDbl& areaCol) {
	//tal mellan 0 och 1  som är P 
	//gångra functions värder med 1/P
	float randomNumber = (float)rand() / RAND_MAX;

	float threshold = 0.5f * ((float)length(areaCol) / (float)length(colorDbl(1.0f)));

	if (randomNumber < threshold) {
		return true;
	}

	return false;

}

Ray Camera::getNewRandDir(const vec3& normal, const vec3& incidence, const vec3& intersection) {

	vec3 Z = normal;
	vec3 I_ = incidence - (glm::dot(incidence, Z)) * Z;
	vec3 X = I_ / glm::length(I_);
	vec3 Y = glm::cross(-X, Z);


	float PI = 3.14f;
	float inclination = ((float)rand() / RAND_MAX) + PI / 2;
	float azimuth = ((float)rand() / RAND_MAX) + 2 * PI;
	/*
	float inclination = asinf(sqrt((float)rand() / RAND_MAX)); //theta
	float azimuth = 2 * PI * ((float)rand() / RAND_MAX); //phi
	*/

	direction mydirection = vec3(cosf(azimuth) * sinf(inclination), sinf(azimuth) * sinf(inclination), cosf(inclination));

	glm::vec4 X4 = glm::vec4(X, 0.0f);
	glm::vec4 Y4 = glm::vec4(Y, 0.0f);
	glm::vec4 Z4 = glm::vec4(Z, 0.0f);
	glm::vec4 H4 = glm::vec4(0.0f, 0.0f, 0.0f, 1.0f);

	glm::vec4 vw = glm::vec4(mydirection, 1.0f);
	glm::mat4x4 M{ X4, Y4, Z4, H4 };
	glm::vec4 Vtransform = glm::inverse(M) * vw;
	vec3 newDir = vec3(Vtransform);

	return Ray{ intersection, newDir };

}

void Camera::Render(Scene& scene)
{
	int raysPerPixel = 4;
	for (int i = 0; i < 800; ++i) {
		for (int j = 0; j < 800; ++j)
		{
			Pixel p;
			Ray totRay = Ray(vec3(0.0f), vec3(0.0f));
			//vec3 rayEnd = p.getPointFromPixel(i, j, 0, 0, raysPerPixel);
			//Ray shotRay = Ray(eye1, rayEnd - eye1);


			for (int k = 0; k < raysPerPixel / 2; ++k) {
				for (int l = 0; l < raysPerPixel / 2; ++l) {

					//skjut 4 ray i riktning mot pixel (i,j)
					vec3 rayEnd = p.getPointFromPixel(j, i, l, k, raysPerPixel);
					Ray shotRay = Ray(eye1, rayEnd - eye1);
					p.addRay(shotRay);
					totRay.AddColor(ShootRay(shotRay, scene));
				}
			}
			p.setColor(totRay.GetColor() / (float)raysPerPixel);
			viewPlane[j][i] = p;
		}
	}
	/*
	for (int i = 0; i < 800; ++i) {
		for (int j = 0; j < 800; ++j){
			//skjut en ray i riktning mot pixeln
			Pixel p;
			vec3 rayEnd = p.getPointFromPixel(j, i);
			Ray shotRay = Ray(eye1, rayEnd - eye1);


			shotRay.setColor(ShootRay(shotRay, scene));

			p.addRay(shotRay);
			viewPlane[j][i] = p;
		}
	}*/
}



void Camera::CreateImage(Scene& theScene)
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