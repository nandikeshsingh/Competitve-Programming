#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
const int mod = 998244353;
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
signed main()
{
    speed;
    // int t;
    // cin>>t;
    // while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector<int>prime(n+1,1);
        for(int i=2;i<=n;i++)
        {
            if(prime[i]==1)
            {
                for(int j=i+i;j<=n;j+=i)
                {
                    prime[j]=0;
                }
            }
        }
        int ans=0;
        int cur=1;
        for(int i=1;i<=n;i++)
        {
            cur*=(m%mod);
            cur%=mod;
            ans+=cur;
            ans%=mod;
        }
        int tot=1;
        int pp=1;
        for(int i=1;i<=n;i++)
        {
            if(prime[i])
            {
                pp*=i;
            }
            int now=m/pp;
            now%=mod;
            tot*=now;
            tot%=mod;
            ans=(ans-tot+mod)%mod;
        }
        cout<<ans<<endl;
    }
    return 0;
}


