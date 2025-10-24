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

const int maxn = 1005;
int n;
int vert[maxn], hor[maxn], diag[maxn*2], revdiag[maxn*2];
int sumv[maxn], sumh[maxn], sumd[maxn*2], sumrd[maxn*2];
void solve()
{
	cin>>n;
	int v;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>v;

			vert[j]+=v;
			sumv[j]+=i+j;

			hor[i]+=v;
			sumh[i]+=i+j;

			diag[n-i+j]+=v;
			sumd[n-i+j]+=i+j;

			revdiag[i+j-1]+=v;
			sumrd[i+j-1]+=i+j;
		}
	}

	int rang=0, sum=0, len=0, sumid=0;
	
	int csum=0, clen=0, csumid=0;
	for(int i=1;i<2*n;i++)
	{
		int line= min(i, 2*n-i);
		if(revdiag[i]==line)
		{
			csum+=line;
			csumid+=sumrd[i];
			clen++;
		}
		else
		{
			csum=0,clen=0, csumid=0;
		}

		if(clen>1)
		if(csum>sum) 
		rang=4, sum=csum, len=clen, sumid=csumid;
	}

	csum=clen=csumid=0;
	for(int i=1;i<2*n;i++)
	{
		int line= min(i, 2*n-i);
		if(diag[i]==line)
		{
			csum+=line;
			clen++;
			csumid+=sumd[i];
		}
		else
		{
			csum=0,clen=0, csumid=0;
		}

		if(clen>1)
		if(csum>sum) 
		rang=3, sum=csum, len=clen, sumid=csumid;
	}

	csum=clen=csumid=0;
	for(int i=1;i<=n;i++)
	{
		int line=n;
		if(vert[i]==line)
		{
			csum+=line;
			clen++;
			csumid+=sumv[i];
		}
		else
		{
			csum=0,clen=0, csumid=0;
		}

		if(clen>1)
		if(csum>sum) 
		rang=2, sum=csum, len=clen, sumid=csumid;
	}

	csum=clen=csumid=0;
	for(int i=1;i<=n;i++)
	{
		int line=n;
		if(hor[i]==line)
		{
			csum+=line;
			clen++;
			csumid+=sumh[i];
		}
		else
		{
			csum=0,clen=0, csumid=0;
		}

		if(clen>1)
		if(csum>sum) 
		rang=1, sum=csum, len=clen, sumid=csumid;
	}

	cout<<rang<<'\n'<<len<<'\n'<<sum<<'\n';

}

int main()
{
	#ifndef LOCAL
		#define fname "banda"
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