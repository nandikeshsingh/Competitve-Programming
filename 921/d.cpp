#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
const int MOD=1e9+7;
const int N=2e5+10;
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
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,k;
        cin>>n>>m>>k;
        int d=(n*(n-1))/2;
        d%=MOD;
        int tot=0;
        for(int i=0;i<m;i++)
        {
            int a,b,f;
            cin>>a>>b>>f;
            tot+=f;
            tot%=MOD;
        }
        int X=0,Y=0;
        for(int x=1;x<=k;x++)
        {
            int cur=binpow(d-1,k-x,MOD);
            cur=(cur*nCr(k,x))%MOD;
            cur=(cur*modinv(binpow(d,k,MOD)))%MOD;
            Y=(Y+(cur*x)%MOD)%MOD;
            cur=(cur*nCr(x,2))%MOD;
            X=(X+cur)%MOD;
        }
        X=(m*X)%MOD;
        Y=(tot*Y)%MOD;
        cout<<(X+Y)%MOD<<endl;
    }
    return 0;
}
