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
        int n,k;
        cin>>n>>k;
        vector<int>a(n);
        int tot=0;
        for(int i=0;i<n;i++)cin>>a[i],tot+=a[i];
        if(tot<=k)
        {
            cout<<n<<endl;
            continue;
        }
        int s=0,e=0;
        if(k%2)
        {
            s=(k/2)+1;e=(k/2);
        }
        else 
        {
            s=(k/2);e=(k/2);
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(a[i]<=s)
            {
                ans++;
                s-=a[i];
                a[i]=0;
            }
            else 
            {
                a[i]-=s;
                s=0;
            }
            if(s==0)break;
        }
        for(int i=n-1;i>=0;i--)
        {
            if(a[i]<=e)
            {
                ans++;
                e-=a[i];
                a[i]=0;
            }
            else 
            {
                a[i]-=e;
                e=0;
            }
            if(e==0)break;
        }
        cout<<ans<<endl;
    }
    return 0;
}


