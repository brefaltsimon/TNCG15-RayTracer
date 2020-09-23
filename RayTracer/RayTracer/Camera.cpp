#include "Header/Camera.h"
#include <fstream>



Camera::Camera()
{
	cameraPlaneVrtx[0][0] = vec3(0.0f,-1.0f,-1.0f);
	cameraPlaneVrtx[1][0] = vec3(0.0f, 1.0f, -1.0f);
	cameraPlaneVrtx[0][1] = vec3(0.0f, -1.0f, 1.0f);
	cameraPlaneVrtx[1][1] = vec3(0.0f, 1.0f, 1.0f);

}

void Camera::ShootRay(Scene &scene) {

	for (int i = 0; i < 800; ++i) {
			for (int j = 0; j < 800; ++j) 
			{
				//skjut en ray i riktning mot pixeln
				Pixel p;
				vec3 rayEnd = p.getMidOfPixel(i, j);
				Ray shotRay = Ray(eye1, rayEnd);
				shotRay.SetDirection(rayEnd-eye1);
				p.addRay(shotRay);
				
				//Ta fram den triangeln som har blivit träffad och ge rayen den färgen
				Triangle hit = scene.whichIsHit(shotRay);
				shotRay.setColor(hit.getColor());
			}
		}

}

void Camera::Render()
{
	
	

}

void Camera::CreateImage(Scene theScene)
{

	const int width = 800, height = 800;
	std::ofstream img("renderad.ppm");
	img << "P3" << std::endl;
	img << width << " " << height << std::endl;
	img << "255" << std::endl;

	//sätt in våra pixel värden på ett coolt sätt
	for (int y = 0; y < height; ++y) {
		for (int x = 0; x < width; ++x) {

			int r = x % 255;
			int g = y % 255;
			int b = x * y % 255;

			img << r << " " << g << " " << b << std::endl;
		}
	}

}
