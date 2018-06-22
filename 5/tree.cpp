
#include "tree.h"


std::ostream& operator << ( std::ostream& stream, const tree& t )
{
	stream << t.functor()<<"["<<t.getaddress()%1000<<"]";
	if(t.nrsubtrees()) stream<<"<";
	for(size_t i=0; i<t.nrsubtrees(); ++i)
		stream << t[i]; 
	if(t.nrsubtrees()) stream<<">";
	return stream;
}

void tree::ensure_not_shared( )
{
	if(pntr->refcnt != 1) 
	{
		pntr->refcnt--;
		pntr = new trnode( functor(), pntr->subtrees, 1);
	}
}

void tree::replacesubtree(size_t i, const tree& t)
{
	if( pntr->subtrees[i].pntr != t.pntr)
	{
		ensure_not_shared();
		pntr -> subtrees[i]=t;
	}
}
void tree::replacefunctor(const std::string& _f)
{
	if( _f != pntr->f)
	{
		ensure_not_shared();
		(pntr->f) = _f;
	}
}

tree subst(const tree& t, const std::string& var, const tree& val)
{
	if(t.nrsubtrees()==0)
	{
		if(t.functor() == var ) return val;
		return t; 
	}
	else 
	{
		tree my = t;
		for(size_t i =0; i< t.nrsubtrees(); ++i)
			my. replacesubtree(i, subst(t[i], var, val));
		return my;
	}
}

// ----------------------------lista 7

bool operator == (tree t1, tree t2)
{
	std:: vector <std::pair<tree, tree> > S;
	S.push_back(std::make_pair(t1,t2));
	while(!S.empty())
	{
		tree T1 = S.back().first;
		tree T2 = S.back().second;
		S.pop_back();
		if( T1.nrsubtrees() != T2. nrsubtrees() or T1.functor() != T2. functor() ) return false;
		for(size_t i=0; i< T1.nrsubtrees(); ++i)
			S.push_back( std::make_pair( T1[i], T2[i] ) );
	}
	return true;
}






























