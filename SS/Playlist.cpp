#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
using namespace std;
signed main()
{
    speed;
    int n;
    cin>>n;
    vector<int>k(n);
    for(int i=0;i<n;i++)cin>>k[i];
    set<int>st;
    int l=0,r=0;
    int ans=1;
    while(r<n)
    {
        if(st.count(k[r]))
        {
            st.erase(st.find(k[l++]));
        }
        else 
        {
            st.insert(k[r++]);
        }
        ans=max(ans,r-l);
    }
    ans=max(ans,r-l);
    cout<<ans<<endl;
    return 0;
}


