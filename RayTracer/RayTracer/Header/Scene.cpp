#include "Scene.h"

Scene::Scene()
{

	CreateRoom();
}

void Scene::CreateRoom() 
{
	//Golv
	Triangle g_0{ vec3(5.0f, 0.0f, 5.0f), vec3(0.0f, 6.0f, 5.0f), vec3(-3.0f, 0.0f, 5.0f), colorDbl(1.0, 1.0, 1.0) };
	Triangle g_1{ vec3(5.0f, 0.0f, 5.0f), vec3(10.0f, 6.0f, 5.0f), vec3(0.0f, 6.0f, 5.0f), colorDbl(1.0, 1.0, 1.0) };
	Triangle g_2{ vec3(5.0f, 0.0f, 5.0f), vec3(13.0f, 0.0f, 5.0f), vec3(10.0f, 6.0f, 5.0f), colorDbl(1.0, 1.0, 1.0) };

	Triangle g_3{ vec3(5.0f, 0.0f, 5.0f), vec3(10.0f, -6.0f, 5.0f), vec3(13.0f, 0.0f, 5.0f), colorDbl(1.0, 1.0, 1.0) };
	Triangle g_4{ vec3(5.0f, 0.0f, 5.0f), vec3(0.0f, -6.0f, 5.0f), vec3(10.0f, -6.0f, 5.0f), colorDbl(1.0, 1.0, 1.0) };
	Triangle g_5{ vec3(5.0f, 0.0f, 5.0f), vec3(-3.0f, 0.0f, 5.0f), vec3(0.0f, -6.0f, 5.0f), colorDbl(1.0, 1.0, 1.0) };
	
	sceneTriangles.push_back(g_0);
	sceneTriangles.push_back(g_1);
	sceneTriangles.push_back(g_2);
	sceneTriangles.push_back(g_3);
	sceneTriangles.push_back(g_4);
	sceneTriangles.push_back(g_5);

	//tak
	Triangle t_0{ vec3(5.0f, 0.0f, 5.0f), vec3(-3.0f, 0.0f, 5.0f), vec3(0.0f, 6.0f, 5.0f), colorDbl(1.0, 1.0, 1.0) };
	Triangle t_1{ vec3(5.0f, 0.0f, 5.0f), vec3(0.0f, 6.0f, 5.0f), vec3(10.0f, 6.0f, 5.0f), colorDbl(1.0, 1.0, 1.0) };
	Triangle t_2{ vec3(5.0f, 0.0f, 5.0f), vec3(10.0f, 6.0f, 5.0f), vec3(13.0f, 0.0f, 5.0f), colorDbl(1.0, 1.0, 1.0) };

	Triangle t_3{ vec3(5.0f, 0.0f, 5.0f), vec3(13.0f, 0.0f, 5.0f), vec3(10.0f, -6.0f, 5.0f), colorDbl(1.0, 1.0, 1.0) };
	Triangle t_4{ vec3(5.0f, 0.0f, 5.0f), vec3(10.0f, -6.0f, 5.0f), vec3(0.0f, -6.0f, 5.0f), colorDbl(1.0, 1.0, 1.0) };
	Triangle t_5{ vec3(5.0f, 0.0f, 5.0f), vec3(0.0f, -6.0f, 5.0f), vec3(-3.0f, 0.0f, 5.0f), colorDbl(1.0, 1.0, 1.0) };

	sceneTriangles.push_back(t_0);
	sceneTriangles.push_back(t_1);
	sceneTriangles.push_back(t_2);
	sceneTriangles.push_back(t_3);
	sceneTriangles.push_back(t_4);
	sceneTriangles.push_back(t_5);

	//Väggar
	Triangle w_0{ vec3(-3.0f, 0.0f, -5.0f), vec3(0.0f, 6.0f, -5.0f), vec3(-3.0f, 0.0f, 5.0f), colorDbl(1.0, 0.0, 0.0) };
	Triangle w_1{ vec3(0.0f, 6.0f, 5.0f), vec3(-3.0f, 0.0f, 5.0f), vec3(-3.0f, 0.0f, -5.0f), colorDbl(1.0, 0.0, 0.0) };
	
	Triangle w_2{ vec3(0.0f, 6.0f, -5.0f), vec3(10.0f, 6.0f, -5.0f), vec3(0.0f, 6.0f, 5.0f), colorDbl(0.0, 1.0, 0.0) };
	Triangle w_3{ vec3(10.0f, 6.0f, 5.0f), vec3(0.0f, 6.0f, 5.0f), vec3(10.0f, 6.0f, -5.0f), colorDbl(0.0, 1.0, 0.0) };
	
	Triangle w_4{ vec3(10.0f, 6.0f, -5.0f), vec3(13.0f, 0.0f, -5.0f), vec3(-3.0f, 0.0f, 5.0f), colorDbl(0.0, 0.0, 1.0) };
	Triangle w_5{ vec3(13.0f, 0.0f, 5.0f), vec3(10.0f, 6.0f, 5.0f), vec3(13.0f, 0.0f, -5.0f), colorDbl(0.0, 0.0, 1.0) };
	
	Triangle w_6{ vec3(13.0f, 0.0f, -5.0f), vec3(10.0f, -6.0f, -5.0f), vec3(13.0f, 0.0f, 5.0f), colorDbl(1.0, 1.0, 0.0) };
	Triangle w_7{ vec3(10.0f, -6.0f, 5.0f), vec3(13.0f, 0.0f, 5.0f), vec3(10.0f, -6.0f, 5.0f), colorDbl(1.0, 1.0, 0.0) };
	
	Triangle w_8{ vec3(10.0f, -6.0f, -5.0f), vec3(0.0f, -6.0f, -5.0f), vec3(10.0f, -6.0f, 5.0f), colorDbl(1.0, 0.0, 1.0) };
	Triangle w_9{ vec3(0.0f, -6.0f, 5.0f), vec3(10.0f, -6.0f, 5.0f), vec3(0.0f, -6.0f, -5.0f), colorDbl(1.0, 0.0, 1.0) };
	
	Triangle w_10{ vec3(0.0f, -6.0f, -5.0f), vec3(-3.0f, 0.0f, -5.0f), vec3(0.0f, -6.0f, 5.0f), colorDbl(1.0, 1.0, 1.0) };
	Triangle w_11{ vec3(-3.0f, 0.0f, 5.0f), vec3(0.0f, -6.0f, 5.0f), vec3(-3.0f, 0.0f, -5.0f), colorDbl(1.0, 1.0, 1.0) };

	sceneTriangles.push_back(w_0);
	sceneTriangles.push_back(w_1);
	sceneTriangles.push_back(w_2);
	sceneTriangles.push_back(w_3);
	sceneTriangles.push_back(w_4);
	sceneTriangles.push_back(w_5);
	sceneTriangles.push_back(w_6);
	sceneTriangles.push_back(w_7);
	sceneTriangles.push_back(w_8);
	sceneTriangles.push_back(w_9);
	sceneTriangles.push_back(w_10);
	sceneTriangles.push_back(w_11);
	
}

void Scene::AddObjects()
{
	
}

Triangle Scene::whichIsHit(const Ray &aRay)
{
	float u = 0;
	float v = 0;
	
	for (auto i = sceneTriangles.begin(); i != sceneTriangles.end(); ++i) {
		if (i->RayIntersection(aRay, u, v)) {
			return *i;
		}
		
	}


}
