#include <iostream>

class Vector2
{
	private:
		float _x;
		float _y;

	protected:
		Vector2();
		Vector2(float x, float y);
	
	public:
		virtual ~Vector2();
		bool operator==(const Vector2& other) const;

	friend class Graph;
};



