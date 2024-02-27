#include<iostream>
#include<complex>
using namespace std;

int difference(int a, int b) {
	return (a - b);
}

complex<double> difference(complex<double> a, complex<double> b) {

	return (a - b);
}

int main() {
	complex<double> complexA(3.0, 2.0);
	complex<double> complexB(1.5, 1.0);
	cout << difference(5, 2) << "\n";
	cout << difference(complexA, complexB);
	return 0;
}