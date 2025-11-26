#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
using namespace std;
signed main()
{
    speed;
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        if(n==1 && m==1)
        {
            cout<<0<<endl;
            continue;
        }
        if(m>n)swap(m,n);
        cout<<2*(m-1)+n<<endl;
    }
    return 0;
}


