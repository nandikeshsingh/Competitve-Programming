#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
signed main()
{
    speed;
    int d;
    cin>>d;
    int xmx=sqrt(d);
    int mn=1e18;
    for(int i=0;i<=xmx;i++)
    {
        int rim=d-i*i;
        int ymx=sqrt(rim);
        mn=min(mn,abs((i*i+ymx*ymx)-d));
        mn=min(mn,abs(i*i+(ymx+1)*(ymx+1)-d));
    }
    mn=min(mn,abs((xmx+1)*(xmx+1)-d));
    cout<<mn<<endl;
    return 0;
}


