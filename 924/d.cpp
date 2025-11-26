#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
int nc2(int n,int r)
{
    return (n*(n-1))/2;
}
signed main()
{
    speed;
    int t;
    cin>>t;
    while(t--)
    {
        int n,b,x;
        cin>>n>>b>>x;
        vector<int>c(n);
        int mx=0;
        for(int i=0;i<n;i++)
        {
            cin>>c[i];
            mx=max(mx,c[i]);
        }
        vector<int>len(mx+1,0);
        vector<int>vec(mx+1,0);
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<=c[i];j++)
            {
                int ans=0;
                int cur=c[i];
                int tot=nc2(cur,2);
                ans+=(tot*b);
                int bb=(cur/j);
                int cnt=cur%j;
                ans-=(nc2(bb,2)*(j-cnt))*b;
                ans-=(nc2(bb+1,2)*(cnt))*b;
                len[j]+=ans;
                if(j==c[i])vec[j]+=ans;
            }
        }
        for(int i=1;i<=mx;i++)vec[i]+=vec[i-1];
        int ans=0;
        for(int i=1;i<=mx;i++)
        {
            len[i]+=vec[i-1];
            ans=max(ans,len[i]-(i-1)*x);
        }
        cout<<ans<<endl;
    }
    return 0;
}


