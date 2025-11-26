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
        int n;
        cin>>n;
        int row[3],col[3];
        cin>>row[0]>>col[0]>>row[1]>>col[1]>>row[2]>>col[2];
        int x,y;
        cin>>x>>y;
        set<pair<int,int>>od,ev;
        for(int i=0;i<3;i++)
        {
            if((row[i]+col[i])%2)od.insert({row[i],col[i]});
            else ev.insert({row[i],col[i]});
        }
        if(sz(od)==1)
        {
            int r,c;
            r=od.begin()->first;
            c=od.begin()->second;   
            if((r==n && c==1))
            {
                if(x==n || y==1)cout<<"YES"<<endl;
                else cout<<"NO"<<endl;
            }        
            else if((r==1 && c==n))
            {
                if(x==1 || y==n)cout<<"YES"<<endl;
                else cout<<"NO"<<endl;
            }
            else if((x+y)%2==0)cout<<"YES"<<endl;
            else 
            {

                if(abs(c-y)%2)cout<<"NO"<<endl;
                else cout<<"YES"<<endl;
            }
        }
        else 
        {
            int r,c;
            r=ev.begin()->first;
            c=ev.begin()->second;
            if(r==1 && c==1)
            {
                if(x==1 || y==1)cout<<"YES"<<endl;
                else cout<<"NO"<<endl;
            }
            else if(r==n && c==n)
            {
                if(x==n || y==n)cout<<"YES"<<endl;
                else cout<<"NO"<<endl;
            }
            else if(r==n && c==1)
            {
                if(x==n || y==1)cout<<"YES"<<endl;
                else cout<<"NO"<<endl;               
            }
            else if(r==1 && c==n)
            {
                if(x==1 || y==n)cout<<"YES"<<endl;
                else cout<<"NO"<<endl;               
            }
            else if((x+y)%2)cout<<"YES"<<endl;
            else 
            {

                if(abs(c-y)%2)cout<<"NO"<<endl;
                else cout<<"YES"<<endl;                
            }
        }
    }
    return 0;
}


