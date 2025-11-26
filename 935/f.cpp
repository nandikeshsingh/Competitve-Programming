#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
#define ordered_set tree<pair<int,int>, null_type,less<pair<int,int>>, rb_tree_tag,tree_order_statistics_node_update>
signed main()
{
    speed;
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>a(n+1,0),p(n+1,0);
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int i=1;i<=n;i++)cin>>p[i];
        int ans=-1e18;
        ordered_set mst;
        for(int i=1;i<=n;i++)
        {
            mst.insert({a[i],p[i]});
        }
        int tot=0;
        for(int i=1;i<=n;i++)
        {
            if(sz(mst)>=i)
            {
                pair<int,int>pp=*mst.find_by_order(sz(mst)-i);
                if(pp.first*i>ans)
                {
                    ans=pp.first*i;
                    tot=i;
                }
                mst.erase({a[p[i]],p[p[i]]});
            }
 
        }
        cout<<ans<<"  "<<tot<<endl;
    }
    return 0;
}
 