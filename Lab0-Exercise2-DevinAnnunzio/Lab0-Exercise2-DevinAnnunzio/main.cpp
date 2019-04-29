/*
 Class: CS3305/Section 04
 Term: Spring 2019
 Name: Devin Annunzio
 Instructor: Monisha Verma
 Assignment: Lab 0 Exercise 2
 */

#include <iostream>

int main() {
    /* write a c++ program to accept a positive integer, N, as an input and display the sum of the first N integers*/
    
    //std::endl = same as \n to send to new line
    
    int i;
    int j;
    /*prints to screen asking user for a number*/
    std::cout << "Enter a number please: ";
    /*takes in the number and stores into i*/
    std::cin >> i;
    /*prints to screen asking user for a number*/
    std::cout << "Enter another number please: ";
    /*takes in the number and stores into j*/
    std::cin >> j;
    /*prints out the total of int i + int j*/
    std::cout << "The total value of the two numbers is: " << i+j <<".\n";
    

    //Main fnct is type int so needs to return a value
    //0 means exectured without errors, 1 means there is error
    return 0;
    
}
