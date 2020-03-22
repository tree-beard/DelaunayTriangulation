#ifndef DELAUNAY_H
#define DELAUNAY_H
#include "vector2.h"
#include "triangle.h"
#include <algorithm>
#include <vector>

class Delaunay
{
	public:
		const std::vector<Triangle>& triangulate(std::vector<Vec2f> &vertices);
		const std::vector<Triangle>& getTriangles() const { return _triangles; };
		const std::vector<Edge>& getEdges() const { return _edges; };
		const std::vector<Vec2f>& getVertices() const { return _vertices; };

	private:
		std::vector<Triangle> _triangles;
		std::vector<Edge> _edges;
		std::vector<Vec2f> _vertices;
};


#endif // DELAUNAY_H_INCLUDED
