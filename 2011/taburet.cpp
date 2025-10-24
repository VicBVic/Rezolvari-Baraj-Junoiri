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

const int maxn = 70;
const int maxrep=55;

int fr[maxn];
int n;

int lft[6]={0,4,1,2,3,5};
int up[6]={3,0,2,5,4,1};

const bool magic[32] = {0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,1,0,0,0,0,1,1,0,0,0,0};
int scaun;

int bit(int nr, int poz)
{
	return (nr>>poz)&1;
}

void apply_perm(int p[])
{
	int news=0;

	for(int i=0;i<6;i++)
	{
		news+=(1<<i)*bit(scaun,p[i]);
	}

	scaun=news;
}

void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int b;
		scaun=0;
		for(int j=0;j<6;j++)
		{
			cin>>b;
			scaun+=b*(1<<j);
		}

		int mn=scaun;
		for(int j=0;j<32;j++)
		{
			if(magic[j]) apply_perm(up);
			else apply_perm(lft);

			mn=min(mn, scaun);
		}

		fr[mn]++;
	}

	int cnt=0, mx=0;
	for(int i=0;i<64;i++)
	{
		cnt+=(fr[i]>0);
		mx=max(mx, fr[i]);
	}

	cout<<cnt<<'\n'<<mx<<'\n';
}

int32_t main()
{
	#ifndef LOCAL
		#define fname "taburet"
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