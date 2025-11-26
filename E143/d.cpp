#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
const int MOD=998244353;
const int N=3e5+10;
int fact[N], invfact[N];

int binpow(int a, int b, int m)
{
	int ans=1;
	while(b)
	{
		if(b&1)
			ans=(ans*a)%m;
		b>>=1;
		a=(a*a)%m;
	}
	return ans;
}

int modinv(int k)
{
	return binpow(k, MOD-2, MOD);
}

void precompute()
{
	fact[0]=fact[1]=1;
	for(int i=2;i<N;i++)
	{
		fact[i]=fact[i-1]*i;
		fact[i]%=MOD;
	}
	invfact[N-1]=modinv(fact[N-1]);
	for(int i=N-2;i>=0;i--)
	{
		invfact[i]=invfact[i+1]*(i+1);
		invfact[i]%=MOD;
	}
}

int nCr(int x, int y)
{
	if(y>x || x<=0 || y<0)return 0;
	int num=fact[x];
	num*=invfact[y];
	num%=MOD;
	num*=invfact[x-y];
	num%=MOD;
	return num;
}
signed main()
{
    speed;
    precompute();
    int n;
    cin>>n;
    vector<int>w(n),prod;
    for(int i=0;i<n;i++)cin>>w[i];
    for(int i=0;i<n;i+=3)
    {
        int a=w[i];
        int b=w[i+1];
        int c=w[i+2];
        int mn=min(a,b);
        mn=min(mn,c);
        prod.push_back((a==mn)+(b==mn)+(c==mn));
    }
    int tot=1;
    for(auto& u : prod)
    {
        tot=(tot*u)%MOD;
    }
    cout<<(nCr(n/3,n/6)*tot)%MOD<<endl;
    return 0;
}
