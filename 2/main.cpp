
#include "rational.h"
#include "matrix.h"

using namespace std;

int main( int argc, char* argv [ ] )
{

   rational r1( 2, 6 );
   rational r2( 4, 3 ); 
   rational r3( 5,6 );
   rational r4( 1, 2 );
   cout<<-r4<<"\n";
   /*

   matrix m1 = { { 2, 3 }, { 4, 6 } };
   std::cout << m1 << "\n";

   matrix m2 = { { 5,4 }, { 6, rational(1,2) } }; 
   std::cout << m2 << "\n";

   matrix m3 = { { 4,5}, { -1, 2 }};

   std::cout << m1. determinant( ) << "\n";

   std::cout << m1. adjugate( ) << "\n";
   std::cout << m1. inverse( ) * m1 << "\n";
*/

	matrix m1 = {{rational(1,2), rational(-2,7)}, {rational(1,3), rational(2,8)} };
	matrix m2 = {{rational(-1,3), rational(2,5)}, {rational(2,7), rational(-1,7)} };
	matrix m3 = {{rational(0,3), rational(-23,5)}, {rational(3,7), rational(-9,7)} };
	
	cout<< m1 * m2<<"\n";
	
	cout<< m1.inverse()<<"\n";
	
	cout<< m1*m2*m3 - m1*m2*m3<<"\n";
	
	cout<< (m1+m2)*m3 - (m1*m3 + m2*m3)<<"\n";
	
	cout<< m3*(m1+m2) - (m3*m1 + m3*m2)<<"\n";
	
	cout<< m1(m2(vector(r1,r2))) <<"\n"<< (m1*m2)(vector(r1,r2))<<"\n";
	
	cout<< (m1*m2).determinant() <<"\n"<<m1.determinant()*m2.determinant()<<"\n";
	
	cout<< m1 * m1.inverse() <<"\n"<< m1.inverse() * m1<<"\n";
	
}

