#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
using namespace std;
signed main()
{
    speed;
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>a(n);
        for(int i=0;i<n;i++)cin>>a[i];
        vector<int>dp(n,1);
        // dp[0]=1;
        for(int i=0;i<n;i++)
        {
            int last=max(i-515,0LL);
            for(int j=last;j<i;j++)
            {
                if((j^a[i])>(i^a[j]))dp[i]=max(dp[i],dp[j]+1);
            }
        }
        cout<<*max_element(all(dp))<<endl;
    }
    return 0;
}
