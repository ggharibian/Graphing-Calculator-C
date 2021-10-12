#ifndef LAB_H
#define LAB_H
#include "lab.cpp"

bool login(int** labs, int lab, int station, int ID, int* lab_sizes);
											//logs in a user with the id 
											//"ID" to a lab "lab" and station
											//"station" within the lab.
									//Precondition: 
									//		0 <= lab < len(lab_sizes)
									//		0 <= station < lab_sizes[row]
									//		Id >= 0
									//Postcondition: The user with the ID will
									//be logged into the desired lab and 
									//station location in the lab.

bool logout(int** labs, int* sizes, int ID);
											//logs out a user with the id 
											//"ID" from the lab
									//Precondition: Id >= 0
									//Postcondition: The user with the ID will
									//be logged out of all stations in the 
									//lab.

bool labMenu(int** labs, int* lab_sizes);
											//displays a menu with a UI to 
											//allow a user to login or logout
											//of a lab. returns false if the 
											//user chooses to exit and true
											//otherwise.
									//Precondition: labs has been initialized.
									//Postcondition: The user is able to login
									//, logout, or exit the menu. The function
									//returns false if the user exits and true
									//otherwise.


#endif // !LAB_H
