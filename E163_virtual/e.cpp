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
        vector<int>a(n+1,0),c(n+1,0);
        int last=1;
        int cur=1;
        int cnt=1;
        int cq=1;
        while(cur+1<=n)
        {
            if(cur+1-last<k)cur++;
            else 
            {
                int dis=(cur-last)/2;
                int mid=-1;
                if((cur-last+1)%2)mid=last+dis-1;
                else mid=last+dis;
                for(int i=mid;i>=last;i--)a[i]=cnt++;
                for(int i=cur;i>mid;i--)a[i]=cnt++;
                for(int i=last;i<=cur;i++)c[i]=cq;
                cq++;
                cur++;
                last=cur;
            }
        }
        if(cur==n)
        {
                int dis=(cur-last)/2;
                int mid=-1;
                if((cur-last+1)%2)mid=last+dis-1;
                else mid=last+dis;
                for(int i=mid;i>=last;i--)a[i]=cnt++;
                for(int i=cur;i>mid;i--)a[i]=cnt++;
                for(int i=last;i<=cur;i++)c[i]=cq;
                cur++;
                last=cur;
        }
        for(int i=1;i<=n;i++)cout<<a[i]<<" ";
        cout<<endl;
        cout<<cq<<endl;
        for(int i=1;i<=n;i++)cout<<c[i]<<" ";
        cout<<endl;
    }
    return 0;
}


