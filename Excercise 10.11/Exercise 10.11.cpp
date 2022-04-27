/*************************************************************************
*
* Program : Assignment - 12/ Exercise 10.11/ Polynomial Class
*
* Created : 04/18/2022
*
* Programmer : Oscar Gastelum
*
*
* ************************************************************************
*  Program description/ purpose : Provides the functionallities of common 
* polynomial operations. Overloading the following operators: 
* +
* =
* -
* *
* +=
* -=
* *=
* ==
*
*-------------------------- Change History -------------------------------
* Programmer :
* Date :
* Description of change :
*
*************************************************************************/




using namespace std; // Eliminates the need to repeat the std:: prefix.
#include <string> // To use the string data type
#include <iostream> // inherits all members from parent classes istream & ostream, perform both input and output operations.
#include<array> // for array, at()
#include<iomanip> //manipulate strings 

//header file
#include "Polynomial.h"

//CONSTANTS 
unsigned int MSG_WIDTH{ 70};



//main. Returns int type 
int main() {
	//display header/ prgogram information 
	cout << setfill(' ');
	cout << setw(MSG_WIDTH) << " DEMONSTRATING POLYNOMIAL CLASS AND OVERLOADED FUNCTIONS " << endl;
	
	//create polynomial objects
	Polynomial p1{ 2, 3, 4 };
	Polynomial p2{ 2, 5, 2, 2 };
	Polynomial p3{ 2, 5, 2, 2 };



	//display values 
	cout << "\n * Polynomial p1 values : ";
	p1.toString();
	cout << "\n * Polynomial p2 values : ";
	p2.toString();
	cout << "\n * Polynomial p3 values : ";
	p3.toString();


	//display msg to user
	cout << "\n\n\n\n====== Displaying overloaded (+) operator ======" << endl;
	cout << "\n * Result after performing operation (p1 + p2)  : ";
	Polynomial sumResult{ p1 + p2 };
	sumResult.toString();


	//display msg to user
	cout << "\n\n\n====== Displaying overloaded (-) operator ======" << endl;
	cout << "\n * Result after performing operation (p1 - p2) : ";
	Polynomial subtractionResult{ p1 - p2 };
	subtractionResult.toString();


	//display msg to user
	cout << "\n\n\n====== Displaying overloaded (*) operator ======" << endl;
	cout << "\n * Result after performing operation (p1 * p2) : ";
	Polynomial xResult{ p1 * p2 };
	xResult.toString();


	cout << "\n\n\n====== Displaying overloaded (+=) operator ======" << endl;
	cout << "\n * Result after performing operation (p1 += p2) : ";
	Polynomial plusEqualsResult{ p1 += p2 };
	plusEqualsResult.toString();


	//display msg to user
	cout << "\n\n\n====== Displaying overloaded (-=) operator ======" << endl;
	cout << "\n * Result after performing operation (p1 -= p2) : ";
	Polynomial subEquals{ p1 -= p2 };
	subEquals.toString();


	//display msg to user
	cout << "\n\n\n====== Displaying overloaded (*=) operator ======" << endl;
	cout << "\n * Result after performing operation (p1 *= p2) : ";
	Polynomial xEquals{ p1 *= p2 };
	xEquals.toString();


	
	//display msg to user
	cout << "\n\n\n====== Displaying overloaded (==) operator ======" << endl;
	
	//display values 
	cout << "\n * Polynomial p1 values : ";
	p1.toString();
	cout << "\n * Polynomial p2 values : ";
	p2.toString();
	cout << "\n * Polynomial p3 values : ";
	p3.toString();

	cout << "\n\n * Result after performing operation (p1 == p2) : ";
	cout << boolalpha;
	cout << (p1 == p2);

	cout << "\n * Result after performing operation (p2 == p3) : ";
	cout << boolalpha;
	cout << (p2 == p3);

	


	cout << "\n\n\n\n~~~ SUCCESSFULLY TERMINTED PROGRAM ~~~" << endl;

}//end main f