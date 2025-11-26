#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
using namespace std;
const int MOD=1e9+7;
const int N=200010;
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
    int h,w,n;
    cin>>h>>w>>n;
    vector<pair<int,int>>vec;
    for(int i=0;i<n;i++)
    {
        int r,c;
        cin>>r>>c;
        vec.push_back({r-1,c-1});
    }
    sort(all(vec),[&](pair<int,int>a,pair<int,int>b){
        return a.first+a.second<=b.first+b.second;
    });
    vec.push_back({h-1,w-1});
    vector<int>dp(n+1,0);
    for(int i=0;i<=n;i++)
    {
        int cur=nCr(vec[i].first+vec[i].second,vec[i].first);
        for(int j=0;j<i;j++)
        {
            int x=vec[i].first-vec[j].first;
            int y=vec[i].second-vec[j].second;
            cur-=(dp[j]*nCr(x+y,x))%MOD;
            cur+=MOD;
            cur%=MOD;
        }
        dp[i]=cur;
    }
    cout<<dp[n]<<endl;
    return 0;
}
