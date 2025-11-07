#include "Vector2.hpp"

Vector2::Vector2() {

	this->_x = 0;
	this->_y = 0;
}

Vector2::Vector2(float x, float y) {
	
	this->_x = x;
	this->_y = y;
}

Vector2::~Vector2() {
}

bool Vector2::operator==(const Vector2& other) const {
    return _x == other._x && _y == other._y;
}