#pragma once
#include <vector>
#include <algorithm>
#include "Vehicle.h"

class CarSystem
{
private:
	std::vector<Vehicle*> cars;

public:
	void addCar(Vehicle* vehicle);
	bool removeCar(const std::string& model);

	std::vector<Vehicle*> findCars(const std::string& model) const;
	std::vector<Vehicle*> getCars() const;

	void clear();
	~CarSystem();
};

