#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
const int maxn=61;
int n;
pair<int,int>p1,p2;
vector<string>grid;
vector<vector<int>>cg(maxn,vector<int>(maxn,0));
void print(vector<vector<int>>&v)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        cout<<v[i][j]<<" ";
        cout<<endl;
    }

}

void floodfill(int i,int j)
{
    if(i<0 || i>=n || j<0 || j>=n)return;
    if(cg[i][j]==1)return;
    if(cg[i][j]==2)return;
    cg[i][j]=2;
    floodfill(i+1,j);
    floodfill(i-1,j);
    floodfill(i,j+1);
    floodfill(i,j-1);
}
int dx[4]={-1,0,1,0};
int dy[4]={0,-1,0,1};
void bfs(int i,int j,vector<vector<int>>&vec)
{
    queue<pair<int,int>>q;
    q.push({i,j});
    while(!q.empty())
    {
        pair<int,int>cur=q.front();
        q.pop();
        for(int d=0;d<4;d++)
        {
            int nx=dx[d]+cur.first;
            int ny=dy[d]+cur.second;
            if(nx<0||nx>=n || ny<0 || ny>=n || grid[nx][ny]=='#')continue;
            if(vec[nx][ny]!=0)
            {
                if(vec[nx][ny]>vec[cur.first][cur.second]+1)
                {
                    vec[nx][ny]=min(vec[cur.first][cur.second]+1,vec[nx][ny]);
                    q.push({nx,ny});
                }
            }
            else 
            {
                vec[nx][ny]=vec[cur.first][cur.second]+1;
                q.push({nx,ny});
            }
            
        }
    }
}
bool ok(int i,int j)
{
    if(i<0 || i>=n || j<0 || j>=n)return 0;
    else return 1;
}
bool check(int i, int j)
{
    if(ok(i+1,j))
    {
        if(grid[i+1][j]=='#')return 1;
    }
    if(ok(i-1,j))
    {
        if(grid[i-1][j]=='#')return 1;
    }
    if(ok(i,j+1))
    {
        if(grid[i][j+1]=='#')return 1;
    }
    if(ok(i,j-1))
    {
        if(grid[i][j-1]=='#')return 1;
    }
    return 0;
}
signed main()
{
    speed;
    cin>>n;
    int cnt=0;
    vector<vector<int>>f(n,vector<int>(n,0));
    vector<vector<int>>s(n,vector<int>(n,0));
    for(int i=0;i<n;i++)
    {
        string s;cin>>s;
        
            for(int j=0;j<n;j++)
            {
                cg[i][j]=(s[j]=='#');
                if(cg[i][j]==1)f[i][j]=1e18;
                if(s[j]=='P' && cnt<2)
                {
                    if(cnt==0)p1.first=i,p1.second=j,cnt++;
                    else p2.first=i,p2.second=j,cnt++;
                }
            }
        grid.push_back(s);
    }
    s=f;
    floodfill(p1.first,p1.second);
    if(cg[p2.first][p2.second]==0)
    {
        cout<<-1<<endl;
    }
    else 
    {
        f[p1.first][p1.second]=1;
        bfs(p1.first,p1.first,f);
        cout<<"Printint f"<<endl;
        print(f);
        int best=1e18;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0 || i==n-1 || j==0 || j==n-1)best=min(best,f[i][j]);
                if(check(i,j))best=min(best,f[i][j]);
            }
        }
        s[p2.first][p2.second]=1;
        bfs(p2.first,p2.second,s);
        cout<<"Printing s"<<endl;
        print(s);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0 || i==n-1 || j==0 || j==n-1)best=min(best,s[i][j]);
                if(check(i,j))best=min(best,s[i][j]);
            }
        }
        cout<<"best="<<best<<endl;
        cout<<(best-1)+s[p1.first][p1.second]-1<<endl;
    }
    return 0;
}