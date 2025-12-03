class Wheels 
{
	private:
		float angle;

	public:
		Wheels() { this->angle = 0; }
		virtual ~Wheels() {};

		void turn_wheel(float angle) {
			if (angle > 45)
				this->angle = 45;
			else if (angle < -45)
				this->angle = -45;
			else
				this->angle = angle;
		};
		void straighten_wheels() { this->angle = 0; };
		float getAngle() { return this->angle; }
};