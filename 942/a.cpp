#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define for(i,n)   for(int i=0;i<(n);++i)
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
        int n;
        cin>>n;
        vector<int>a(n),b(n);
        for(i,n)cin>>a[i];
        for(i,n)cin>>b[i];
        int ans=0;
        bool ok=1;
        do
        {
            bool f=0;
            for(i,n)
            {
                if(a[i]>b[i])
                {
                    f=1;
                    break;
                }
            }
            if(f)
            {
                ans++;
                ok=0;
                a.pb(1);
                sort(all(a));
                a.pop_back();
            }
            else ok=1;
        } while (!ok);
        
        cout<<ans<<endl;
    }
    return 0;
}


