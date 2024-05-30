#include "Ship.hpp"
#include "Cow.hpp"
#include <iostream>

Ship::Ship(const std::string& shipName) : shipName(shipName), numCows(0) {
    for (int i = 0; i < 100; i++) {
        cowInventory[i] = nullptr;
    }
}

    Ship::~Ship() {
      std::cout << shipName << " was destroyed..." << std::endl;
      for (auto& pair : cowInventory) {
        delete pair.second;
      }
    }

    void Ship::abductCow(Cow* cow) {
      auto result = cowInventory.insert({ cow->getName(), cow });
      if (result.second) {
        numCows++;
        std::cout << cow->getName() << " was abducted :O" << std::endl;
      }
      else {
        std::cout << "Error: There's already a cow with that name >:( abduction failed" << std::endl;
        delete cow;
      }
    }

  void Ship::dropOffCow() {
    if (cowInventory.empty()) { 
      std::cout << "we don't have any cows :(" << std::endl;
      return;
    }

    auto it = std::next(cowInventory.begin(), cowInventory.size () / 2);
    delete it->second;
    cowInventory.erase(it);
    numCows--;
    
    std::cout << "we lost a cow :(" << std::endl;
  }
  void Ship::dropOffCow(const std::string& cowID) {
    auto it = cowInventory.find(cowID);
    if (it != cowInventory.end()) {
      delete it->second;
      cowInventory.erase(it);
      numCows--;
      std::cout << cowID << " was dropped off." << std::endl;
    }
    else {
      std::cout << "Error: " << cowID << " doesn't exist :|" << std::endl;
    }
  }
