#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
void spiralOrder(vector<vector<int> >& matrix,int cur)
{
    int m = matrix.size(), n = matrix[0].size();
 
    vector<vector<bool> > seen(m, vector<bool>(n, false));
    int dr[] = { 0, 1, 0, -1 };
    int dc[] = { 1, 0, -1, 0 };
 
    int x = 0, y = 0, di = 0;
 
    for (int i = 0; i < m * n; i++) {
        matrix[x][y]=cur++;
        seen[x][y] = true;
        int newX = x + dr[di];
        int newY = y + dc[di];
 
        if (0 <= newX && newX < m && 0 <= newY && newY < n
            && !seen[newX][newY]) {
            x = newX;
            y = newY;
        }
        else {
            di = (di + 1) % 4;
            x += dr[di];
            y += dc[di];
        }
    }
}
signed main()
{
    speed;
    int n;
    cin>>n;
    vector<vector<int>>vec(n,vector<int>(n,0));
    spiralOrder(vec,1);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(vec[i][j]!=n*n)
            cout<<vec[i][j]<<" ";
            else cout<<"T"<<" ";
        }
        cout<<endl;
    }
    return 0;
}


