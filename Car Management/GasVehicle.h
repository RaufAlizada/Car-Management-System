#pragma once
#include "Vehicle.h"
#include <string>
class GasVehicle : public Vehicle
{
private:
	std::string _model;
	double _fuelCapacity;
	double _price;
public:
	GasVehicle(const std::string model, double price, double fuelCapacity) :
		_model(model), _price(price), _fuelCapacity(fuelCapacity) {}

	virtual std::string getModel() const override { return _model; }
	virtual double getPrice() const override { return _price; }
	virtual double getCapacity() const override { return _fuelCapacity; }
	virtual std::string getType() const override { return "Gas"; }
};

