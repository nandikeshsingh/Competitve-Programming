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
    for(int i=1;i<=n;i++)
    {
        if(i%3==0)cout<<"x";
        else cout<<"o";
    }
    cout<<endl;
    return 0;
}


