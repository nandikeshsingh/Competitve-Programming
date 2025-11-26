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
        int n,m;
        cin>>n>>m;
        vector<int>b(m);
        multiset<int>a;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int x;cin>>x;
            a.insert(x);
        }
        for(int i=0;i<m;i++)
        {
            cin>>b[i];
        }
        for(int i=0;i<m;i++)
        {
            a.erase(a.begin());
            a.insert(b[i]);
        }
        for(auto& u : a)ans+=u;
        cout<<ans<<endl;
    }
    return 0;
}


