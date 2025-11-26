#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
signed main()
{
    speed;
    int p;
    cin>>p;
    if(p==0)
    {
        cout<<0<<" "<<0<<endl;
        return 0;
    }
    vector<int>w(641);
    for(int i=1;i<=640;i++)
    {
        w[i]=(i*(i-1))/2;
    }
    vector<int>vec;
    vector<int>dp(p+1,1e18);
    vector<vector<int>>used(p+1);
    dp[0]=0;
    for(int i=1;i<=p;i++)
    {
        int ans=0;
        int cur=i;
        for(int j=640;j>=2;j--)
        {
            if(w[j]>cur)continue;
            else 
            {
                int d=cur/w[j];
                if(dp[cur]>dp[cur-d*w[j]]+d*j)
                {
                    dp[cur]=dp[cur-d*w[j]]+d*j;
                    used[cur].clear();
                    used[cur]=used[cur-d*w[j]];
                    for(int i=0;i<d;i++)used[cur].push_back(j);
                }
            }
        }
    }
    // sort(all(used[p]));
    int val=0;
    int sum=0;
    for(int i=0;i<sz(used[p]);i++)
    {
        val+=used[p][i]*sum;
        sum+=used[p][i];
    }
    cout<<dp[p]<<" "<<val<<endl;
    return 0;
}