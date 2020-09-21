#include "Header/Camera.h"
#include "Header/Scene.h"
#include "Header/Pixel.h"


int main() {

	Scene scene;
	Camera camera;
	camera.CreateImage(scene);
	
	return 0;
}