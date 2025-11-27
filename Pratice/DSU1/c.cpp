#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
using namespace std;
const int maxn=1e5+10;
int bit[maxn][12];
void update(int x,int val,int pos)
{
    for(int i=x;i<maxn;i+=(i&(-i)))
    bit[i][pos]+=val;
}
int query(int x,int pos)
{
    int ret=0;
    for(int i=x;i>0;i-=(i&(-i)))
    ret+=bit[i][pos];
    return ret;
}
signed main()
{
    speed;
    int n,k;
    cin>>n>>k;
    vector<int>vec(n+1);
    for(int i=1;i<=n;i++)cin>>vec[i];
    vector<vector<int>>dp(n+3,vector<int>(k+5,0));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=k+1;j++)
        {
            if(j>i)break;
            if(j==1)dp[i][j]=1,update(vec[i],1,j);
            else 
            {
                dp[i][j]=query(vec[i]-1,j-1);
                update(vec[i],dp[i][j],j);
            }
        }
        // cout<<"Printing bit"<<endl;
        //    for(int i=1;i<=n;i++)
        // {
        //     for(int j=0;j<=k+1;j++)
        //     cout<<bit[i][j]<<" ";
        //     cout<<endl;
        // }     
        // cout<<"Printing dp"<<endl;
        // for(int i=1;i<=n;i++)
        // {
        //     for(int j=0;j<=k+1;j++)
        //     cout<<dp[i][j]<<" ";
        //     cout<<endl;
        // }
    }
    // for(int j=1;j<=k+1;j++)
    // {
    //     for(int i=1;i<=n;i++)
    //     {
    //         // if(j==0)dp[vec[i]][j]=0;
    //         // if(j==1)dp[vec[i]][j]=1;
    //         // else 
    //         {
                
    //             dp[vec[i]][j]=query(vec[i]-1);
    //         }
    //     }
    //     for(int i=0;i<maxn;i++)bit[i]=0;
    //     for(int i=1;i<=n;i++)
    // update(vec[i],dp[i][j]);
    //     cout<<"Printing bit"<<endl;
    //     for(int i=0;i<=n;i++)
    //     cout<<i<<" "<<bit[i]<<endl;   
    // }
    // cout<<"Printing dp"<<endl;
    // for(int i=0;i<=n;i++)
    // {
    //     for(int j=0;j<=k+1;j++)
    //     {
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // cout<<"now"<<endl;
    int ans=0;
    for(int i=1;i<=n;i++)
        ans+=dp[i][k+1];
        cout<<ans<<endl;
    return 0;
}
