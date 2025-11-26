#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
using namespace std;
//answer will never be more than n.
signed main()
{
    speed;
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>a(n+1,0);
        for(int i=1;i<=n;i++)cin>>a[i];
        int ans=n-1;
        set<int>st;
        int cur=0;
        for(int i=1;i<=n;i++)
        {
            cur^=a[i];
            if(st.count(cur))ans--;
            st.insert(cur);
        }
        cout<<ans<<endl;
    }
    return 0;
}

