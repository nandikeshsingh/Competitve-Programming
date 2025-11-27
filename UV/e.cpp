#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
int h,w;
char vec[1000][1000];
int f[1000][1000];
bool vis[1000][1000];
const int mod=998244353;
int binpow(int a, int b, int m)
{
	int ans=1;
	while(b)
	{
		if(b&1)
			ans=(ans*a)%m;
		b>>=1;
		a=(a*a)%m;
	}
	return ans;
}
void floodfill(int i,int j,int val)
{
    if(i<0 || j<0 || i>=h || j>=w)return;
    if(vis[i][j])return;
    if(vec[i][j]=='.')return;
    vis[i][j]=1;
    f[i][j]=val;
    floodfill(i+1,j,val);
    floodfill(i-1,j,val);
    floodfill(i,j+1,val);
    floodfill(i,j-1,val);
}
bool isok(int i,int j)
{
    if(i>=0 && i<h && j>=0 && j<w)return 1;
    else return 0;
}
int find(int i,int j)
{
    if(isok(i,j))return f[i][j];
    else return 0;
}
int get(int i,int j)
{
    set<int>st;
    if(find(i+1,j)>0)
    st.insert(find(i+1,j));
    if(find(i-1,j)>0)
    st.insert(find(i-1,j));
    if(find(i,j-1)>0)
    st.insert(find(i,j-1));
    if(find(i,j+1)>0)
    st.insert(find(i,j+1));
    return (int)st.size();
}

signed main()
{
    speed;
    cin>>h>>w;
    int tot=0;
    for(int i=0;i<h;i++)for(int j=0;j<w;j++)cin>>vec[i][j],tot+=(vec[i][j]=='.');
    int cnt=0;
    for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++)
        {
            if(vec[i][j]=='.')continue;
            if(!vis[i][j])
            {
                cnt++;
                floodfill(i,j,cnt);
            }
        }   
    }
    int p=0;
    for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++)
        {
            if(vec[i][j]=='.')
            {
                int ret=get(i,j);
                if(ret>0)p+=(cnt-ret+1);
                else p+=(cnt+1);
            }
        }
    }
    int g=__gcd(p,tot);
    p/=g;
    tot/=g;
    int ans=binpow(tot,mod-2,mod);
    ans=(ans*(p%mod))%mod;
    cout<<ans<<endl;
    return 0;
}


