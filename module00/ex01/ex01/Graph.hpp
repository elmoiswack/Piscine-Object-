#include <iostream>
#include <vector>
#include "Vector2.hpp"

class Graph
{
	private:
		Vector2 _size;
		std::vector<Vector2> _points;

	public:
		Graph(float x, float y);
		~Graph();

		void addPoint(float x, float y);
		bool isPointSet(Vector2 pointToFind);
		void displayGraph();
};


