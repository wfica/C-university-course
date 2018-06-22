#include <list>
#include <iostream>

using namespace std;

int main()
{
	list< int>  l = {1,2,3,4,5};
	
	cout<< l.size()<<"\n";
	
	list<int> l2;
	l2 = move(l);
	cout<<l2.size()<<" "<<l.size()<<"\n";
	return 0;
}
