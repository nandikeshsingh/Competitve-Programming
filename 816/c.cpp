#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
using namespace std;
signed main()
{
    speed;
    int n,m;
    cin>>n>>m;
    vector<int>a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    vector<int>dp(n,0);
    // dp[0]=0;
    int ans=0;
    for(int i=1;i<n;i++)
    {
        if(a[i]!=a[i-1])
        ans+=i*(n-i);
    }
    ans+=(n*(n+1))/2;
    // for(int i=0;i<n;i++)
    // {
    //     if(i==0)
    //     {
    //         dp[i]=1;
    //         ans+=1;
    //         continue;
    //     }
    //     if(a[i]!=a[i-1])dp[i]+=(dp[i-1]+i+1);
    //     else dp[i]=dp[i-1]+1;
    //     ans+=dp[i];
    // }
    // cout<<"ans="<<ans<<endl;
    while(m--)
    {
        int id,x;
        cin>>id>>x;
        id--;
        if(a[id]==x)
        {
            a[id]=x;
            cout<<ans<<endl;
            continue;
        }
        if(n==1)
        {
            a[id]=x;
            cout<<1<<endl;
            continue;
        }
        else if(n==2)
        {
            a[id]=x;
            if(a[0]!=a[1])cout<<4<<endl;
            else cout<<3<<endl;
        }
        if(id==0)
        {
            if(a[id]==a[id+1] && x!=a[id+1])ans+=(n-1-id);
            if(a[id]!=a[id+1] && x==a[id+1])ans-=(n-1-id);
        }
        else if(id==n-1)
        {
            if(a[id]==a[id-1] && x!=a[id-1])ans+=id;
            if(a[id]!=a[id-1] && x==a[id-1])ans-=id;
        }
        else 
        {
            if(a[id]==a[id-1] && a[id]==a[id+1])ans+=((2*(id)*(n-id-1))+id+n-1-id);
            else if(a[id-1]==a[id+1] && a[id]!=a[id-1])
            {
                if(x==a[id-1])
                {
                    ans-=id;
                    ans-=(n-1-id);
                    ans-=(2*(id)*(n-1-id));
                }
            }
            else if(a[id]==a[id-1] && a[id]!=a[id+1] && x==a[id+1])
            {
                ans+=id;
                ans-=(n-1-id);
            }
            else if(a[id]==a[id+1] && a[id+1]!=a[id-1] && x==a[id-1])
            {
                ans-=id;
                ans+=(n-1-id);
            }
            else if((a[id]==a[id-1] && a[id-1]!=a[id+1]) && x!=a[id-1] && x!=a[id+1] )
            {
                ans+=id;
                ans+=((n-1-id)*id);
            }
            else if((a[id]==a[id+1] && a[id+1]!=a[id-1]) && x!=a[id-1] && x!=a[id+1])
            {
                ans+=(n-1-id);
                ans+=((n-1-id)*id);
            }
            else if(a[id-1]!=a[id+1] && a[id]!=a[id-1] && a[id]!=a[id+1])
            {
                if(x==a[id-1])
                {
                    ans-=id;
                    ans-=(id*(n-1-id));
                }
                else if(x==a[id+1])
                {
                    ans-=(n-1-id);
                    ans-=(id*(n-1-id));
                }
            }
        }
        a[id]=x;
        cout<<ans<<endl;
    }
    return 0;
}


