//
// Created by dawiddobrowolski on 13.01.2022.
//
//! Poly Tests.
/*!
 * The section include all test for from Poly
 * @author Dawid Dobrowolski
 * @version 1.0
 */
#include <cassert>
#include "poly.h"

void testDegree() {
    Poly<int> polyTest(10);
    int degree = polyTest.degree();
    assert(degree == 10);
    std::cout<<"\033[1;32m[OK]\033[0mTest metody:'degree()'"<<std::endl;
}

void test_is_zero() {
    int coefPoly2[] = {0,0,0,0};
    Poly<int> polyTest(3,coefPoly2);
    bool flag = polyTest.is_zero();
    assert(flag == true);
    std::cout<<"\033[1;32m[OK]\033[0mTest metody is_zero()"<<std::endl;
}

void testHorner() {
    int coefPoly[] = {1,2,3,4,5};
    double hornerRandValue[] =  {0,5, 1.5, 10};
    double hornerResult[] = {5,975,29.5625,12345};
    Poly<int> polyTest(4,coefPoly);
    for(int i = 0; i< 4; i++) {
        double result = polyTest.horner(hornerRandValue[i]);
        assert(result == hornerResult[i]);
    }
    std::cout<<"\033[1;32m[OK]\033[0mTest metody:'horner()'"<<std::endl;
}

void testAdd() {
    int coefPoly[] = {2,3,4,5};
    int coefPoly2[] = {1,3,4,5};
    int resultPoly[] = {3,6,8,10};
    Poly<int> polyTest(3,coefPoly);
    Poly<int> polyTest2(3,coefPoly2);
    Poly<int> polyTest3;
    polyTest3 = polyTest + polyTest2;
    for(int i = 0; i < 4; i++) {
        assert(polyTest3.tab[i] == resultPoly[i]);
    }
    std::cout<<"\033[1;32m[OK]\033[0mTest metody:'addition()'"<<std::endl;
}

void testSubstract() {

    int coefPoly[] = {2,5,8,7};
    int coefPoly2[] = {1,3,4,5};
    int resultPoly[] = {1,2,4,2};
    Poly<int> polyTest(3,coefPoly);
    Poly<int> polyTest2(3,coefPoly2);
    Poly<int> polyTest3;
    polyTest3 = polyTest - polyTest2;
    for(int i = 0; i < 4; i++) {
        assert(polyTest3.tab[i] = resultPoly[i]);
    }
    std::cout<<"\033[1;32m[OK]\033[0mTest metody:'substraction()'"<<std::endl;
}

void testMultiply() {

    int coefPoly[] = {2,5,8,7};
    int coefPoly2[] = {1,3,4,5};
    int resultPoly[] = {2,15,32,35};
    Poly<int> polyTest(3,coefPoly);
    Poly<int> polyTest2(3,coefPoly2);
    Poly<int> polyTest3;
    polyTest3 = polyTest * polyTest2;
    for(int i = 0; i < 4; i++) {
        assert(polyTest3.tab[i] = resultPoly[i]);
    }
    std::cout<<"\033[1;32m[OK]\033[0mTest metody:'multiplication()'"<<std::endl;
}

void testCopyConstructor() {
    int coefPoly[] = {3,4,5,9,8,6,5};
    Poly<int> polyTest(6,coefPoly);
    Poly<int> polyTest2(polyTest);
    for(int i = 0; i < 7; i++) {
        assert(polyTest.tab[i] == polyTest2.tab[i]);
    }
    std::cout<<"\033[1;32m[OK]\033[0mTest konstruktora kopiujacego"<<std::endl;
}

void testOverrideSign1() {
    int coefPoly[] = {2,5,8,7};
    int coefPoly2[] = {2,5,8,7};
    Poly<int> polyTest(3,coefPoly);
    Poly<int> polyTest2(3,coefPoly2);
    bool flag = (polyTest != polyTest2);
    assert(flag == false);
    std::cout<<"\033[1;32m[OK]\033[0mTest nadpisanego operatora !="<<std::endl;
}

void testOverrideSign2() {
    int coefPoly[] = {2,5,8,7};
    int coefPoly2[] = {2,5,8,7};
    Poly<int> polyTest(3,coefPoly);
    Poly<int> polyTest2(3,coefPoly2);
    bool flag = (polyTest == polyTest2);
    assert(flag == true);
    std::cout<<"\033[1;32m[OK]\033[0mTest nadpisanego operatora =="<<std::endl;
}

void testOverrideSign3() {
    int coefPoly[] = {2,5,8,7};
    Poly<int> polyTest(3,coefPoly);
    cout<<polyTest;
    std::cout<<"\033[1;32m[OK]\033[0mTest nadpisanego operatora <<"<<std::endl;
}

