#include <iostream>

class Complex {
	private:
		double _real;
		double _imag;
	public:
		//constructors and destructors
		Complex();
		Complex(double real, double imag);
		Complex(const Complex &c1);
		~Complex();
		
		//functions
		double real() const;
		double imag() const;
		void print();
		
		Complex add(Complex c1);
		Complex sub(Complex c1);
		Complex mult(Complex c1);
		Complex div(Complex c1);

		double magnitude();
		double phase();
/*		
		//overload
		Complex operator+(Complex c1);
		Complex operator-(Complex c1);
		Complex operator*(Complex c1);
		Complex operator/(Complex c1);

		bool operator<<(Complex c1);
		bool operator>>(Complex c1);*/
};

