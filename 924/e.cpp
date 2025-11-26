#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
int nc2(int n)
{
    return n*(n-1)/2;
}
signed main()
{
    speed;
    int t;cin>>t;
    vector<int>dp(2e5+5,1e18);
    dp[0]=0;
    for(int i=1;i<=2e5+4;i++)
    {
        for(int l=1;nc2(l+1)<=i;l++)
        {
            dp[i]=min(dp[i],dp[i-nc2(l+1)]+l+1);
        }
    }
    while(t--)
    {
        bool ok=0;
        int n,x,y,s;
        cin>>n>>x>>y>>s;
        for(int i=0;i<n;i++)
        {
            int tot=x*(i+1)+nc2(i+1)*y;
            if(tot>s)continue;
            int rim=s-tot;
            rim-=(x%y)*(n-i-1);
            if(rim<0)continue;
            if((rim%y)!=0)continue;
            rim/=y;
            if(dp[rim]<=n-i-1)
            {
                vector<int>ans(n,0);
                ans[0]=x;
                for(int j=1;j<=i;j++)ans[j]=ans[j-1]+y;
                for(int j=i+1;j<n;j++)ans[j]+=(x%y);
                vector<int>vec;
                while(rim>0)
                {
                    // cout<<"cur="<<cur<<endl;
                    for(int l=2;l<=dp[rim];l++)
                    {
                        if(dp[rim]==dp[rim-nc2(l)]+l)
                        {
                            vec.push_back(l);
                            rim-=nc2(l);
                            break;
                        }
                    }
                }
                int last=i+1;
                for(auto& len : vec)
                {
                    for(int k=0;k<len;k++)
                    {
                        ans[last]+=k*y;
                        last++;
                    }
                }
                ok=1;
                cout<<"YES"<<endl;
                for(auto& u : ans)cout<<u<<" ";
                cout<<endl;
                break;
            }
        }
        if(!ok)
        cout<<"NO"<<endl;
    }
    return 0;
}


