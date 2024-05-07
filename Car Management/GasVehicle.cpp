#include "GasVehicle.h"

GasVehicle::GasVehicle(const string model, double price, int fuelCapacity) :
	Vehicle(model, price), fuelCapacity(fuelCapacity) {}