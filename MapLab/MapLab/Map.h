#pragma once
#include "Location.h"
#include <stack>

class Map
{
private:
  std::stack<Location *> _locationsVisited;
public:
  Map(std::string startingLocationName);
  ~Map();
  
  Location * CurrentLocation = nullptr;
  std::string GetPathBackToHome();
  std::stack<Location *> Path;
  void Move(Location * newLocation);
  

};
