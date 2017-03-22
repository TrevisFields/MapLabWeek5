#include "Map.h"
#include <iostream>
using namespace std;


void GoNorth(Map &map);
void GoSouth(Map &map);
void GoEast(Map &map);
void GoWest(Map &map);

  //main function
int main()
{
  auto map = Map("Home");
  
  int choice = -1;
  //while loop
  while (choice != 0)
	 {
		system("clear");//Does not clear the terminal in xcode/ "TERM environment variable not set."
		cout << "1) Display current location." << endl;
		cout << "2) Go North." << endl;
		cout << "3) Go South." << endl;
		cout << "4) Go East." << endl;
		cout << "5) Go West." << endl;
		cout << "6) Path To Home." << endl;
		cout << "0) Close Program" << endl;
		
		cin >> choice;
		
		  //switch statements used for each choice given in the options menu
		switch (choice)
		{
		  case 1:
			 cout << "Current Location: " << map.CurrentLocation -> DisplayLocationInfo();
			 break;
			 
		  case 2:
			 GoNorth(map);
			 break;
			 
		  case 3:
			 GoSouth(map);
			 break;
			
		  case 4:
			 GoEast(map);
			 break;
			 
		  case 5:
			 GoWest(map);
			 break;
			 case 6:
			 //Does not clear the terminal in xcode/ "TERM environment variable not set."
			 cout << map.GetPathBackToHome() << endl;
			 break;
			 
			 default:
			 cout << "Enter a valid option\n";
			 break;
		}
		cin.get();
	 }
  
  return 0;
}

void GoNorth(Map &map)
{
  auto newLocation = map.CurrentLocation -> North;
  int currentX = map.CurrentLocation -> getX();
  int currentY = map.CurrentLocation -> getY();
  if(newLocation == nullptr)
	 {
		int newX = currentX;
		int newY = currentY + 1;
		auto existing = map.LookupLocationOnMap(newX, newY);
		
		system("cls");
		system("clear");
		cout << "You haven't been here before, enter a name for this place: ";
		string name;
		cin >> name;
		newLocation = new Location(name, newX, newY);
		cout << "This place is now called: " + name << endl;
	 }
  
  else
	 {
		cout << "You are at: " + newLocation -> DisplayLocationInfo();
	 }
  newLocation -> South = map.CurrentLocation;
  map.Move(newLocation);
  return;
}


void GoSouth(Map &map)
{
  auto newLocation = map.CurrentLocation -> North;
  int currentX = map.CurrentLocation -> getX();
  int currentY = map.CurrentLocation -> getY();
  if(newLocation == nullptr)
	 {
		int newX = currentX;
		int newY = currentY - 1;
		auto existing = map.LookupLocationOnMap(newX, newY);
		
		system("cls");
		system("clear");
		cout << "You haven't been here before, enter a name for this place: ";
		string name;
		cin >> name;
		newLocation = new Location(name, newX, newY);
		cout << "This place is now called: " + name << endl;
	 }
  
  else
	 {
		cout << "You are at: " + newLocation -> DisplayLocationInfo();
	 }
  newLocation -> North = map.CurrentLocation;
  map.Move(newLocation);
  return;
}


void GoWest(Map &map)
{
  auto newLocation = map.CurrentLocation -> North;
  int currentX = map.CurrentLocation -> getX();
  int currentY = map.CurrentLocation -> getY();
  if(newLocation == nullptr)
	 {
		int newX = currentX - 1;
		int newY = currentY;
		auto existing = map.LookupLocationOnMap(newX, newY);
		
		system("cls");
		system("clear");
		cout << "You haven't been here before, enter a name for this place: ";
		string name;
		cin >> name;
		newLocation = new Location(name, newX, newY);
		cout << "This place is now called: " + name << endl;
	 }
  
  else
	 {
		cout << "You are at: " + newLocation -> DisplayLocationInfo();
	 }
  newLocation -> East = map.CurrentLocation;
  map.Move(newLocation);
  return;
}


void GoEast(Map &map)
{
  auto newLocation = map.CurrentLocation -> North;
  int currentX = map.CurrentLocation -> getX();
  int currentY = map.CurrentLocation -> getY();
  if(newLocation == nullptr)
	 {
		int newX = currentX + 1;
		int newY = currentY;
		auto existing = map.LookupLocationOnMap(newX, newY);
		
		system("cls");
		system("clear");
		cout << "You haven't been here before, enter a name for this place: ";
		string name;
		cin >> name;
		newLocation = new Location(name, newX, newY);
		cout << "This place is now called: " + name << endl;
	 }
  
  else
	 {
		cout << "You are at: " + newLocation -> DisplayLocationInfo();
	 }
  newLocation -> West = map.CurrentLocation;
  map.Move(newLocation);
  return;
}
