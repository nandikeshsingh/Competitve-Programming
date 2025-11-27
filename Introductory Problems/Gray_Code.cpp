#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
using namespace std;
signed main()
{
    speed;
    int n;
    cin>>n;
    for(int i=0;i<(1<<n);i++)
    {
        int gray=0;
        for(int bit=n-1;bit>=0;bit--)
        {
            if(((i>>bit)&1)==0 && ((i>>(bit+1))&1)==1 || ((i>>bit)&1)==1 && ((i>>(bit+1))&1)==0)
            cout<<1;
            else cout<<0;
        }
        cout<<endl;
    }
    return 0;
}


