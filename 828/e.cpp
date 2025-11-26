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
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        int xx=-1,yy=-1;
        for(int x=a+1;x<=c;x++)
        {
            int up=a*b;
            int down=x;
            int g=__gcd(up,down);
            up/=g;
            down/=g;
            if(up>d)continue;
            else if(up>b && up<=d)
            {
                xx=x;
                yy=up;
                break;
            }
            else if(up<=b)
            {
                int f=ceil((double)(b+1)/(double)up);
                if(f*up>d)continue;
                else 
                {
                    xx=x;
                    yy=f*up;
                    break;
                }
            }
        }
        cout<<xx<<" "<<yy<<endl;
    }
    return 0;
}


