#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
int find(int tot,int i,int m)
{
    int lo=1,hi=m;
    while(lo<hi)
    {
        int t=(lo+hi)>>1;
        if((t+(t/2)*i)>=tot)hi=t;
        else lo=t+1;
    }
    return lo;
    // return ceil((double)tot/(double)(1.0+(double)(i/2.0)));
}
signed main()
{
    speed;
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector<int>vec(m);
        vector<int>cnt(n+1,0);
        for(int i=0;i<m;i++)
        {
            cin>>vec[i];
            cnt[vec[i]]++;
        }
        sort(cnt.begin(),cnt.end());
        int ans=0;
        int lo=1,hi=m;
        while(lo<hi)
        {
            int t=(lo+hi)>>1;
            int cur=0;
            int rim=0;
            for(int i=1;i<=n;i++)
            {
                if(cnt[i]<=t)
                {
                    cur+=((t-cnt[i])/2);
                }
                else rim+=(cnt[i]-t);
            }
            // cout<<"t="<<t<<" cur="<<cur<<" rim="<<rim<<endl;
            if(cur>=rim)hi=t;
            else lo=t+1;

        }
        cout<<lo<<endl;
        // for(int i=1;i<=n;i++)
        // {
        //     cnt[i]-=ans;
        //     if(cnt[i]>0)
        //     ans+=find(cnt[i],i-1,m);
        // }
        // cout<<ans<<endl;
    }
    return 0;
}

