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
        vector<int>a(n+1,0),pre(n+1,0),cnt(n+1,0);
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int i=2;i<n;i++)
        {
            if(a[i]-a[i-1]<a[i+1]-a[i])pre[i+1]=a[i+1]-a[i],cnt[i+1]=1;
        }
        for(int i=1;i<=n;i++)pre[i]+=pre[i-1],cnt[i]+=cnt[i-1];
        vector<int>suf(n+2,0),bcnt(n+2,0);
        for(int i=n-1;i>1;i--)
        {
            if(a[i+1]-a[i]<a[i]-a[i-1])suf[i-1]=a[i]-a[i-1],bcnt[i-1]=1;
        }
        for(int i=n;i>0;i--)suf[i]+=suf[i+1],bcnt[i]+=bcnt[i+1];
        int m;cin>>m;
        while(m--)
        {
            int l,r;cin>>l>>r;
            if(l<r)
            {
                int tot=cnt[r]-cnt[l];
                cout<<pre[r]-pre[l]+(r-l-tot)<<endl;
            }
            else 
            {
                int tot=bcnt[r]-bcnt[l];
                cout<<suf[r]-suf[l]+(l-r-tot)<<endl;
            }
        }
    }
    return 0;
}

