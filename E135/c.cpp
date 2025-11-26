#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
using namespace std;
int reduce(int n)
{
    int ret=0;
    while(n)
    {
        ret++;
        n/=10;
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
        int n;
        cin>>n;
        multiset<int>a,b;
        for(int i=0;i<n;i++)
        {
            int x;cin>>x;
            a.insert(x);

        }
        for(int i=0;i<n;i++)
        {
            int x;cin>>x;
            b.insert(x);
        }
        int ans=0;
        while((int)a.size()>0)
        {  
            int x=*prev(a.end());
            int y=*prev(b.end());
            if(x==y)
            {
                a.erase(prev(a.end()));
                b.erase(prev(b.end()));
            }
            else if(x>y)
            {
                int cur=reduce(x);
                ans++;
                a.erase(prev(a.end()));
                if(b.find(cur)!=b.end())b.erase(b.find(cur));
                else a.insert(cur);
            }
            else 
            {
                int cur=reduce(y);
                ans++;
                b.erase(prev(b.end()));
                if(a.find(cur)!=a.end())a.erase(a.find(cur));
                else b.insert(cur);                
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}


