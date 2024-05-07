#pragma once
#include "Vehicle.h"


class ElectricVehicle : public Vehicle
{
private:
	std::string _model;
	double _price;
	double _batteryCapacity;
public:
	ElectricVehicle(const std::string model, double price, double batteryCapacity) :
		_model(model), _price(price), _batteryCapacity(batteryCapacity) {}

	virtual std::string getModel() const override { return _model; }
	virtual double getPrice() const override { return _price; }
	virtual double getCapacity() const override { return _batteryCapacity; }
	virtual std::string getType() const override { return "Electric"; }

};

