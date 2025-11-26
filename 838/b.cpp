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
        vector<int>a(n);
        vector<pair<int,int>>vec;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            vec.push_back({a[i],i+1});
        }
        sort(all(vec));
        vector<pair<int,int>>ans;
        for(int i=1;i<n;i++)
        {
            int last=vec[i-1].first;
            int cur=vec[i].first;
            int need=last-(cur%last);
            vec[i].first+=need;
            ans.push_back({vec[i].second,need});
        }
        cout<<sz(ans)<<endl;
        for(auto& u : ans)cout<<u.first<<" "<<u.second<<endl;
    }
    return 0;
}


