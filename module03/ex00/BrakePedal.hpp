class BrakePedal 
{
	private:
		float force;
	public:
		BrakePedal() { this->force = 0; }
		virtual ~BrakePedal() {};

		void apply_force_on_brakes(float force) { 
			if (force > 100)
				this->force = 100;
			else
				this->force = force; 
		};
		void apply_emergency_brakes() { this->force = 100; };
		float getForce() { return this->force; }
};