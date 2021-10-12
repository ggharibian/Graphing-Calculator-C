#include "../twod/twod.h"
#include <iostream>
#include "plane.h"
using namespace std;

bool reserve(bool** plane, int rowNumber, char seatLetter, int* seats) {
	int row = rowNumber - 1;
	int col = static_cast<int>(seatLetter - 'A');
			//Integer values representing the row and col indexes of the
			//inputted row number and seat letter.

	if (read(plane, row, col, seats)) {
		return false;
	}		//If the seat has been taken, the function does nothing and 
			//returns false.

	write(plane, true, row, col, seats);
	return true;
			//A reservation has been made for the desired location and the
			//function will return true.
}

bool cancel(bool** plane, int rowNumber, char seatLetter, int* seats) {
	int row = rowNumber - 1;
	int col = static_cast<int>(seatLetter - 'A');
			//Integer values representing the row and col indexes of the
			//inputted row number and seat letter.

	if (read(plane, row, col, seats) == 0) {
		return false;
	}		//If no reservation has been made for the desired seat, the
			//function will return false.

	write(plane, false, row, col, seats);
	return true;
			//The reservation at the desired location will be canceled and
			//the function will return true.
}

void printPlane(bool** plane, int* seats) {
	int row = 1;
	char col = 'A';
			//Values representing the current value to be printed in the loop.

	cout << "  PLANE" << endl
		<< "  =====" << endl;

	for (int i = 0; i < getSize(seats); i++) {
		cout << row << " ";

		for (int e = 0; e < *seats; e++) {

			if (!read(plane, i, e, seats)) {
				cout << col << " ";
			}		//If not already taken, will print the letter value of the
					//current column in the plane.
			else {
				cout << "X ";
			}		//Prints 'X' if the location in the plane has been taken.

			col++;
		}
		cout << endl;
				//Prints entire plane as:
				//
				//		1 A B C D
				//		2 A B C D
				//		3 A B C D
				//		4 A B C D
				//		5 A B C D

		col = 'A';
		row++;
	}
}

bool planeMenu(bool** plane, int* seats) {
	int row;
	char seatLetter;

			//Integer and character values representing the inputted row and
			//seat letter values by the user during the UI.
		
	char choice;

			//The user's desired choice of what to do in the UI.

	printPlane(plane, seats);
	cout << endl;

	cout << "[r]eserve seat    [c]ancel seat      e[x]it" << endl;
	cout << ":"; cin >> choice;
				//The user is able to input a choice to decide whether to
				//reserve a seat, cancel a reservation, or exit (designated by
				//the characters "r", "c", and "x" respectively).

	switch (toupper(choice)) {
	case 'R':
				//If the user wants to reserve a seat.

		cout << "---- RESERVE SEAT: ------" << endl;
		cout << "seats: " << endl;
		print(seats, getSize(seats));
		cout << endl;
				//The "seats" are printed as a reference for the user to
				//reserve a valid seat location.

		cout << "Row: "; cin >> row;
		cout << "Seat Letter: "; cin >> seatLetter;
				//The user enters the desired row and seat letter.

		if (isValid(seats, row - 1, toupper(seatLetter) - 'A')) {
					//If the seat location exists within the plane.

			if (reserve(plane, row, toupper(seatLetter), seats)) {

				cout << "You have reserved a space in Row: " << row <<
					", Seat: " << seatLetter << endl;

			}		//reserves the desired location in the plane and displays
					//a successful message.
			else {

				cout << "Row " << row << ", Seat " << seatLetter << " is "
					<< "occupied" << endl;

			}		//Does not reserve the desired seat due to the location
					//being occupied. Displays an unsuccessful message.
		}
		else {

			cout << "[" << row << "][" << seatLetter << "] is an "
				<< "invalid seat location. " << endl;

		}		//Desired seat location is not an existing location in the 
				//plane.

		break;

	case 'C':
				//If the user wants to cancel a reservation.

		cout << "---- CANCEL SEAT: ------" << endl;

		cout << "Row: "; cin >> row;
		cout << "Seat Letter: "; cin >> seatLetter;
				//The user enters the desired row and seat letter.

		if (isValid(seats, row - 1, toupper(seatLetter) - 'A')) {
					//If the seat location exists within the plane.

			if (cancel(plane, row, toupper(seatLetter), seats)) {

				cout << "Your reservation has been canceled." << endl;

			}		//Cancels the reservation of the desired location in the
					//plane and displays a successful message.

			else {

				cout << "There is no one at that seat." << endl;
				cout << "Try making a reservation first." << endl;

			}		//Does not cancel the reservation of the desired seat 
					//location due to the location being occupied. Displays
					//an unsuccessful message.

		}
		else {
			cout << "[" << row << "][" << seatLetter << "] is an "
				<< "invalid seat location. " << endl;
		}		//The desired location is not an existing location in the 
				//plane.

		break;

	case 'X':
				//If the user wants to exit the menu.

		return false;
				//The function will return false.

	default:
		cout << "Invalid Choice. Please enter again." << endl;

	} //valid index
	

	cout << endl;
	return true;

			//The function will return true the user does not want to exit.
}