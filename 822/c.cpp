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
        string T;
        cin>>T;
        set<int>t;
        // set<int>s;
        for(int i=1;i<=n;i++)
        {
            if(T[i-1]=='1')t.insert(i);
            // s.insert(i);
        }
        int ans=0;
        vector<bool>vis(n+1);
        for(int i=1;i<=n;i++)
        {
            int k=i;
            int kk=k;
            while(t.count(k)==0 && k<=n)
            {
                if(!vis[k])
                ans+=kk;
                vis[k]=1;
                k+=kk;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
