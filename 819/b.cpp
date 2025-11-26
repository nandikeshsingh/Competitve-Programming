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
        if(m<n)cout<<"No"<<endl;
        else 
        {
            if(n%2)
            {
                cout<<"Yes"<<endl;
                for(int i=0;i<n;i++)
                {
                    if(i!=n-1)cout<<1<<" ";
                    else cout<<m-n+1<<endl;
                }
            }
            else 
            {
                if(n%2==0 && m%2==0)
                {
                    cout<<"Yes"<<endl;
                    for(int i=0;i<n-2;i++)
                    cout<<1<<" ";
                    int rim=m-n+2;
                    cout<<rim/2<<" "<<rim/2<<endl;
                }
                else cout<<"No"<<endl;
            }
        }
    }
    return 0;
}


