#include "grid.h"

void grid::nextgeneration( )
{
   for(size_t y = 0; y< ysize; ++y)
      for( size_t x = 0; x < xsize; ++x)
      {
         int curr = y* xsize + x;
         int ngh = 
            on_ngh(x-1,y-1) + on_ngh(x-1,y) + on_ngh(x-1,y+1)
          + on_ngh(x+1,y-1) + on_ngh(x+1,y) + on_ngh(x+1,y+1)
          + on_ngh(x , y-1) + on_ngh(x,y+1);
          
          c[curr].s1 = 0;
          
          if( c[curr].s0 && ( ngh == 2 or ngh == 3) )
             c[curr].s1 = 1;
          else if (ngh == 3)
             c[curr].s1 = 1;
      }
  for(size_t i =0; i< xsize * ysize; ++i)
      c[i].s0 = c[i].s1;
}


void grid::addfigure( unsigned int x, unsigned int y, const figure& f )
{
   for(size_t i = 0; i < f.repr.size(); ++i)
   {
      for(int j = 0; j < f.repr[i].size(); ++j)
          c[y*xsize + x+j].s0 = (f.repr[i][j] == '0');
      y--;
   }      
}


void grid::addfigure( unsigned int x, unsigned int y,
               std::initializer_list< const char* > p )
{
  for( auto it = p.begin(); it != p.end(); it++)
  {
      c[y*xsize + x].s0 = *it;
      x++;
      if(x == xsize)
      { 
         x = 0;
         y--;
      }
  }
}


void grid::clear( )
{
    for(size_t i=0; i<xsize*ysize; ++i)
    {
       c[i].s0 = '.';
       c[i].s1 = '.';
    }
}
   
   
std::ostream& operator << ( std::ostream& stream, const grid& g)
{
   for(int y = g.ysize-1; y > -1; y--)
   {
      stream<<"\n";
      for(int x = 0; x < g.xsize; ++x)
         if(g.c[y * g.xsize + x].s0) stream<< "0";
         else stream << ".";
   }
   return stream;
}

std::ostream& operator << ( std::ostream& stream, const grid::wrongchar& w )
{
   stream<<"wrong char:?? "<<w.c;

   return stream;
}
