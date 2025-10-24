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

const int maxn = 800005;
int k,p,nr;
string s;
bool is_alpha(int st, int dr)
{
	for(int i=st;i<=dr;i++)
	{
		if(s[i]=='0') return 0;
		if(s[i]>i-st+1+'0') return 0;
	}
	return 1;
}

int fr[11];
int decod(int a)
{
	int put=1;
	int ans=0;
	while(a)
	{
		int cif=a%10;
		a/=10;
		for(int i=0;i<p;i++)
		{
			if(fr[i]==0) cif--;
			if(cif==0)
			{
				ans= ans+put*(i+k);	
				fr[i]=1;
				break;
			}
		}
		put*=10;
	}
	return ans;
}

void solve()
{
	cin>>k>>p>>nr>>s;

	cout<<decod(nr)<<'\n';
	

	bool next=1;
	int best=0, runsum=0;
	for(int i=0;i<s.size();i+=p)
	{
		bool me = is_alpha(i,i+p-1);
		if(me==next)
		{
			runsum++;
			next=!next;
		}
		else if(me==1)
		{
			runsum=1;
			next=0;
		}
		else
		{
			runsum=0;
			next=1;
		}

		if(next==1) best=max(best, runsum);
	}

	cout<<best*p<<'\n';
}

int main()
{
	#ifndef LOCAL
		#define fname "decod"
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