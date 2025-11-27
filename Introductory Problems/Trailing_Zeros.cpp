#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
using namespace std;
signed main()
{
    speed;
    int n;
    cin>>n;
    int x=0;
    int cur=5;
    while(cur<=n)
    {
        x+=(n/cur);
        cur*=5;
    }
    cout<<x<<endl;
    return 0;
}


