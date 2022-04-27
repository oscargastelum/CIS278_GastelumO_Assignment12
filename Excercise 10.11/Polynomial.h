#pragma once // Assures that the file will not be included multiple times in the current project.

//Header files declarations 

#ifndef POLYNOMIAL_H // Will prevent C++ header files from being included multiple times.
#define POLYNOMIAL_H // If not already defined, proceed to define header.


using namespace std; // eliminates the need to repeat the std:: prefix
#include <string> // to use the string data type
#include <iostream> // This class inherits all members from its two parent classes istream and ostream, 
#include <memory>


class Polynomial {



// public methods 
public:

	//constructors & destructor 
	Polynomial();
	Polynomial(const initializer_list<double>);
	~Polynomial(); // destructor 
	//void setPolynomial(const initializer_list<double>);

	//overload operators :)
	Polynomial operator+(const Polynomial&);
	Polynomial operator-(const Polynomial&);
	bool operator==(const Polynomial& ) const;
	const Polynomial& operator=(const Polynomial&);
	Polynomial operator*(const Polynomial&);
	Polynomial operator*=(const Polynomial&);
	Polynomial operator+=(const Polynomial&);
	Polynomial operator-=(const Polynomial&);


	//setters and getters 
	void setSize(int);
	int getSize() const;


	//toString method 
	void toString();

//private fields 
private:
	int fixSizes(Polynomial&, const Polynomial&, const Polynomial&);

	int aSize; // pointer-based array size 
	double* ptr; // pointer to first element of pointer-based array

};


#endif // end if condition 