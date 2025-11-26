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
        map<int,set<int>>mp;
        for(int i=0;i<m;i++)
        {
            int u,v;
            cin>>u>>v;
            if(u>v)swap(u,v);
            mp[v].insert(u);
        }
        int cnt=0;
        int last=0;
        for(int cur=1;cur<=n;cur++)
        {
            if(mp.count(cur))
            {
                last=max(last,*prev(mp[cur].end()));
            }
            cnt+=(cur-last);
        }
        cout<<cnt<<endl;
    }
    return 0;
}


