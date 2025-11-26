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
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        
        if(a*d==c*b)cout<<0<<endl;
        else if(a==0 || c==0)cout<<1<<endl;
        else if((a*d)%(c*b)==0)cout<<1<<endl;
        else if((c*b)%(a*d)==0)cout<<1<<endl;
        else cout<<2<<endl;
    }
    return 0;
}


