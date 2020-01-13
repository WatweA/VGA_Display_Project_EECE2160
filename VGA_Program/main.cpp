#include "VGADisplay.h"
#include <unistd.h>
#include <iostream>
using namespace std;

// Prompt the user to enter RGB values into the given pointer locations with error checking
void promptColor(int* r, int* g, int* b)
{
	// Prompt for the colors
	cout << "Enter a red value [0, 255]: ";
	if(!(cin >> *r)) {
		cerr << "ERR: Invalid red value" << endl;
	} else {
		cout << "Enter a green value [0, 255]: ";
		if(!(cin >> *g)) {
			cerr << "ERR: Invalid green value" << endl;
		} else {
			cout << "Ener a blue value [0, 255]: ";
			if(!(cin >> *b)) {
				cerr << "ERR: Invalid blue value" << endl;
			} else {
				return;
			}
		}
	}
}

/*
// Prompt the user to enter the box's size woth error checking
void promptSize(int* h, int* v)
{
	// Prompt for the size
	cout << "Enter a horizontal value [0, 640]: ";
	if(!(cin >> *h)) {
		cerr << "ERR: Invalid horizontal value" << endl;
	} else if(*h > 640 || *h < 0) {
		cerr << "ERR: Horizontal value out of range" << endl;
	} else {
		cout << "Enter a vertical value [0, 480]: ";
		if(!(cin >> *v)) {
			cerr << "ERR: Invalid vertical value" << endl;
		} else if(*v > 640 || *v < 0) {
			cerr << "ERR: Vertical value out of range" << endl;
		} else {
			return;
		}
	}
}
*/

int main()
{
	VGADisplay display;
	display.Background_RGB_Write(0,0,255);
//	display.Size_Write(100, 50);

	display.RGB_Write(255, 0, 0);

	string menu = 
		"Main menu:\n"
		"1. Set background color\n"
		"2. Set box color\n"
//		"3. Set box dimensions\n"
		"3. Exit\n"
		"Select an option: ";
	string choice1 = "\"Set background color\"";
	string choice2 = "\"Set box color\"";
//	string choice3 = "\"Set box dimensions\"";
	string choice3 = "\"Exit\"";

	string option_str;
	int option;
	cout << menu;

	bool selected_exit = false;
	while(!(selected_exit)) {

		if(!(cin >> option)) {
			cin.clear();
			cin.ignore(10000, '\n');
			cerr << "ERR1: Invalid option entered. Please select from the menu." << endl;	
		}
		else {
			cout << "You selected: ";
		}

		switch (option) {
			case 1:
			{
				cout << choice1 << endl;
				// Prompt the user to enter a background color
				int r, g, b;
				cout << "Enter the RGB values for your display background" << endl;
				promptColor(&r, &g, &b);
				display.Background_RGB_Write(r, g, b);
				break;
			}
			case 2:
			{
				cout << choice2 << endl;
				// Prompt the user to enter a box color
				int r, g, b;
				cout << "Enter the RGB values for your box" << endl;
				promptColor(&r, &g, &b);
				display.RGB_Write(r, g, b);
				break;
			}
/*			case 3:
			{
				cout << choice3 << endl;
				// Prompt the user for sizes
				int h, v;
				cout << "Enter the box's dimensions" << endl;
				promptSize(&h, &v);
				display.Size_Write(h, v);
				break;
			}
*/			case 3:
			{
				cout << choice3 << endl;
				selected_exit = true;
				break;
			}
			default:
			{
				cerr << "ERR: Invalid option. Please select from the menu." << endl;
				break;
			}
			
		}
		
		if(!selected_exit) {
			cout << menu;
		}
	}

}
