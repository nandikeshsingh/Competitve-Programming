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
        vector<int>p;
        int l=1,r=n;
        bool f=1;
        while(l<=r)
        {
            if(f)
            {
                p.push_back(r--);   
                f=1-f;
            }
            else 
            {
                p.push_back(l++);
                f=1-f;
            }
        }
        for(int i=0;i<n;i++)cout<<p[i]<<" ";
        cout<<endl;
    }
    return 0;
}


