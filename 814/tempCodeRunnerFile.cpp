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
        int n,k;
        cin>>n>>k;
        if(k%2 || k%4==2)
        {
            if(k%2)
            {
                cout<<"YES"<<endl;
                for(int i=1;i<=n-1;i+=2)
                cout<<i<<" "<<i+1<<endl;
            }
            else if(k%4==2)
            {
                cout<<"YES"<<endl;
                for(int i=1;i<=n-1;i+=2)
                cout<<i+1<<" "<<i<<endl;               
            }

        }
        else cout<<"NO"<<endl;
    }
    return 0;
}


