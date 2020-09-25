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
	/*
	glm::vec3 aBottom(0.0f, -5.0f, 13.0f), aTop(0.0f, 5.0f, 13.0f);
	glm::vec3 bBottom(-6.0f, -5.0f, 10.0f), bTop(-6.0f, 5.0f, 10.0f);
	glm::vec3 cBottom(6.0f, -5.0f, 10.0f), cTop(6.0f, 5.0f, 10.0f);
	glm::vec3 dBottom(-6.0f, -5.0f, 0.0f), dTop(-6.0f, 5.0f, 0.0f);
	glm::vec3 eBottom(6.0f, -5.0f, 0.0f), eTop(6.0f, 5.0f, 0.0f);
	glm::vec3 fBottom(0.0f, -5.0f, -3.0f), fTop(0.0f, 5.0f, -3.0f);
	*/

	glm::vec3 aBottom(13.0f, 0.0f, -5.0f), aTop(13.0f, 0.0f, 5.0f);
	glm::vec3 bBottom(10.0f, 6.0f, -5.0f), bTop(10.0f, 6.0f, 5.0f);
	glm::vec3 cBottom(10.0f, -6.0f, -5.0f), cTop(10.0f, -6.0f, 5.0f);
	glm::vec3 dBottom(0.0f, 6.0f, -5.0f), dTop(0.0f, 6.0f, 5.0f);
	glm::vec3 eBottom(0.0f, -6.0f, -5.0f), eTop(0.0f, -6.0f, 5.0f);
	glm::vec3 fBottom(-3.0f, 0.0f, -5.0f), fTop(-3.0f, 0.0f, 5.0f);

	Surface White = colorDbl(1.0f);
	Surface Grey = colorDbl(0.5f);
	Surface Red = colorDbl(1.0f, 0.0f, 0.0f);
	Surface Green = colorDbl(0.0f, 1.0f, 0.0f);
	Surface Blue = colorDbl(0.0f, 0.0f, 1.0f);
	Surface Yellow = colorDbl(1.0f, 1.0f, 0.0f);
	Surface Purple = colorDbl(1.0f, 0.0f, 1.0f);

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
	sceneTriangles.push_back(Triangle(bTop, aTop, cTop, Blue));
	sceneTriangles.push_back(Triangle(bTop, cTop, dTop, Blue));
	sceneTriangles.push_back(Triangle(dTop, cTop, eTop, Blue));
	sceneTriangles.push_back(Triangle(dTop, eTop, fTop, Blue));
	// Right side back
	sceneTriangles.push_back(Triangle(fBottom, fTop, eTop, Blue));
	sceneTriangles.push_back(Triangle(fBottom, eTop, eBottom, Blue));
	// Left side back
	sceneTriangles.push_back(Triangle(dBottom, dTop, fTop, Yellow));
	sceneTriangles.push_back(Triangle(dBottom, fTop, fBottom, Yellow));
	// Left side center
	sceneTriangles.push_back(Triangle(bBottom, bTop, dTop, Grey));
	sceneTriangles.push_back(Triangle(bBottom, dTop, dBottom, Grey));
	// Left side front
	sceneTriangles.push_back(Triangle(aBottom, aTop, bTop, Green));
	sceneTriangles.push_back(Triangle(aBottom, bTop, bBottom, Green));
	// Right side front
	sceneTriangles.push_back(Triangle(cBottom, cTop, aTop, Red));
	sceneTriangles.push_back(Triangle(cBottom, aTop, aBottom, Red));
	// Right side center
	sceneTriangles.push_back(Triangle(eBottom, eTop, cTop, Purple));
	sceneTriangles.push_back(Triangle(eBottom, cTop, cBottom, Purple));
	
	//tetrahedron
	Tetrahedron tet1{ Grey };

	sceneTriangles.push_back(tet1.getTriangles()[0]);
	sceneTriangles.push_back(tet1.getTriangles()[1]);
	sceneTriangles.push_back(tet1.getTriangles()[2]);
	sceneTriangles.push_back(tet1.getTriangles()[3]);

	vec3 v0, v1, v2, v3;
	v0 = vec3(8.0, 4.0, -3.0);
	v1 = vec3(7.0, 1.0, -2.0);
	v2 = vec3(4.0, 2.0, -2.0);
	v3 = vec3(6.0, 2.0, 1.0);

	Triangle t0 = Triangle(v2, v1, v0, Purple); // botten
	Triangle t1 = Triangle(v1, v3, v0, Purple); //mot v1/v0 sidan
	Triangle t2 = Triangle(v2, v0, v3, Purple); //mot v3 sidan
	Triangle t3 = Triangle(v2, v3, v1, Purple); //mot v2/v1 sidan

	sceneTriangles.push_back(t0);
	sceneTriangles.push_back(t1);
	sceneTriangles.push_back(t2);
	sceneTriangles.push_back(t3);

	/*
	// vit 1.0, 1.0, 1.0
	//Golv
	Triangle g_0{ vec3(5.0f, 0.0f, -5.0f), vec3(0.0f, 6.0f, -5.0f), vec3(-3.0f, 0.0f, -5.0f), White };
	Triangle g_1{ vec3(5.0f, 0.0f, -5.0f), vec3(10.0f, 6.0f, -5.0f), vec3(0.0f, 6.0f, -5.0f), White };
	Triangle g_2{ vec3(5.0f, 0.0f, -5.0f), vec3(13.0f, 0.0f, -5.0f), vec3(10.0f, 6.0f, -5.0f), White };

	Triangle g_3{ vec3(5.0f, 0.0f, -5.0f), vec3(10.0f, -6.0f, -5.0f), vec3(13.0f, 0.0f, -5.0f), White };
	Triangle g_4{ vec3(5.0f, 0.0f, -5.0f), vec3(0.0f, -6.0f, -5.0f), vec3(10.0f, -6.0f, -5.0f), White };
	Triangle g_5{ vec3(5.0f, 0.0f, -5.0f), vec3(-3.0f, 0.0f, -5.0f), vec3(0.0f, -6.0f, -5.0f), White };
	
	sceneTriangles.push_back(g_0);
	sceneTriangles.push_back(g_1);
	sceneTriangles.push_back(g_2);
	sceneTriangles.push_back(g_3);
	sceneTriangles.push_back(g_4);
	sceneTriangles.push_back(g_5);

	//tak
	Triangle t_0{ vec3(5.0f, 0.0f, 5.0f), vec3(-3.0f, 0.0f, 5.0f), vec3(0.0f, 6.0f, 5.0f), Grey };
	Triangle t_1{ vec3(5.0f, 0.0f, 5.0f), vec3(0.0f, 6.0f, 5.0f), vec3(10.0f, 6.0f, 5.0f), Grey };
	Triangle t_2{ vec3(10.0f, 6.0f, 5.0f), vec3(5.0f, 0.0f, 5.0f), vec3(13.0f, 0.0f, 5.0f), Grey };

	Triangle t_3{ vec3(5.0f, 0.0f, 5.0f), vec3(13.0f, 0.0f, 5.0f), vec3(10.0f, -6.0f, 5.0f), Grey };
	Triangle t_4{ vec3(5.0f, 0.0f, 5.0f), vec3(10.0f, -6.0f, 5.0f), vec3(0.0f, -6.0f, 5.0f), Grey };
	Triangle t_5{ vec3(5.0f, 0.0f, 5.0f), vec3(0.0f, -6.0f, 5.0f), vec3(-3.0f, 0.0f, 5.0f), Grey };

	sceneTriangles.push_back(t_0);
	sceneTriangles.push_back(t_1);
	sceneTriangles.push_back(t_2);
	sceneTriangles.push_back(t_3);
	sceneTriangles.push_back(t_4);
	sceneTriangles.push_back(t_5);

	//V�ggar
	Triangle w_0{ vec3(-3.0f, 0.0f, -5.0f), vec3(0.0f, 6.0f, -5.0f), vec3(-3.0f, 0.0f, 5.0f), Red };
	Triangle w_1{ vec3(0.0f, 6.0f, 5.0f), vec3(-3.0f, 0.0f, 5.0f), vec3(-3.0f, 0.0f, -5.0f), Red };
	
	Triangle w_2{ vec3(0.0f, 6.0f, -5.0f), vec3(10.0f, 6.0f, -5.0f), vec3(0.0f, 6.0f, 5.0f), Green };
	Triangle w_3{ vec3(10.0f, 6.0f, 5.0f), vec3(0.0f, 6.0f, 5.0f), vec3(10.0f, 6.0f, -5.0f), Green };
	
	Triangle w_4{ vec3(10.0f, 6.0f, -5.0f), vec3(13.0f, 0.0f, -5.0f), vec3(-3.0f, 0.0f, 5.0f), Blue };
	Triangle w_5{ vec3(13.0f, 0.0f, 5.0f), vec3(10.0f, 6.0f, 5.0f), vec3(13.0f, 0.0f, -5.0f), Blue };
	
	Triangle w_6{ vec3(13.0f, 0.0f, -5.0f), vec3(10.0f, -6.0f, -5.0f), vec3(13.0f, 0.0f, 5.0f), Yellow };
	Triangle w_7{ vec3(10.0f, -6.0f, 5.0f), vec3(10.0f, -6.0f, 5.0f), vec3(13.0f, 0.0f, 5.0f),  Yellow };
	
	Triangle w_8{ vec3(10.0f, -6.0f, -5.0f), vec3(0.0f, -6.0f, -5.0f), vec3(10.0f, -6.0f, 5.0f), Purple };
	Triangle w_9{ vec3(0.0f, -6.0f, 5.0f), vec3(10.0f, -6.0f, 5.0f), vec3(0.0f, -6.0f, -5.0f), Purple };
	
	Triangle w_10{ vec3(0.0f, -6.0f, -5.0f), vec3(-3.0f, 0.0f, -5.0f), vec3(0.0f, -6.0f, 5.0f), Yellow };
	Triangle w_11{ vec3(-3.0f, 0.0f, 5.0f), vec3(0.0f, -6.0f, 5.0f), vec3(-3.0f, 0.0f, -5.0f), Purple };

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

Triangle Scene::whichIsHit(const Ray &aRay, vec3& intersection)
{
	bool hit = false;
	//std::vector<Triangle> hitTriangles;

	vec3 point;
	vec3 hi(0, 0, 0);
	Surface hey;
	Triangle hitTriangle{ Triangle(hi, hi, hi, hey) };
	float closestDist = 100.0f;
	int location = 0;
	for (auto i = sceneTriangles.begin(); i != sceneTriangles.end(); ++i) {
		if (i->RayIntersection(aRay, point)) {
			if (length((i->getMid() - aRay.GetStart())) < closestDist)
			{
				intersection = point;
				hitTriangle = *i;
				++location;
			}
			//hitTriangles.push_back(*i);
		}
	}

	/*
	for (auto i = hitTriangles.begin(); i != hitTriangles.end(); ++i) {

	}*/

	return hitTriangle;
	
}
