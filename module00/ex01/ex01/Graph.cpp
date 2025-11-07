#include "Graph.hpp"
#include <algorithm>

Graph::Graph(float x, float y) {

	this->_size._x = x;
	this->_size._y = y;
	this->_points = {};
	std::cout << "Graph constructed" << std::endl;
}

Graph::~Graph() {

	std::cout << "Graph Decostructor is called" << std::endl;
}

void Graph::addPoint(float x, float y) {

	if (x >= this->_size._x || y >= this->_size._y)
	{
		std::cout << "Error Point is outside of size" << std::endl;
		return ;
	}

	this->_points.push_back(Vector2(x, y));
	std::cout << "Point succesfully added" << std::endl;
}

bool Graph::isPointSet(Vector2 pointToFind) {

	for (auto it = this->_points.begin(); it != this->_points.end(); it++)
	{
		if ((*it) == pointToFind)
			return (true);
	}
	return (false);
}

void Graph::displayGraph() {

	auto graph = std::vector<std::vector<Vector2>>(int(this->_size._y), std::vector<Vector2>(int(this->_size._x), Vector2(0, 0)));
	for (int yIndex = 0; yIndex < int(this->_size._y); yIndex++)
	{
		for (int xIndex = 0; xIndex < int(this->_size._x); xIndex++)
		{
			graph[yIndex][xIndex]._x = xIndex;
			graph[yIndex][xIndex]._y = yIndex;
		}
	}

	for (int y = (int(this->_size._y) - 1); y >= 0; y--)
	{
		std::cout << y << " ";
		for (int x = 0 ; x < int(this->_size._x); x++)
		{	
			if (isPointSet(graph[y][x])) {
				std::cout << 'X';
			} else {
				std::cout << '.';
			}
			if ((x + 1) != int(this->_size._x))
					std::cout << ' ';
		}
		std::cout << std::endl;
	}
	
	std::cout << "  ";

	for (int x = 0 ; x < int(this->_size._x); x++)
	{
		std::cout << x;
		if ((x + 1) != int(this->_size._x))
			std::cout << ' ';
	}
	std::cout << std::endl;
}