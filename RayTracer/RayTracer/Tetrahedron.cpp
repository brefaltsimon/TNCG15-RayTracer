#include "Header/Tetrahedron.h"

Tetrahedron::Tetrahedron(colorDbl color)
{

	vec3 v0, v1, v2, v3;
	v0 = vec3( 10.0, -4.0, -4.0);
	v1 = vec3( 9.0, 0.0, -3.0);
	v2 = vec3( 6.0, -2.0, -3.0);
	v3 = vec3( 8.0, -3.0, 0.0);

	Triangle t0 = Triangle(v2, v1, v0,color); // botten
	Triangle t1 = Triangle(v1, v3, v0, color); //mot v1/v0 sidan
	Triangle t2 = Triangle(v2, v0, v3, color); //mot v3 sidan
	Triangle t3 = Triangle(v2, v3, v1, color); //mot v2/v1 sidan

	triangles.push_back(t0);
	triangles.push_back(t1);
	triangles.push_back(t2);
	triangles.push_back(t3);
	
	
}

Tetrahedron::Tetrahedron(vec3 position, float sideLength)
{

	
	//TODO: make position be middle of tetra and put that in room huhuhuhuhuhuh

}

const std::vector<Triangle>& Tetrahedron::getTriangles() const
{
	
	return triangles;
}


