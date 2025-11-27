#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
using namespace std;
const int maxn=5001;
string n,m;
int dp[maxn][maxn];
int get(int i,int j)
{
    if(i==-1 && j==-1)return 0;
    else if(i!=-1 && j==-1)return i+1;
    else if(i==-1 && j!=-1)return j+1;
    if(dp[i][j]!=-1)return dp[i][j];
    int ans=1e18;
    ans=min({ans,1+get(i,j-1),1+get(i-1,j)});
    if(n[i]==m[j])
    ans=min(ans,get(i-1,j-1));
    else ans=min(ans,1+get(i-1,j-1));
    return dp[i][j]=ans;
}
signed main()
{
    speed;
    for(int i=0;i<maxn;i++)
    for(int j=0;j<maxn;j++)
    dp[i][j]=-1;
    cin>>n>>m;
    cout<<get((int)n.length()-1,(int)m.length()-1)<<endl;
    return 0;
}


