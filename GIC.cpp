#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<pair<double,double>>pos;
vector<pair<int,pair<double,double>>>vec;
vector<int>t;
map<pair<double,double>,int>mp;
const int h=100;//number of home lat long points in the array/dataset
const int w=40;//number of work lat long points in the array/dataset
const int e=10;//number of errands/market lat long points in the array/dataset
const int f=5;//number of friends and family location, lat long points in the array/dataset
const int l=3;//number of leisure lat long points in the array/dataset
void shuffle()
{
    int n=(int)t.size();
    srand (time(NULL));
    for (int i = n - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);
        swap(t[i], t[j]);
    }
}
signed main()
{
    for(int i=0;i<h;i++)pos.push_back({12.45,44.78});//home
    for(int i=0;i<w;i++)pos.push_back({77.88,35.67});//work
    for(int i=0;i<e;i++)pos.push_back({19.33,67.76});//errands
    for(int i=0;i<f;i++)pos.push_back({98.76,23.55});//family and friends
    for(int i=0;i<l;i++)pos.push_back({75.32,91.34});//leisure
    for(int i=0;i<h+w+e+f+l;i++)t.push_back(i+1);
    shuffle();
    for(int i=0;i<h+w+e+f+l;i++)vec.push_back({t[i],pos[i]});
    sort(vec.begin(),vec.end());
    for(int i=1;i<h+w+e+f+l;i++)
    {
        if(vec[i].second.first==vec[i-1].second.first && vec[i].second.second==vec[i-1].second.second)
        {
            mp[{vec[i].second.first,vec[i].second.second}]+=vec[i].first-vec[i-1].first;
        }
    }
    cout<<"Priting coordinates and corresponding time spent by the car in that location"<<endl;
    for(auto& u : mp)
    {
        cout<<u.first.first<<","<<u.first.second<<"->"<<u.second<<endl;
    }
    return 0;
}

