#include "Map.h"
#include <iostream>
using namespace std;

/*
 ERRORS FOUND SO FAR:
 every time i try to go from the starting location of HOME (0,0) the default location is HOME (0,0) but when i change to a new location and try to go back I end up creating a new location name for the area in which i came from. There seems to be a problem with the code in that part of the programming and at the moment i am not able to figure out how to fix the problem. there arent really any break points that are helping me get to the conclusion of the program.
 Another problem is that i start at HOME (0,0) and i can move to another location and set the name, when i try to go back to the previous location i have to reset the name. After reseting the name i am no longer able to go further in the same location (almost like a broken loop that goes back and forth between the location i set and the first location i made.) the HOME location is always being renamed when i go back to it.
 
 After a while the problem was that the direction i was going was in a loop for each of the directions i wanted to go. i was going north in each of the four directions instead of going to the same location that was originally meant for each path. 
 
 
 now i need to record all of the paths taken and send back each one to get my path back home
 (is it suppose to be one to one or a whole bunch of paths that lead back to HOME???)
 
 EXTRA credit id to put myself in the location that is needed
 */
void GoNorth(Map &map);
void GoSouth(Map &map);
void GoEast(Map &map);
void GoWest(Map &map);


int main()
{
  auto map = Map("HOME");
  
  int choice = - 1;
  
  while (choice != 0)
	 {
		system("clear");
		cout << "1) Display current location." << endl;
		cout << "2) Go North." << endl;
		cout << "3) Go South." << endl;
		cout << "4) Go East." << endl;
		cout << "5) Go West." << endl;
		cout << "6) Path To Home." << endl;
		cout << "0) Close Program" << endl;
		
		cin >> choice;
		
		
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
			 
			 cout << map.GetPathBackToHome() << endl;
			 break;
			 
			 case 0:
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
		
		if (existing == nullptr)
		{
		  system("cls");
		  system("clear");
		  cout << "You haven't been here before, enter a name for this place: ";
		  string name;
		  cin >> name;
		  newLocation = new Location(name, newX, newY);
		  cout << "This place is now called: " + name << endl;
	 }
		  //work on this portion in order to get the desired results
		else
		{
		  //map.CurrentLocation = existing;
		  cout << " You've been here before." << existing -> DisplayLocationInfo();
		}

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
  auto newLocation = map.CurrentLocation -> South;
  int currentX = map.CurrentLocation -> getX();
  int currentY = map.CurrentLocation -> getY();
  if(newLocation == nullptr)
	 {
		int newX = currentX;
		int newY = currentY - 1;
		auto existing = map.LookupLocationOnMap(newX, newY);
		
		if (existing == nullptr)
		{
		system("cls");
		system("clear");
		cout << "You haven't been here before, enter a name for this place: ";
		string name;
		cin >> name;
		newLocation = new Location(name, newX, newY);
		cout << "This place is now called: " + name << endl;
	 }
		  //work on this portion in order to get the desired results
		else
		{
		  //map.CurrentLocation = existing;
		  cout << " You've been here before." << existing -> DisplayLocationInfo();
		}
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
  auto newLocation = map.CurrentLocation -> West;
  int currentX = map.CurrentLocation -> getX();
  int currentY = map.CurrentLocation -> getY();
  if(newLocation == nullptr)
	 {
		int newX = currentX - 1;
		int newY = currentY;
		auto existing = map.LookupLocationOnMap(newX, newY);
		
		if (existing == nullptr)
		{
		  system("cls");
		  system("clear");
		  cout << "You haven't been here before, enter a name for this place: ";
		  string name;
		  cin >> name;
		  newLocation = new Location(name, newX, newY);
		  cout << "This place is now called: " + name << endl;
	 }
		  //work on this portion in order to get the desired results
		else
		{
		  //map.CurrentLocation = existing;
		  cout << " You've been here before." << existing -> DisplayLocationInfo();
		}

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
  auto newLocation = map.CurrentLocation -> East;
  int currentX = map.CurrentLocation -> getX();
  int currentY = map.CurrentLocation -> getY();
  if(newLocation == nullptr)
	 {
		int newX = currentX + 1;
		int newY = currentY;
		auto existing = map.LookupLocationOnMap(newX, newY);
		if (existing == nullptr)
		{
		  system("cls");
		  system("clear");
		  cout << "You haven't been here before, enter a name for this place: ";
		  string name;
		  cin >> name;
		  newLocation = new Location(name, newX, newY);
		  cout << "This place is now called: " + name << endl;
	 }
		  //work on this portion in order to get the desired results
		else
		{
		  //map.CurrentLocation = existing;
		  cout << " You've been here before." << existing -> DisplayLocationInfo();
		}
	 }
  
  else
	 {
		cout << "You are at: " + newLocation -> DisplayLocationInfo();
	 }
  newLocation -> West = map.CurrentLocation;
  map.Move(newLocation);
  return;
}
