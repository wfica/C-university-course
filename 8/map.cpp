#include<map>
#include<iostream>
#include<vector>
#include<cctype>
#include<string>
#include<unordered_map>


using namespace std;
/*
map< string, unsigned int > 
	frequencytable(const vector< string > & text )
{
	map<string, unsigned int > res;
	for( const auto& p : text )
		res[p]++;
		
	return res;		
}

ostream& operator << ( ostream& stream,
	const map< string, unsigned int > & freq )
{
	for( const auto& p : freq )
		stream << p.first << " --> "<< p.second<<"\n";
		
	return stream;
}*/

struct case_insensitive
{
	bool operator( ) ( const string& s1, const string& s2 ) const
	// Return true if s1 < s2, ignoring case of the letters.
	{
		size_t len = min(s1.length(), s2.length()); 
		for( size_t  i = 0 ; i < len; ++i)
		{
			if( tolower(s1[i] ) < tolower(s2[i]) ) return true;
			if( tolower(s1[i] ) > tolower(s2[i]) ) return false;
		}
		return s1.length() < s2.length();
	}
};

template< typename C > map< string, unsigned int, C >
	frequencytable( const vector< string > & text )
{
	map<string, unsigned int, C > res;
	for( const auto& p : text )
		res[p]++;
		
	return res;	
}
// frequencytable( test ) will produce a frequency table, using
// std::less< std::string >, which is the good old <
// frequencytable<case_insensitive>( test ) will produce a
// case insensitive frequency table.

template< typename C > ostream& operator << ( ostream& out, 
	const map< string, unsigned int, C > & m )
{
	for( const auto& p : m )
		out << p.first << " --> "<< p.second<<"\n";
		
	return out;
}
// Prints frequencytable, for every possible comparator.


struct case_insensitive_hash
{
	size_t operator ( ) ( const std::string& s ) const
	{
		size_t val = 0, mn = 31, mod = 43212307;
		for( const auto& p : s)
		{
			val += ( (tolower(p) - 'a' )*mn ) % mod;
			mn = (mn * mn)%mod;
		}
		return val;
	}
};

struct case_insensitive_equality
{
	bool operator ( ) ( const string& s1, const string& s2 ) const
	{
		case_insensitive c;
		return !c( s1, s2) && !c( s2, s1);
	}
};

unordered_map< string, unsigned int , 
	case_insensitive_hash, case_insensitive_equality>
	hashed_frequencytable( vector< string > &text )
{
	unordered_map< string, unsigned int , 
		case_insensitive_hash, case_insensitive_equality> res;
	for( const auto& p : text )
		res[p]++;
		
	return res;	
} 
// As with frequencytable for map, you can make this
// function polymorphic.
// The default parameters are std::hash<std::string> and
// std::equal_to<std::string>.

ostream& operator << ( ostream& stream,
	const unordered_map< string, unsigned int ,
	 case_insensitive_hash, case_insensitive_equality> & freq )
{
	for( const auto& p : freq )
		stream << p.first << " --> "<< p.second<<"\n";
		
	return stream;
}

int main()
{
	vector< string > vec = { "Ala", "mA", "koTa", "alA", "aLicja", "Ma" , "kOT"};
	auto frec = frequencytable<case_insensitive>( vec );
	cout<<frec;

	case_insensitive_hash h;
	cout<< h("xxx") - h("XxX")<< "\n";
	cout<< h("ALZzaA") - h("alZZaA")<< "\n";
	
	case_insensitive_equality e;
	cout<< e("xxx", "Xxx")<<  "\n";
	cout<< e("ALZzaA", "AlzzAa") <<"\n";
	
	auto frec2 = hashed_frequencytable(  vec );
	
	cout<< frec2;
	
	
	return 0;
}
