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
        bool is_sort=1;
        int cur=0;
        for(int i=1;i<=n;i++)
        {
            if(p[i]!=i)is_sort=0;
        }
        if(is_sort)
        {
            cout<<1<<endl;
            continue;
        }
        vector<vector<int>>cyc;
        vector<int>vis(n+1);
        for(int i=1;i<=n;i++)
        {
            if(vis[i])continue;
            else 
            {
                vector<int>temp;
                int cur=i;
                do
                {
                    vis[cur]=1;
                    temp.push_back(p[cur]);
                    cur=p[cur];
                } while(cur!=i);
                sort(all(temp));
                cyc.push_back(temp);
            }
        }
        int ans=0;
        bool f=0;
        for(auto& u : cyc)
        {
            if(!f)
            {
                vector<int>now=u;
                for(int i=1;i<sz(now);i++)
                {
                    if(now[i]-now[i-1]==1)
                    {
                        f=1;
                        break;
                    }
                }
                if(f)
                ans+=(sz(now)-2);
                else ans+=(sz(now)-1);
            }
            else ans+=(sz(u)-1);

        }
        if(!f)ans++;
        cout<<ans<<endl;
    }   
    return 0;
}


