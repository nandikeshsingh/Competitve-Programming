#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
const int mod=1e9+7;
int binpow(int a,int b)
{
    int ret=1;
    a%=mod;
    while(b)
    {
        if(b&1)ret=(ret*a)%mod;
        b>>=1;
        a=(a*a)%mod;
    }
    return ret;
}
signed main()
{
    speed;
    int n;
    cin>>n;
    while(n--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        cout<<binpow(a,binpow(b,c))<<endl;
    }
    return 0;
}


