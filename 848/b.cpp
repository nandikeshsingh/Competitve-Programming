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
        int n,m,d;
        cin>>n>>m>>d;
        vector<int>p(n+1),a(m+1);
        map<int,int>pos;
        for(int i=1;i<=n;i++)
        {
            cin>>p[i];
            pos[p[i]]=i;
        }
        for(int i=1;i<=m;i++)cin>>a[i];
        int ans=1e18;
        for(int i=2;i<=m;i++)
        {
            int lo=pos[a[i-1]];
            int hi=min(lo+d,n);
            int cur=pos[a[i]];
            if(cur<lo || cur>hi)
            {
                ans=min(ans,0LL);
                break;
            }
            else 
            {
                ans=min(ans,cur-lo);

                if(hi+1<=n)
                ans=min(ans,hi-cur+1);
                if(lo>lo+d-hi+1)
                ans=min(ans,lo+d-cur+1);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}


