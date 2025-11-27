#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
signed main()
{
    speed;
    int M,D;
    cin>>M>>D;
    int y,m,d;
    cin>>y>>m>>d;
    if(d+1>D)
    {
        d=1;
        if(m+1>M)
        {
            m=1;
            y++;
        }
        else 
        {
            m++;
        }
    }
    else d++;
    cout<<y<<" "<<m<<" "<<d<<endl;
    return 0;
}


