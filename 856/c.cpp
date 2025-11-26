#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
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
        vector<int>a(n);
        for(int i=0;i<n;i++)cin>>a[i];
        ordered_set st;
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            st.insert({a[i],i+1});
            int lo=0,hi=i;
            while(lo<hi)
            {
                int mid=(lo+hi)>>1;
                auto it=st.find_by_order(mid);
                if(it->first>=(i+2-(it->second)))hi=mid;
                else lo=mid+1;
            }
            ans.push_back(i-lo+1);
        }
        for(auto& u : ans)cout<<u<<" ";
        cout<<endl;
    }
    return 0;
}


