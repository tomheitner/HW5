#include "func.h"
#include <vector>

using namespace std;

/*
Function Name: func::plot

Brief:
Member function that would be called whnever printing to ostream outside of the class' context using operator<<.

Parameters:
ostream& ost

Output:
void
*/
void func::plot(ostream& os) const {
 
  vector<int> sortImage;
    
  sortImage.clear();
  for ( auto it : fmap_){
    //complete code here: insert the image of the function into sortImage 
  }
  //complete code here: sort sortImage
  //complete code here: flip sortImage (reverse)
  
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
    
    // check that the for statement is good syntax or whatever
    for (auto it_dom = fmap_.begin; it_dom.ptr != nullptr; it_dom.next()) {
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
Function Name: func::operator<<

Brief: 
Enter a new value x where the function would be computed at.
Returns itself so that the operator could be cascaded.

Parameters: 
const int& x

Output: 
func&
*/
func& func::operator<<(const int& x)
{
    // calculate f(x)
    int fx = 0;
    //check whether the new value is maximal or minimal (maybe both)
    maxVal_ = (fx > maxVal_) ? fx : maxVal_;
    minVal_ = (fx < minVal_) ? fx : minVal_;
    fmap_.insert(pair<int, int>(x, fx));  //insert the value into fmap
    return *this;
}




/*
Function Name: func::get_fmap

Brief:
Getter for the function's fmap

Parameters:
ostream& ost
const func& f

Output:
ostream&
*/
map<int, int> func::get_fmap() const {
    return fmap_;
}


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
    // plot is protected for some reason, consider making public
    // or maybe this is a pure virtual (=0) that would be implemented in all the derived classes.
    f.plot(ost); 
}

