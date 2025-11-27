#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
using namespace std;
const int mod=1e9+7;
signed main()
{
    speed;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t;
    cin>>t;
    for(int c=1;c<=t;c++)
    {
        int n;
        cin>>n;
        vector<pair<int,int>>tr;
        int aa=0,xx=0,sa=0,sx=0;
        int aay=0,xxy=0,say=0,sxy=0;
        for(int i=0;i<n;i++)
        {
            int a,b;
            cin>>a>>b;
            tr.push_back({a,b});
            aa=(aa+((a*a)%mod))%mod;
            sa=(sa+a)%mod;
            aay=(aay+((b*b)%mod))%mod;
            say=(say+b)%mod;
        }
        int m;
        cin>>m;
        vector<pair<int,int>>q;
        for(int i=0;i<m;i++)
        {
            int x,y;
            cin>>x>>y;
            q.push_back({x,y});
            xx=(xx+((x*x)%mod))%mod;
            sx=(sx+x)%mod;
            xxy=(xxy+((y*y)%mod))%mod;
            sxy=(sxy+y)%mod;
        }
        int ans=0;
        ans=(ans+((n*(xx))%mod+(m*(aa))%mod-(2*((sa*sx)%mod))%mod+mod)%mod)%mod;
        ans=(ans+((n*(xxy))%mod+(m*(aay))%mod-(2*((say*sxy)%mod))%mod+mod)%mod)%mod;
        cout<<"Case #"<<c<<": "<<ans<<endl;
    }
    return 0;
}


