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
        vector<vector<int>>gp(n+1,vector<int>(0));
        vector<int>deg(n+1);
        cout<<"ready"<<endl;
        char b[n+1][n+1];
        for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)cin>>b[i][j];
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(b[i][j]=='1')
                {
                    gp[j].push_back(i);
                    deg[j]++;
                }
            }
        }
        cout<<"out"<<endl;
        vector<set<int>>ans(n+1);
        vector<int>vis(n+1);
        int root=-1;
        int cur=1;
        int tot=n;
        for(int i=1;i<=n;i++)
        {
            if(deg[i]==0)
            {
                tot--;
                ans[i].insert(cur++);
                vis[i]=1;
            }
        }
        while(tot)
        {
            cout<<"tot="<<tot<<endl;
            for(int i=1;i<=n;i++)
            {
                if(vis[i]==0)
                {
                    bool ok=1;
                    for(auto& u : gp[i])
                    {
                        if(vis[u]==0)ok=0;
                    }
                    if(ok)
                    {
                        if(gp[i].size()>=2)
                        {
                            for(auto& u : gp[i])
                            {
                                for(auto& v : ans[u])
                                ans[i].insert(v);

                            }
                        }
                        else 
                        {
                            int last=-1;
                            for(auto& u : gp[i])
                            {
                                for(auto& v : ans[u])
                                ans[i].insert(v),last=v;
                            }
                            ans[i].insert(++last);
                        }
                        vis[i]=1;
                        tot--;
                    }
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            cout<<sz(ans[i])<<" ";
            for(auto& u : ans[i])cout<<u<<" ";
            cout<<endl;
        }
    }
    return 0;
}


