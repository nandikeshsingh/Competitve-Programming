#include<bits/stdc++.h>
using namespace std;
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
signed main()
{
    speed;
    int q;
    cin>>q;
    set<int>st;
    st.insert(0);
    map<int,int>mp;
    map<int,set<int>>tot,gap;
    while(q--)
    {
        char ch;
        cin>>ch;
        if(ch=='+')
        {
            int x;
            cin>>x;
            st.insert(x);
            for(auto& u: tot[x])
            {
                gap[u].erase(x);
            }
        }
        else if(ch=='-')
        {
            int x;cin>>x;
            st.erase(x);
            for(auto& u : tot[x])
            {
                gap[u].insert(x);
            }
        }
        else 
        {
            int k;cin>>k;
            if(sz(gap[k]))
            {
                cout<<*gap[k].begin()<<endl;
            }
            else 
            {
                int cur=mp[k];
                while(st.count(cur))
                {
                    tot[cur].insert(k);
                    cur+=k;
                }
                mp[k]=cur;
                cout<<mp[k]<<endl;
            }
        }
    }
    return 0;
}
//45 and 54