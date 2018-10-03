#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include "stdafx.h"
//#include <string>

using namespace std;

void find_root(double&, double&, double&);
//bool isImaginary(double&);

int main()
{
	char any;
	bool valid = true;
	//double root1, root2;
	double A, B, C;

	cout << "Welcome to my polynomial root program!" << endl;

	do {

		if (!valid) {
			std::cout << "\nPlease only enter a numerical value for coefficients" << endl;
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


	//using the changed values
	    if (C < 0) {
			cout << "\nYour roots are " << setw(4) << A << "" << setw(4) << B << "i" <<
				" and " << setw(4) << A << "+" << setw(4) << abs(B) << "i" << endl;

	    }
	    else {
			cout << "\nYour roots are " << setw(4) << A <<
				" and " << setw(4) << B << endl;
	
	    }
		cout << "\nEnter any value to continue   ";
		cin >> any;

	return 0;
}

void find_root(double& A, double& B, double& C) {
	//double root1, root2;

	//to evaluate whether roots are imaginary
	double disc = (pow(B, 2) - (4 * A*C));
	double b2a = -B / (2 * A);
	double denominator = 2 * A;

	//change the value of C
	C = disc;

	if (C < 0) {
		//changing the values of a and b
		A = b2a;
		B = sqrt(abs(disc)) / denominator; //this is using the new A value of b2a

	}

	else {
		//check with 4,8,3
		//changing the values of a and b
		A = b2a + (sqrt(disc) / denominator);
		B = b2a - (sqrt(disc) / denominator);
	}

}

// best website to test values http://w...content-available-to-author-only...e.com/quadratic/quadratic-formula-calculator.php