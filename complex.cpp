#include <iostream>
#include <math.h>
#include "complexlib.hpp"
//CONSTRUCTURES
//default
Complex::Complex(){
	_real=0, _imag=0;
}
//paramerterized
Complex::Complex(double real, double imag) {
	_real = real;
	_imag = imag;
}
//copy function
Complex::Complex(const Complex &c1) {
	_real = c1._real;
	_imag = c1._imag;
}

//DESTRUCT
Complex::~Complex() {
//	std::cout << "BYE" <<std::endl;
}

//FUNCTIONS
double Complex::real() const {
	return _real;
}

double Complex::imag() const {
	return _imag;
}

void Complex::print() {
	if(imag() < 0) {
		std::cout << _real << "-" << _imag*-1 <<"j" << std::endl;
		return;
	}

	std::cout << _real << "+" << _imag << "j"<< std::endl;
}

double Complex::magnitude() {
	double result = sqrt((_real*_real) + (_imag*_imag));
	return result;
}

double Complex::phase() {
	double ph = atan(_imag/_real) * (180 / M_PI);
	return (ph<0) ? -ph:ph;
}

Complex Complex::add(Complex c1) {
	Complex temp(c1.real() + _real, c1.imag() + _imag);
	return temp;
}

Complex Complex::sub(Complex c1) {
	Complex temp(_real - c1.real(), _imag - c1.imag());
	return temp;
}

Complex Complex::mult(Complex c1) {
	Complex temp( (_real*c1.real())+(_imag*c1.imag()*-1), (_imag*c1.real())+(_real*c1.imag()));
	return temp;
}

Complex Complex::div(Complex c1) {
	double denom = c1.magnitude()*c1.magnitude();
	if(denom == 0) {
		Complex no(0, 0);
		std::cout << "Division by zero" << std::endl;
		//printf("Division by zero");
		return no;
	}
	Complex temp(_real, _imag*-1);
	Complex temp1(temp.mult(c1));
	temp1._real /= denom;
	temp1._imag /= denom;
	return temp1;
}

Complex Complex::operator+(Complex c1){
	return add(c1);
}

Complex Complex::operator-(Complex c1){
	return sub(c1);
}

Complex Complex::operator*(Complex c1){
	return mult(c1);
}

Complex Complex::operator/(Complex c1){
	return div(c1);
}

Complex Complex::operator=(Complex c1){
	_real = c1._real;
	_imag = c1._imag;
	return *this;
}

std::ostream& operator<<(std::ostream &out, const Complex &c1){
	if(c1.imag() < 0) {
		double temp = -1 * c1.imag();
		out << c1.real() << " - " << temp <<"i";
	}
	else {
		out << c1.real() << " + " << c1.imag() << "i";
	}
	return out;
}

std::istream& operator>>(std::istream &in, Complex &c1) {
	in >> c1._real >> c1._imag;
	return in;
}
