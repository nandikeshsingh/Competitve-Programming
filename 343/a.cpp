#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
signed main()
{
    speed;
    int a,b;
    cin>>a>>b;
    for(int i=0;i<=9;i++)
    {
        if(i!=a+b)
        {
            cout<<i<<endl;
            break;
        }
    }
    return 0;
}


