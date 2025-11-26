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
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        vector<int>diva,divb;
        for(int i=1;i*i<=a;i++)
        {
            if(a%i)continue;
            diva.push_back(i);
            diva.push_back(a/i);
        }
        for(int i=1;i*i<=b;i++)
        {
            if(b%i)continue;
            divb.push_back(i);
            divb.push_back(b/i);
        }
        bool ok=0;
        for(auto& u : diva)
        {
            for(auto& v : divb)
            {
                int s=u*v;
                int f=a*b/s;
                int x=a+1;
                int y=b+1;
                if(x%f)x+=f-(x%f);
                if(y%s)y+=s-(y%s);
                if(x<=c && y<=d)
                {
                    cout<<x<<" "<<y<<endl;
                    ok=1;
                    break;
                }
            }
            if(ok)break;
        }
        if(!ok)
        cout<<-1<<" "<<-1<<endl;
    }
    return 0;
}
