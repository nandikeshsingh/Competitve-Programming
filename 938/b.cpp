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
        int n,c,d;
        cin>>n>>c>>d;
        multiset<int>mst;
        for(int i=0;i<n*n;i++)
        {
            int x;cin>>x;
            mst.insert(x);
        }
        bool ok=1;
        int a=*mst.begin();
        for(int i=0;i<n;i++)
        {
            int cur=a+(i*d);
            bool f=1;
            for(int j=0;j<n;j++)
            {
                if(mst.find(cur)!=mst.end())
                {
                    mst.erase(mst.find(cur));
                    cur+=c;
                }
                else 
                {
                    f=0;
                    break;
                }
            }
            if(!f)
            {
                ok=0;
                break;
            }
        }
        cout<<(ok?"YES":"NO")<<endl;
    }
    return 0;
}


