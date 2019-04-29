/*
 Class: CS3305/Section 04
 Term: Spring 2019
 Name: Devin Annunzio
 Instructor: Monisha Verma
 Assignment: Lab 0 Exercise 1
 */

#include <iostream>

int main() {
    int i=1;
    int k =2;
    int *p1;
    int *p2;
    p1= &i;
    p2= &k;
    *p1=*p2;
    *p1=3;
    *p2=4;
    std::cout <<i;
    return 0;
    
}
