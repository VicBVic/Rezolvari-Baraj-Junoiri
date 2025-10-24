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

const int maxn = 155;
int n,m,k;

int v[maxn][maxn];
int s[maxn][maxn];

int platou(int st, int dr, int h)
{
	return s[h][dr]-s[h][st-1];
}

bool good(int x)
{
	int sol=0;
	for(int st=1;st<=m;st++)
	{
		for(int dr=st;dr<=m;dr++)
		{
			int down=0;
			for(int up=1;up<=n;up++)
			{
				while(platou(st, dr, up)-platou(st,dr,down)>x)
					down++;
				
				//if(x==4) cout<<"here! "<<st<<','<<dr<<' '<<up<<' '<<down<<' '<<platou(st,dr,up)<<','<<platou(st,dr,down)<<'\n';
				sol+=up-down;
			}
		}
	}

	//cout<<"here "<<x<<' '<<sol<<'\n';
	return sol<k;
}
void solve()
{
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>v[i][j];
			s[i][j]=v[i][j]+s[i-1][j]+s[i][j-1]-s[i-1][j-1];
			//cout<<s[i][j]<<' ';
		}
		//cout<<'\n';
	}

	int x=-1;
	for(int b=(1<<30);b>0;b>>=1)
	{
		if(good(x+b)) x+=b;
	}

	cout<<x+1<<'\n';
}

int32_t main()
{
	#ifndef LOCAL
		#define fname "ssk"
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