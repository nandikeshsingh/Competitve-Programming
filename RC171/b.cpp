#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
const int mod=998244353;
signed main()
{
    speed;
    int n;
    cin>>n;
    vector<int>a(n+1);
    bool ok=1;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]<i)ok=0;
    }
    for(int i=1;i<=n;i++)
    {
        if(a[a[i]]!=a[i])ok=0;
    }
    if(!ok)cout<<0<<endl;
    else 
    {
        int ans=1;
        vector<int>val(n+1,0);
        for(int i=n;i>=1;i--)
        {
            if(a[i]>i)
            {
                if(val[a[i]]==0)val[a[i]]=i;
                else 
                {
                    int temp=val[a[i]];
                    val[a[i]]=i;
                    a[i]=temp;
                }
            }
        }
        ordered_set st;
        for(int i=1;i<=n;i++)st.insert(i);
        for(int i=1;i<=n;i++)
        {
            if(a[i]>i)st.erase(st.find(a[i]));
        }
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i]==i)
            {
                ans*=(st.order_of_key(i+1)-cnt++);
                ans%=mod;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}


