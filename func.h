#ifndef _LE
#define _LE
#include <map>
#include <iostream>



using std::map;
using std::ostream;


class func {
 


 protected:
   
  
  int maxVal_; //maximum of all inputs
  int minVal_; //minimum of all inputs
  map<int,int> fmap_; //holds inputs and corresponding outputs
  void plot(ostream& os) const ; //plot fmap_

 public:
  func();//ctor;
  virtual func& operator<<(const int& x) = 0; // entering new value operator
  virtual void toString(ostream& ost) const = 0; // method for printing the function's properties
  virtual int calcValue(const int& x) const = 0;  // calculate the function's value at x [ f(x) ]
  friend ostream& operator<<(ostream& ost, const func& f); // printing operator
  virtual ~func();
};



#endif
