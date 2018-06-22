
#include "rational.h"

// Complete these methods:

#if 0 

int rational::gcd( int n1, int n2 );

void rational::normalize( );

rational operator - ( rational r );

rational operator + ( const rational& r1, const rational& r2 );

rational operator - ( const rational& r1, const rational& r2 );

rational operator * ( const rational& r1, const rational& r2 );

rational operator / ( const rational& r1, const rational& r2 );

bool operator == ( const rational& r1, const rational& r2 );
bool operator != ( const rational& r1, const rational& r2 );

std::ostream& operator << ( std::ostream& stream, const rational& r ) ;

#endif

int Abs(int x)
{
	return x>0 ? x : -x; 
}

int rational::gcd( int n1, int n2 )
{	
	while(n2!=0)
	{	
		int c = n1%n2;
		n1=n2;
		n2=c;
	}
	return n1;
}

void rational::normalize( )
{
	int sgn = 1;
	if(num <0) sgn*=-1;
	if(denum <0) sgn *=-1;
	num = Abs(num);
	denum = Abs(denum);
	int GCD = gcd(num, denum);
	num/=GCD;
	denum/=GCD;
	num*=sgn;	
}

rational operator - ( rational r )
{
	return rational(-r.num, r.denum);
}

rational operator + ( const rational& r1, const rational& r2 )
{
	return rational(r1.num*r2.denum + r1.denum * r2.num, r1.denum*r2.denum);
}

rational operator - ( const rational& r1, const rational& r2 )
{
	return r1+(-r2);
}

rational operator * ( const rational& r1, const rational& r2 )
{
	return rational(r1.num*r2.num, r1.denum*r2.denum);
}

rational operator / ( const rational& r1, const rational& r2 )
{
	return rational(r1.num*r2.denum, r1.denum*r2.num);
}

bool operator == ( const rational& r1, const rational& r2 )
{
	return (r1.num == r2.num and r1.denum == r2.denum);
}

bool operator != ( const rational& r1, const rational& r2 )
{
	return !(r1==r2);
}

std::ostream& operator << ( std::ostream& stream, const rational& r )
{
	stream << r.num<<"/"<<r.denum;
	return stream;
}
