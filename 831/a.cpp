#include<bits/stdc++.h>
// #define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
signed main()
{
    speed;
    vector<int>prime(1e6+1,1);
    prime[1]=0;
    prime[0]=0;
    for(int i=2;i<=1e6;i++)
    {
        if(prime[i])
        {
            for(int j=i+i;j<=1e6;j+=i)
            prime[j]=0;
        }
    }
    vector<int>p;
    for(int i=2;i<=1e6;i++)
    {
        if(prime[i])p.push_back(i);
    }
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        for(auto&u : p)
        {
            int num=u+n;
            if(!prime[num])
            {
                cout<<u<<endl;
                break;
            }
        }
    }
    return 0;
}


