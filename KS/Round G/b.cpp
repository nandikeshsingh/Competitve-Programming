#include<bits/stdc++.h>
using namespace std;
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
#define int long long
signed main()
{
    int t;
    cin>>t;
    for(int c=1;c<=t;c++)
    {
        int s,h;
        cin>>s>>h;
        int n;
        cin>>n;
        vector<int>x(n),y(n);
        for(int i=0;i<n;i++)cin>>x[i]>>y[i];
        int m;
        cin>>m;
        vector<int>z(m),w(m);
        for(int i=0;i<m;i++)cin>>z[i]>>w[i];
        int a=0,b=0;
        vector<int>red,yellow;
        for(int i=0;i<n;i++)
        {
            int dis=x[i]*x[i]+y[i]*y[i];
            if(dis<=(s+h)*(s+h))
            red.push_back(dis);
        }
        for(int i=0;i<m;i++)
        {
            int dis=z[i]*z[i]+w[i]*w[i];
            if(dis<=(s+h)*(s+h))
            yellow.push_back(dis);
            
        }
        sort(all(red));
        sort(all(yellow));
        if(sz(red)==0)
        {
            cout<<"Case #"<<c<<": "<<0<<" "<<sz(yellow)<<endl;
            continue;
        }
        else if(sz(yellow)==0)
        {
            cout<<"Case #"<<c<<": "<<sz(red)<<" "<<0<<endl;
            continue;
        }
        int i=0,j=0;
        bool ok=1;
        while(i<sz(red))
        {
            if(red[i]<yellow[j]){
                a++;i++;
                ok=0;
            }
            else break;
        }
        if(ok)
        {
            while(j<sz(yellow))
            {
                if(red[i]>yellow[j])
                {
                    b++;j++;
                }
                else break;
            }
        }
        cout<<"Case #"<<c<<": "<<a<<" "<<b<<endl;
    }
    return 0;
}