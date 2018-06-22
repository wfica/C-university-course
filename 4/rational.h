
#ifndef RATIONAL_INCLUDED
#define RATIONAL_INCLUDED 1

#include <iostream>

class rational
{
   int num;
   int denum;
   
   
   static int gcd( int n1, int n2 );
      // Use Euclidean Algorithm. 
      // static means that the function can be called without
      // class object. The function has no access to the fields
      // num and denum. 

   void normalize( );
      // Divide common factors out of num and denum.
      // Normalizing a rational number is quite a subtle process.
      // What to do with i / 0?
      // What about 0 / 0?
      // What about -4 / -3?
   
public:
   rational( ) 
      : num{0},
        denum{1}
   { }

   rational( int i )
      : num{i}, 
        denum{1}
   { }

   rational( int _num, int _denum )
      : num{ _num }, denum{ _denum }
   {
      normalize( ); 
   }
   /// inline?
   inline int get_num() const {return num;}
   inline int get_denum() const {return denum;}

};

rational operator - ( rational r );

rational operator + ( const rational& r1, const rational& r2 );  
rational operator - ( const rational& r1, const rational& r2 ); 
rational operator * ( const rational& r1, const rational& r2 );
rational operator / ( const rational& r1, const rational& r2 );

bool operator == ( const rational& r1, const rational& r2 );
bool operator != ( const rational& r1, const rational& r2 );

std::ostream& operator << ( std::ostream& stream, const rational& r ); 

#endif

