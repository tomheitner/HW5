#include "func.h"
#include <vector>
#include <algorithm>

using namespace std;

/*
Function Name: func::plot

Brief:
Plots the function's graph.

Parameters:
ostream& ost

Output:
void
*/
void func::plot(ostream& os) const {
 
  vector<int> sortImage;
    
  sortImage.clear();
  for ( auto it : fmap_){
      sortImage.push_back(it.second);//complete code here: insert the image of the function into sortImage 
  }
  sort(sortImage.begin(), sortImage.end());//complete code here: sort sortImage
  reverse(sortImage.begin(), sortImage.end());//complete code here: flip sortImage (reverse)
  
  for ( auto it_im = sortImage.begin();
       it_im != sortImage.end(); ++it_im) {
    if(it_im!=sortImage.begin() && *it_im==*(it_im-1)){ //remove repeated
      it_im = sortImage.erase(it_im)-1;
      
    }
  }
 
  for (auto it_im = sortImage.begin();
       it_im != sortImage.end(); ++it_im) {
    int x_anchor=minVal_;
    if(*it_im<-9) 
      os <<*it_im;
    else
      if((*it_im<0) || (*it_im>9)) 
	os<<" "<<*it_im;
      else 
	os<<"  "<<*it_im;
    
    for (auto it_dom : fmap_) {
      if(it_dom.second == *it_im){
	    int x=it_dom.first;
	    int spaces= x-x_anchor;
	    int i=0;
	    while(i<spaces){
	      os<<"   ";
	      i++;
	    }
	    os<<"*  ";
	    x_anchor=x+1;
      }

    }

    os<<endl;
    if((it_im+1)!=sortImage.end()){ //print empty lines
      int lines=*it_im-*(it_im+1)-1;
      int i=1;
      
      while(i<lines+1){
	if(*it_im-i<-9) 
	  os <<*it_im-i;
	else 
	  if( (*it_im-i<0) || (*it_im-i>9) )
	    os<<" "<<*it_im-i;
	  else 
	    os<<"  "<<*it_im-i;
	cout<<endl;
	i++;

      }
    }

  }//for sortImage

  //print x axis
  cout<< " ";
  for (auto i=minVal_; i<maxVal_+1;i++){
    if(i<0) os<<" "<<i;
    else os<<"  "<<i;
  }
  os<<endl;
}
/*
Function Name : func::func

Brief :
ctor without parameters for abstract class func to prevent undefined behavior

Parameters :
-
Output :
    -
 */
func::func() : maxVal_(0),minVal_(0){}

/*
Function Name: func::~func

Brief:
dtor without parameters for abstract class func to prevent undefined behavior

Parameters:
-
Output:
-
*/
func::~func() {}

/*
Function Name: operator<< (for printing)

Brief:
Prints the function's values at the points previously added to fmap.
Returns itself so that the operator could be cascaded.

Parameters:
ostream& ost
const func& f

Output:
ostream&
*/
ostream& operator<<(ostream& ost, const func& f) {
    f.toString(ost);
    if (!(f.fmap_.empty())) {
        f.plot(ost);
    }
    return ost;
}

