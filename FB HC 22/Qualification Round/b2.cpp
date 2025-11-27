#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
using namespace std;
vector<vector<char>>vec;
int r,c;
bool is_valid(int i,int j)
{
    if(i>=0 && i<r && j>=0 && j<c)return 1;
    else return 0;
}
int get(int i,int j)
{
    int ret=0;
    if(is_valid(i-1,j))
    ret+=(vec[i-1][j]=='^');
    if(is_valid(i,j-1))
    ret+=(vec[i][j-1]=='^');
    if(is_valid(i+1,j))
    ret+=(vec[i+1][j]=='^');
    if(is_valid(i,j+1))
    ret+=(vec[i][j+1]=='^');
    return ret;
}
// int check(int i,int j)
// {
//     int ret=0;
//     if(is_valid(i-1,j))
//     ret+=((vec[i-1][j]=='^') || (vec[i-1][j]=='.'));
//     if(is_valid(i,j-1))
//     ret+=((vec[i][j-1]=='^') || (vec[i][j-1]=='.'));
//     if(is_valid(i+1,j))
//     ret+=((vec[i+1][j]=='^') || (vec[i+1][j]=='.'));
//     if(is_valid(i,j+1))
//     ret+=((vec[i][j+1]=='^') || (vec[i][j+1]=='.'));
//     return ret;
// }
signed main()
{
    speed;
    freopen("input1.txt","r",stdin);
    freopen("out1.txt","w",stdout);
    int t;
    cin>>t;
    for(int cc=1;cc<=t;cc++)
    {
        // int r,c;
        cin>>r>>c;
        vec.clear();
        vec.resize(r,vector<char>(c));
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
            for(int i=0;i<r;i++)
            {
                for(int j=0;j<c;j++)
                {
                    if(vec[i][j]!='#')
                    vec[i][j]='^';
                }
            }    
            // bool ok=1;
            queue<pair<int,int>>q;
            for(int i=0;i<r;i++)
            {
                for(int j=0;j<c;j++)
                {
                    if(vec[i][j]=='#')continue;
                    if(get(i,j)<2)
                    {
                        q.push({i,j});
                        // ok=0;
                    }
                }
            }
            if(q.empty())
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
                while(!q.empty())
                {
                    pair<int,int>p=q.front();
                    int x=p.first,y=p.second;
                    q.pop();
                    vec[p.first][p.second]='.';
                    if(is_valid(x-1,y) && vec[x-1][y]!='#' && get(x-1,y)<2 && vec[x-1][y]!='.')q.push({x-1,y});
                    if(is_valid(x+1,y) && vec[x+1][y]!='#' && get(x+1,y)<2 && vec[x+1][y]!='.')q.push({x+1,y});
                    if(is_valid(x,y-1) && vec[x][y-1]!='#' && get(x,y-1)<2 && vec[x][y-1]!='.')q.push({x,y-1});
                    if(is_valid(x,y+1) && vec[x][y+1]!='#' && get(x,y+1)<2 && vec[x][y+1]!='.')q.push({x,y+1});
                }
                bool ok=1;
                for(int i=0;i<r;i++)
                {
                    for(int j=0;j<c;j++)
                    {
                        if(vec[i][j]=='#' || vec[i][j]=='.')continue;
                        if(get(i,j)<2)
                        {
                            ok=0;
                        }
                    }
                }
                if(!ok)
                cout<<"Case #"<<cc<<": "<<"Impossible"<<endl;
                else 
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
            }
        }

    }
    return 0;
}


