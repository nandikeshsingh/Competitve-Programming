#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
using namespace std;
signed main()
{
    speed;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t;
    cin>>t;
    for(int cc=1;cc<=t;cc++)
    {
        int r,c;
        cin>>r>>c;
        vector<vector<char>>vec(r,vector<char>(c));
        int cnt=0;
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                cin>>vec[i][j];
                if(vec[i][j]=='^')cnt++;
            }
            
        }
        if((r==1 || c==1) & cnt>=1)
        {
            cout<<"Case #"<<cc<<": "<<"Impossible"<<endl;
            continue;

        }
        if(cnt==0)
        {
            cout<<"Case #"<<cc<<": "<<"Possible"<<endl;
            for(int i=0;i<r;i++)
            {
                for(int j=0;j<c;j++)
                {
                    cout<<vec[i][j];
                }
                cout<<endl;
            }
        }
        else 
        {
            cout<<"Case #"<<cc<<": "<<"Possible"<<endl;
            for(int i=0;i<r;i++)
            {
                for(int j=0;j<c;j++)
                {
                    cout<<"^";
                }
                cout<<endl;
            }
        }

    }
    return 0;
}


