#include "ElectricVehicle.h"

ElectricVehicle::ElectricVehicle(const string model, double price, int batteryCapacity) :
	Vehicle(model, price), batteryCapacity(batteryCapacity) {}