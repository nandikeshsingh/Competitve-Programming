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
        int n,k;
        cin>>n>>k;
        vector<pair<int,int>>vec;
        vector<int>a(n),b(n);
        for(int i=0;i<n;i++)cin>>a[i];
        for(int i=0;i<n;i++)cin>>b[i];
        for(int i=0;i<n;i++)vec.push_back({b[i],a[i]});
        sort(all(vec));
        reverse(all(vec));
        multiset<int>mst;
        int ans=0;
        int pos=0;
        for(int i=0;i<k;i++)pos+=vec[i].second,mst.insert(vec[i].second);
        int neg=0;
        for(int i=k;i<n;i++)
        {
            if(vec[i].first>vec[i].second)neg+=(vec[i].first-vec[i].second);
        }
        ans=max(ans,-pos+neg);
        for(int i=k;i<n;i++)
        {
           
            if(k>0 && *prev(mst.end())>vec[i].second)
            {
                pos-=*prev(mst.end());
                mst.erase(prev(mst.end()));
                mst.insert(vec[i].second);
                pos+=vec[i].second;
            }
            if(vec[i].first>vec[i].second)
            {
                neg-=(vec[i].first-vec[i].second);
            }
             ans=max(ans,-pos+neg);
        }
        cout<<ans<<endl;
 
    }
    return 0;
}
 


