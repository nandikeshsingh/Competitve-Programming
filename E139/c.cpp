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
        int m;
        cin>>m;
        string x,y;
        cin>>x>>y;
        x.push_back('B');
        y.push_back('B');
        reverse(all(x));
        x.push_back('B');
        reverse(all(x));
        reverse(all(y));
        y.push_back('B');
        reverse(all(y));
        bool ok=1;
        for(int i=2;i<=m;i++)
        {
            if(x[i-1]=='B' && y[i-1]=='W' && y[i]=='B' && x[i]=='W')
            {
                ok=0;
                break;
            }
            else if(x[i-1]=='W' && y[i-1]=='B' && y[i]=='W' && x[i]=='B')
            {
                ok=0;
                break;
            }
        }
        if(!ok)cout<<"NO"<<endl;
        else 
        {
            int cnt=0;
            bool up=1,dw=1;
            for(int i=1;i<=m;i++)
            {
                if(x[i]=='B' && y[i]=='B')cnt++;
                else 
                {
                    if(cnt>0)
                    {
                        if(cnt&1)
                        {
                            if(x[i]=='B' && dw==0)
                            {
                                ok=0;
                                break;
                            }
                            else if(y[i]=='B' && up==0)
                            {
                                ok=0;
                                break;
                            }
                        }
                        else 
                        {
                            if(x[i]=='B' && up==0)
                            {
                                ok=0;
                                break;
                            }
                            else if(y[i]=='B' && dw==0)
                            {
                                ok=0;
                                break;
                            }
                        }
                    }
                    cnt=0;
                    if(x[i]=='B')
                    {
                        up=1,dw=0;
                    }
                    else 
                    {
                        up=0,dw=1;
                    }
                }
            }
            if(ok)cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
    return 0;
}


