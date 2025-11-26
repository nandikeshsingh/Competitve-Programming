#include<bits/stdc++.h>
// #define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
using namespace std;
const int mod=998244353;
signed main()
{
    speed;
    int n,k;
    cin>>n>>k;
    int mx=sqrt(2*n);
    // cout<<"mx="<<mx<<endl;
    vector<int>dp(n+1,0);
    dp[0]=1;
    for(int i=k;i<=n;i++)dp[i]+=dp[i-k];
    dp[0]=0;
    // cout<<"Printing dp"<<endl;
    // for(int i=1;i<=n;i++)cout<<dp[i]<<" ";
    // cout<<endl;
    vector<int>ctemp=dp;
    //ctemp is the last array and temp is the current array and dp stores the answer i.e. sum of all values in a column.
    for(int jump=1;jump<=mx;jump++)
    {
        vector<int>temp(n+1,0);
        // if(jump==0)temp[0]=1;
        // vector<int>has=temp;
        for(int cur=k+jump;cur<=n;cur++)temp[cur]=(ctemp[cur-k-jump]+temp[cur-k-jump])%mod;
        // if(jump==0)dp=temp,dp[0]=0;
        // else 
        {
            for(int i=0;i<=n;i++)
            {
                dp[i]+=(temp[i]);
                dp[i]%=mod;
            }
        }
        // cout<<"Printing temp"<<endl;
        // for(int i=1;i<=n;i++)cout<<temp[i]<<" ";
        // cout<<endl;
        // cout<<"Printing dp"<<endl;
        // for(int i=1;i<=n;i++)cout<<dp[i]<<" ";
        // cout<<endl;
        ctemp.clear();
        ctemp=temp;
        // temp.resize(n+1,0);
        // temp=dp
    }
    for(int i=1;i<=n;i++)cout<<dp[i]<<" ";
    cout<<endl;
    return 0;
}