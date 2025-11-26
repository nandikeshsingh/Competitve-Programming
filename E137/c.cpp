#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
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
        string s;
        cin>>s;
        int cnt=0;
        for(auto u : s)cnt+=(u=='1');
        vector<int>a(n);
        for(int i=0;i<n;i++)cin>>a[i];
        int ans=0;
        int pos=-1;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='1')ans+=a[i];
            else 
            {
                pos=i;
                break;
            }
        }
        if(pos==-1)
        {
            cout<<ans<<endl;
            continue;
        }
        for(int i=pos;i<n;)
        {
            if(s[i]=='0' && s[i+1]=='1')
            {
                int sum=0;
                int mn=1e18;
                for(int k=i;;k++)
                {
                    sum+=a[k];
                    mn=min(mn,a[k]);
                    if(s[k]=='1' && s[k+1]=='0')
                    {
                        i=k+1;
                        break;
                    }
                    else if(s[k]=='1' && k+1==n)
                    {
                        i=k+1;
                        break;
                    }
                }
                ans+=(sum-mn);
            }   
            else i++;
        }
        cout<<ans<<endl;
    }
    return 0;
}


