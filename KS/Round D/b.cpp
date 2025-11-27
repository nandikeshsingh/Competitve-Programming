#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    int t;
    cin>>t;
    for(int c=1;c<=t;c++)
    {
        int n;
        cin>>n;
        vector<int>a(n);
        for(int i=0;i<n;i++)cin>>a[i];
        int m;
        cin>>m;
        vector<int>b(m);
        for(int i=0;i<m;i++)cin>>b[i];
        int k;
        cin>>k;
        int cnt=0;
        for(int i=0;i<=k;i++)
        {
            int ans=0;
            int f=i,s=k-i;
            if(f>n || s>m)continue;
            else 
            {
                int len=n-f;
                // cout<<"len="<<len<<endl;
                int tot=0;
                for(int j=0;j<n;j++)tot+=a[j];
                if(len==0)
                {
                    // cout<<"i="<<i<<"->";
                    // cout<<"tot="<<tot<<endl;
                    ans+=tot;
                }
                else 
                {
                    int cur=1e18;
                    int st=0,ed=st+len-1;
                    int sum=0;
                    for(int j=st;j<=ed;j++)sum+=a[j];
                    cur=sum;
                    while(ed<n-1)
                    {
                        sum-=a[st];
                        st++;
                        ed++;
                        sum+=a[ed];
                        cur=min(cur,sum);
                    }
                    //                     cout<<"i="<<i<<"->";
                    // cout<<"tot-cur="<<tot-cur<<endl;
                    ans+=tot-cur;
                }
                 len=m-s;
                tot=0;
                // cout<<"len="<<len<<endl;
                for(int j=0;j<m;j++)tot+=b[j];
                if(len==0)
                {
                    //                     cout<<"i="<<i<<"->";
                    // cout<<"tot="<<tot<<endl;
                    ans+=tot;
                }
                else 
                {
                    int cur=1e18;
                    int st=0,ed=st+len-1;
                    int sum=0;
                    for(int j=st;j<=ed;j++)sum+=b[j];
                    cur=sum;
                    while(ed<m-1)
                    {
                        sum-=b[st];
                        st++;
                        ed++;
                        sum+=b[ed];
                        cur=min(cur,sum);
                    }
                    //                     cout<<"i="<<i<<"->";
                    // cout<<"tot-cur="<<tot-cur<<endl;
                    ans+=tot-cur;
                }
            }
            // cout<<"ans="<<ans<<endl;
            cnt=max(cnt,ans);
        }
        cout<<"Case #"<<c<<": "<<cnt<<endl;
    }
    return 0;
}