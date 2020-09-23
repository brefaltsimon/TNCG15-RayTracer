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

void Camera::ShootRay(Scene &scene) {

	for (int i = 0; i < 800; ++i) {
			for (int j = 0; j < 800; ++j) 
			{
				//skjut en ray i riktning mot pixeln
				Pixel p;
				vec3 rayEnd = p.getMidOfPixel(i, j);
				Ray shotRay = Ray(eye1, rayEnd-eye1);
				//shotRay.SetDirection(rayEnd-eye1);
				
				
				//Ta fram den triangeln som har blivit tr�ffad och ge rayen den f�rgen
				Triangle hit = scene.whichIsHit(shotRay);
				shotRay.setColor(hit.getColor());
				p.addRay(shotRay);
				viewPlane[i][j] = p;
			}
		}

}

void Camera::Render()
{

	

}

void Camera::CreateImage(Scene &theScene)
{

	const int width = 800, height = 800;
	std::ofstream img("renderad.ppm");
	img << "P3" << std::endl;
	img << width << " " << height << std::endl;
	img << "255" << std::endl;

	ShootRay(theScene);
	//s�tt in v�ra pixel v�rden p� ett coolt s�tt
	for (int y = 0; y < height; ++y) {
		for (int x = 0; x < width; ++x) {
			vec3 unscaledColor = viewPlane[y][x].GetColor();
			int r = floor(unscaledColor[0] * 255);
			int g = floor(unscaledColor[1] * 255);
			int b = floor(unscaledColor[2] * 255);

			img << r << " " << g << " " << b << std::endl;
		}
	}

}
