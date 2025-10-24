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

const int maxn = 1e6+5;

int c,n,k,s;
int v[maxn];
int stk[maxn], sk;
int tol[maxn];
deque<int> deq;
int sp[maxn];
void solve()
{
	cin>>c>>n>>k>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>v[i];
		sp[i]=v[i]+sp[i-1];
	}

	if(c==1)
	{
		stk[0]=0;
		int ans=0;
		int runsum=0;
		for(int i=1;i<=n;i++)
		{
			//cout<<"here "<<v[i]<<','<<runsum<<" : ";
			stk[++sk]=i;

			sp[i] -= runsum;

			if(sk>=k)
			{
				if(sp[stk[sk]]-sp[stk[sk-k]]>s)
				{
					ans++;
					runsum+=(sp[stk[sk]] - sp[stk[sk-k]]);
					sk-=k;
				}
			}

			/*for(int j=1;j<=sk;j++)
			{
				cout<<sp[stk[j]]<<' ';
			}
			cout<<'\n';*/
		}

		cout<<ans<<'\n';
		return;
	}

	k++;
	for(int i=k;i<=n;i++)
	{
		tol[i] = sp[i]-sp[i-k]-s;
		//cout<<tol[i]<<' ';
	}
	//cout<<'\n';

	int ans=0;
	for(int i=n-1;i>=1;i--)
	{
		if(i+1>=k)
		{
			while(deq.size()>0&&tol[i+1] >= tol[deq.front()]) deq.pop_front();
			deq.push_front(i+1);
		}
		while(deq.back() >= i + k) deq.pop_back();

		int max_tol = tol[deq.back()];

		//cout<<"here "<<i<<" : "<<max_tol<<'\n';

		ans+=(v[i]<max_tol);
	}

	cout<<ans<<'\n';
}

int32_t main()
{
	#ifndef LOCAL
		#define fname "secv"
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