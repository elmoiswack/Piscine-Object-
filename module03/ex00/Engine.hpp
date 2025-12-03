class Engine
{
	private:
		bool isActive;

	public:
		Engine() { this->isActive = false; }
		virtual ~Engine() {};

		void start() { this->isActive = true; };
		void stop() { this->isActive = false; };
		bool getIsActive() { return this->isActive; };
};