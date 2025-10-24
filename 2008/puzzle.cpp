#include <bits/stdc++.h>
using namespace std;
//#define TESTS

#define x first
#define y second
#define pii pair<int,int>
#define veci vector<int>
#define vecp vector<pii>
#define all(x) x.begin(), x.end()
#define pb(x,y) x.push_back(y)

const int maxn = 255;

int v[maxn];
string a,b;
int n;

vector<int> ap[255];

void solve()
{
	cin>>a>>b;
	n = a.size();

	for(int i=0;i<n;i++)
	{
		ap[a[i]].push_back(i);
	}

	for(int i=0;i<n;i++)
	{
		v[i]= ap[b[i]].back();
		ap[b[i]].pop_back();
		//cout<<v[i]<<'\n';
	}
	for(int i=0;i<n;i++)
	{
		int j;
		for(j=0;j<n;j++) if(v[j]==i) break;

		if(i==j) continue;

		int x = i, y = j-i-1, z = n-j-1;
		assert(x+y+z+2==n); 

		for(int rep=0; rep<x+y+2; rep++) cout<<n<<' ';
		for(int rep=0;rep<z+x; rep++) cout<<n-1<<' ';
		for(int rep=0; rep<z+x+1; rep++) cout<<1<<' ';
		for(int rep=0;rep<1+z;rep++) cout<<n<<' ';

		//cout<<"end\n";
		swap(v[i], v[j]);
	}
	cout<<0<<'\n';
}

int main()
{
	#ifndef LOCAL
		#define fname "puzzle"
		freopen(fname".in","r", stdin);
		freopen(fname".out","w",stdout);
	#endif

	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	int t=1;

	#ifdef TESTS
		cin>>t;
	#endif
	while(t--)
	{
		solve();
	}
	return 0;
}