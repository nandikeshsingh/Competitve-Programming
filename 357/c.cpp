#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define fo(i,n)   for(int i=0;i<(n);++i)
#define rep(i,a,b)   for(int i=(a);i<=(b);++i)
#define per(i,b,a)   for(int i=(b);i>=(a);--i)
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
#define pb push_back
#define F first
#define S second
using namespace std;
using ii = pair<int,int>;
using vii = vector<ii>;
using vi = vector<int>;
signed main()
{
    speed;
    vector<vector<vector<char>>>vec(7);
    rep(k,0,6)
    {
        if(k==0)
        {
            vector<vector<char>>temp(1,vector<char>(1));
            temp[0][0]='#';
            vec[k]=temp;
        }
        else 
        {
            int val=pow(3,k);
            int lval=pow(3,k-1);
            vector<vector<char>>temp(val,vector<char>(val));
            int li=0,lj=0;
            rep(i,0,val-1)
            {
                rep(j,0,val-1)
                {
                    temp[i][j]=vec[k-1][li][lj];
                    lj++;
                    if(lj>=lval)lj-=lval;
                }
                li++;
                if(li>=lval)li-=lval;
            }
            int si=val/2,sj=val/2;
            int len=lval;
            si-=(lval/2);
            sj-=(lval/2);
            rep(i,si,si+len-1)
            {
                rep(j,sj,sj+len-1)
                temp[i][j]='.';
            }
            // cout<<"Printing temp"<<endl;
            // rep(i,0,val-1)
            // {
            //     rep(j,0,val-1)
            //     cout<<temp[i][j];
            //     cout<<endl;
            // }
            vec[k]=temp;
        }
    }
    int n;
    cin>>n;
    int val=pow(3,n);
    rep(i,0,val-1)
    {
        rep(j,0,val-1)
        {
            cout<<vec[n][i][j];
        }
        cout<<endl;
    }
    return 0;
}


