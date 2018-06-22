#include "surf.h"
#include <iostream>
#include <math.h>

const double PI = 3.1415;

double ABS( double x)
{
   if(x<0) return -x;
   return x;
}

 
rectangle::rectangle(double X1, double Y1, double X2, double Y2)
   :  x1{X1},   y1{X1},   x2{X2},   y2{Y2}
   {}
   
double rectangle::area() const
{
   return ABS((x1-x2)*(y1-y2));
}

double rectangle::circumference() const
{
   return 2.0*(ABS(x1-x2) + ABS(y1-y2));
}
/*
rectangle* rectangle::clone() const &
{
   return new rectangle (*this);
}

rectangle* rectangle::clone() const &&
{
   return new rectangle(std::move(*this));
}
*/
void rectangle::print( std::ostream& out) const 
{
      out<< "rect: ("<<x1<<", "<<y1<<")  ("<<x2<<", "<<y2<<")";
    //  return out;
}


triangle::triangle(double X1, double Y1, double X2, double Y2, double X3, double Y3)
   : x1{X1},   y1{Y1},   x2{X2},   y2{Y2},   x3{X3},   y3{Y3}
   {}
   
double triangle::area() const
{
   return ABS((x1-x3)*(y2-y3) - (x2-x3)*(y1-y3));
}

double triangle::circumference() const
{
   return  sqrt( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) ) +
           sqrt( (x3-x2)*(x3-x2) + (y3-y2)*(y3-y2) ) +
           sqrt( (x1-x3)*(x1-x3) + (y1-y3)*(y1-y3) ) ;
}
/*
triangle* triangle::clone() const &
{
   return new triangle (*this);
}

triangle* triangle::clone() const &&
{
   return new triangle(std::move(*this));
}
*/
void triangle::print( std::ostream& out) const 
{
      out<< "tria: ("<<x1<<", "<<y1<<")  ("<<x2<<", "<<y2<<")  ("<<x3<<", "<<y3<<")";
  //    return out;
}

//----

circle::circle(double X, double Y, double Radius)
   : x{X},   y{Y},  radius{Radius}
   {}
   
double circle::area()  const
{
   return radius*radius*PI;
}

double circle::circumference()  const
{
   return 2*PI*radius;
}
/*
circle* circle::clone() const & 
{
   return new circle (*this);
}

circle* circle::clone() const &&  
{
   return new circle(std::move(*this));
}
*/

void circle::print( std::ostream& out) const 
{
      out<< "circ: ("<<x<<", "<<y<<") "<< radius;
}

std::ostream& operator << ( std::ostream& stream, const surface& s )
{
   s.getsurf().print(stream);
   return stream;
}
























