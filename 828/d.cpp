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
        vector<int>a(n);
        for(int i=0;i<n;i++)cin>>a[i];
        int cur=0;
        for(int i=0;i<n;i++)
        {
            int now=a[i];
            while(now%2==0)
            {
                now/=2;
                cur++;
            }
        }
        if(cur>=n)cout<<0<<endl;
        else 
        {
            int tot=0;
            vector<int>has;
            for(int i=1;i<=n;i++)
            {
                int now=i;
                int cnt=0;
                while(now%2==0)
                {
                    now/=2;
                    cnt++;
                }
                tot+=cnt;
                if(cnt)
                has.push_back(cnt);
            }
            int need=n-cur;
            if(need>tot)cout<<-1<<endl;
            else 
            {
                int ans=0;
                sort(all(has));
                for(int i=sz(has)-1;i>=0;i--)
                {
                    if(need>=has[i])
                    {
                        need-=has[i];
                        ans++;
                    }
                }
                cout<<ans<<endl;
            }
        }
    }
    return 0;
}


