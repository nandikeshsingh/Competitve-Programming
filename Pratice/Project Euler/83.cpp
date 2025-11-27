#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
vector<std::vector<int>> get2DVector(int n, string filename)
{
    vector<std::vector<int>> result(n);

    ifstream input(filename);

    string s;
    for (int i = 0; i < n; i++)
    {
        getline(input, s);
        istringstream iss(s);

        string num;
        while (getline(iss, num, ','))
            result[i].push_back(std::stoi(num));
    }

    return result;
}
const int inf=1e18;
int vis[80][80], dist[80][80];
int dx[4]={ +1, 0,0,-1};
int dy[4]={ 0, +1,0,0};
vector<vector<int>>vec;
void bfs(int x, int y, int n, int m)
{
	queue<pair<int, int> > q;
	q.push({x, y});
	vis[x][y]=1;
	dist[x][y]=vec[x][y];
	while(!q.empty())
	{
		int x=q.front().first;
		int y=q.front().second;
		q.pop();
        // cout<<x<<" "<<y<<endl;
		for(int dir=0;dir<4;dir++)
		{
			int nx=x+dx[dir];
			int ny=y+dy[dir];
            // cout<<"nx="<<nx<<" ny="<<ny<<endl;
			if(nx<0 || ny<0 || nx>=n || ny>=m)
				continue;
			if(!vis[nx][ny])
			{
				dist[nx][ny]=min(dist[x][y]+vec[nx][ny],dist[nx][ny]);
				vis[nx][ny]=1;
				q.push({nx, ny});
			}
			else
			{
                if(dist[nx][ny]>dist[x][y]+vec[nx][ny])
                {
                    dist[nx][ny]=dist[x][y]+vec[nx][ny];
                    q.push({nx,ny});
                }
			}
		}
	}
}
signed main()
{
    speed;
    auto ret = get2DVector(80, "0082_matrix.txt");
    vec=ret;
    for(int i=0;i<80;i++)for(int j=0;j<80;j++)dist[i][j]=inf;
    int mn=1e18;
    for(int i=0;i<80;i++)
    {
        bfs(i,0,80,80);
        for(int j=0;j<80;j++)
        mn=min(mn,dist[j][79]);
        for(int k=0;k<80;k++)for(int l=0;l<80;l++)vis[k][l]=0,dist[k][l]=inf;
        cout<<"i="<<i<<endl;
    }
    // bfs(0,0,80,80);
    cout<<mn<<endl;
    // cout<<dist[79][79]<<endl;
    return 0;
}


