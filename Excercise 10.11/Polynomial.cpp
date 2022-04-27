/*************************************************************************
*
* Program : Class/ Polynomial
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


//Include:
#include "Polynomial.h" // include Polynomial.h header file 

using namespace std;// eliminates the need to repeat the std:: prefix
#include <iostream> // This class inherits all members from its two parent classes istream and ostream, 			        
#include <string> // to use the string data type


//----------------------------------------------------------------------------------------------------




/// <summary>
/// default constructor
/// </summary>
Polynomial::Polynomial()
    : aSize{ 0 },
    ptr{ 0 }
{}




/*
C++ How to program/ Chapter 10.10.2
Use initializer_list to support list initialization.
*/
Polynomial::Polynomial(const initializer_list<double> list) {
    //set the size of the 
    Polynomial::setSize((list.size() > 0 ? static_cast<int>(list.size()) :
                        throw invalid_argument{ "List size must be greater than 0" }));
    //Polynomial::setPolynomial(list);
    
    // set the polynomail given a initializer_list of values
    ptr = { new double[aSize] {} };

    int i{ 0 };
    for (double item : list) {
        ptr[i++] = item;

    }

}




//destructor 
Polynomial::~Polynomial() {}




/// <summary>
/// set the polynomail given a initializer_list of values
/// </summary>
/// <param name="list"></param>
//void Polynomial::setPolynomial(const initializer_list<double> list) {
//
//    ptr = { new double[aSize] {} };
//
//    int i{ 0 };
//    for (double item : list) {
//        ptr[i++] = item;
//
//    }
//
//}




/// <summary>
/// Overload the "-=" operator and return the product. 
/// </summary>
/// <param name="p"></param> Polynomial : second argument in the binary operation. 
/// <returns></returns> Polynomial : difference result. 
Polynomial Polynomial::operator-=(const Polynomial& p) {

    // ex. P = P + P2
    //create a temp polynomial object 
    Polynomial temp = { 0 };
    temp.aSize = (*this).aSize;

    //copy elements to temp
    for (int i{ 0 }; i < (*this).aSize; ++i) {
        temp.ptr[i] = (*this).ptr[i];
    }

    //delete and reallocate memory
    delete[] ptr;
    ptr = { new double[temp.aSize] {} };

    //iterate through polynomials
    for (int i{ 0 }; i < temp.aSize; ++i) {

        // assign new values after p += p2
        ptr[i] = temp.ptr[i] - p.ptr[i];

    }

    //return modified values
    return *this;

}




/// <summary>
/// Overload the "+=" operator and return the sum 
/// </summary>
/// <param name="p"></param> Polynomial : second argument in the binary operation. 
/// <returns></returns> Polynomial : sum result. 
Polynomial Polynomial::operator+=(const Polynomial& p) {

    // ex. P = P + P2
    //create a temp polynomial object 
    Polynomial temp = { 0 };
    temp.aSize = (*this).aSize;

    //copy elements to temp
    for (int i{ 0 }; i < (*this).aSize; ++i) {
        temp.ptr[i] = (*this).ptr[i];
    }

    //delete and reallocate memory
    delete[] ptr;
    ptr = { new double[temp.aSize] {} };

    //iterate through polynomials
    for (int i{ 0 }; i < temp.aSize; ++i) {
              
            // assign new values after p += p2
            ptr[i] = temp.ptr[i] + p.ptr[i];
                 
    }

    //return modified values
    return *this;

}




/// <summary>
/// Overload the "*=" operator and return the product. 
/// </summary>
/// <param name="p"></param> Polynomial : second argument in the binary operation. 
/// <returns></returns> Polynomial : product result. 
Polynomial Polynomial::operator*=(const Polynomial& p) {
    
    // ex. P = P * P2
    //create a temp polynomial object 
    Polynomial temp = { 0 };
    temp.aSize = (*this).aSize;

    //copy elements to temp
    for (int i{ 0 }; i < (*this).aSize; ++i) {
        temp.ptr[i] = (*this).ptr[i];
    }

    //delete and reallocate memory
    delete[] ptr;
    ptr = { new double[temp.aSize] {} };

    //iterate through first polynomial ex.( 2 + 1x^1 + 2x^2 )
    for (int i{ 0 }; i < temp.aSize; ++i) {

        //iterate through second polynomial ex.( 8 + 22x^1 + 4x^2 )
        for (int j{ 0 }; j < p.getSize(); ++j) {
            // assign new values after p *= p2
            ptr[i + j] += temp.ptr[i] * p.ptr[j];

        }

    }

    //return modified values
    return *this;

}




/// <summary>
/// multiply two polynomials and return the result as a new polynomial.
/// </summary>
/// <param name="p"></param> Polynomial : the second polynomial in the binary operation. 
/// <returns></returns> Polynomial : product result.
Polynomial Polynomial::operator*(const Polynomial& p) {

    //get sizes of polynomials
    int thisSize = (*this).getSize();
    int pSize = p.getSize();

    //create a temp polynomial object 
    Polynomial temp = { 0 };

    //delete and reallocate memory
    delete[] temp.ptr;
    temp.ptr = { new double[aSize] {} };
    temp.setSize(thisSize + pSize - 1);

    //iterate through first polynomial ex.( 2 + 1x^1 + 2x^2 )
    for (int i{ 0 }; i < (*this).aSize; ++i) {

        //iterate through second polynomial ex.( 8 + 22x^1 + 4x^2 )
        for (int j{ 0 }; j < p.getSize(); ++j) {

            temp.ptr[i + j] += (*this).ptr[i] * p.ptr[j];

        }

    }

    //return the temp polynomial object created  
    return temp;

}




/// <summary>
/// override the assignment operator.
/// </summary>
/// <param name="p"></param> Polynomail : second binary operation object. 
/// <returns></returns> Polynomial : *this
const Polynomial& Polynomial::operator=(const Polynomial& p) {

    if (p == *this) {

        cerr << "ERROR:  Attempt to copy Polynomial onto self." << endl;

    }
    else {
        //set the size for *this
        (*this).setSize(p.getSize());

        //iterate through the ptr in p and assing values to (*this)
        for (size_t i{ 0 }; i < p.getSize(); ++i) {

            (*this).ptr[i] = p.ptr[i];

        }

    }

    return *this;

}




/// <summary>
/// overide the equals operator. Determine if one polynomial object is equal to the other
/// </summary>
/// <param name="p"></param> the polynomial object
/// <returns></returns> bool : true if equal, else false.
bool  Polynomial::operator==(const Polynomial& p) const {
    // Declare/initialize variables 
    bool result = true;

    //if sizes are not equal, return false
    if (aSize != p.aSize) {
        return false;
    }
    else {
        //iterate through both 
        for (int i{ 0 }; ((i < (*this).aSize) && (result == true)); ++i) {
            //if one value not equal to the other, return false.
            if ((*this).ptr[i] != p.ptr[i]) {
                return false;
            }
        }
    }
    //return resutl 
    return result;
}




/// <summary>
/// override the subtraction operator to subtract two Polynomial objects. 
/// </summary>
/// <param name="p"></param> Polynomial : second Polynomial object of the binary operation. 
/// <returns></returns> Polynomial object as a result of subtracting the two objects. 
Polynomial Polynomial::operator-(const Polynomial& p) {

    //create a temp polynomial object 
    Polynomial temp = { 0 };

    //find the min value and fix sizes for Polynomial objects
    int min{ fixSizes(temp, *this, p) };

    //iterate through both polynomials
    for (int i{ 0 }; i < temp.aSize; ++i) {

        //if less than or equal to the smallest sized polynomial 
        if (i <= min) {

            //add both values 
            temp.ptr[i] = ((*this).ptr[i] - p.ptr[i]);

        }
        //esle determing which one has more than the other
        else {

            //if this size is the smallest, assign the second polynomials value to temp * negative one
            if ((*this).getSize() == min) {
                temp.ptr[i] = (p.ptr[i]) * -1;

            }
            //esle the other way around
            else {
                temp.ptr[i] = ((*this).ptr[i]);
            }

        }

    }

    //return the temp polynomial object created  
    return temp;
}




/// <summary>
/// add two polynomial objects together 
/// </summary>
/// <param name="p"></param> Polynomial : th second polynomial object of the binary operation. 
/// <returns></returns> Polynomial : Polynomial object result of adding the two polynomial objects.  
Polynomial Polynomial::operator+(const Polynomial& p) {

    //create a temp polynomial object 
    Polynomial temp = { 0 };


    //find the min value and fix sizes for Polynomial objects
    int min{ fixSizes(temp, *this, p) };

    //iterate through both polynomials
    for (int i{ 0 }; i < temp.aSize; ++i) {
        //if less than or equal to the smallest sized polynomial 
        if (i <= min) {

            //add both values 
            temp.ptr[i] = ((*this).ptr[i] + p.ptr[i]);


        }
        //esle determing which one has more than the other
        else {

            //if this size is the smallest, assign the second polynomials value to temp
            if ((*this).getSize() == min) {
                temp.ptr[i] = p.ptr[i];

            }
            //esle the other way around
            else {
                temp.ptr[i] = (*this).ptr[i];
            }

        }

    }

    //return the temp polynomial object created  
    return temp;
}




//set size value 
void Polynomial::setSize(int size) {
    (*this).aSize = size;
}
//return the number of elements in the polynomial 
int Polynomial::getSize() const {
    return (*this).aSize;
}




/// <summary>
/// assign the proper sises to the Polynomial objects.
/// </summary>
/// <param name="temp"></param> temporary polynomial object. 
/// <param name="thisPolynomial"></param> *this object
/// <param name="secondPointer"></param> the second object in a binary operation 
/// <returns></returns>
int Polynomial::fixSizes(Polynomial& temp, const Polynomial& thisPolynomial, const Polynomial& secondPointer) {



    //set variables (easier to read)
    int thisSize = thisPolynomial.getSize();
    int p2Size = secondPointer.getSize();


    //find the min value of the two objects being added 
    int min{ 0 };

    //dtermine correct assignment of sizes
    if (thisSize > p2Size) {
        min = p2Size;
        temp.setSize(thisSize);

    }
    else {
        min = thisSize;
        temp.setSize(p2Size);

    }

    temp.ptr = { new double[temp.aSize]{} };

    return min;

}




/// <summary>
/// display the contents of the object as a string 
/// </summary>
void Polynomial::toString() {
    //declare variables 
    char sign;

    //display the Polynomaial as a string 
    for (int i = 0; i < aSize; ++i) {
        double coeff = ptr[i];

        //while not equal to zero 
        if (coeff != 0) {

            //calculate sign 
            if (ptr[i] < 0) {
                sign = '-';
            }
            else {
                sign = '+';
            }

            //print coeff if index 0, else print sign
            if (i == 0) {
                cout << coeff;
            }
            else if (i != (aSize)) {

                cout << " " << sign << " ";

            }

            //print absolute value
            if (coeff < 0 && i != 0) {
                cout << coeff * -1;
            }
            else if (i != 0) {
                cout << coeff;
            }

            //print sign 
            if (i != 0) {
                cout << "x^" << i;

            }

        }

    }

}









