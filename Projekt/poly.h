//
// Created by dawiddobrowolski on 04.01.2022.
//

#ifndef POLY_POLY_H
#define POLY_POLY_H

#include <iostream>
#include <cassert>
#include <cmath>
using namespace std;
//! Poly class.
/*!
 * The class implements use of polynomials based on arrays
 * using a template.
 * @author Dawid Dobrowolski
 * @version 1.0
 * @param tab - the array stores the successive coefficients of the polynomial.
 * @param msize - the size of the array according to the degree of the polynomial
 */
template<typename T>
class Poly {
    public:
            T *tab;
            int msize;


public:
    /**
     * Default constructor
     * Create a zero degree polynomial and sets its value to zero
     * @return Poly class object
     */
    Poly() {
        msize = 1;
        tab = new T[msize];
        tab[0] = 0;
    }

    /**
     * Main constructor.
     * Creates a polynomial of a given degree and creates an array that stores its coefficients which we can set by
     * loadPoly().
     * @param s - degree of polynomial
     * @return Poly class object
     * @see loadPoly()
     */
    Poly(int s) {
        msize = s + 1;
        tab = new T[msize];
        tab[msize] = {};
        assert(tab != nullptr);
    }

    Poly(int s, T* userTab) {
        msize = s + 1;
        tab = new T[msize];
        for(int i = 0; i < msize; i++) {
            tab[i] = userTab[i];
        }
    }

    /**
     * Default destructor.
     * Destructor is a special function that is always called just before the class is deleted from memory.
     */
    ~Poly() {
    }

    /**
     * Copy constructor.
     * Takes the references of the other object of Poly class and creates a new one which is identical to him.
     * @param Poly &other - references to the other Poly object.
     *@return Poly class object
     * ### Exapmple of use in Main function
     * ~~~~~~~~~~~~~~~~~~~~~~~.cpp
     * Poly poly1();
     * poly1.loadPoly();
     * Poly poly2(poly1);
     * ~~~~~~~~~~~~~~~~~~~~~~~
     */
    Poly(const Poly &other) {
            msize = other.msize;
            tab = new T[msize];
            for(int i = 0; i < msize; i++) {
                tab[i] = other.tab[i];
        }
    }

    /**
     * Method returns the degree of a polynomial
     * @return Size of the polynomial
     */
    int const degree() { return msize - 1; }

    /**
     * Method check if all of the polynomial coefficients are zero
     * @return True of False 
     */
    bool is_zero() {
        for(int i = 0; i < msize; i++) {
            if(tab[i] != 0) {
                return false;
            }
        }
            return true;
    }
    /**
     * Method loads the coefficients of a polynomial.
     * The User is asked for successive polynomial coefficients that are assigned to the array.
     * @see displayPoly()
     */
    void loadPoly() {
        T value;
        std::cout << "\033[1;32m[poly.out]\033[0m [Wpisz wspolczynniki wielomianu] :" << std::endl;
        for (int i = 0; i < msize; i++) {
            std::cout << "\t   [Wspolczynnik stopnia " << msize - 1 - i << " wielomianu] :";
            std::cin >> value;
            tab[i] = value;
        }
        if (msize != 1) assert(tab[0] != 0); // if user declare a degree of polynomial, the coefficient at the highest
        // power can't be 0
        std::cout << "\033[1;32m[poly.out]\033[0m [Pomyslnie ustawiono wspolczynniki wielomianu]" << std::endl;
    }
    /**
     * Method display the construction of the polynomial
     * @see loadPoly()
     */
    Poly displayPoly() {
        int value;
        cout << "\033[1;32m[poly.out]\033[0m [Wielomian ma postac] : ";
        for (int i = 0; i < msize; i++) {
            if (i == 0) value = 1;
            else if (i == msize - 1 && msize - 1 != 0) value = 0;
            else value = 2;
            switch (value) {
                case 0:
                    if (tab[msize - 1] > 0 && msize - 1 != 0) { cout << "+" << tab[msize - 1] << std::endl; }
                    else if (tab[msize - 1] < 0 && msize - 1 != 0) cout << tab[msize - 1] << std::endl;
                    else cout << std::endl;
                    break;

                case 1:
                    cout << tab[i] << "x^" << msize - 1;
                    break;

                default:
                    if (tab[i] > 0) { cout << "+" << tab[i] << "x^" << msize - 1 - i; }
                    else if (tab[i] < 0) { cout << tab[i] << "x^" << msize - 1 - i; }
                    break;
            }
        }
        cout << std::endl;
        return cout;
    }

    /**
    * Method calculates value of the polynomial at a given point
     * @param value - the point at which the method will count the value of the polynomial.
     * @return Object of Poly class, which could be assigned to other already existing Object
    */
    double horner(double value) {
        if (msize == 1) {
            std::cout << "\033[1;32m[poly.out]\033[0m [Wartosc wielomianu w punkcie wynosi] : " << tab[0] << std::endl;
            return tab[0];
        }
        double result = 0;
        for (int i = 0; i < msize; i++) {
            if(i<=msize-2)
            result = result + tab[i] * pow(value, msize-i-1);
            else
                result = result + tab[msize-1];
        }
        result = result;
        //std::cout << "\033[1;32m[poly.out]\033[0m [Wartosc wielomianu w punkcie " << value << " wynosi] : " << result<< std::endl;
        return result;
    }

    /**
    * Method calculates the sum of two polynomials
    * @param Poly &other - references to the other Poly object.
    * @return An Object of Poly class which is a new polynomial resulting from adding two other polynomials, could be assigned to other already existing Object.
    * @warning Both polynomials should be of the same type
    * @see subtraction(), multiplication()
    * ### Exapmple of use in Main function
    * ~~~~~~~~~~~~~~~~~~~~~~~.cpp
    * Poly poly3();
    * poly3 = poly1.addition(poly2);
    * ~~~~~~~~~~~~~~~~~~~~~~~
    */
    Poly operator+(Poly &otherPoly) {
        int sizeOfAdditionsPolys = (msize >= otherPoly.msize) ? msize : otherPoly.msize;
        Poly<T> addition(sizeOfAdditionsPolys - 1);
        if (msize >= otherPoly.msize) {
            for (int i = 0; i < msize; i++) {
                if (i <= otherPoly.msize) addition.tab[i] = tab[i] + otherPoly.tab[i];
                else addition.tab[i] = tab[i];
            }
        } else {
            for (int i = 0; i < addition.msize; i++) {
                if (i <= msize)addition.tab[i] = tab[i] + otherPoly.tab[i];
                else addition.tab[i] = otherPoly.tab[i];
            }
        }
        return addition;
    }

    /**
   * Method calculates the subtraction of two polynomials
   * @param Poly &other - references to the other Poly object.
   * @return An Object of Poly class which is a new polynomial resulting from subtraction two other polynomials, could be assigned to other already existing Object.
   * @warning Both polynomials should be of the same type
   * @see addition(), multiplication()
   * ### Exapmple of use in Main function
   * ~~~~~~~~~~~~~~~~~~~~~~~.cpp
   * Poly poly3();
   * poly3 = poly1.subtraction(poly2);
   * ~~~~~~~~~~~~~~~~~~~~~~~
   */
    Poly operator-(Poly &otherPoly) {
        int sizeOfSubtractionsPolys = (msize >= otherPoly.msize) ? msize : otherPoly.msize;
        Poly<T> subtraction(sizeOfSubtractionsPolys - 1);
        if (msize >= otherPoly.msize) {
            for (int i = 0; i < msize; i++) {
                if (i <= otherPoly.msize) subtraction.tab[i] = tab[i] - otherPoly.tab[i];
                else subtraction.tab[i] = tab[i];
            }
        } else {
            for (int i = 0; i < subtraction.msize; i++) {
                if (i <= msize)subtraction.tab[i] = tab[i] - otherPoly.tab[i];
                else subtraction.tab[i] = otherPoly.tab[i];
            }
        }
        return subtraction;
    }

    Poly subtraction(Poly &otherPoly) {
        int sizeOfSubtractionsPolys = (msize >= otherPoly.msize) ? msize : otherPoly.msize;
        Poly<T> subtraction(sizeOfSubtractionsPolys - 1);
        if (msize >= otherPoly.msize) {
            for (int i = 0; i < msize; i++) {
                if (i <= otherPoly.msize) subtraction.tab[i] = tab[i] - otherPoly.tab[i];
                else subtraction.tab[i] = tab[i];
            }
        } else {
            for (int i = 0; i < subtraction.msize; i++) {
                if (i <= msize)subtraction.tab[i] = tab[i] - otherPoly.tab[i];
                else subtraction.tab[i] = otherPoly.tab[i];
            }
        }
        return subtraction;
    }


    /**
    * Method calculates the multiplication of two polynomials
    * @param Poly &other - references to the other Poly object.
    * @return An Object of Poly class which is a new polynomial resulting from multiplication two other polynomials, could be assigned to other already existing Object.
    * @warning Both polynomials should be of the same type
    * @see addition(), subtraction()
    * ### Exapmple of use in Main function
    * ~~~~~~~~~~~~~~~~~~~~~~~.cpp
    * Poly poly3();
    * poly3 = poly1.multiplication(poly2);
    * ~~~~~~~~~~~~~~~~~~~~~~~
    */
    Poly operator*(Poly &otherPoly) {
        int sizeOfMultiplyPolys = ((msize + otherPoly.msize) - 2);
        Poly<T> multiply(sizeOfMultiplyPolys);

        for (int i = 0; i < multiply.msize; i++) {
            for (int j = 0; j < otherPoly.msize; j++) {
                multiply.tab[i + j] = multiply.tab[i + j] + (tab[i] * otherPoly.tab[j]);
            }
        }
        return multiply;
    }
    
    /**
     * Ovveride the != operator, which checks if the two polynomnials are different
     * @return True of False 
     */
    bool operator !=(Poly &otherPoly) {
            Poly<T> test(otherPoly.msize);
            test = this->subtraction(otherPoly);
            bool flag = test.is_zero();
            if(flag == true){  
                //std::cout<<"Te wielomiany sa takie same"<<std::endl;
                return false;   
        }
        else {
         //std::cout<<"Te wielomiany sa rozne"<<std::endl;
         return true;
        }
    }

    /**
     * Ovveride the == operator, which checks if the two polynomnials are the same, by checking if the
     * subtraction of two polynomials gives a zero polynomial
     * @return True of False 
     */
    bool operator ==(Poly &otherPoly) {
            Poly<T> test(otherPoly.msize);
            test = this->subtraction(otherPoly);
            bool flag = test.is_zero();
            if(flag == true){  
                //std::cout<<"Te wielomiany sa takie same"<<std::endl;
                return true;   
        }
        else {
         //std::cout<<"Te wielomiany sa rozne"<<std::endl;
         return false;
     }
    }

    /**
     * Ovveride the << operator, to display a Polynomial in easy way  
     */
    friend std::ostream& operator<< (std::ostream& cout,Poly<T> &polyToPrint) {
            int value;
        cout << "\033[1;32m[poly.out]\033[0m [Wielomian ma postac] : ";
        for (int i = 0; i < polyToPrint.msize; i++) {
            if (i == 0) value = 1;
            else if (i == polyToPrint.msize - 1 && polyToPrint.msize - 1 != 0) value = 0;
            else value = 2;
            switch (value) {
                case 0:
                    if (polyToPrint.tab[polyToPrint.msize - 1] > 0 && polyToPrint.msize - 1 != 0) { cout << "+" << polyToPrint.tab[polyToPrint.msize - 1] << std::endl; }
                    else if (polyToPrint.tab[polyToPrint.msize - 1] < 0 && polyToPrint.msize - 1 != 0) cout << polyToPrint.tab[polyToPrint.msize - 1] << std::endl;
                    else cout << std::endl;
                    break;

                case 1:
                    cout << polyToPrint.tab[i] << "x^" << polyToPrint.msize - 1;
                    break;

                default:
                    if (polyToPrint.tab[i] > 0) { cout << "+" << polyToPrint.tab[i] << "x^" << polyToPrint.msize - 1 - i; }
                    else if (polyToPrint.tab[i] < 0) { cout << polyToPrint.tab[i] << "x^" << polyToPrint.msize - 1 - i; }
                    break;
            }
        }
        //cout << std::endl;
        return cout;
    }

};
#endif //POLY_POLY_H
