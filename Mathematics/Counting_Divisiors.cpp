#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
signed main()
{
    speed;
    vector<int>cnt(1e6+5);
    for(int i=1;i<1e6+5;i++)
    {
        for(int j=i;j<1e6+5;j+=i)
        cnt[j]++;
    }
    int n;
    cin>>n;
    while(n--)
    {
        int x;
        cin>>x;
        cout<<cnt[x]<<endl;
    }
    return 0;
}


