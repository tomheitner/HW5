#include "compfunc.h"

/*
Function Name: compfunc::compfunc

Brief:
c-tor for the class

Parameters:
func &in
func &out

Output:
-
*/
compfunc::compfunc(func &f, func &g) : in(&g), out(&f)
{
}

/*
Function Name: compfunc::~compfunc

Brief:
d-tor for the class

Parameters:
-

Output:
-
*/
compfunc::~compfunc() {}



/*
Function Name: compfunc::operator<<

Brief:
c-tor for the class

Parameters:
const int& x

Output:
-
*/
compfunc& compfunc::operator<<(const int& x)
{
	int fx = this->calcValue(x);
	fmap_.insert(pair<int, int>(x, fx));
	return *this;
}

/*
Function Name: compfunc::toString

Brief:
prints the function according to the instructions

Parameters:
ostream& ost

Output:
-
*/
void compfunc::toString(ostream& ost) const
{
	cout << endl;
}

/*
Function Name: compfunc::calcValue

Brief:
calculates the value of the function at x [ f(x) ]

Parameters:
const int& x

Output:
int
*/
int compfunc::calcValue(const int& x) const
{
	int in_val = in->calcValue(x);
	return out->calcValue(in_val);
}
