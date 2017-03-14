#include "Map.h"

Map::Map(std::string startingLocation)
{
  CurrentLocation = new Location(startingLocation);
}

Map::~Map()
{
  
}

void Map::Move(Location * newLocation)
{
  _locationsVisited.push(newLocation);
  CurrentLocation = newLocation;
}

std::string Map::GetPathBackToHome()
{
  return "You are: ";
}

  //implement program to take string names and not just part of a name
  //get path back home to display the entire path
