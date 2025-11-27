#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
string t;
int n;
vector<vector<string>>vec;
int dp[110][110];
int get(int i,int j)
{
    if(i<0 && j>=0)return 1e18;
    if(i<0 && j<0)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    int ret=1e18;
    for(auto& s : vec[i])
    {
        bool ok=1;
        int pos=j;
        for(int k=sz(s)-1;k>=0;k--)
        {
            if(t[pos]==s[k])pos--;
            else 
            {
                ok=0;
                break;
            }
        }
        if(ok)
        ret=min(ret,1+get(i-1,pos));
    }
    ret=min(ret,get(i-1,j));
    return dp[i][j]=ret;
}
signed main()
{
    speed;
    cin>>t;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int a;cin>>a;
        vector<string>temp;
        for(int j=0;j<a;j++)
        {
            string x;cin>>x;
            temp.push_back(x);
        }
        vec.push_back(temp);
    }
    for(int i=0;i<110;i++)for(int j=0;j<110;j++)dp[i][j]=-1;
    int ans=get(n-1,sz(t)-1);
    if(ans>=1e18/2)ans=-1;
    cout<<ans<<endl;
    return 0;
}


