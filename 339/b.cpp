#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
signed main()
{
    speed;
    int h,w,n;
    cin>>h>>w>>n;
    vector<vector<int>>vec(h,vector<int>(w,0));
    int i=0,j=0;
    char dir='u';
    while(n--)
    {
        if(vec[i][j]==0)
        {
            vec[i][j]=1;
            if(dir=='u')
            {
                dir='r';
                j++;
                if(j>=w)j-=w;
            }
            else if(dir=='r')
            {
                dir='d';
                i++;
                if(i>=h)i-=h;
            }
            else if(dir=='d')
            {
                dir='l';
                j--;
                if(j<0)j+=w;
            }
            else if(dir=='l')
            {
                dir='u';
                i--;
                if(i<0)i+=h;
            }
        }
        else if(vec[i][j]==1)
        {
            vec[i][j]=0;
            if(dir=='u')
            {
                dir='l';
                j--;
                if(j<0)j+=w;
            }
            else if(dir=='r')
            {
                dir='u';
                i--;
                if(i<0)i+=h;
            }
            else if(dir=='d')
            {
                dir='r';
                j++;
                if(j>=w)j-=w;
            }
            else if(dir=='l')
            {
                dir='d';
                i++;
                if(i>=h)i-=h;
            }
        }
    }
    for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++)
        {
            if(vec[i][j])cout<<"#";
            else cout<<".";
        }
        cout<<endl;
    }
    return 0;
}


