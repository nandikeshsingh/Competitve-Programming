#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
int mod=1e9+7;
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

signed main()
{
    speed;
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int ans=n;
        ans*=(n+1);
        ans%=mod;
        ans*=(2*n+1);
        ans%=mod;
        ans=(ans*binpow(6,mod-2,mod))%mod;

        int ans2=n;
        ans2*=(n-1);
        ans2%=mod;
        ans2*=(n+1);
        ans2%=mod;
        ans2=(ans2*binpow(3,mod-2,mod))%mod;
        ans+=(ans2);
        ans%=mod;
        cout<<(ans*2022)%mod<<endl;
    }
    return 0;
}


