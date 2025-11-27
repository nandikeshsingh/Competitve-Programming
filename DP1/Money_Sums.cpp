#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
using namespace std;
vector<int>x;
set<int>ans;
int n;
bool dp[100001][101];
void go(int sum,int idx)
{
    if(sum>0)
    ans.insert(sum);
    if(idx>=n)return;
    if(dp[sum][idx])return;
    go(sum+x[idx],idx+1);
    go(sum,idx+1);
    dp[sum][idx]=1;
}
signed main()
{
    speed;
    cin>>n;
    x.resize(n);
    for(int i=0;i<n;i++)cin>>x[i];
    go(0,0);
    cout<<ans.size()<<endl;
    for(auto& u : ans)cout<<u<<" ";
    cout<<endl;
    return 0;
}


