#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
using namespace std;
signed main()
{
    speed;
    int n;
    cin>>n;
    int tot=(n*(n+1))/2;
    if(tot%2)cout<<"NO"<<endl;
    else 
    {
        if(n%4==2 || n%4==1)cout<<"NO"<<endl;
        else 
        {
            if(n%4==0)
            {
                cout<<"YES"<<endl;
                vector<int>f,s;
                for(int i=1;i<=n;i++)
                {
                    if(i%4==1 || i%4==0)f.push_back(i);
                    else s.push_back(i);
                }
                cout<<f.size()<<endl;
                for(auto& u : f)cout<<u<<" ";
                cout<<endl;
                cout<<s.size()<<endl;
                for(auto& u : s)cout<<u<<" ";
                cout<<endl;
            }
            else 
            {
                cout<<"YES"<<endl;
                vector<int>f,s;
                for(int i=4;i<=n;i++)
                {
                    if(i%4==3 || i%4==0)f.push_back(i);
                    else s.push_back(i);
                }
                f.push_back(3);
                s.push_back(1);
                s.push_back(2);
                cout<<f.size()<<endl;
                for(auto& u : f)cout<<u<<" ";
                cout<<endl;
                cout<<s.size()<<endl;
                for(auto& u : s)cout<<u<<" ";
                cout<<endl;
            }
        }
    }
    return 0;
}


