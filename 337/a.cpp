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
    int x=0,y=0;
    for(int i=0;i<n;i++)
    {
        int a,b;cin>>a>>b;
        x+=a;y+=b;
    }
    if(x>y)cout<<"Takahashi"<<endl;
    else if(x<y)cout<<"Aoki"<<endl;
    else cout<<"Draw"<<endl;
    return 0;
}


