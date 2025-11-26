#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
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
        vector<int>p(n+1);
        for(int i=1;i<=n;i++)cin>>p[i];
        bool ok=0;
        for(int i=1;i<=n;i++)
        {
            if(p[p[i]]==i)ok=1;
        }
        if(ok)cout<<2<<endl;
        else cout<<3<<endl;
    }
    return 0;
}


