#include<bits/stdc++.h>
using namespace std;
int main()
{
	unordered_map<string,int>m;
	pair<string,int>p("abc",1);
	m.insert(p);
	cout<<m["abc"]<<"\n";
	m["xyz"]=100;
	m["123"]=122;
	cout<<m.size()<<"\n";
}
