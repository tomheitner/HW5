#include "polynom.h"

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
