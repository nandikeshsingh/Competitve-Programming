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
    int n,q;
    cin>>n>>q;
    ordered_set st;
    vector<int>p(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>p[i];
        st.insert({p[i],i});
    }
    while(q--)
    {
        char c;cin>>c;
        if(c=='?')
        {
            int a,b;
            cin>>a>>b;
            cout<<st.order_of_key({b+1,-1e18})-st.order_of_key({a,-1e18})<<endl;
        }
        else 
        {
            int k,x;
            cin>>k>>x;
            st.erase(st.find({p[k],k}));
            p[k]=x;
            st.insert({p[k],k});
        }
    }
    return 0;
}

