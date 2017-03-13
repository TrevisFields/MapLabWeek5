#include <iostream>
using namespace std;

int main()
{
  Map map = Map("Home");
  
  int choice = -1;
  while (choice != 0)
	 {
		cout << "CHoose an option" << endl;
		cout << "0) Exit" << endl;
		cout << "1) Get Current Location Info" << endl;
		cout << "2) Go North" << endl;
	 }
  system("pause");
  return 0;
}
