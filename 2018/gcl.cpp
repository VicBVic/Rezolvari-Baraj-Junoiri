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

const int maxn = 55;
const int maxvar = 30;
int v[maxvar];
int expr[maxn][maxvar], exprvar[maxn], exprconst[maxn];
int repcnt[maxn], repstop[maxn], repret[maxn];
int writevar[maxn];
int c, wk;
int n;

void read_program()
{
	string s;
	char c;
	n=0;
	int last_rep=0;
	while(true)
	{
		cin>>c;


		n++;
		exprvar[n]=-1;
		repcnt[n]=-1;
		writevar[n]=-1;
		repret[n]=-1;
		
		if('a'<=c&&c<='z')
		{
			//citeste expresie
			int mod=1, runmult=0;
			
			exprvar[n] = c-'a';

			cin.get(c);
			while(c!='\n')
			{
				if(c==' '&&runmult>0)
				{
					exprconst[n] += runmult*mod;
					runmult=0;
					mod=1;
				}
				else if('a'<=c&&c<='z')
				{
					//cout<<"REAL? "<<n<<' '<<c<<' '<<runmult<<'\n';
					if(runmult==0) runmult=1;
					expr[n][c-'a'] += runmult*mod;
					runmult=0;
					mod=1;
				}
				else if(c=='-')
				{
					mod=-1;
				}
				else if(c=='+')
				{
					mod=1;
				}
				else if('0'<=c&&c<='9')
				{
					runmult=runmult*10+(c-'0');
				}

				cin.get(c);
			}
			
			if(runmult>0)
			{
				exprconst[n] += runmult*mod;
				runmult=0;
				mod=1;
			}

			//cerr<<"HERE "<<c<<'\n';
			continue;
		}

		//cout<<"here "<<n<<' '<<s<<'\n';
		cin>>s;
		//cerr<<"HERE!! "<<c<<' '<<s<<' '<<(s=="TOP")<<'\n';
		if(s=="NCEPE") continue;

		if(s=="CRIE")
		{
			
			char c; cin>>c;
			writevar[n]=c-'a';
			continue;
		}

		if(s=="EPETA")
		{
			assert(last_rep==0);
			int x; cin>>x;
			repcnt[n]=x;
			last_rep = n;
			continue;
		}

		if(s=="TOP")
		{
			//cerr<<"YESSS "<<last_rep<<'\n';
			if(last_rep==0) return;
			
			repstop[last_rep]=n;
			repret[n]=last_rep;
			last_rep=0;

			continue;
		}	
	}
}

void run_program()
{
	int ip=1;
	while(ip<=n)
	{
		//cerr<<"here "<<ip<<' '<<writevar[ip]<<' '<<exprvar[ip]<<' '<<repcnt[ip]<<'\n';
		if(writevar[ip]!=-1)
		{
			if(c==2)
			{
				cout<<(char)(writevar[ip]+'a')<<" = "<<v[writevar[ip]]<<'\n';
			}
			else
			{
				wk++;
			}
		}
		if(repret[ip]!=-1)
		{
			ip=repret[ip];
		}
		if(repcnt[ip]!=-1)
		{
			if(repcnt[ip]>0) repcnt[ip]--;
			else
			{
				ip=repstop[ip];
			}
		}
		if(exprvar[ip]!=-1)
		{
			//v[exprvar[ip]]=0;
			int aux=exprconst[ip];
			//cout<<"here "<<ip<<','<<exprvar[ip]<<" : ";
			for(int i=0;i<maxvar;i++)
			{
				//cout<<i<<','<<expr[ip][i]<<' ';
				aux+=expr[ip][i]*v[i];
			}
			//cout<<" end "<< aux <<'\n';

			v[exprvar[ip]]=aux;
		}

		ip++;
	}
}

void solve()
{
	cin>>c;
	read_program();
	//cerr<<"final\n";
	run_program();
	if(c==1) cout<<wk<<'\n';
}

int32_t main()
{
	#ifndef LOCAL
		#define fname "gcl"
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