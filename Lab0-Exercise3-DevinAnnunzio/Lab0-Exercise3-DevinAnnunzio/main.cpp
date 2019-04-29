/*
 Class: CS3305/Section 04
 Term: Spring 2019
 Name: Devin Annunzio
 Instructor: Monisha Verma
 Assignment: Lab 0 Exercise 3
 */

#include <iostream>

int main() {
    /*Write a C++ Program to generate the following output using a loop structure(s).(Do not hard code the output values!)
     
     8 6 4 2 0
     6 4 2 0
     4 2 0
     2 0
     0*/
    //std::endl = same as \n to send to new line
    
    /*i loop handles the even digits, and the j loop handles the decimal places*/
    
    int total = 86420;
    std::cout << total << std::endl;
    for (int i =4; i>0; --i) {
        int a = i*2;
        int b = 1;
        for (int j = 0; j<i; ++j) {
            b*=10;
        }
        total-=a*b;
        std::cout << total << std::endl;
    }

    //Main fnct is type int so needs to return a value
    //0 means exectured without errors, 1 means there is error
    return 0;
             
}
