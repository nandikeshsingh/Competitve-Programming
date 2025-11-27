#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
signed main()
{
    speed;
    int n;
    cin>>n;
    vector<int>x(n),y(n);
    for(int i=0;i<n;i++)cin>>x[i]>>y[i];
    for(int i=0;i<n;i++)
    {
        int mx=0;
        int id=-1;
        for(int j=0;j<n;j++)
        {
            if(i==j)continue;
            int dis=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
            if(dis>mx)
            {
                mx=dis;
                id=j;
            }
        }
        cout<<id+1<<endl;
    }
    return 0;
}


