
#include "rational.h"


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
	return rational(-r.get_num(), r.get_denum());
}

rational operator + ( const rational& r1, const rational& r2 )
{
	return rational(r1.get_num()*r2.get_denum() + r1.get_denum() * r2.get_num(), r1.get_denum()*r2.get_denum());
}

rational operator - ( const rational& r1, const rational& r2 )
{
	return r1+(-r2);
}

rational operator * ( const rational& r1, const rational& r2 )
{
	return rational(r1.get_num()*r2.get_num(), r1.get_denum()*r2.get_denum());
}

rational operator / ( const rational& r1, const rational& r2 )
{
	return rational(r1.get_num()*r2.get_denum(), r1.get_denum()*r2.get_num());
}

bool operator == ( const rational& r1, const rational& r2 )
{
	return (r1.get_num() == r2.get_num() and r1.get_denum() == r2.get_denum());
}

bool operator != ( const rational& r1, const rational& r2 )
{
	return !(r1==r2);
}

std::ostream& operator << ( std::ostream& stream, const rational& r )
{
	stream << r.get_num()<<"/"<<r.get_denum();
	return stream;
}
