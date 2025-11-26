#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define fo(i,n)   for(int i=0;i<(n);++i)
#define rep(i,a,b)   for(int i=(a);i<=(b);++i)
#define per(i,b,a)   for(int i=(b);i>=(a);--i)
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
#define pb push_back
#define F first
#define S second
using namespace std;
signed main()
{
    speed;
    int t;
    cin>>t;
    while(t--)
    {
        int x,y;
        cin>>x>>y;
        if(y%2==0)
        {
            int tot=(y)/2;
            int left=7*tot;
            if(x<=left)cout<<tot<<endl;
            else 
            {
                int rim=x-left;
                int more=rim/15;
                if(rim%15>0)more++;
                cout<<tot+more<<endl;
            }
        }
        else 
        {
            int tot=(y+1)/2;
            int left=(7*(tot-1))+11;
            if(x<=left)cout<<tot<<endl;
            else 
            {
                int rim=x-left;
                int more=rim/15;
                if(rim%15>0)more++;
                cout<<tot+more<<endl;
            }
        }
    }
    return 0;
}


