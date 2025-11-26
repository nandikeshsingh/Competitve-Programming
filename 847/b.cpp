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
        int n,s,r;
        cin>>n>>s>>r;
        int rr=r;
        vector<int>ans(n-1);
        // ans[0]=s-r;
        int cur=0;
        while(r)
        {
            ans[cur]++;
            cur++;
            if(cur==n-1)cur=0;
            r--;
        }
        ans.push_back(s-rr);
        for(auto& u : ans)cout<<u<<" ";
        cout<<endl;
    }
    return 0;
}


