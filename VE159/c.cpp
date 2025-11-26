#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
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
        set<int>st;
        int g=0;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            st.insert(a[i]);
        }
        if(n==1)
        {
            cout<<1<<endl;
            continue;
        }
        sort(all(a));
        for(int i=1;i<n;i++)
        {
            g=__gcd(g,a[i]-a[i-1]);
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            ans+=((a[n-1]-a[i])/g);
        }
        int cur=a[n-1]-g;
        while(st.count(cur))
        {
            cur-=g;
        }
        ans+=min((a[n-1]-cur)/g,n);
        cout<<ans<<endl;
    }
    return 0;
}


