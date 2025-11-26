#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define fo(i,n)   for(int i=0;i<(n);++i)
#define rep(i,a,b)   for(int i=(a);i<=(b);++i)
#define per(i,b,a)   for(int i=(b);i>=(a);--i)
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
#define pb push_back
#define F first
#define S second
using namespace std;
signed main()
{
    speed;
    int t;
    cin>>t;
    while(t--)
    {
        int n;cin>>n;
        vector<int>a(n),b(n+1);
        rep(i,0,n-1)cin>>a[i];
        rep(i,0,n)cin>>b[i];
        int ans=0;
        int cur=b.back();
        bool f=0;
        int get=1e18;
        rep(i,0,n-1)
        {
            ans+=abs(a[i]-b[i]);
            int mn=min(a[i],b[i]);
            int mx=max(a[i],b[i]);
            if(cur>=mn && cur<=mx)f=1;
            else 
            {
                int now=min(abs(a[i]-cur),abs(b[i]-cur));
                get=min(get,now);
            }
        }
        if(f)cout<<ans+1<<endl;
        else cout<<ans+get+1<<endl;
    }
    return 0;
}


