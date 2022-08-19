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
    int n,t;
    cin>>n>>t;
    vector<int>vec(n+1,0),pre(n+1,0);
    for(int i=1;i<=n;i++)
    {
        cin>>vec[i];
        pre[i]=vec[i]+pre[i-1];
    }
    int ans=0;
    ordered_set st;
    st.insert({0,0});
    for(int i=1;i<=n;i++)
    {
        int rim=st.order_of_key({pre[i]-t+1,-1});
        ans+=((int)st.size()-rim);
        st.insert({pre[i],i});
    }
    // for(int i=0;i<=n;i++)
    // {
    //     auto it=st.find_by_order(i);
    //     cout<<it->first<<" "<<it->second<<endl;
    // }
    cout<<ans<<endl;
    return 0;
}

//The above implementation is PBDS on multiset for using it as set replace pair<int,int>(to store {value,index}) with int.
//st.order_of_key(k) returns the number of element strictly lesser than k and if a pair<int,int> is used then it compares first based on the first value in pair and if
//first value is same in the pair then it compares with the second value.
//st.find_by_order(k) returns an iteratore to the K-th element in the set (counting from zero).
