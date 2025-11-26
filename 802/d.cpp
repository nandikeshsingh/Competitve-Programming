#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
signed main()
{
    speed;
    int n;
    cin>>n;
    vector<int>vec(n);
    vector<double>pre(n);
    for(int i=0;i<n;i++)cin>>vec[i];
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=vec[i];
        double now=ceil(double(sum)/double(i+1));
        if(i==0)pre[i]=now;
        else pre[i]=max(pre[i-1],now);
    }
    int q;
    cin>>q;
    while(q--)
    {
        int t;
        cin>>t;
        if(t*n<sum)
        {
            cout<<-1<<endl;
            continue;
        }
        // int lo=1,hi=n;
        // while(lo<hi)
        // {
        //     int pipe=(lo+hi)>>1;
        //     if(t*pipe<sum)lo=pipe+1;
        //     else hi=pipe;
        // }
        int lo=ceil(double(sum)/double(t));
        if(pre[lo-1]<=(double)t)cout<<lo<<endl;
        else cout<<-1<<endl;
    }
    return 0;
}
