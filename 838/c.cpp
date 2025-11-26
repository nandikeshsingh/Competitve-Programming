#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
const int mod=998244353;
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
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string s;
        cin>>s;
        int tot=1;
        int ans=1;
        for(int i=1;i<n;i++)
        {
            if(s[i]==s[i-1])
            {
                tot++;
            }
            else tot=1;
            ans+=binpow(2,tot-1,mod);
            ans%=mod;
        }
        cout<<ans<<endl;
    }
    return 0;
}


