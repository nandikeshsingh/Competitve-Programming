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
        vector<int>a(n+1),b(n+1),pre(n+1);
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int i=1;i<=n;i++)cin>>b[i];
        for(int i=1;i<=n;i++)pre[i]=pre[i-1]+b[i];
        vector<int>div(n+2),extra(n+2);
        for(int i=1;i<=n;i++)
        {
            int cur=a[i]+pre[i-1];
            int pos=upper_bound(pre.begin(),pre.end(),cur)-pre.begin();
            div[i]++;
            div[pos]--;
            int ex=a[i]-pre[pos-1]+pre[i-1];
            extra[pos]+=ex;
        }
        for(int i=1;i<=n;i++)div[i]+=div[i-1];
        for(int i=1;i<=n;i++)
        {
            cout<<div[i]*b[i]+extra[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}


