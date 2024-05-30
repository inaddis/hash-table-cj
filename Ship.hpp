#ifndef SHIP_HPP
#define SHIP_HPP

#include <vector>
#include <set>
#include <map>
#include <string>
#include "Cow.hpp"

class Cow;

class Ship {
  private: 
    std::string shipName;
    // std::map<std::string, Cow*> cowInventory;
    int numCows;
    Cow* cowInventory[100];
    // std::set<std::string> abductedCows;

  public: 
    Ship(const std::string& shipName);

    ~Ship();

    void abductCow(Cow* cow);

    const std::map<std::string, Cow*>& getCowInventory() const {
      return cowInventory;
  }

  void dropOffCow();

  void dropOffCow(const std::string& cowID);

};

#endif // SHIP_HPP
