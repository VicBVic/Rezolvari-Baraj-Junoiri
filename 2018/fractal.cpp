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

struct bignum_t{
	static const int base = 10;
	static const int maxcif = 1e5+5;
	int val[maxcif];
	int cif=0;

	bignum_t()
	{
		cif=1;
		val[1]=1;
	}

	bignum_t(int x)
	{
		while(x)
		{
			cif++;
			val[cif] = x%base;
			x/=base;
		}
	}

	void operator *=(int x)
	{
		int carry=0;
		for(int i=1;i<=cif||carry>0;i++)
		{
			val[i]=val[i]*x+carry;
			
			carry=val[i]/base;
			val[i]%=base;

			cif=max(cif,i);
		}
	}

	void operator +=(bignum_t &other)
	{
		int carry=0;
		for(int i=1;i<=cif||i<=other.cif||carry>0;i++)
		{
			val[i]=val[i]+other.val[i]+carry;
			
			carry=val[i]/base;
			val[i]%=base;

			cif=max(cif,i);
		}
	}

	void operator /=(int x)
	{
		int carry=0;
		for(int i=cif;i>=1;i--)
		{
			carry=carry*base+val[i];
			val[i]=carry/x;
			carry%=x;
		}

		while(val[cif]==0) cif--;
	}
};

ostream& operator <<(ostream &o, bignum_t &b)
{
	for(int i=b.cif;i>=1;i--) o<<b.val[i];
	return o;
}

bignum_t ans;
bignum_t ans2(0);
bignum_t p;
int n,c;

void beck(int poz, int mod)
{

}

void solve()
{
	cin>>c>>n;
	if(c==1)
	{
		if(n==1)
		{
			cout<<0<<'\n';
			return;
		}
		if(n==2)
		{
			cout<<1<<'\n';
			return;
		}
		for(int i=1;i<=n-2;i++) ans*=4;

		cout<<ans<<'\n';
		return;
	}

	if(n==1)
	{
		cout<<0<<'\n';
		return;
	}
	if(n==2)
	{
		cout<<4<<'\n';
		return;
	}

	for(int i=1;i<=n-1;i++) p*=4;

	ans2+=p;
	
	for(int i=1;i<=n-2;i++)
	{
		p/=4;
		p*=3;
		ans2+=p;
	}

	cout<<ans2;

}

int32_t main()
{
	#ifndef LOCAL
		#define fname "fractal"
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