#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
vector<int>dp(20,0);
int get(int n)
{
    if(n<=9)return n;
    int ans=0;
    vector<int>vec;
    while(n)
    {
        vec.push_back(n%10);
        n/=10;
    }
    reverse(all(vec));
    int len=sz(vec);
    for(int d=1;d<len;d++)ans+=dp[d];
    for(int i=0;i<sz(vec);i++)
    {
        if(i==0)
        {
            ans+=(vec[i]-1)*dp[len-1];
        }
        else 
        {
            if(vec[i-1]<=vec[i])
            {
                int cur=vec[i]-1;
                ans+=(cur*dp[len-i-1]);
            }
            else ans+=(vec[i]*dp[len-i-1]);
        }
    }
    return ans+1;
}
bool check(int n)
{
    bool ok=1;
    vector<int>vec;
    while(n)
    {
        vec.push_back(n%10);
        n/=10;
    }
    reverse(all(vec));
    for(int i=1;i<sz(vec);i++)
    {
        if(vec[i]==vec[i-1])
        {
            ok=0;
            break;
        }
    }
    return ok;
}
signed main()
{
    speed;
    int cur=1;
    dp[0]=1;
    for(int i=1;i<20;i++)
    {
        cur*=9;
        dp[i]=cur;
    }
    int t;cin>>t;
    while(t--)
    {
        int k;cin>>k;
        int tot=0;
        vector<int>ans;
        int i=1;
        while(tot+dp[i]<k)
        {
            tot+=dp[i];
            i++;
        }
        bool f=1;
        for(int d=i;d>=1;d--)
        {
            if(f)
            {
                f=0;
                for(int v=1;v<=9;v++)
                {
                    if(tot+dp[d-1]<k)tot+=dp[d-1];
                    else 
                    {
                        ans.push_back(v);
                        break;
                    }
                }
            }
            else 
            {
                for(int v=0;v<=9;v++)
                {
                    if(v==ans.back())continue;
                    if(tot+dp[d-1]<k)tot+=dp[d-1];
                    else 
                    {
                        ans.push_back(v);
                        break;
                    }
                }
            }
        } 
                int pt=0;
        for(int i=0;i<sz(ans);i++)
        {
            pt*=10;
            pt+=ans[i];
        }
        cout<<pt<<endl;  
    }

    // cout<<get(77)<<endl;
    // cout<<get(2506230721)<<endl;
    // cout<<get(2506226300)<<endl;
    // int t;cin>>t;
    // while(t--)
    // {
    //     int k;cin>>k;
    //     int lo=1,hi=1e13;
    //     while(lo<hi)
    //     {
    //         int mid=(lo+hi)/2;
    //         // cout<<"lo="<<lo<<" hi="<<hi<<" mid="<<mid<<" "<<get(mid)<<endl;
    //         if(get(mid)>=k)hi=mid;
    //         else lo=mid+1;
    //     }
    //     while(!check(lo))lo--;
    //     cout<<lo<<endl;
    // }
    return 0;
}


