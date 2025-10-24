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

const int maxl = 205;
const int maxn = 55;
const int maxb = 3e5+5;
int p,r,c,n,t;

int v[maxl][maxl];
int x[maxn], y[maxn], w[maxn], z[maxn];

bool bordat(int i, int j)
{
	return (i>0)&&(j>0)&&(i<=r)&&(j<=c);
}


void build(int i , int j, int raza)
{
	raza--;
	for(int ii=-raza;ii<=raza;ii++)
	{
		for(int jj = -raza; jj<=raza; jj++)
		{
			if(!bordat(i+ii,j+jj)) continue;
			//cout<<"here "<<ii+i<<' '<<jj+j<<' '<<abs(ii)+abs(jj)<<'\n';

			if(abs(ii)+abs(jj)>raza) continue;

			v[i+ii][j+jj]++;
		}
	}
}

void build_nor(int id)
{
	int rt = t-w[id];
	if(rt<=0) return;

	rt--;
	if(x[id]==1)
	{
		//cout<<"Yes! "<<x[id]+rt<<' '<<y[id]<<'\n';
		build((x[id]+rt-1)%(r+z[id])+1-z[id]/2, y[id], z[id]/2+1);
	}
	else
	{
		//cout<<"NO! "<<x[id]<<' '<<y[id]+rt<<'\n';
		build(x[id], (y[id]+rt-1)%(c+z[id])+1-z[id]/2, z[id]/2+1);
	}
}

bool is_full(int id)
{
	if(x[id]==1)
	{
		if(!bordat(1, y[id]+z[id]/2)) return 0;
		if(!bordat(1, y[id]-z[id]/2)) return 0;

		if(r< z[id]) return 0;

		return 1;
	}

	if(!bordat(x[id]+z[id]/2, 1)) return 0;
	if(!bordat(x[id]-z[id]/2, 1)) return 0;

	if(c < z[id]) return 0;

	return 1;
}

bool time_good(int id, int my_t)
{
	int rt = my_t-w[id];

	if(rt<=0) return 0;
	rt--;
	if(x[id]==1)
	{
		int rpoz = (x[id]+rt-1)%(r+z[id])+1-z[id]/2;

		return rpoz>z[id]/2&&rpoz+z[id]/2<=r;
	}

	int rpoz = (y[id]+rt-1)%(c+z[id])+1-z[id]/2;

	return rpoz>z[id]/2&&rpoz+z[id]/2<=c;
}

void solve()
{
	cin>>p>>r>>c>>n>>t;

	for(int i=1;i<=n;i++)
	{
		cin>>x[i]>>y[i]>>z[i]>>w[i];

	}

	if(p==1)
	{
		int ans=0, tmin=0;
		for(int i=1;i<=n;i++)
		{
			ans+=is_full(i);
		}

		for(int tmin = 1; tmin <= maxb ; tmin++)
		{
			int tgood=0;
			for(int i=1;i<=n;i++)
			{
				tgood += (is_full(i)&&time_good(i, tmin));
			}

			if(tgood == ans)
			{
				cout<< ans <<' ' <<tmin<<'\n';
				return;
			}
		}

		assert(0);
		return;
	}

	if(p==2)
	{
		for(int i=1;i<=n;i++)
		{
			build_nor(i);
			/*for(int y=1;y<=r;y++)
			{
				for(int j=1;j<=c;j++)
				{
					cout<<v[y][j]<<' ';
				}
				cout<<'\n';
			}
			cout<<'\n';*/
		}

		int ans=0, furt=0;
		for(int i=1;i<=r;i++)
		{
			for(int j=1;j<=c;j++)
			{
				ans+=(v[i][j]==0);
				furt+=(v[i][j]>=2);
			}
		}

		cout<<ans<<' '<<furt<<'\n';
		return;
	}

	assert(0);
}

int32_t main()
{
	#ifndef LOCAL
		#define fname "nori"
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