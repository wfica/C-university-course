
#include "varchain.h"
#include "polynomial.h"
#include "bigint.h"
#include "rational.h"


template< typename N >
polynomial< N > exptaylor( unsigned int n )
{
   varchain v;

   N fact = 1;

   polynomial< N > result;
   for( unsigned int i = 0; i < n; ++ i )
   {
      result[v] += fact;
      v = v * powvar( "x" );
      fact = fact / (i+1);
   }

   return result;
}


template<typename N, typename M>
polynomial< N > power( polynomial< N > pol, M n)
{
   polynomial < N > res=1;
   for( int i = 0; i < n; ++ i )
      res = res * pol;
   return res;
} 

int main( int argc, char* argv [] )
{
   std::cout << "hello\n";
   

   polynomial< rational > pol;

   int N = 50;

   pol[ { } ] = 1;
   pol[ { "x" } ] = rational( 1, N ); 

   std::cout<<pol<<"\n";
   
    
   polynomial< rational > res = 1;
 
   for( int i = 0; i < N; ++ i )
      res = res * pol;

   std::cout << "result = " << res << "\n";

   std::cout << "taylor expansion = " << exptaylor<rational>(20) << "\n";

   std::cout << "difference = " ;  
   std::cout << res - exptaylor<rational> ( 40 ) << "\n";
   
   std::cout<< "new tests\n";
   
   polynomial< int > pol2, res2=1;   
   pol2[ {} ] = 1;
   pol2[ {"x"} ] = 1;

   std::cout<<pol2<<" do piątej to\n"<<power(pol2, 5)<<"\n";

   polynomial< int > pol3, res3=1;   
   pol3[ {} ] = 1;
   pol3[ { powvar("x",2), powvar("y",1),powvar("z",3)  } ] = 1;
      
   std::cout<<pol3<<" do czwartej to\n"<<power(pol3, 4)<<"\n";
   
   polynomial< bigint > pol4, res4=1;   
   pol4[ {} ] = 3;
   pol4[ { powvar("x",1), powvar("y",1) } ] = -1;
      
   std::cout<<pol4<<" do szóstej to\n"<<power(pol4, 3)<<"\n";
   
 
 
   return 0;
}


