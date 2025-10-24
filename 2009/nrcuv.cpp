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


struct bigint{
	short cif[1005];
	int len=0;

	bigint()
	{
		len=1;
		cif[0]=1;
	}

	void mult(int nr)
	{
		int carry=0;
		for(int i=0;i<len;i++)
		{
			cif[i]=cif[i]*nr+carry;
			carry = cif[i]/10;
			cif[i]%=10;
			if(i==len-1&&carry) len++;
		}
	}

	void sub(bigint &other)
	{
		int carry=0;
		for(int i=0;i<len;i++)
		{
			cif[i]-=other.cif[i]+carry;
			carry=0;
			if(cif[i]<0) carry++, cif[i]+=10;
		}
	}
};

ostream& operator <<(ostream &out, bigint b)
{
	bool ok=0;

	for(int i=b.len-1;i>=0;i--)
	{
		if(b.cif[i]!=0) ok=1;
		if(ok) out<<b.cif[i];
	}
	if(!ok) out<<"0";
	return out;
}


int n;
bigint prod_cart, perm;
void solve()
{
	cin>>n;

	for(int i=1;i<=n;i++) prod_cart.mult(n);

	for(int i=1;i<=n;i++) perm.mult(i);

	prod_cart.sub(perm);

	cout<<prod_cart<<'\n';
}

int main()
{
	#ifndef LOCAL
		#define fname "nrcuv"
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