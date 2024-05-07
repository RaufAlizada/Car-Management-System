#include <iostream>
#include<vector>
#include"GasVehicle.h"
#include"ElectricVehicle.h"
#include"FileManager.h"
#include "CarSystem.h"



int main()
{

    GasVehicle car_1("Mercedes CLS", 50000, 60);
    GasVehicle car_2("Porsche 911 GT3RS", 20000, 50);
    ElectricVehicle car_3("BMW X7", 100000, 85);

    CarSystem carSystem;
    carSystem.addCar(&car_1);
    carSystem.addCar(&car_2);
    carSystem.addCar(&car_3);

    //FileManager::writeToFile("cars.bin", carSystem);

    //std::cout << "Cars saved to file successfully!" << std::endl;

    CarSystem loadedCars = FileManager::readFromFile("cars.bin");

    for (const auto& car : loadedCars.getCars())
    {
        std::cout << "Model: " << car->getModel() << "\nCapacity: " << car->getCapacity() << "\nPrice: " << car->getPrice() << "\n\n";
    }

    carSystem.clear();
}
