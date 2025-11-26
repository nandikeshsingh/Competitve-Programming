#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
int get(int up,int dw)
{
    if((up%dw)==0)return up/dw;
    else return ((up/dw)+1);
}
signed main()
{
    speed;
    int t;
    cin>>t;
    while(t--)
    {
        int k,x,a;
        cin>>k>>x>>a;
        bool ok=1;
        if(x>=a)
        {
            cout<<"NO"<<endl;
            continue;
        }
        int s=1;
        for(int i=2;i<=x;i++)
        {
            int cur_s=get(s,k-1);
            // cout<<"cur="<<cur_s<<endl;
            if(cur_s>a)ok=0;
            if((a-s)+(cur_s*(k-1))<=a)ok=0;
            s+=cur_s;
            if(s>=a)ok=0;
        }
        if((a-s)*k<=a)ok=0;
        if(ok)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}


