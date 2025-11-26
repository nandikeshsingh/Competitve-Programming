#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
const int mod=998244353;
signed main()
{
    speed;
    int t;
    cin>>t;
    while(t--)
    {
        int n,s;
        cin>>n>>s;
        int tot=0;
        vector<int>a(n);
        for(int i=0;i<n;i++)cin>>a[i];
        vector<int>b(n);
        for(int i=0;i<n;i++)cin>>b[i];
        int ans=1;
        map<int,int>mp1,mp2;
        for(int i=0;i<n;i++)
        {
            mp1[a[i]]=i;
        }
        for(int i=0;i<n;i++)
        {
            if(b[i]==-1)tot++;
            else mp2[b[i]]=i;
        }
        int cur=0;
        for(int i=1;i<=n;i++)
        {
            if(mp2.find(i)==mp2.end())
            {
                ans=(ans*tot)%mod;
                tot--;
            }
            else 
            {
                if(abs(mp1[i]-mp2[i])>s)
                {
                    ans=0;
                    break;
                }
            }
        }
        cout<<"Printing"<<endl;
        cout<<ans<<endl;
    }
    return 0;
}

