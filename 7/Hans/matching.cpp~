
#include "matching.h"


std::list< matching > match( tree from, tree into )
{
   // std::cout << "matching " << from << " into " << into << "\n";

   matching m;

   std::vector< tree > vectfrom = { from };
   std::vector< tree > vectinto = { into };

   while( vectfrom. size( ))
   {	
   	tree T1 = vectfrom.back();
   	tree T2 = vectinto.back();
   	vectfrom.pop_back();
   	vectinto.pop_back();
   	if( T1.nrsubtrees() == 0 and matching::isvariable(T1.functor()) ) /// T1 - variable
   	{
   		std::map< std::string, tree >::iterator it = m.subst. find( T1. functor() );
   		if( it != m.subst.end() and  T2 == it -> second )
   			 continue; 	
   		else if( it == m.subst.end() ) 
   		{
   			m.assign(T1.functor() , T2);
   			continue;
   		}
   	}
   	else if ( T1.functor() == T2.functor()  and T1.nrsubtrees() == T2.nrsubtrees() )
   	{
   		for(size_t i=0; i< T1.nrsubtrees(); ++i)
   		{
   			vectfrom.push_back(T1[i]);
   			vectinto.push_back(T2[i]);
   		}
   		continue;
   	}
   	return { };
   }
   return { m };
   	
   
#if 0
      for( auto t : vectfrom )
         std::cout << t << "  ";
      std::cout << "\n";

      for( auto t : vectinto )
         std::cout << t << "  ";
      std::cout << "\n";
      
      std::cout << "\n";
#endif
   // Failure: return { };

}

tree matching::operator( ) ( const tree& t ) const
{
	if(t.nrsubtrees()==0)
	{
		std::map< std::string, tree >::const_iterator it  = subst. find( t. functor() );
		if( it == subst. end() ) return t;
		return it->second;
	}
	else 
	{
		tree my = t;
		for(size_t i =0; i< t.nrsubtrees(); ++i)
			my. replacesubtree(i, (*this)( t[i] ) );
		return my;
	}
}	

std::ostream& operator << ( std::ostream& out, const matching& m )
{
   out << "matching: ";
   for( const auto& p : m. subst )  
   {
      out << p. first << " := " << p. second << "\n";
   }
   return out;
}


