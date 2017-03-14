#pragma once
#include <string>


class Location
{
private:
  std::string _name;
public:
  Location * North = nullptr;
  Location * South = nullptr;
  Location * West = nullptr;
  Location * East = nullptr;
  
  Location(std::string name);
  ~Location();
  std::string DisplayLocationInfo();
};
