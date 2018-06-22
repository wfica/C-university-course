#ifndef _STACK
#define _STACK 1

#include <iostream>
#include <initializer_list>
#include <stdexcept>
class stack
{
	size_t current_size;
	size_t current_capacity;
	double* tab;
	void ensure_capacity( size_t c );
public:
	stack( )
	:	current_size{0},
		current_capacity{0},
		tab{new double[0]}
	{}
	stack( std::initializer_list< double > d );
	stack( const stack& s );
	~stack( ){delete[] tab;	}
	void operator = ( const stack& s );
	void push( double d ); 
	void pop( ){ current_size--;}
	void reset( size_t s ){ current_size=s; }
	double& top( )	{ return tab[current_size-1]; }
	double top( ) const{ return tab[current_size-1];}
	size_t size( ) const { return current_size; }
	bool empty( ) const { return current_size == 0; }
	/*
	double operator [] (size_t i) const 
	{
		try {
			if( i < current_size )
				return tab[current_size-1-i]; 
        	else 
        		throw std::runtime_error ("a runtime error");
    	}
    	catch (std::runtime_error &e) {
			std::cout << "Caught a runtime_error exception:" << e.what () << '\n';
    	}
	}*/
	
	
	double operator [] (size_t i) const { return tab[current_size-1-i]; }
	double& operator [] (size_t i) { return tab[current_size-1-i]; }
	
	void operator += ( double d) { push(d); };
	void operator += ( const stack& s );
	// Be careful with self assignment!
	// The second operator pushes all elements of s.


friend std::ostream& operator << ( std::ostream& stream, const stack& s );

};	


//stack operator + ( const stack& s1, const stack& s2 );
stack operator + ( stack s1, const stack& s2 );
//stack operator + ( stack s1, stack s2 );
//stack operator + ( const stack& s1,  stack s2 );

#endif

