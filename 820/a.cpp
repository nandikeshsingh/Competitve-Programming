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
        int a,b,c;
        cin>>a>>b>>c;
        int time=0;
        if(c>b)time=c+c-b;
        else time=b;
        if(a<time)
        {
            cout<<1<<endl;
        }
        else if(time<a)cout<<2<<endl;
        else cout<<3<<endl;
    }
    return 0;
}