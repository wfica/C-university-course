
#include "figure.h"

figure::figure( std::initializer_list< const char* > f )
{
   for( auto p = f. begin( ); p != f. end( ); ++ p )
      repr. push_back( *p );
}

std::ostream& operator << ( std::ostream& out, const figure& f )
{
   for( auto p = f. repr. begin( ); p != f. repr. end( ); ++ p )
      out << *p << "\n";
   out << "\n";
   return out;
}


figure glider( ) 
{
   return 
      { ".0.",
        "0..",
        "000" };
}

figure square( ) 
{
  return 
    { "00",
      "00" };
}

figure glider_gun( )
{
   return
      { "........................0...........",
        "......................0.0...........",
        "............00......00............00",
        "...........0...0....00............00",
        "00........0.....0...00..............",
        "00........0...0.00....0.0...........",
        "..........0.....0.......0...........",
        "...........0...0....................",
        "............00......................"
      }; 
}

figure toad( )
{
   return 
      { ".0..",
        ".0.0",
        "0.0.",
        "..0." };
} 

figure glider_eater( )
{
    return
       { "00...",
         "0.0..",
         "..0..",
         "..00."
       };
}

figure glider_eater2( ) 
{
   return 
      { "00..",
        "0...",
        ".000",
        "...0" 
      };
}

figure blinker( )
{
   return 
      { "...",
        "000",
        "..." 
     };
}

figure pulsar( )
{
   return
      { "...............",
        "...000...000...",
        "...............",
        ".0....0.0....0.",
        ".0....0.0....0.",
        ".0....0.0....0.",
        "...000...000...",
        "...............",
        "...000...000...",
        ".0....0.0....0.",
        ".0....0.0....0.",
        ".0....0.0....0.",
        "...............",
        "...000...000...",
        "..............." };
}

figure pentadecathlon( )
{
   return 
      { "..................",
         "..................",
         "..................",
         "......0....0......",
         "....00.0000.00....",
         "......0....0......",
         "..................",
         "..................",
         "..................",
         ".................."
     };
}

figure relay( ) 
{
   return 
      { "...........................................",
        "...........................................",
        "...........................................",
        "...............................0....0......",
        "....................00.......00.0000.00....",
        ".....................00........0....0......",
        "....................0......................",
        "......0....0...............................",
        "....00.0000.00.............................",
        "......0....0...............................",
        "...........................................",
        "...........................................",
        "..........................................."
       };
}


