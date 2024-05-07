#pragma once
#include  <string>
class Vehicle
{
public:
	virtual ~Vehicle() {}

	virtual std::string getModel() const = 0;
	virtual double getCapacity() const = 0;
	virtual double getPrice() const = 0;
	virtual std::string getType() const = 0;

};

