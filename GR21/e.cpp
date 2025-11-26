#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
using namespace std;
const int mod=1e9+7;
vector<int>fac;
int binpow(int x,int y)
{
    if(x==0)return 1;
    int ret=1;
    while(y>0LL)
    {
        if(y&1LL)ret=(ret*x)%mod;
        y>>=1LL;
        x=(x*x)%mod;
    }
    // cout<<"x="<<x<<" y="<<y<<" ret="<<ret<<endl;
    return ret;
}
signed main()
{
    speed;
    int n;
    cin>>n;
    int maxn=2e5+5;
    fac.resize(3*maxn+1,0);
    fac[0]=1;
    fac[1]=1;
    for(int i=2;i<=3*maxn;i++)
    {
        fac[i]=(fac[i-1]*i)%mod;
    }
    vector<int>a(n+1);
    for(int i=0;i<=n;i++)cin>>a[i];
    int ans=0;
    for(int i=0;i<=n;i++)
    {
        if(a[i]==0)break;
        // if(a[i]<=-1)break;
        // int cur=a[i]+1;
        // for(int j=0;j<a[i];j++)
        {
            int cnt=fac[i+a[i]];
            cnt=(cnt*binpow(fac[i+1],mod-2))%mod;
            cnt=(cnt*binpow(fac[a[i]-1],mod-2))%mod;
            // cnt=(cnt*cur)%mod;
            // cout<<"cnt="<<cnt<<endl;
            // cur--;
            ans=(ans+cnt)%mod;
        }
        // int cur=fac[a[i]+i];
        // cout<<"cur before="<<cur<<endl;
        // cur=(cur*binpow(a[i],mod-2))%mod;
        // if(i>0)
        // cur=(cur*binpow(i,mod-2))%mod;
        // cout<<"i="<<i<<" cur="<<cur<<endl;
        // ans=(ans+(cur*(i+a[i]))%mod)%mod;
    }
    cout<<ans<<endl;
    return 0;
}
