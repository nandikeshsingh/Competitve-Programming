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
        int x1,y1,x2,y2,x3,y3;
        cin>>x1>>y1>>x2>>y2>>x3>>y3;
        set<int>stx,sty;
        stx.insert(x1);
        stx.insert(x2);
        stx.insert(x3);
        sty.insert(y1);
        sty.insert(y2);
        sty.insert(y3);
        if(sz(stx)==2 && sz(sty)==2)cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    return 0;
}


