#include<bits/stdc++.h>
// #define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
using namespace std;
string s;
vector<vector<int>>dp;
int can(int l,int r)
{
    if(l+1==r)
    {
        if(s[l]!=s[r])return 0;
        else return 0
    }
    if(dp[l][r]!=-1)return dp[l][r];
    int win=0;
    int x=can(l+1,r-1);
    int y=can(l+2,r);
    int z=can(l,r-2);
    if((y==1)&&(x==1))win=1;
    else if((z==1)&&(x==1))win=1;
    else 
    {
        if(s[l]!=s[r])win=1;
    }
    return dp[l][r]=win;
}
signed main()
{
    speed;
    int t;
    cin>>t;
    while(t--)
    {
        s.clear();
        cin>>s;
        int n=(int)s.length();
        dp.clear();
        dp.resize(n,vector<int>(n));
        for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)dp[i][j]=-1;
        int ret=can(0,n-1);
        if(ret==1)cout<<"Alice"<<endl;
        else if(ret==0)cout<<"Draw"<<endl;
        // else cout<<"Bob"<<endl;
    }
    return 0;
}


