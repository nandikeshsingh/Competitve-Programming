#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
const int mod=998244353;
signed main()
{
    speed;
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector<int>a(n),b(n);
        for(int i=0;i<n;i++)cin>>a[i];
        b[0]=1;
        for(int i=1;i<n;i++)
        {
            if(a[i-1]%a[i]!=0)
            {
                b[i]=0;
                break;
            }
            // else if(a[i-1]==a[i])
            // {
                // b[i]=(m/a[i])%mod;
            // }
            else 
            {
                int num=a[i-1]/a[i];
                vector<int>fac;
                for(int d=2;d*d<=num;d++)
                {
                    if(num%d==0)
                    {
                        fac.push_back(d);
                        while(num%d==0)num/=d;
                    }
                }
                if(num>1)fac.push_back(num);
                int len=sz(fac);
                int tot=0;
                for(int mask=0;mask<(1<<len);mask++)
                {
                    int sign=1;
                    int val=1;
                    for(int j=0;j<len;j++)
                    {
                        
                        if(mask&(1<<j))
                        {
                            sign*=-1;
                            val=(val*fac[j]);
                        }
                        
                    }
                    tot=(tot+sign*((m/a[i])/val));
                }
                
                b[i]=tot;
            }
        }
        int ans=1;
        for(int i=0;i<n;i++)ans=(ans*b[i])%mod;
        cout<<ans<<endl;
    }
    return 0;
}


