#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
signed main()
{
    speed;
    ofstream MyFile("hack.txt");
    int t;t=100;
    while(t--)
    {
        for(int i=0;i<100;i++)
        {
            if(i==0)
            MyFile<<1000000<<" ";
            else MyFile<<1<<" ";
        }
        MyFile<<endl;
    }
    return 0;
}


