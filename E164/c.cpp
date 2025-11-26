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
        string x,y;
        cin>>x>>y;
        bool f=0;
        for(int i=0;i<x.length();i++)
        {
            if(x[i]==y[i])continue;
            else 
            {
                if(!f)
                {
                    if(x[i]<y[i])swap(x[i],y[i]);
                    f=1;
                }
                else 
                {
                    if(y[i]<x[i])swap(x[i],y[i]);
                }

            }
        }
        cout<<x<<endl;
        cout<<y<<endl;
    }
    return 0;
}


