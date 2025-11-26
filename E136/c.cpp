#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
const int MOD=998244353;
const int N=61;
int fact[N], invfact[N];
int binpow(int a, int b, int m)
{
	int ans=1;
	while(b)
	{
		if(b&1)
			ans=(ans*a)%m;
		b/=2;
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
    vector<int>dpa(61),dpb(61);
    dpa[2]=1;
    dpb[2]=0;
    for(int i=4;i<=60;i+=2)
    {
        dpa[i]=(dpb[i-2]+nCr(i-1,i/2))%MOD;
        dpb[i]=(nCr(i,i/2)-1-dpa[i]+MOD)%MOD;
    }
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        cout<<dpa[n]<<" "<<dpb[n]<<" "<<1<<endl;
    }
    return 0;
}


