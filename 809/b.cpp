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
        vector<int>c(n);
        map<int,vector<int>>mp;
        for(int i=0;i<n;i++)
        {
            cin>>c[i];
            mp[c[i]].push_back(i+1);
        }
        vector<int>ans(n+1,0);
        for(auto& u : mp)
        {
            int last=u.second[0];
            ans[u.first]++;
            for(int i=1;i<u.second.size();i++)
            {
                if((u.second[i]-last)%2)ans[u.first]++,last=u.second[i];
            }
        }
        for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
        cout<<endl;

    }
    return 0;
}