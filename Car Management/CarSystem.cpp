#include "CarSystem.h"

void CarSystem::addCar(Vehicle* vehicle)
{
	if (vehicle)
		cars.push_back(vehicle);
}

bool CarSystem::removeCar(const std::string& model)
{
	for (auto it = cars.begin(); it != cars.end(); ++it)
	{
		if ((*it)->getModel() == model) {
			delete* it;
			cars.erase(it);
			return true;
		}
	}

	return false;
}

std::vector<Vehicle*> CarSystem::findCars(const std::string& model) const
{
	std::vector<Vehicle*> foundedCars;
	for (const auto& car : cars) {
		if (car->getModel() == model) {
			foundedCars.push_back(car);
		}
	}
	return foundedCars;
}

std::vector<Vehicle*> CarSystem::getCars() const {
	return cars;
}

void CarSystem::clear()
{
	cars.clear();
}

CarSystem::~CarSystem()
{
	clear();
}
