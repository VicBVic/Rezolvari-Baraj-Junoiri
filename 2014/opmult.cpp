#include <bits/stdc++.h>
using namespace std;
#define TESTS

#define x first
#define y second
#define pii pair<int,int>
#define veci vector<int>
#define vecp vector<pii>
#define all(x) x.begin(), x.end()
#define pb(x,y) x.push_back(y)

const int maxn = 11;

int x,n;
char buf[2005];

bool eval_interval(int st, int dr)
{
	int nr_st=0, nr_dr=0;
	int i;
	for(i=st+1;buf[i]!=',';i++)
		nr_st=nr_st*10 + buf[i]-'0';
	for(i++; buf[i]!=']'&&buf[i]!=')'; i++)
		nr_dr=nr_dr*10 + buf[i]-'0';
	
	if(buf[st]=='(') nr_st++;
	if(buf[dr]==')') nr_dr--;

	return nr_st<=x&&x<=nr_dr;
}

bool eval_intersection(int st, int dr)
{
	bool ans=1;
	int last_poz=st-1;
	for(int i=st;i<=dr+1;i++)
	{
		if(buf[i]=='n'||i==dr+1)
		{
			ans=ans&&eval_interval(last_poz+1,i-1);

			last_poz=i;
		}
	}

	return ans;
}

bool eval_dif(int st, int dr)
{
	bool ans=0;
	char last='u';
	int last_poz=st-1;
	for(int i=st;i<=dr+1;i++)
	{
		if(buf[i]=='-'||buf[i]=='u'||i==dr+1)
		{
			bool next= eval_intersection(last_poz+1, i-1);

			if(last == '-')
			{
				if(next) ans=0;
			}
			else
			{
				ans=ans||next;
			}

			last = buf[i];
			last_poz = i;
		}
	}

	return ans;
}

void solve()
{
	cin>>x;
	cin.get();
	cin.getline(buf, 2005);
	n=strlen(buf);

	if(eval_dif(0,n-1))
	{
		cout<<"DA\n";
	}
	else 
	{
		cout<<"NU\n";
	}
}

int32_t main()
{
	#ifndef LOCAL
		#define fname "opmult"
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