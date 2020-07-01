#pragma once
#ifndef _COMPFUNC_F
#define _COMPFUNC_F

#include "func.h"

using namespace std;


class compfunc : public func {
public:

    compfunc(func& f, func& g); // c-tor
    ~compfunc(); // d-tor

    // Virtuals
    compfunc& operator<<(const int& x);
    void toString(ostream& ost) const;
    int calcValue(const int& x) const;

protected:

    func* in;
    func* out;
};



#endif

