#include "../twod/twod.h"
#include <cctype>
#include "lab.h"
using namespace std;

bool login(int** labs, int lab, int station, int ID, int* lab_sizes) {
	if (read(labs, lab, station, lab_sizes) != -1) {
		return false;
	}			//returns false if the desired location in the lab has
				//already been taken.

	write(labs, ID, lab, station, lab_sizes);

				//Adds the user to the laboratory.

	return true;
				//Returns true to signify that the user has been successfully
				//logged in.
}

bool logout(int** labs, int* lab_sizes, int ID) {
	int row, col;
				//integer values representing the row and column location
				//of the found ID in the lab.

	if (!search(labs, ID, row, col, lab_sizes)) {
		return false;
	}			//returns false if the given ID doesn't exist in the lab.


	do {

		write(labs, -1, row, col, lab_sizes);

	} while (search(labs, ID, row, col, lab_sizes));
				//Will log out the user with the ID from all lab stations
				//until they are no longer in the lab.

	return true;
			//returns true to signify that the user has been successful 
			//logged out of the lab.
}

bool labMenu(int** labs, int* lab_sizes) {
	int id, lab, station;
				//integer values representing the inputted ID, lab, and 
				//station values by the user during the UI.

	char choice;
				//The user's desired choice of what to do in the UI.

	print(labs, lab_sizes, 5);
	cout << endl;

	cout << "log[i]n    log[o]ut      e[x]it" << endl;
	cout << ":"; cin >> choice;
				//The user is able to input a choice to decide whether to
				//login, logout, or exit (designated by the characters "i",
				//"o", and "x" respectively.

	switch (toupper(choice)) {
	case 'I':
				//If the user wants to login.

		cout << "---- LOG IN: ------" << endl;
		cout << "labs: " << endl;
		print(lab_sizes, getSize(lab_sizes));
		cout << endl;
				//The "lab_sizes" are printed as a reference for the user to
				//log in to a valid lab station.

		cout << "id: "; cin >> id;
		cout << "lab: "; cin >> lab;
		cout << "station: "; cin >> station;
				//The user enters their ID, desired lab, and desired station.

		if (isValid(lab_sizes, lab, station)) {
					//If the lab and station exists within the lab.

			if (id >= 0) {
						//If the ID value is a real, valid ID.

				if (login(labs, lab, station, id, lab_sizes)) {

					cout << "You are logged in in lab: " << lab <<
						", station: " << station << endl;

				}		//Logs in in the user to their desired location in the
						//lab and displays a successful message.
				else {

					cout << "lab: " << lab << ", station: " << station 
						<< " is occupied" << endl;

				}		//Does not log in the user to the lab due to location
						//being occupied. Displays an unsuccessful message.
			}
			else {

				cout << "The ID, " << id << ", is not a valid ID." << endl;
			}		//If the ID value is not valid, the user will not be 
					//logged into the lab and an unsuccessful message is printed.

		} //valid index
		else {
			cout << "[" << lab << "][" << station << "] is invalid. " << endl;
		}	//The desired location is not a existing location in the lab.

		break;

	case 'O':
					//If the user wants to logout.
		cout << "---- LOG OUT: ------" << endl;

		cout << "id: "; cin >> id;
					//The user only needs to enter their ID, as they will be
					//logged out of all locations in the lab.

		if (logout(labs, lab_sizes, id)) {
			cout << "You are logged out of all lab stations." << endl;
		}			//Logs out the user and displays a successful message.
		else {
			cout << "You are not logged into any lab stations." << endl;
			cout << "Try logging in first." << endl;
		}			//Does not log out the user since they do not exist in the
					//lab. Displays an unsuccessful message.

		break;

	case 'X':
				//If the user wants to exit the menu.

		return false;
				//The function will return false.

	default:
		cout << "Invalid Choice. Please enter again." << endl;

	}

	cout << endl;
	return true;
			//The function returns true if the user has not tried to exit.
}