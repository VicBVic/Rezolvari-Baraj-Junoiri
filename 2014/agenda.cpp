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


int monthlen[16]={0,31,28,31,30,31,30,31,31,30,31,30,31};

void precalc()
{
	for(int i=1;i<=12;i++)
	{
		monthlen[i]+=monthlen[i-1];
	}
}

string month="###";
int monthsum(string &s)
{
	int id=0;
	if(s=="ian") id=0;
	else if (s=="feb") id=1;
	else if (s=="mar") id=2;
	else if (s=="apr") id=3;
	else if (s=="mai") id=4;
	else if (s=="iun") id=5;
	else if (s=="iul") id=6;
	else if (s=="aug") id=7;
	else if (s=="sep") id=8;
	else if (s=="oct") id=9;
	else if (s=="noi") id=10;
	else if (s=="dec") id=11;
	else assert(0);
	return monthlen[id];
}

void prepare_month()
{
	for(int i=0;i<3;i++) if('A'<=month[i]&&month[i]<='Z') month[i]+='a'-'A';
}

char line[1005];
int lk;
int read_unix()
{
	int day=0;
	int hour=0;
	int minutes=0;
	
	while('0'<=line[lk]&&line[lk]<='9') day=10*day+(line[lk++]-'0');
	
	int mk=0;
	while(mk<3) month[mk++]=line[lk++];
	prepare_month();
	
	day+=monthsum(month);
	

	while('0'>line[lk]||line[lk]>'9') lk++;
	while('0'<=line[lk]&&line[lk]<='9') hour=10*hour+(line[lk++]-'0');
	lk++;
	while('0'<=line[lk]&&line[lk]<='9') minutes=10*minutes+(line[lk++]-'0');
	if(line[lk]=='-') lk++;


	minutes += hour*60;
	minutes += day*60*24;
	
	return minutes;
}

void fixline()
{
	int st=0;
	for(int dr=0;line[dr]!='\0';dr++)
	{
		if(line[dr]!=' ')
		{
			line[st++]=line[dr];
		}
	}
	line[st]='\0';
}

void unix_to_time(int x)
{
	cout<<x/(24*60)<<' ';
	x%=(24*60);

	cout<<x/60<<' ';
	x%=60;
	cout<<x<<'\n';

}

const int maxn=24*370*60+5;

int mars[maxn];



void solve()
{
	precalc();

	int c;
	int mx=0;
	int capst=maxn, capdr=0;
	cin>>c;
	cin.get();
	string buf;

	while(!cin.eof())
	{
		cin.getline(line,1005,'\n');
		if(cin.eof()) break;
		fixline();


		lk=0;
		int st=read_unix();
		int dr=read_unix();

		mars[st]++;
		mars[dr+1]--;
		mx=max(mx, dr-st);

		//cerr<<"HERE "<<st<<' '<<dr<<'\n';
		capst=min(capst, st);
		capdr=max(capdr, dr);
	}

	if(c==1)
	{
		unix_to_time(mx);
		return;
	}
	if(c==2)
	{
		int mx=0;
		for(int i=capst;i<=capdr;i++)
		{
			
			mars[i]+=mars[i-1];
			mx=max(mx, mars[i]);
		}
		cout<<mx<<'\n';
		return;
	}
	if(c==3)
	{
		int mx=0, runsum=0;
		for(int i=capst;i<=capdr;i++)
		{
			mars[i]+=mars[i-1];
			
			if(mars[i]==0) runsum++;
			else runsum=0;

			mx=max(mx, runsum);
		}

		unix_to_time(mx+1);
		return;
	}
	assert(0);
}

int32_t main()
{
	#ifndef LOCAL
		#define fname "agenda"
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