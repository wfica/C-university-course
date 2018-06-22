#include "fifteen.h"

fifteen::fifteen()
	: open_i{dimension-1},
	  open_j{dimension-1}	
{
	for( size_t i = 0 ; i< dimension; ++i)
		for( size_t j = 0; j < dimension; ++j)
			table[i][j] = i*j+1;
	table[open_i][open_j]=0;
} 

fifteen::fifteen( std::initializer_list< std::initializer_list< size_t > > init )
	: open_i{init.size()-1},
	  open_j{init.size()-1}	 
{
	size_t i = 0, j=0;
	for( auto it = init.begin(); it != init.end(); ++it, ++i)
		for(auto it2 = (*it).begin(); it2 != (*it).end(); ++it2, ++j)
			table[i][j] = *it2;
	table[open_i][open_j]=0;
}


std::pair< size_t, size_t > fifteen::solvedposition( size_t val )
{
	std::pair< size_t, size_t > p = std::make_pair((val-1)/dimension, (val-1) % dimension);
	if(val==0) p = std::make_pair(dimension-1, dimension-1);
	return p;
}

    // Estimated distance from solution. Use Manhattan distance,
      // see the wikipedia article. 

bool fifteen::issolved( ) const
      // True if the puzzle is in solved state.
{
	return distance() == 0;
}

size_t fifteen::hashvalue( ) const
      // Construct a hash value on the state.
{
	size_t constexpr mod = 16974321LL;
	size_t  mn = dimension*dimension + 10;
	size_t res =0;
	for(size_t i = 0; i< dimension; ++i)
		for(size_t j =0; j< dimension; ++j)
		{
			res += (table[i][j] * mn )% mod;
			mn = ( mn * mn) % mod;
		}
	return res;
}

bool fifteen::equals( const fifteen& other ) const
      // True if we are equal to other.
{
	for(size_t i =0; i < dimension; ++i)
		for(size_t j =0; j< dimension; ++j)
			if ( table[i][j] != other.table[i][j]) return false;
	return true;
}

void fifteen::makemove( move m )
      // This method tries to make a move m. If it fails then 
      // it throws illegalmove( move ); 
      // Note that in C++, you don't have to declare possible exceptions.
      // A move is illegal if it would move the open place out of the
      // board. 
{
	int x, y;
	switch(m)
	{
		case move::up:    x = -1; y = 0;  break;
		case move::down:  x = 1;  y = 0;  break;
		case move::left:   x = 0;  y = -1; break;
		case move::right: x = 0;  y = 1;  break;
	}
	
	x += open_i;
	y += open_j;
	
	if( x < 0 or y < 0 or x >= dimension or y >= dimension )  
		throw illegalmove(m);
		
	std::swap(table[x][y], table[open_i][open_j]);
	
	open_i = x;
	open_j = y;
		
}


std::ostream& operator << ( std::ostream& stream, const fifteen& f )
{
	for(size_t i = 0; i < f.dimension; ++i)
	{
		for(size_t j = 0; j < f.dimension; ++j)
		{
			stream << f.table[i][j] << "\t";
		}

		stream << "\n";
	}

	return stream;
}

size_t fifteen::distance( ) const
{
	size_t dist = 0;

	for(size_t i = 0; i < dimension; ++i)
	{
		for(size_t j = 0; j < dimension; ++j)
		{
			auto p = solvedposition(table[i][j]);

			dist += distance(p,{i,j});
		}
	}

	return dist;
}













