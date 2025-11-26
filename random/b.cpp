#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
int get(int val,int f)
{
    if(f==5)
    {
        int lo=0,hi=13;
        while(lo<hi)
        {
            int mid=(lo+hi+1)>>1;
            int p=pow(5,mid);
            if(val%p==0)lo=mid;
            else hi=mid-1;
        }
        return lo;
    }
    else 
    {
        int lo=0,hi=30;
        while(lo<hi)
        {
            int mid=(lo+hi+1)>>1;
            int p=(1LL<<mid);
            if(val%p==0)lo=mid;
            else hi=mid-1;
        }
        return lo;
    }
}
signed main()
{
    speed;
    int n;
    cin>>n;
    int vec[n][n];
    bool found=0;
    int x=-1,y=-1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>vec[i][j];
            if(vec[i][j]==0)
            {
                found=1;
                x=i;
                y=j;
            }
        }
    }
    char two_path[n][n],five_path[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            two_path[i][j]='#';
            five_path[i][j]='#';
        }


    }
    int two[n][n],five[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            two[i][j]=get(vec[i][j],2);
            five[i][j]=get(vec[i][j],5);
        }
    }
    for(int j=n-1;j>=0;j--)
    {
        for(int i=n-1;i>=0;i--)
        {
            if(i==n-1 && j==n-1)continue;
            if(j==n-1 && i!=n-1)
            {
                two[i][j]+=two[i+1][j];
                five[i][j]+=five[i+1][j];
                two_path[i][j]='D';
                five_path[i][j]='D';
            }
            else if(i==n-1 && j!=n-1)
            {
                two[i][j]+=two[i][j+1];
                five[i][j]+=five[i][j+1];      
                two_path[i][j]='R';
                five_path[i][j]='R';     
            }
            else 
            {
                two[i][j]=min(two[i+1][j],two[i][j+1])+two[i][j];
                five[i][j]=min(five[i+1][j],five[i][j+1])+five[i][j];
                if(two[i+1][j]<two[i][j+1])
                    two_path[i][j]='D';
                else 
                    two_path[i][j]='R';

                if(five[i+1][j]<five[i][j+1])
                five_path[i][j]='D';
                else five_path[i][j]='R';
                
            }
        }
    }
    if(!found)
    {
        cout<<min(two[0][0],five[0][0])<<endl;
        string ans;
        if(two[0][0]<=five[0][0])
        {
            int i=0,j=0;
            while(1)
            {   
                ans+=two_path[i][j];
                if(two_path[i][j]=='D')i++;
                else j++;
                if(i==n-1 && j==n-1)break;
            }
        }
        else 
        {
            int i=0,j=0;
            while(1)
            {   
                ans+=five_path[i][j];
                if(five_path[i][j]=='D')i++;
                else j++;
                if(i==n-1 && j==n-1)break;
            }      
        }
        cout<<ans<<endl;
    }
    else 
    {
        int cur=min(two[0][0],five[0][0]);
        if(cur>=1)
        {
            cout<<1<<endl;
            string ans;
            for(int i=1;i<=x;i++)ans+='D';
            for(int j=1;j<n;j++)ans+='R';
            for(int i=1;i<=n-1-x;i++)ans+='D';
            cout<<ans<<endl;
        }
        else 
        {
            cout<<cur<<endl;
                    string ans;
        if(two[0][0]<=five[0][0])
        {
            int i=0,j=0;
            while(1)
            {   
                ans+=two_path[i][j];
                if(two_path[i][j]=='D')i++;
                else j++;
                if(i==n-1 && j==n-1)break;
            }
        }
        else 
        {
            int i=0,j=0;
            while(1)
            {   
                ans+=five_path[i][j];
                if(five_path[i][j]=='D')i++;
                else j++;
                if(i==n-1 && j==n-1)break;
            }      
        }
        cout<<ans<<endl;
        }
    }
    return 0;
}
