// Polynomials.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

/* Matt Drajeske

*/



#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
//#include <string>

using namespace std;

void find_root(double&, double&, double&);
//bool isImaginary(double&);

int main()
{
	char complete = 'y';
	bool valid = true;
	double A, B, C;

	cout << "Welcome to my polynomial root program!" << endl;

	do {

		if (!valid) {
			cout << "\nPlease only enter a numerical value for coefficients" << endl;
		}

		valid = true;

		cout << "\nPlease enter the coefficients for a polynomial" << endl;

		cout << "\na:  ";
		cin >> A;

		cout << "\nb:  ";
		cin >> B;

		cout << "\nc:  ";
		cin >> C;

		if (cin.fail()) {
			valid = false;
			cin.clear();
			cin.ignore();

			system("CLS");
		}

	} while (!valid);

	find_root(A, B, C);

	cout << setprecision(4);
	cout << fixed;

	if (C < 0) {
		cout << "\nYour roots are " << setw(4) << A << " + " << setw(4) << B << "i" <<
			" and " << setw(4) << A << "-" << setw(4) << B << "i" << endl;
	}
	else {
		cout << "\nYour roots are " << setw(4) << A <<
			" and " << setw(4) << B << endl;
	}

	cout << "\nEnter any character to exit   ";
	cin >> complete;

	return 0;
}

void find_root(double& A, double& B, double& C) {

	double discriminant = pow(B, 2) - (4 * A * C);
	double b2a = -B / (2 * A);

	C = discriminant; //to evaluate whether roots are imaginary

	if (discriminant < 0) {

		A = b2a;
		B = sqrt(abs(discriminant));

	}
	else {

		A = b2a + sqrt(discriminant);
		B = b2a - sqrt(discriminant);
	}

}


