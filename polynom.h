#ifndef _POLY_F
#define _POLY_F

#include "func.h"

using namespace std;


class polynom : public func {
 public:

  polynom(int order, int* cof); // c-tor
  polynom();// parameterless c-tor
  polynom(const polynom& other); // copy c-tor
  ~polynom(); // d-tor

  void printcoefs(ostream&)  const ;
  

  // Basic math operations
  polynom operator+(const polynom& other) const;
  polynom operator-(const polynom&  other) const;
  polynom operator*(const polynom&  other) const;

  // Hedva operations
  polynom Derivative() const;
  polynom Integral() const ;

  // Virtuals
  void toString(ostream& ost) const;
  func& operator<<(const int& x);
  int calcValue(const int& x) const;

 protected:

  int n_; // order of the polynom
  int* coefs_; // coefficients 
};



#endif
 
