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
        int n,m;
        cin>>n>>m;
        if((m&n)==m)
        {
            cout<<1<<endl;
            cout<<n<<" "<<m<<endl;
            continue;
        }
        vector<int>ans;
        ans.push_back(n);
        int x=n;
        int msb=-1;
        bool need=0;
        for(int i=59;i>=0;i--)
        {
            if(((1LL<<i)&x)>0 && ((1LL<<i)&m)>0)
            {
                if(msb==-1)
                msb=i;
                continue;
            }
            else if(((1LL<<i)&x)==0 && ((1LL<<i)&m)==0)continue;
            else if(((1LL<<i)&x)>0 && ((1LL<<i)&m)==0)
            {
                if(msb==-1)msb=i;
                if(i<msb)
                {
                    cout<<"i="<<i<<endl;
                    int y=0;
                    for(int j=i;j>=0;j--)
                    {
                        if(((1LL<<j)&x)>0 && ((1LL<<j)&m)==0)y|=(1LL<<j);
                        else if(((1LL<<j)&x)==0 && ((1LL<<j)&m)>0)y|=(1LL<<j);
                    }
                    x^=y;
                    ans.push_back(x);
                }
                else 
                {
                    need=1;
                }
            }
        }
        if(need)
        {
            if((1LL<<msb)==x || (x^(1LL<<msb))!=m)
            {
                cout<<-1<<endl;
                continue;
            }
            else 
            ans.push_back(x^(1LL<<msb));
        }
        cout<<sz(ans)-1<<endl;
        for(auto& u : ans)cout<<u<<" ";
        cout<<endl;
    }
    return 0;
}

