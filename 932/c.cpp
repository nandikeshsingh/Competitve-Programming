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
        int n,l;
        cin>>n>>l;
        vector<pair<int,int>>vec;//b,a;
        for(int i=0;i<n;i++)
        {
            int a,b;cin>>a>>b;
            vec.push_back({b,a});
        }
        sort(all(vec));
        int ans=0;
        for(int i=0;i<n;i++)
        {
            multiset<int>mst;
            int sum=0;
            for(int j=i;j<n;j++)
            {
                sum+=vec[j].second;
                mst.insert(vec[j].second);
                while(sz(mst) && l+vec[i].first-vec[j].first<sum)
                {
                    sum-=*prev(mst.end());
                    mst.erase(prev(mst.end()));
                }
                ans=max(ans,sz(mst));
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}


