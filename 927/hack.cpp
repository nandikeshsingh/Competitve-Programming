#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
signed main()
{
    speed;
    // ofstream MyFile("hack.txt");
    int t;t=1000;
    cout<<t<<endl;
    while(t--)
    {
        cout<<100<<endl;
        for(int i=0;i<100;i++)
        {
            if(i==0)
            cout<<1000000<<" ";
            else 
            {
                if(i<99)
                cout<<1<<" ";
                else if(i==99)
                cout<<1<<endl;
            }
        }
    }
    return 0;
}
