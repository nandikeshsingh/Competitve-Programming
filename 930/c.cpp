#include<bits/stdc++.h>
#define int long long
// #define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
char ask(int a,int b,int c,int d)
{
    cout<<"? "<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
    char ch;cin>>ch;
    return ch;
}
signed main()
{
    // speed;
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int b=0;
        for(int i=1;i<n;i++)
        {
            if(ask(b,b,i,i)=='<')
            {
                b=i;
            }
        }
        vector<int>pos;
        int nd=-1;
        if(b>0)nd=0;
        else nd=1;
        pos.push_back(nd);
        for(int i=nd+1;i<n;i++)
        {
            if(i==b)continue;
            char ret=ask(nd,b,b,i);
            if(ret=='<')
            {
                nd=i;
                pos.clear();
                pos.push_back(nd);
            }
            else if(ret=='=')
            {
                pos.push_back(i);
            }
        }
        int mn=pos[0];
        for(int i=1;i<sz(pos);i++)
        {
            if(ask(mn,mn,pos[i],pos[i])=='>')
            {
                mn=pos[i];
            }
        }
        cout<<"! "<<mn<<" "<<b<<endl;
    }
    return 0;
}


