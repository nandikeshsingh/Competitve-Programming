#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
using namespace std;
signed main()
{
    speed;
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        if(n%2 && m%2)cout<<"Tonya"<<endl;
        else if(n%2==0 && m%2==0)cout<<"Tonya"<<endl;
        else cout<<"Burenka"<<endl;
    }
    return 0;
}


