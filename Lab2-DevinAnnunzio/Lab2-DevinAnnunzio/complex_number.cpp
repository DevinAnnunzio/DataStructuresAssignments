/*
 Class: CS3305/Section 04
 Term: Spring 2019
 Name: Devin Annunzio
 Instructor: Monisha Verma
 Assignment: Lab 2
 */

#include "complex_number.h"
#include <cmath>

complex_number::complex_number(double r, double i)
{
    real_part = r;
    imag_part = i;
}

double complex_number::get_real_part () const{

    return real_part;
}

double complex_number::get_imag_part() const{
    return imag_part;
    
}

complex_number operator + (const complex_number& c1, const complex_number& c2){
    
// returned: sum of c1 and c2
    double a = (c1.get_real_part()+c2.get_real_part());
    double b = (c1.get_imag_part()+c2.get_imag_part());
    
    return complex_number(a,b);
}
complex_number operator - (const complex_number& c1, const complex_number& c2){
    
// returned: difference of c1 and c2
    return complex_number((c1.get_real_part()-c2.get_real_part()), (c1.get_imag_part()-c2.get_imag_part()));
}



complex_number operator * (const complex_number& c1, const complex_number& c2){
// returned: product of c1 and c2
    double a = c1.get_real_part();
    double b = c1.get_imag_part();
    double c = c2.get_real_part();
    double d = c2.get_imag_part();
    double e = a*c;
    double f = a*d;
    double g = b*c;
    double h = b*d*-1;
    
    double real = (e+h);
    double imaginary= f+g;
    
    return complex_number(real,imaginary);
}
 


complex_number operator / (const complex_number& c1, const complex_number& c2){
// precondition: c2 is not the zero of complex numbers
// returned: quotient of c1 and c2

    complex_number numerator= c1*conjugate(c2);
    complex_number denominator= c2*conjugate(c2);
    double real= numerator.get_real_part()/denominator.get_real_part();
    double imaginary = numerator.get_imag_part()/denominator.get_real_part();
    
    
    return complex_number(real,imaginary);
}

complex_number conjugate (const complex_number& c){
// returned: conjugate of c
    return complex_number(c.get_real_part(),c.get_imag_part()*(-1));
}
double complex_modulus (const complex_number& c){
 // returned: modulus of c
 
    return sqrt(pow(c.get_real_part(), 2)+pow(c.get_imag_part(),2));
             }



bool operator == (const complex_number& c1, const complex_number& c2){
// returned whether c1 and c2 are equal to each other
    
    return (c1.get_real_part()==c2.get_real_part() && c1.get_imag_part() == c2.get_imag_part());
    }


bool operator != (const complex_number& c1, const complex_number& c2){
// returned whether c1 and c2 are not equal to each other
    return !(c1==c2);
    
}



std::ostream& operator << (std::ostream& output, const complex_number& c){
// postcondition: c has been put on the output stream output
// returned: modified output stream output
    
    output << c.get_real_part() << " " << c.get_imag_part();
    
    
    return output;
}
