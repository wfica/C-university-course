
#include "tree.h"


int main( int argc, char* argv [ ] )
{
	/*
   tree t1( std::string( "a" ));
   tree t2( std::string( "b" )); 
   tree t3 = tree( std::string( "f" ), { t1, t2 } ); 

   std::vector< tree > arguments = { t1, t2, t3 };
   tree t4 = tree( "F", std::move( arguments ));
   std::cout << t4 << "\n";

   t2 = t3;
   
   std::cout<<t2<<"\n";
   
   t2.replacefunctor("X");
   std::cout<<t2<<"\n"<<t3<<"\n";
   t2 = std::move(t3);
   
   std:: cout<< t2<<"\n";
   
   arguments = {t1,t1};
   tree t6 = tree("Y", std::move(arguments) );
   
   tree t5 = subst(t4, "a", t6);
   std::cout<<"T5:\n"<<t5<<"\n";
   
   const std:: string& s = t5.functor();
   std::   cout<<s<<"\n";
   
   
   std::cout<<"T5`:\n"<<t5<<"\n";
   
   tree t10 = t5;
   tree t11 = subst(t5, "%", t5);
   
   std::cout<<t10.getaddress()<<"\n"<<t11.getaddress()<<"\n";
   
   std::cout<< t5[2]<<"\n";
   */
   //------lista 7
   tree t1( std::string( "a" ));
   tree t2( std::string( "b" )); 
   tree t3 = tree( std::string( "f" ), { t1, t2 } ); 

   std::vector< tree > arguments = { t1, t2, t3 };
   tree t4 = tree( "F", std::move( arguments ));
   std::cout << t4 << "\n";
   
   tree t5 = t4;
   t5 = subst(t5, "a", t1);
   std::cout<<t5<<"\n";
   std::cout<< (t5 == t4)<<"\n";
   
   
   
}



