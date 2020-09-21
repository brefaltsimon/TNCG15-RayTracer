#include "Camera.h"
#include <fstream>


Camera::Camera()
{
	cameraPlaneVrtx[0][0] = vec3(0.0f,-1.0f,-1.0f);
	cameraPlaneVrtx[1][0] = vec3(0.0f, 1.0f, -1.0f);
	cameraPlaneVrtx[0][1] = vec3(0.0f, -1.0f, 1.0f);
	cameraPlaneVrtx[1][1] = vec3(0.0f, 1.0f, 1.0f);

}

void Camera::ShootRay() {

	for (int i = 0; i < 800; ++i) {
			for (int j = 0; j < 800; ++j) 
			{
				Pixel p;
				vec3 rayEnd = p.getMidOfPixel(i, j);
				

				//skjut en ray i riktning mot pixeln
				//spara f�rgen p� pixel
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

	//s�tt in v�ra pixel v�rden p� ett coolt s�tt
	for (int y = 0; y < height; ++y) {
		for (int x = 0; x < width; ++x) {

			int r = x % 255;
			int g = y % 255;
			int b = x * y % 255;

			img << r << " " << g << " " << b << std::endl;
		}
	}

}
