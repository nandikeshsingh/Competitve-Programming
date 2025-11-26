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
        cin>>n;vector<int>a(n);
        for(int i=0;i<n;i++)cin>>a[i];
        int ans=1e18;
        int v=a[0];
        int cur=0;
        for(int i=0;i<n;i++)
        {
            if(a[i]==v)cur++;
            else 
            {
                ans=min(ans,cur);
                cur=0;
            }
        }
        ans=min(ans,cur);
        if(ans==n)ans=-1;
        cout<<ans<<endl;
    }
    return 0;
}


