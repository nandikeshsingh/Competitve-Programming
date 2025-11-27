#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
using namespace std;
vector<int>a;
int n,k;
vector<vector<int>>dp;
int get(int idx,int f)
{ 
    if(f>=30)return 0;//pruning
    if(idx>=n)return 0;//base case
    if(dp[idx][f]!=-1)return dp[idx][f];//caching 
    return dp[idx][f]=max((a[idx]/(1LL<<f))-k+get(idx+1,f),((a[idx]/(1LL<<f))/2)+get(idx+1,f+1));//compute,save and return 
}
signed main()
{
    speed;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        // a.resize(n+2,0);
        a.resize(n,0);
        for(int i=0;i<n;i++)cin>>a[i];
        dp.resize(n,vector<int>(31,-1));
        cout<<get(0,0)<<endl;
        dp.clear();
        // vector<int>sum(n+1,0);
        // for(int i=n-1;i>=0;i--)
        // {
        //     sum[i]=(a[i]/2)+(sum[i+1]/2);
        // }
        // int ans=-1e18;
        // int all=0;
        // for(int i=1;i<=n+1;i++)
        // {
        //     int cur=2;
        //     int tot=0;
        //     for(int j=i;j<=min(i+35,n);j++)
        //     {
        //         // if((a[j]/cur)==0)break;
        //         tot+=(a[j]/cur);
        //         cur*=2;
        //     }
        //     ans=max(ans,tot-(i-1)*k+all);
        //     all+=a[i];
        // }
        // cout<<ans<<endl;
    }   
    return 0;
}


//for any dp problem just write the recursion
//then try to memoize
//if the constraint size are too big and is not possible to make the dp table 
//then some prunning must be done to reduce the size of the constraints and for this you have to make some observations.






// LH direction indicator tell-tale (green) - Functional TRM Requirements (update to match .proto file)
// RH direction indicator tell-tale (green) - Functional TRM Requirements (update to match .proto file)