#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
signed main()
{
    speed;
    int a,b,d;
    cin>>a>>b>>d;
    int cur=a;
    cout<<a<<" ";
    while(cur!=b)
    {
        cur+=d;
        cout<<cur<<" ";
    }
    cout<<endl;
    return 0;
}


