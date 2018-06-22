
#ifndef TREE_INCLUDED
#define TREE_INCLUDED  1


#include <iostream>
#include <vector>
#include <string>


class tree;

// struct trnode should be invisible to the user of tree. This can be 
// obtained by making it a private number of tree. 
// In this exercise, we leave it like this, because it is simpler.
// In real code, trnode should be defined inside tree.


struct trnode 
{
   std::string f;
   std::vector< tree > subtrees;
   
   size_t refcnt;
      // The reference counter: Counts how often this trnode is referred to.

   trnode( const std::string& f, const std::vector< tree > & subtrees, 
           size_t refcnt )
      : f{f},
        subtrees{ subtrees },
        refcnt{ refcnt }
   { }

   trnode( const std::string& f, std::vector< tree > && subtrees,
           size_t refcnt )
      : f{f},
        subtrees{ std::move( subtrees )}, 
        refcnt{ refcnt }
   { }

};


class tree
{
	trnode* pntr;

public: 
	tree( const std::string& f ) 
	  : pntr( new trnode( f, { }, 1 ))
	{ }

	tree( const std::string& f, const std::vector< tree > & subtrees )   
	  : pntr( new trnode( f, subtrees, 1 ))
	{ } 

	tree( const std::string& f, std::vector< tree > && subtrees )
	  : pntr( new trnode( f, std::move( subtrees ), 1 ))
	{ }


	tree( const tree& t )
	  :	pntr(t.pntr)
	{
		(pntr->refcnt)++;
	}	
	  // There is no need to write tree( tree&& t ),
      // because we cannot improve. 

   	void operator = ( tree&& t )
	{
		std::swap(pntr, t.pntr);
   	}
   	void operator = ( const tree& t )
   	{
   		*this = tree(t);
   	} 
	
	const std::string& functor( ) const
	{
	
		//std::cout<<"const func\n";
		return pntr->f;
	}
	//std::string& functor( );

	const tree& operator [ ] ( size_t i ) const
	{
		return pntr-> subtrees[i];
	}
	
	//tree& operator [ ] ( size_t i );
	
	size_t nrsubtrees( ) const
	{
		return pntr->subtrees.size();
	}

	~tree( )
	{
		(pntr->refcnt)--;	
		if((pntr->refcnt)==0) delete pntr;
	}
	
	size_t getaddress() const
	{
		return reinterpret_cast< size_t> (pntr);
	}
	
	void replacesubtree(size_t i, const tree& t);
	void replacefunctor(const std::string& _f);

	private: 
	// public: 
	// Delete public, when the thing is tested:

	void ensure_not_shared( ); 

};

std::ostream& operator << ( std::ostream& stream, const tree& t );
	// Doesn't need to be friend, because it uses only functor( ),
	// nrsubtrees( ) and [ ].

tree subst(const tree& t, const std::string& var, const tree& val);

bool operator == (tree t1, tree t2);

#endif

