#include "polynom.h"
#include <math.h>

void polynom::printcoefs(ostream& os)  const {
  int allZero = 1;
  for (auto i = n_ ; i>=0; i--) {
    if (coefs_[i]>0) {
      allZero = 0;
      if(i!=n_){
	os << "+";
      }
      if (coefs_[i]!=1 || i==0){
	os << coefs_[i];
      }
      if(i>0) {
	os << "x";
	if (i>1) 
	  os << "^" << i ;
      }
    }
    else if(coefs_[i]<0) {
      allZero = 0;
      if (coefs_[i]!=-1 || i==0){
	os << coefs_[i];
      }
      else 
	os << "-";
      if(i>0) {
	os << "x";
	if (i>1) 
	  os << "^" << i ;
      }
    }
    else if(i==0 && allZero == 1){ //coefs_[i]==0
        os << "0";
	continue;
    }
  }
}

/*
Function Name: polynom::polynom

Brief:
The class' c-tor. Recieves the order of the polynom and a pointer to an array of ints that are the polynoms coefficients

Parameters:
int order
int* cof

Output:
-
*/
polynom::polynom(int order, int* cof) : n_(order) {
    coefs_ = new int[order + 1];
    for (int i = 0; i <= order; i++) {
        coefs_[i] = cof[i];
    }
}
/*
Function Name: polynom::polynom

Brief:
The class' c-tor with no parameters.

Parameters:

Output:
-
*/
polynom::polynom() : n_(0){
    coefs_ = nullptr;
}

/*
Function Name: polynom::polynom

Brief:
The class' copy-tor. Recieves other polynom and clone it to another polyhon

Parameters:
polynom& other

Output: 
-
*/
polynom::polynom(const polynom& other) : n_(other.n_) {
    coefs_ = new int[other.n_ + 1];
    for (int i = 0; i <= other.n_; i++) {
        coefs_[i] = other.coefs_[i];
    }
}
/*
Function Name: polynom::~polynom

Brief:
The class' dtor

Parameters:
-
Output:
-
*/
polynom::~polynom()
{
    delete[] coefs_;
}

/*
Function Name: polynom::operator<<

Brief:
operator for inserting new value x to polynom 

Parameters:
const int& x

Output:
function by reference
*/
func& polynom::operator<<(const int& x)
{
    int fx = 0;
    for (int i = 0; i <= n_; i++)
    {
        fx += (int)coefs_[i] * pow(x, i);
    }  
    fmap_.insert(pair<int, int>(x, fx));
    if(fmap_.size() == 1)
    {
        maxVal_ = x;
        minVal_ = x;
	}
    else
    {
        if (x > maxVal_) maxVal_ = x;
        if (x < minVal_) minVal_ = x;
	}
    return *this;
}
/*
Function Name: polynom::operator+

Brief:
operator adding two polynoms together

Parameters:
const polynom& other

Output:
polynom
*/
polynom polynom::operator+(const polynom& other) const
{
    int minimum, maximum;
    int* bigger_order_coef;

    if (n_ < other.n_) {
        minimum = n_;
        maximum = other.n_;
        bigger_order_coef = other.coefs_;
    }
    else {
        minimum = other.n_;
        maximum = n_;
        bigger_order_coef = coefs_;
    }
    int* new_coef = new int[maximum + 1];

    for(int i=0; i<maximum+1 ;i++)
    {
        if (i < minimum + 1) 
        {
            new_coef[i] = this->coefs_[i] + other.coefs_[i];
        }
        else
        {
            new_coef[i] = bigger_order_coef[i];
		}
	}

    polynom res_p (maximum, new_coef);
    delete[] new_coef;
    return res_p;
}
/*
Function Name: polynom::operator-

Brief:
operator for subtracting polynom from another one

Parameters:
const polynom& other

Output:
polynom
*/
polynom polynom::operator-(const polynom& other) const
{
    int minimum, maximum;
    int* bigger_order_coef;
    bool other_order_bigger;

    if (n_ < other.n_) {
        minimum = n_;
        maximum = other.n_;
        bigger_order_coef = other.coefs_;
        other_order_bigger = true;
    }
    else {
        minimum = other.n_;
        maximum = n_;
        bigger_order_coef = coefs_;
        other_order_bigger = false;
    }
    int* new_coef = new int[maximum + 1];

    for(int i=0; i<maximum+1 ;i++)
    {
        if (i < minimum + 1) 
        {
            new_coef[i] = this->coefs_[i] - other.coefs_[i];
        }
        else
        {
            if(other_order_bigger) 
                new_coef[i] = -bigger_order_coef[i];
            else                    
                new_coef[i] = +bigger_order_coef[i];
		}
	}

    polynom res_p(maximum, new_coef);
    delete[] new_coef;
    return res_p;
}
/*
Function Name: polynom::operator*

Brief:
operator for multiplying  two polynoms 

Parameters:
const polynom& other

Output:
polynom
*/
polynom polynom::operator*(const polynom& other) const
{
    int minimum, maximum;

    if (n_ < other.n_) {
        minimum = n_;
        maximum = other.n_;
    }
    else {
        minimum = other.n_;
        maximum = n_;
    }

    int order = minimum + maximum;
    int* cofs = new int[order + 1];

    int* cofs1 = new int[order + 1]; //this' coefficients
    for (int i = 0; i < order + 1 ; i++)
    {
        if (i <= this->n_)
            cofs1[i] = coefs_[i];
        else
            cofs1[i] = 0;
    }

    int* cofs2 = new int[order + 1]; // other's coefficients
    for (int i = 0; i < order + 1; i++)
    {
        if (i <= other.n_)
            cofs2[i] = other.coefs_[i];
        else
            cofs2[i] = 0;
    }

    for (int i = 0; i < order + 1; i++)
    {
        cofs[i] = 0;
        for (int j = 0; j < i + 1; j++)
        {
            cofs[i] += cofs1[j] * cofs2[i - j];
        }
    }

    polynom res_p(order, cofs);

    delete[] cofs;
    delete[] cofs1;
    delete[] cofs2;

    return res_p;
}
/*
Function Name: polynom::Derivative

Brief:
calculating the derivative of a polynom

Parameters:

Output:
polynom which is a derivative of the polynom
*/
polynom polynom::Derivative() const
{
    //checking if its a constant function
    if (n_ == 0) {
        int new_coef[1] = { 0 };
        int new_order = 0;
        polynom res_p(new_order, new_coef);
        return res_p;
    }
    int new_order = n_ - 1;
    int* new_coef = new int[new_order + 1];

    for (int i = 0; i <= new_order; i++)
    {
        new_coef[i] = (i + 1) * coefs_[i+1];
    }
    polynom res_p(new_order,new_coef);
    delete[] new_coef;
    return res_p;
}
/*
Function Name: polynom::integral

Brief:
calculating the integral of a polynom

Parameters:
-

Output:
polynom which is a integral of the polynom
*/
polynom polynom::Integral() const
{
    int new_order = n_ + 1;
    int* new_coef = new int[new_order + 1];
    new_coef [0] = 0;

    for (int i = 1; i <= new_order; i++)
    {
        new_coef[i] = coefs_[i -1]/(i) ;
    }
    polynom res_p(new_order, new_coef);
    delete[] new_coef;
    return res_p;
}
/*
Function Name: polynom::toString

Brief:
printing the polynom , his derivative and integral and the graph of points added to it.

Parameters:
ostream& ost

Output:
-
*/
void polynom::toString(ostream& ost) const
{   
    printcoefs(ost);
    cout << endl;
    cout << "Derivative: ";
    Derivative().printcoefs(ost);
    cout << endl;
    cout << "Integral: ";
    Integral().printcoefs(ost);
    cout << "+C";
    cout << endl;
    plot(ost);
}
/*
Function Name: polynom::calcValue

Brief:
calculating the value of the polynom with a given x coordinate

Parameters:
const int& x

Output:
int- the value of the polynom with given x.
*/
int polynom::calcValue(const int& x) const
{
    int res = 0;

    for (int i = 0; i <= n_ ; i++) {
        res += coefs_[i] * pow(x, i);
    }
    
    return res;
}