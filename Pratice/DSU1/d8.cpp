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
        int n,m;
        cin>>n>>m;
        vector<int>a(m);
        int sum=0;
        for(int i=0;i<m;i++)cin>>a[i],sum+=a[i];
        if(sum<n)
        {
            cout<<-1<<endl;
            continue;
        }
        else if(sum==n)
        {
            cout<<0<<endl;
            continue;
        }
        int cnt[62]={0};
        for(int i=0;i<m;i++)
        {
            int res=0;
            while(a[i]>1)
            {
                res++;
                a[i]/=2;
            }
            cnt[res]++;
        }
        int ans=0;
        for(int i=0;i<61;i++)
        {
            if((1LL<<i)&n)
            {
                if(cnt[i]>0)cnt[i]--;
                else 
                {
                    int j=i+1;
                    while(cnt[j]==0)j++;
                    cnt[j]--;
                    --j;
                    while(j>=i)
                    {
                        cnt[j]++;
                        ans++;
                        j--;
                    }
                    cnt[i]--;
                }
            }
            cnt[i+1]+=cnt[i]/2;
        }
        cout<<ans<<endl;
    }
    return 0;
}
