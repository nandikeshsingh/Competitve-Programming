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
        int n,k;
        cin>>n>>k;
        if(k<=((4*n)-4))
        {
            double d=2;
            cout<<(int)ceil((double)k/d)<<endl;
        }
        else if(k==((4*n)-3))
        {
            cout<<n+n-1<<endl;
        }
        else if(k==((4*n)-2)) cout<<n+n<<endl;
    }
    return 0;
}


