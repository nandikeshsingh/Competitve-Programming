#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
using namespace std;
signed main()
{
    speed;
    int n,a,b;
    cin>>n>>a>>b;
    vector<int>x(n+1),pre(n+1);
    for(int i=1;i<=n;i++)cin>>x[i],pre[i]=pre[i-1]+x[i];
    set<pair<int,int>>st;
    int ans=-1e18;
    for(int i=1;i<=n;i++)
    {
        if(i-a>=0)st.insert({pre[i-a],i-a});
        if(i-b-1>=0)st.erase({pre[i-b-1],i-b-1});
        if(st.size())
        ans=max(ans,pre[i]-(st.begin()->first));
    }
    cout<<ans<<endl;
    return 0;
}

