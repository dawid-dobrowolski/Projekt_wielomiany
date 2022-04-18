#include <iostream>
#include "poly.h"
#include "polyTest.h"

/**
     * Clean method
     * Method clears the console cache and the appropriate console windows containing display information
     */
void cleanScreen() {
    system("clear");
}

/**
     * Method asked the User to give the degree of the polynomial to create
     * @return degree - degree of polynomial
     */
int giveDegree() {
    int degree;
    std::cout << "\033[1;32m[poly.out]\033[0m [Podaj stopien wielomianu] : ";
    std::cin >> degree;
    return degree;
}
/**
     * Main function
     * Function responsible for the launch of the program and presentation of the results
     */
int main(void) {
    cleanScreen();
    testDegree();
    testAdd();
    testSubstract();
    testMultiply();
    testHorner();
    testCopyConstructor();
    test_is_zero();
    testOverrideSign1();
    testOverrideSign2();
    testOverrideSign3(); 
    int coefPoly[] = {2,5,8,7};
    int coefPoly2[] = {10,2,1,3,4,5};
    int resultPoly[] = {-10,-2,1,2,4,2};
    Poly<int> polyTest(3);
    Poly<int> polyTest2(5);
    polyTest.loadPoly();
    polyTest2.loadPoly();
    Poly<int> polyTest3;
    polyTest3 = polyTest * polyTest2;
    cout<<polyTest3;
    return 0;
}
