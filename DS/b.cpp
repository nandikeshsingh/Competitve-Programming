#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
int n,s,m,l;
int get(int n)
{
    if(n<=0)return 0;
    return min({s+get(n-6),m+get(n-8),l+get(n-12)});
}
signed main()
{
    speed;
    cin>>n>>s>>m>>l;
    cout<<get(n)<<endl;
    return 0;
}


