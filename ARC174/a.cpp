#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
signed main()
{
    speed;
    int n,c;
    cin>>n>>c;
    vector<int>a(n+1,0);
    int tot=0;
    for(int i=1;i<=n;i++)cin>>a[i],tot+=a[i];
    int mn=0;
    int cur=0;
    int best_mx=-1e18;
    for(int i=1;i<=n;i++)
    {
        cur+=a[i];
        mn=min(mn,cur);
        best_mx=max(best_mx,cur-mn);
    }
    int mx=0;
    cur=0;
    int best_mn=1e18;
    for(int i=1;i<=n;i++)
    {
        cur+=a[i];
        mx=max(mx,cur);
        best_mn=min(best_mn,cur-mx);
    }
    if(c==0)
    {
        if(best_mn>=0)cout<<tot<<endl;
        else cout<<tot-best_mn<<endl;
    }
    else if(c>0)
    {
        if(best_mx>=0)cout<<tot-best_mx+best_mx*c<<endl;
        else cout<<tot<<endl;
    }
    else if(c<0)
    {
        if(best_mn<=0)cout<<tot-best_mn+best_mn*c<<endl;
        else cout<<tot<<endl;
    }
    return 0;
}


