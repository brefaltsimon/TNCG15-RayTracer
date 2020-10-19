#include "Header/Camera.h"
#include "Header/Scene.h"
#include "Header/Pixel.h"

#include <iostream>
#include <chrono> 


int main() {
	auto start = std::chrono::high_resolution_clock::now();
	srand(time(0));
	Scene scene;
	scene.AddObjects();

	Camera camera;
	camera.CreateImage(scene);
	auto end = std::chrono::high_resolution_clock::now();

	double time_taken =
		std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();

	time_taken *= 1e-9;

	std::cout << "Time taken by program is : " << std::fixed
		<< time_taken;
	std::cout << " sec" << std::endl;

	return 0;
}