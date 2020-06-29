#ifndef _POLY_F
#define _POLY_F

#include "func.h"

using namespace std;


class polynom : public func {
 public:

  polynom(int order, int* cof); // c-tor
  polynom(const polynom& other); // copy c-tor
  ~polynom(); // d-tor
  void printcoefs(ostream&)  const ;
  polynom& operator<<(const int& x); // virtual

  // Basic math operations
  polynom operator+(const polynom& other);
  polynom operator-(const polynom&  other);
  polynom operator*(const polynom&  other);

  // Hedva operations
  polynom Derivative();
  polynom Integral();

  void toString(ostream& ost) const; // virtual

 protected:

  int n_; // order of the polynom
  int* coefs_; // coefficients 
};



#endif
 
