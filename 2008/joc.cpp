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

const int maxn = 11;

int n;
deque <int> a,b;
deque <int> table;
int last[maxn];

void solve()
{
	cin>>n;
	
	int x;
	cin>>x;
	while(x!=0) a.push_back(x), cin>>x;
	cin>>x;
	while(x!=0) b.push_back(x), cin>>x;

	while(n)
	{
		n--;
		x = a.front();
		a.pop_front();
		table.push_back(x);
		
		if(last[x]!=0)
		{
			while(table.size()>=last[x])
			{
				int y = table.back();
				table.pop_back();
				a.push_back(y);
				//cerr<<y<<'\n';
				if(y!=x) last[y] = 0;
			}
			last[x] = 0;
		}
		else last[x] = table.size();


		if(a.empty()) break;
		if(!n) break;

		n--;
		x = b.front();
		b.pop_front();
		table.push_back(x);

		
		if(last[x]!=0)
		{
			while(table.size()>=last[x])
			{
				int y = table.back();
				table.pop_back();
				b.push_back(y);
				//cerr<<y<<'\n';
				if(y!=x) last[y] = 0;
			}
			last[x] = 0;
		}
		else last[x] = table.size();
		
		if(b.empty()) break;
		if(!n) break;

	}

	if(a.empty()) cout<<"A";
	else while(!a.empty()) cout<<a.front()<<' ', a.pop_front();
	cout<<'\n';
	
	if(b.empty()) cout<<"B";
	else while(!b.empty()) cout<<b.front()<<' ', b.pop_front();
	cout<<'\n';

	if(table.empty()) cout<<"0";
	else while(!table.empty()) cout<<table.front()<<' ', table.pop_front();
	cout<<'\n';
}

int main()
{
	#ifndef LOCAL
		#define fname "joc"
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