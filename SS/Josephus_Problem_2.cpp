#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
signed main()
{
    speed;
    int n,k;
    cin>>n>>k;
    ordered_set st;
    for(int i=1;i<=n;i++)
    st.insert(i-1);
    int cur=0;
    while(st.size()>0)
    {
        // cout<<"Printing set"<<endl;
        // for(int i=0;i<st.size();i++)
        // cout<<*st.find_by_order(i)<<" ";
        // cout<<endl;
        cur+=k;
        cur%=st.size();
        auto val=st.find_by_order(cur);
        cout<<*val+1<<" ";
        st.erase(val);
    }
    cout<<endl;
    return 0;
}
