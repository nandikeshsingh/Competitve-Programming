#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
struct edge{
    int a,b,c;
};
signed main()
{
    speed;
    int n,m;
    cin>>n>>m;
    vector<edge>ee(m);
    vector<int>dis(n+1,1e18);
    vector<int>p(n+1,-1);
    for(int i=0;i<m;i++)
    {
        cin>>ee[i].a>>ee[i].b>>ee[i].c;
    }
    dis[1]=0;
    for(int i=1;i<=n;i++)
    {
        bool any=0;
        int v;
        for(auto& e : ee)
        {
            // if(dis[e.a]<1e18)
            {
                if(dis[e.b]>dis[e.a]+e.c)
                {
                    dis[e.b]=dis[e.a]+e.c;
                    p[e.b]=e.a;
                    any=1;
                    v=e.b;
                }
            }
        }
        if(i==n && any)
        {
            cout<<"YES"<<endl;
            for(int i=0;i<n;i++)
            v=p[v];
            int cur=v;
            vector<int>path;
            do
            {
                path.push_back(cur);
                cur=p[cur];
            } while (cur!=v);
            path.push_back(v);
            reverse(all(path));
            for(auto& u : path)cout<<u<<" ";
            cout<<endl;
            exit(0);
        }   
        if(!any)break;
    }
    cout<<"NO"<<endl;
    return 0;
}


