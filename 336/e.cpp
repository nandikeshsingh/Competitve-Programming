#include <bits/stdc++.h>
#define double long double
#define int long long
#define mp make_pair
using namespace std;
int b[16],dp[16][136][136][136],cnt;
int solve(int n,int sum,int mod,int s,int limit)
{
	if(n==0)
		return mod==0 && s==sum;
	if(s>sum)
		return 0;
	if(!limit and dp[n][mod][s][sum]!=-1)
	{
		return dp[n][mod][s][sum];
	}
	int ans=0;
	int upper=(limit?b[n]:9);
	for(int i=0;i<=upper;i++)
	{
		ans+=solve(n-1,sum,(mod*10+i)%sum,s+i,limit && (i==upper));
	}
	if(!limit)
		dp[n][mod][s][sum]=ans;
	return ans;
}
int solve1(int n)
{
	cnt=0;
	int temp=n;
	while(temp!=0)
	{
		b[cnt+1]=temp%10;
		temp/=10;
		cnt++;
	}
	int ans=0;
	for(int i=1;i<=126;i++)
	{
		ans+=solve(cnt,i,0,0,1);
	}
	return ans;
}
signed main()
{

//	int s=clock();
    memset(dp,-1,sizeof dp);
	int t=1;
	while(t--)
	{
		int l=1,r;
		cin>>r;
		cout<<solve1(r)-solve1(l-1)<<endl;
	}
//	int e=clock();
//	cout << "time: " << ((e-s)/(double)CLOCKS_PER_SEC)*1000 << endl;
	return 0;
} 