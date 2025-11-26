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
        int n;
        cin>>n;
        int x=0,y=0;
        vector<int>vec;
        while(n)
        {
            vec.push_back(n%10);
            n/=10;
        }
        reverse(all(vec));
        bool f=1;
        int now=10;
        for(int i=0;i<sz(vec);i++)
        {
            if(vec[i]%2)
            {
                if(f)
                {
                    x*=now;
                    int a=vec[i]/2;
                    int b=vec[i]-a;
                    x+=a;
                    y*=now;
                    y+=(b);
                    // now*=10;
                    f=0;
                }
                else 
                {
                    y*=now;
                    int a=vec[i]/2;
                    int b=vec[i]-a;
                    y+=a;
                    x*=now;
                    x+=b;
                    // now*=10;                   
                    f=1;
                }
            }
            else 
            {
                x*=now;
                y*=now;
                x+=vec[i]/2;
                y+=vec[i]/2;
                // now*=10;
            }
        }
        cout<<x<<" "<<y<<endl;
    }
    return 0;
}


