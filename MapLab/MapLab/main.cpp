#include "Map.h"
#include <stdlib.h>
#include <iostream>
using namespace std;


void GoNorth(Map &map);
void GoSouth(Map &map);
void GoEast(Map &map);
void GoWest(Map &map);


int main()
{
  Map map = Map("Home");
  
  int choice = -1;
  
  while (choice != 0)
	 {
		system("clear");
		cout << "Choose an option." << endl;
		cout << "0) Exit" << endl;
		cout << "1) Get current location." << endl;
		cout << "2) Go North." << endl;
		cout << "3) Go South." << endl;
		cout << "4) Go East." << endl;
		cout << "5) Go West." << endl;
		cout << "6) Path To Home." << endl;
		
		cin >> choice;
		system("pause");
		
		switch (choice)
		{
		  case 1:
			 cout << "You are currently located: " << map.CurrentLocation -> DisplayLocationInfo();
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
			 system("clear");
			 cout << map.GetPathBackToHome() << endl;
			 break;
			 
			 default:
			 cout << "Enter a valid option";
			 break;
		}
	 }
  
  system("pause");
  return 0;
}

  //void function for Go North
void GoNorth(Map &map)
{
  auto newLocation = map.CurrentLocation -> North;
  if(newLocation == nullptr)
	 {
		system("clear");
		cout <<"You have not been here before, enter a name for this discovery: ";
		string name;
		cin >> name;
		newLocation = new Location(name);
		cout << "Welcome to: " + name << endl;
	 }
  
  else
	 {
		cout << "Welcome back to: " + newLocation -> DisplayLocationInfo();
	 }
  
  newLocation -> South = map.CurrentLocation;
  map.Move(newLocation);
  return;
}

  //void function for GoSouth
void GoSouth(Map &map)
{
  auto newLocation = map.CurrentLocation -> South;
  if(newLocation == nullptr)
	 {
		system("clear");
		cout <<"You have not been here before, enter a name for this discovery: ";
		string name;
		cin >> name;
		newLocation = new Location(name);
		cout << "Welcome to: " + name << endl;
	 }
  
  else
	 {
		cout << "Welcome back to: " + newLocation -> DisplayLocationInfo();
	 }
  
  newLocation -> North = map.CurrentLocation;
  map.Move(newLocation);
  return;

}

  //void function for GoWest
void GoWest(Map &map)
{
  auto newLocation = map.CurrentLocation -> West;
  if(newLocation == nullptr)
	 {
		system("clear");
		cout <<"You have not been here before, enter a name for this discovery: ";
		string name;
		cin >> name;
		newLocation = new Location(name);
		cout << "Welcome to: " + name << endl;
	 }
  
  else
	 {
		cout << "Welcome back to: " + newLocation -> DisplayLocationInfo();
	 }
  
  newLocation -> East = map.CurrentLocation;
  map.Move(newLocation);
  return;
 
}

  //void function for GoEast
void GoEast(Map &map)
{
  auto newLocation = map.CurrentLocation -> East;
  if(newLocation == nullptr)
	 {
		system("clear");
		cout <<"You have not been here before, enter a name for this discovery: ";
		string name;
		cin >> name;
		newLocation = new Location(name);
		cout << "Welcome to: " + name << endl;
	 }
  
  else
	 {
		cout << "Welcome back to: " + newLocation -> DisplayLocationInfo();
	 }
  
  newLocation -> West = map.CurrentLocation;
  map.Move(newLocation);
  return;

}
