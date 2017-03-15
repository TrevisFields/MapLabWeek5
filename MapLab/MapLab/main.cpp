#include "Map.h"
#include <stdlib.h>
#include <iostream>
using namespace std;


void GoNorth(Map &map);
void GoSouth(Map &map);
void GoEast(Map &map);
void GoWest(Map &map);

  //main function
int main()
{
  Map map = Map("Home");
  
  int choice = -1;
  //while loop
  while (choice != 0)
	 {
		system("clear");//Does not clear the terminal in xcode/ "TERM environment variable not set."
		cout << endl;
		cout << endl;
		cout << "Choose an option." << endl;
		cout << "1) Get current location." << endl;
		cout << "2) Go North." << endl;
		cout << "3) Go South." << endl;
		cout << "4) Go East." << endl;
		cout << "5) Go West." << endl;
		cout << "6) Path To Home." << endl;
		cout << "0) Close Program" << endl;
		
		cin >> choice;
		cin.get();//sh: pause: command not found
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
			 cout << "Enter a valid option";
			 break;
		}
	 }
  
  cin.get();
  return 0;
}

  //Void functions declared outside the scope of the main function of the program
/*******************************************************************/
  //void function for Go North
void GoNorth(Map &map)
{
  auto newLocation = map.CurrentLocation -> North;
  if(newLocation == nullptr)
	 {
		system("clear");//Does not clear the terminal in xcode/ "TERM environment variable not set."
		cout <<"You have not been here before, enter a name for this discovery: ";
		string name;
		cin >> name;
		newLocation = new Location(name);
		cout << "Welcome traveler, you are now entering: " + name << endl;
	 }
  
  else
	 {
		cout << "\"Nani wan\" - Welcome!  : " + newLocation -> DisplayLocationInfo();
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
		system("clear");//Does not clear the terminal in xcode/ "TERM environment variable not set."
		cout <<"You have not been here before, enter a name for this discovery: ";
		string name;
		cin >> name;
		newLocation = new Location(name);
		cout << "You are a foreiner in a distant land: " + name << endl;
	 }
  
  else
	 {
		cout << "May your weary travels become rested here once again: " + newLocation -> DisplayLocationInfo();
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
		system("clear");//Does not clear the terminal in xcode/ "TERM environment variable not set."
		cout <<"You have not been here before, enter a name for this discovery: ";
		string name;
		cin >> name;
		newLocation = new Location(name);
		cout << "Aloha land dweller: " + name << endl;
	 }
  
  else
	 {
		cout << "Aloha again: " + newLocation -> DisplayLocationInfo();
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
		system("clear");//Does not clear the terminal in xcode/ "TERM environment variable not set."
		cout <<"You have not been here before, enter a name for this discovery: ";
		string name;
		cin >> name;
		newLocation = new Location(name);
		cout << "You must be some city folk: " + name << endl;
	 }
  
  else
	 {
		cout << "We welcome your return to: " + newLocation -> DisplayLocationInfo();
	 }
  
  newLocation -> West = map.CurrentLocation;
  map.Move(newLocation);
  return;

}
/**********************************************************************/
