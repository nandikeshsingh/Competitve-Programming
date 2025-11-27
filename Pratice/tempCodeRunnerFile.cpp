#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
using namespace std;
vector<int>a;
int n,k;
// int dp[][2];
// int get(int idx,int f)
// {
//     if(idx>=n)return 0;

//     return max((a[idx]/(1LL<<f))-k+get(idx+1,f),((a[idx]/(1LL<<f))/2)+get(idx+1,f+1));
// }
signed main()
{
    speed;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        a.resize(n+2,0);
        for(int i=1;i<=n;i++)cin>>a[i];
        // vector<int>sum(n+1,0);
        // for(int i=n-1;i>=0;i--)
        // {
        //     sum[i]=(a[i]/2)+(sum[i+1]/2);
        // }
        int ans=-1e18;
        int all=0;
        for(int i=1;i<=n+1;i++)
        {
            int cur=2;
            int tot=0;
            for(int j=i;j<=n;j++)
            {
                if(a[j]/cur==0)break;
                tot+=(a[j]/cur);
                cur*=2;
            }
            ans=max(ans,tot-(i-1)*k+all);
            all+=a[i];
        }
        cout<<ans<<endl;
    }   
    return 0;
}
