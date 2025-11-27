#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
signed main()
{
    speed;
    int n,a,b;
    cin>>n>>a>>b;
    vector<int>d(n);
    for(int i=0;i<n;i++)cin>>d[i];
    for(int i=n-1;i>=0;i--)
    {
        if(i!=0)
        d[i]=d[i]-d[i-1];
        else d[i]=0;
    }
    bool ok=0;
    for(int i=0;i<n;i++)
    {
        if(i==0)
        {
            if(d[n-1]<=a-1)
            {
                ok=1;
                break;
            }
        }
        else 
        {
            if(d[n-1]-d[i]<=a-1 && d[i]-d[i-1]-1>b)
            {
                ok=1;
                break;
            }
        }
    }
    cout<<(ok?"Yes":"No")<<endl;
    return 0;

}

