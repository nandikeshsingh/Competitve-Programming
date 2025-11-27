#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
using namespace std;
signed main()
{
    speed;
    int n,xx;
    cin>>n>>xx;
    vector<int>a(n+1,0LL);
    for(int i=1;i<=n;i++)cin>>a[i];
    vector<int>pre(n+1,0LL);
    for(int i=1;i<=n;i++)pre[i]=pre[i-1]+a[i];
    vector<int>x(n+2,0LL),y(n+2,0LL);
    int cur=0LL;
    for(int i=1;i<=n;i++)
    {
        cur=min(cur,pre[i]);
        x[i]=pre[i]-cur;
    }
    cur=pre[n];
    for(int i=n;i>=1;i--)
    {
        cur=max(cur,pre[i]);
        y[i]=max(cur-pre[i-1],0LL);
    }
    cur=0LL;
    int ans=0LL;
    for(int i=1;i<=n;i++)
    {
         cur=max(cur,x[i]-xx*pre[i]);
        ans=max(ans,cur+y[i+1]+xx*pre[i]);
       
    }
    cout<<ans<<endl;
    return 0;
}
