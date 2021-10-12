#ifndef PLANE_H
#define PLANE_H
#include "plane.cpp"

bool reserve(bool** plane, int rowNumber, char seatLetter, int* seats);
											//Reserves a seat in the plane
											//at the inputted row number
											//and column letter.
									//Precondition: 
									//		0 <= rowNumber < len(seats)
									//		0 <= (seatLetter - 'A') <
									//		seats[rowNumber]
									//Postcondition: The seat at the given row
									//number and seat letter has been 
									//reserved.

bool cancel(bool** plane, int rowNumber, char seatLetter, int* seats);
											//cancels a seat in the plane
											//at the inputted row number
											//and column letter.
									//Precondition: 
									//		0 <= rowNumber < len(seats)
									//		0 <= (seatLetter - 'A') <
									//		seats[rowNumber]
									//Postcondition: The reservation of the
									//seat at the given row number and seat 
									//letter has been canceled.

void printPlane(bool** plane, int* seats);
											//Prints all the locations on the
											//plane. Prints the letter of the
											//seat if empty or an "X" if 
											//taken.
									//Precondition: None
									//Postcondition: All seats in the plane
									//have been displayed.

bool planeMenu(bool** plane, int* seats);
											//displays a menu with a UI to 
											//allow a user to reserve or 
											//cancel a seat in a plane. 
											//returns false if the user 
											//chooses to exit and true
											//otherwise.
									//Precondition: plane has been 
									//				initialized.
									//Postcondition: The user is able to 
									//reserve, cancel, or exit the menu. 
									//The function returns false if the user
									//exits and true otherwise.

#endif // !PLANE_H
