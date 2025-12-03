class Gears 
{
	private:
		char gear;

	public:
		Gears() { this->gear = '0'; }
		virtual ~Gears() {};

		void shift_gears_up() { 
			if (this->gear == 'R')
				this->gear = '1';
			else
				this->gear += 1;
		};
		void shift_gears_down() { 
			if (this->gear - 1 < '0')
				this->gear = '0';
			else
				this->gear -= 1;
		};
		void reverse() { this->gear = 'R'; };
		char getGear() { return this->gear; }
};