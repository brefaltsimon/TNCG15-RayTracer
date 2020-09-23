#include "Header/Scene.h"

Scene::Scene()
{
	CreateRoom();
}

void Scene::CreateRoom() 
{
// View from above:
// ^ = camera 1 and viewing direction (origo)
// v = camera 2 and viewing direction
//           a
//          / \   <-- front
// LEFT    b   c     RIGHT
//         |   |  <-- center
//         d   e
//          \ /   <-- back
//           f
//
//    ^ z
//    |
//    |----> x

	glm::vec3 aBottom(0.0f, -5.0f, 13.0f), aTop(0.0f, 5.0f, 13.0f);
	glm::vec3 bBottom(-6.0f, -5.0f, 10.0f), bTop(-6.0f, 5.0f, 10.0f);
	glm::vec3 cBottom(6.0f, -5.0f, 10.0f), cTop(6.0f, 5.0f, 10.0f);
	glm::vec3 dBottom(-6.0f, -5.0f, 0.0f), dTop(-6.0f, 5.0f, 0.0f);
	glm::vec3 eBottom(6.0f, -5.0f, 0.0f), eTop(6.0f, 5.0f, 0.0f);
	glm::vec3 fBottom(0.0f, -5.0f, -3.0f), fTop(0.0f, 5.0f, -3.0f);

	colorDbl White = colorDbl(1.0f);
	colorDbl Grey = colorDbl(0.5f);
	colorDbl Red = colorDbl(1.0f, 0.0f, 0.0f);
	colorDbl Green = colorDbl(0.0f, 1.0f, 0.0f);
	colorDbl Blue = colorDbl(0.0f, 0.0f, 1.0f);
	colorDbl Yellow = colorDbl(1.0f, 1.0f, 0.0f);
	colorDbl Purple = colorDbl(1.0f, 0.0f, 1.0f);

	//const Surface White(colorDbl(1.0f));
	//const Surface Grey(colorDbl(0.5f));
	//const Surface Red(colorDbl(1.0f, 0.0f, 0.0f));
	//const Surface Green(colorDbl(0.0f, 1.0f, 0.0f));
	//const Surface Blue(colorDbl(0.0f, 0.0f, 1.0f));
	//const Surface Yellow(colorDbl(1.0f, 1.0f, 0.0f));
	//const Surface Purple(colorDbl(1.0f, 0.0f, 1.0f));
	//const Surface Teal(ColorDouble(0.0f, 0.0f, 0.0f), SPECULAR);
	//const Surface Mirror(ColorDouble(0.0f), SPECULAR);

	// Floor
	sceneTriangles.push_back(Triangle(bBottom, cBottom, aBottom, White));
	sceneTriangles.push_back(Triangle(bBottom, dBottom, cBottom, White));
	sceneTriangles.push_back(Triangle(dBottom, eBottom, cBottom, White));
	sceneTriangles.push_back(Triangle(dBottom, fBottom, eBottom, White));
	// Roof
	sceneTriangles.push_back(Triangle(bTop, aTop, cTop, White));
	sceneTriangles.push_back(Triangle(bTop, cTop, dTop, White));
	sceneTriangles.push_back(Triangle(dTop, cTop, eTop, White));
	sceneTriangles.push_back(Triangle(dTop, eTop, fTop, White));
	// Right side back
	sceneTriangles.push_back(Triangle(fBottom, fTop, eTop, Blue));
	sceneTriangles.push_back(Triangle(fBottom, eTop, eBottom, Blue));
	// Left side back
	sceneTriangles.push_back(Triangle(dBottom, dTop, fTop, Yellow));
	sceneTriangles.push_back(Triangle(dBottom, fTop, fBottom, Yellow));
	// Left side center
	sceneTriangles.push_back(Triangle(bBottom, bTop, dTop, White));
	sceneTriangles.push_back(Triangle(bBottom, dTop, dBottom, White));
	// Left side front
	sceneTriangles.push_back(Triangle(aBottom, aTop, bTop, White));
	sceneTriangles.push_back(Triangle(aBottom, bTop, bBottom, White));
	// Right side front
	sceneTriangles.push_back(Triangle(cBottom, cTop, aTop, White));
	sceneTriangles.push_back(Triangle(cBottom, aTop, aBottom, White));
	// Right side center
	sceneTriangles.push_back(Triangle(eBottom, eTop, cTop, White));
	sceneTriangles.push_back(Triangle(eBottom, cTop, cBottom, White));
	/*
	// vit 1.0, 1.0, 1.0
	//Golv
	Triangle g_0{ vec3(5.0f, 0.0f, 5.0f), vec3(0.0f, 6.0f, 5.0f), vec3(-3.0f, 0.0f, 5.0f), colorDbl(0.0,0.0,0.0) };
	Triangle g_1{ vec3(5.0f, 0.0f, 5.0f), vec3(10.0f, 6.0f, 5.0f), vec3(0.0f, 6.0f, 5.0f), colorDbl(0.0,0.0,0.0) };
	Triangle g_2{ vec3(5.0f, 0.0f, 5.0f), vec3(13.0f, 0.0f, 5.0f), vec3(10.0f, 6.0f, 5.0f), colorDbl(0.0,0.0,0.0) };

	Triangle g_3{ vec3(5.0f, 0.0f, 5.0f), vec3(10.0f, -6.0f, 5.0f), vec3(13.0f, 0.0f, 5.0f), colorDbl(0.0,0.0,0.0) };
	Triangle g_4{ vec3(5.0f, 0.0f, 5.0f), vec3(0.0f, -6.0f, 5.0f), vec3(10.0f, -6.0f, 5.0f), colorDbl(0.0,0.0,0.0) };
	Triangle g_5{ vec3(5.0f, 0.0f, 5.0f), vec3(-3.0f, 0.0f, 5.0f), vec3(0.0f, -6.0f, 5.0f), colorDbl(0.0,0.0,0.0) };
	
	sceneTriangles.push_back(g_0);
	sceneTriangles.push_back(g_1);
	sceneTriangles.push_back(g_2);
	sceneTriangles.push_back(g_3);
	sceneTriangles.push_back(g_4);
	sceneTriangles.push_back(g_5);

	//tak
	Triangle t_0{ vec3(5.0f, 0.0f, 5.0f), vec3(-3.0f, 0.0f, 5.0f), vec3(0.0f, 6.0f, 5.0f), colorDbl(0.8, 1.0, 1.0) };
	Triangle t_1{ vec3(5.0f, 0.0f, 5.0f), vec3(0.0f, 6.0f, 5.0f), vec3(10.0f, 6.0f, 5.0f), colorDbl(0.8, 1.0, 1.0) };
	Triangle t_2{ vec3(5.0f, 0.0f, 5.0f), vec3(10.0f, 6.0f, 5.0f), vec3(13.0f, 0.0f, 5.0f), colorDbl(0.8, 1.0, 1.0) };

	Triangle t_3{ vec3(5.0f, 0.0f, 5.0f), vec3(13.0f, 0.0f, 5.0f), vec3(10.0f, -6.0f, 5.0f), colorDbl(0.8, 1.0, 1.0) };
	Triangle t_4{ vec3(5.0f, 0.0f, 5.0f), vec3(10.0f, -6.0f, 5.0f), vec3(0.0f, -6.0f, 5.0f), colorDbl(0.8, 1.0, 1.0) };
	Triangle t_5{ vec3(5.0f, 0.0f, 5.0f), vec3(0.0f, -6.0f, 5.0f), vec3(-3.0f, 0.0f, 5.0f), colorDbl(0.8, 1.0, 1.0) };

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
	*/
}

void Scene::AddObjects()
{
	
}

Triangle Scene::whichIsHit(const Ray &aRay)
{

	
	for (auto i = sceneTriangles.begin(); i != sceneTriangles.end(); ++i) {
		if (i->RayIntersection(aRay)) {
			return *i;
		}
	}
	vec3 hi(0,0,0);
	return Triangle(hi, hi, hi, hi);

}
