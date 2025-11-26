#include<bits/stdc++.h>
#define int long long
// #define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
int ask(int x,int y)
{
    cout<<"? "<<x<<" "<<y<<endl;
    int ret;cin>>ret;
    return ret;
}
signed main()
{
    // speed;
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        int d1=ask(1,1);
        int d2=ask(n,m);
        if(d1+d2==n+m-2)
        {
            int r1;
            int x1,y1;
            if(d1<=n-1)
            {
                r1=ask(1+d1,1);
                x1=1+d1;
                y1=1;
            }
            else 
            {
                r1=ask(n,1+d1-(n-1));
                x1=n;
                y1=1+d1-(n-1);
            }
            cout<<"! "<<x1-r1/2<<" "<<y1+r1/2<<endl;
        }
        else 
        {
            int d3=ask(1,m);
            // cout<<"d1="<<d1<<" d2="<<d2<<" d3="<<d3<<endl;
            int fx=(m-1+d1-d3)/2;
            fx++;
            int fy=(m-1-d1-d3)/2;
            fy=-fy;fy++;
            // cout<<"fx="<<fx<<" fy="<<fy<<endl;
            if(fx<1||fx>m||fy<1||fy>n||ask(fy,fx)!=0)
            {
                int sx=(n-1+m-1+m-1-d2-d3)/2;sx++;
                int sy=(d2-d3-n+1)/2;sy=-sy;sy++;
                cout<<"! "<<sy<<" "<<sx<<endl;
            }
            else cout<<"! "<<fy<<" "<<fx<<endl;
        }
    }
    return 0;
}


