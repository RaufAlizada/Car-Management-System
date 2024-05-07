#pragma once
#include <vector>
#include "Vehicle.h"
#include "GasVehicle.h"
#include "ElectricVehicle.h"
#include "CarSystem.h"
#include <fstream>

class FileManager
{
public:
	static void writeToFile(const std::string& fileName, const CarSystem& carSystem) {
		std::ofstream file(fileName, std::ios::binary);
		if (file.is_open()) {
			int numCars = carSystem.getCars().size();
			file.write(reinterpret_cast<const char*>(&numCars), sizeof(numCars));

			for (const auto& car : carSystem.getCars())
			{
				std::string model = car->getModel();
				double capacity = car->getCapacity();
				double price = car->getPrice();
				std::string type = car->getType();

				int modelSize = model.size();
				file.write(reinterpret_cast<const char*>(&modelSize), sizeof(modelSize));
				file.write(model.c_str(), modelSize);
				file.write(reinterpret_cast<const char*>(&capacity), sizeof(capacity));
				file.write(reinterpret_cast<const char*>(&price), sizeof(price));
				int typeSize = type.size();
				file.write(reinterpret_cast<const char*>(&typeSize), sizeof(typeSize));
				file.write(type.c_str(), typeSize);
			}
			file.close();
		}
	}


	static CarSystem readFromFile(const std::string& fileName) {
		CarSystem carSystem;

		std::ifstream file(fileName, std::ios::binary);

		if (file.is_open()) {
			int numCars;
			file.read(reinterpret_cast<char*>(&numCars), sizeof(numCars));

			for (size_t i = 0; i < numCars; i++)
			{
				std::string model;
				double price, capacity;
				std::string type;

				int modelSize;
				file.read(reinterpret_cast<char*>(&modelSize), sizeof(modelSize));
				model.resize(modelSize);
				file.read(&model[0], modelSize);

				file.read(reinterpret_cast<char*>(&capacity), sizeof(capacity));
				file.read(reinterpret_cast<char*>(&price), sizeof(price));

				int typeSize;
				file.read(reinterpret_cast<char*>(&typeSize), sizeof(typeSize));
				type.resize(typeSize);
				file.read(&type[0], typeSize);

				if (type == "Gas") {
					carSystem.addCar(new GasVehicle(model, price, capacity));
				}
				else if (type == "Electric") {
					carSystem.addCar(new ElectricVehicle(model, price, capacity));
				}
			}
			file.close();
		}

		return carSystem;
	}
};

