#include<bits/stdc++.h>
#define mp make_pair
using namespace std;

const double pi  =  3.141592653589793;


map< pair<int,int>, long long> memo;

long long n_po_k(int n, int k){
	map< pair<int,int>, long long>::iterator it;
	
	it = memo.find(mp(n,k));
	
	if( it != memo.end() )
		return it->second;
	
	long long res = 1;
	if( n != k && n != 0 && k != 0)
		res = n_po_k(n-1, k-1) + n_po_k(n-1,k);
	memo[mp(n,k)] = res;
	return res;
}

int main(){
	while(true){
		int n;
		scanf("%d", &n);
		if(n<0)
			break;
		if(n<4){
			printf("1\n");
			continue;
		}
		long long ans=2;
		for(int a =0; a< n-4; ++a)
		{
			int b = ceil( ( (double)n-4.-a)/pi);
			int k = min(1, min( b, (int)floor( pi*(double)b - ( n - 4. - a )  )));
		//	cout<< a <<" "<< b<< " "<<k<<" --- " <<n_po_k(a+b-k, a)<<endl;
			ans += n_po_k(a+b-k, a);
		}		
		printf("%lld\n", ans);
		
	}
	return 0;
}
