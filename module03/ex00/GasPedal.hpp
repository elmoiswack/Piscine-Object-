class GasPedal
{
	private:
		float speed;

	public:
		GasPedal() { this->speed = 0; }
		virtual ~GasPedal() {};

		void accelerate(float speed) { this->speed = speed; };
		float getSpeed() { return this->speed; }

};