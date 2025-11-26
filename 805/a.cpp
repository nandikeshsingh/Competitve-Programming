#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
int get(int m)
{
    int ret=0;
    while(m)
    {
        ret++;
        m/=10;
    }
    return ret;
}
signed main()
{
    speed;
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        int dig=get(m);
        int num=1;
        for(int i=1;i<dig;i++)
        {
            num*=10;
        }
        cout<<m-num<<endl;
      
    }
    return 0;
}

