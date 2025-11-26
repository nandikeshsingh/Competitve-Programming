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
        int n,k;
        cin>>n>>k;
        vector<int>a(n);
        vector<vector<int>>vec(k,vector<int>(0));
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            vec[i%k].push_back(a[i]);
        }
        for(auto& u : vec)
        {
            sort(all(u));
        }
        int ans=0;
        int s=0,e=k-1;
        while(e<n)
        {
            vector<vector<int>>cvec=vec;
            int cur=0;
            for(int i=s;i<=e;i++)
            {
                cur+=cvec[i%k].back();
                cvec[i%k].pop_back();
            }
            ans=max(ans,cur);
            s++,e++;
        }
        cout<<ans<<endl;
    }
    return 0;
}


