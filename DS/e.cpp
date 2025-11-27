#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
signed main()
{
    speed;
    int n,m,l;
    cin>>n>>m>>l;
    vector<pair<int,int>>a,b;
    for(int i=1;i<=n;i++)
    {
        int x;cin>>x;
        a.push_back({x,i});
    }
    for(int j=1;j<=m;j++)
    {
        int x;cin>>x;
        b.push_back({x,j});
    }
    sort(all(a));
    sort(all(b));
    set<pair<int,int>>st;
    while(l--)
    {
        int c,d;
        cin>>c>>d;
        st.insert({c,d});
    }
    int ans=0;
    for(int i=n-1;i>=0;i--)
    {
        for(int j=m-1;j>=0;j--)
        {
            if(st.find({a[i].second,b[j].second})!=st.end())
            continue;
            else 
            {
                ans=max(ans,a[i].first+b[j].first);
                break;
            }
        }
    }
    // for(int j=m-1;j>=0;j--)
    // {
    //     for(int i=n-1;i>=0;i--)
    //     {
    //         if(st.find({a[i].second,b[j].second})!=st.end())continue;
    //         else 
    //         {
    //             ans=max(ans,a[i].first+b[j].first);
    //             break;
    //         }
    //     }
    // }
    cout<<ans<<endl;
    return 0;   
}


