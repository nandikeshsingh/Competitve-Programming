#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
using namespace std;
vector<int>a;
map<pair<int,int>,int>mp;
bool get(int s,int i)
{
    if(i<0)
    {
        if(s==0)return 1;
        else return 0;
    }
    int x=0,y=0;
    if(mp.count({s-a[i],i-1}))
    x=mp[{s-a[i],i-1}];
    else x=get(s-a[i],i-1);
    if(mp.count({s,i-1}))
    y=mp[{s,i-1}];
    else y=get(s,i-1);
    return x|y;
}
signed main()
{
    speed;
    int n;
    cin>>n;
    a.resize(n);
    int s=0;
    for(int i=0;i<n;i++)cin>>a[i],s+=a[i];
    if(s&1)
    {
        cout<<"NO"<<endl;
        return 0;
    }
    cout<<(get(s/2,n-1)?"YES":"NO")<<endl;
    return 0;
}
