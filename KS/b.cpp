#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
    int tt;
    cin>>tt;
    for(int t=1;t<=tt;t++)
    {
        int n,x,y;
        cin>>n>>x>>y;
        int k=(n*(n+1))/2;
        int up=x*k;
        int down=x+y;
        if(up%down!=0)
        {
             cout<<"Case #"<<t<<": "<<"IMPOSSIBLE"<<endl;
        }
        else 
        {
            int a=up/down;
            int cur=a;
            int cnt=0;
            vector<bool>vec(n+1,0);
            for(int i=n;i>=1;i--)
            {
                if(cur>=i)
                {
                    vec[i]=1;
                    cur-=i;
                    cnt++;
                }
            }
            cout<<"Case #"<<t<<": "<<"POSSIBLE"<<endl;
            cout<<cnt<<endl;
            for(int i=1;i<=n;i++)
            {
                if(vec[i]==1)cout<<i<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}