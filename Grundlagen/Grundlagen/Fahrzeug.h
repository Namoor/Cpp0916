
class Fahrzeug
{
public:
	Fahrzeug();
	~Fahrzeug();

	virtual void Drive();

	virtual int GetWheelCount() = 0;
};
