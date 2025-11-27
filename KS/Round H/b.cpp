#include<bits/stdc++.h>
using namespace std;
#define all(v) v.begin(),v.end()
#define int long long
#define sz(v) (int)v.size()
signed main()
{
    int t;
    cin>>t;
    for(int c=1;c<=t;c++)
    {
        int l;
        cin>>l;
        vector<int>dp(l+1,1e18);
        dp[0]=0;
        for(int i=1;i<=l;i++)
        {
            dp[i]=min(dp[i],dp[i-1]+1);
            int cur=i+i;
            int add=i;
            bool f=1;
            int val=dp[i];
            while(cur<=l)
            {
                if(f)
                {
                    val+=6;
                    dp[cur]=min(dp[cur],val);
                    f=0;
                
                    // if(dp[cur]>=dp[cur-add]+6)
                    // {
                    //     dp[cur]=dp[cur-add]+6;
                    //     f=0;
                    // }
                    // else break;
                }
                else 
                {
                    val+=2;
                    dp[cur]=min(dp[cur],val);
                }
                cur+=add;
                
            }
        }
        // cout<<"Printing dp"<<endl;
        // for(int i=1;i<=l;i++)cout<<dp[i]<<" ";
        // cout<<endl;
        cout<<"Case #"<<c<<": "<<dp[l]<<endl;
    }
    return 0;
}

