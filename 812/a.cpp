#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
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
        vector<int>x,y;
        for(int i=0;i<n;i++)
        {
            int u,v;
            cin>>u>>v;
            if(u==0)y.push_back(v);
            if(v==0)x.push_back(u);
        }
        x.push_back(0);
        y.push_back(0);
        sort(all(y));
        sort(all(x));
        int ans=2*(y[(int)y.size()-1]-y[0]);
        ans+=2*(x[(int)x.size()-1]-x[0]);
        cout<<ans<<endl;
    }
    return 0;
}