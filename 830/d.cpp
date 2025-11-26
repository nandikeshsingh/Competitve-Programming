#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
signed main()
{
    speed;
    int q;
    cin>>q;
    set<int>st;
    st.insert(0);
    map<int,int>mp;
    while (q--)
    {
        char c;
        cin>>c;
        if(c=='+')
        {
            int x;
            cin>>x;
            st.insert(x);
        }
        else 
        {
            int k;cin>>k;
            int cur=mp[k];
            while (st.count(cur))
            {
                cur+=k;
            }
            cout<<cur<<endl;
            mp[k]=cur;
        }
    }
    return 0;
}
 