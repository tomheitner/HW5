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

polynom::polynom(const polynom& other) : n_(other.n_) {
    coefs_ = new int[other.n_ + 1];
    for (int i = 0; i <= other.n_; i++) {
        coefs_[i] = other.coefs_[i];
    }
}

polynom::~polynom()
{
    delete[] coefs_;
}


polynom& polynom::operator<<(const int& x)
{
    int fx = 0;
    for (int i = 0; i < n_; i++)
    {
        fx += coefs_[i] * pow(x, i);
    }  
    fmap_.insert(pair<int, int>(x, fx));
    if(fmap_.size() == 1){
        maxVal_ = x;
        minVal_ = x;
	}else{
        if (x > maxVal_) maxVal_ = x;
        if (x < minVal_) minVal_ = x;
	}
    return *this;
}

polynom polynom::operator+(polynom other)
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
    int new_coef[maximum + 1];

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

    polynom res_p = polynom(maximum, new_coef);
    return res_p;
}

polynom polynom::operator-(polynom other)
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
    int new_coef[maximum + 1];

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

    polynom res_p = polynom(maximum, new_coef);
    return res_p;
}

polynom polynom::operator*(polynom other)
{
    int minimum, maximum;
    int* bigger_order_coef;

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
            cofs[i] = 0
    }

    int* cofs2 = new int[order + 1]; // other's coefficients
    for (int i = 0; i < order + 1; i++)
    {
        if (i <= other.n_)
            cofs2[i] = other.coefs_[i];
        else
            cofs2[i] = 0
    }

    for (int i = 0; i < order + 1; i++)
    {
        cofs[i] = 0;
        for (int j = 0; j < i + 1; j++)
        {
            cofs[i] += cofs1[j] * cofs2[i - j];
        }
    }

    polynom res_p = polynom(order, cofs);

    delete[] cofs;
    delete[] cofs1;
    delete[] cofs2;

    return res_p;
}

polynom polynom::Derivative()
{
    return polynom();
}

polynom polynom::Integral()
{
    return polynom();
}

void polynom::toString(ostream& ost)
{
    printcoefs
}
