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
       int n;
       cin>>n;
       vector<int>h(n);
       int cnt=0;
       for(int i=0;i<n;i++)
       {
            cin>>h[i];
            cnt+=(h[i]==1);
       }
       cout<<n-cnt+((cnt+1)/2)<<endl;
    }
    return 0;
}



