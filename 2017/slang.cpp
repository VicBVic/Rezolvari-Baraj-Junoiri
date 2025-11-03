#include <bits/stdc++.h>
using namespace std;
//#define TESTS

#define int long long
#define x first
#define y second
#define pii pair<int,int>
#define veci vector<int>
#define vecp vector<pii>
#define all(x) x.begin(), x.end()
#define pb(x,y) x.push_back(y)

const int maxn = 11;
const int mod = 1e6;
int c,n;



int fact[7];
int a0, a1;
int run_mod=1, run_cnt=0;
void beck(int poz)
{
	if(poz==6)
	{
		//cout<<"here "<<run_cnt<<'\n'; 
		if(run_cnt!=0) a0+=fact[run_cnt]*run_mod;
		a1+=fact[run_cnt+1]*run_mod;
		return;
	}
	
	beck(poz+1);
	run_cnt++;
	if(poz==4) run_mod*=6;
	if(poz==5) run_mod*=6*6;

	beck(poz+1);

	run_cnt--;
	if(poz==4) run_mod/=6;
	if(poz==5) run_mod/=6*6;
}


void solve()
{
	cin>>c>>n;
	fact[0]=1;
	for(int i=1;i<7;i++) fact[i]=i*fact[i-1];

	if(c==1)
	{
		beck(2);
		int ans=a0;
		for(int i=1;i<=n;i++) ans=ans*a1%mod;
		cout<<ans<<'\n';
		return;
	}

	cout<<n+3<<' '<<12+n*11<<'\n';	
}

int32_t main()
{
	#ifndef LOCAL
		#define fname "slang"
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