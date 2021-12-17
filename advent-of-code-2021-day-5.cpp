#include <bits/stdc++.h>

#define db1(x) cout<<#x<<"="<<x<<'\n'
#define db2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<'\n'
#define db3(x,y,z) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<'\n'
#define rep(i,n) for(int i=0;i<(n);++i)
#define repA(i,a,n) for(int i=a;i<=(n);++i)
#define repD(i,a,n) for(int i=a;i>=(n);--i)
typedef long long ll;
using namespace std;


void init_code(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("D:/competitive/input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("D:/competitive/output.txt", "w", stdout);
#endif
    
}


int countDanger( vector<vector<int>> plane)
{
    int count=0;
    int size=plane.size();
    rep(i,size)
    {
        rep(j,plane[i].size())
        {
            if(plane[i][j]>1)
                count++;
        }
    }
    return count;
}
void printPlane( vector<vector<int>> plane)
{
    int size=plane.size();
    rep(i,size)
    {
        rep(j,plane[i].size())
        {
            if(plane[i][j]==0)
                cout<<".";
            else
                cout<<plane[i][j];
        }
        cout<<endl;
    }
}
void solve(    vector< pair< pair<int,int>, pair<int, int>> > start
    ,vector<pair<int,int>> end,int n,int row,int col)
{
    vector<vector<int>> plane(row+1,vector<int>(col+1,0));
    // plane.resize(row+1);
    // printPlane();
    int count=0;
    rep(i,n)
    {
        // plane[i].resize(col+1);
        // cout<<start[i].first.first<<" "<<start[i].first.second<<" -> ";
        // cout<<start[i].second.first<<" "<<start[i].second.second<<"\n";
        int x1=start[i].first.first;
        int x2=start[i].second.first;
        int y1=start[i].first.second;
        int y2=start[i].second.second;
        cout<<x1<<" "<<y1<<"->"<<x2<<" "<<y2<<endl;


        if(x1==x2)
        {
            if(y1>y2)
            {
                while(y2!=(y1+1))
                    plane[y2++][x2]++;
            }
            else if(y2>y1)
            {
                while(y1!=(y2+1))
                    plane[y1++][x2]++;
            }
        }
        else if(y1==y2)
        {
            if(x1>x2)
            {
                while(x2!=(x1+1))
                    plane[y2][x2++]++;
            }
            else if(x2>x1)
            {
                while(x1!=(x2+1))
                    plane[y2][x1++]++;
            }

        }
        else if(x1==x2&&y1==y2)
        {
            plane[y1][x1]++;
        }
    }
    printPlane(plane);
    count=countDanger(plane);
    cout<<count<<endl;
}
void solve2(    vector< pair< pair<int,int>, pair<int, int>> > start
    ,vector<pair<int,int>> end,int n,int row,int col)
{
    vector<vector<int>> plane(row+1,vector<int>(col+1,0));
    // plane.resize(row+1);
    // printPlane();
    int count=0;
    rep(i,n)
    {
        // plane[i].resize(col+1);
        // cout<<start[i].first.first<<" "<<start[i].first.second<<" -> ";
        // cout<<start[i].second.first<<" "<<start[i].second.second<<"\n";
        int x1=start[i].first.first;
        int x2=start[i].second.first;
        int y1=start[i].first.second;
        int y2=start[i].second.second;
        cout<<x1<<" "<<y1<<"->"<<x2<<" "<<y2<<endl;


        if(x1==x2)
        {
            if(y1>y2)
            {
                while(y2!=(y1+1))
                    plane[y2++][x2]++;
            }
            else if(y2>y1)
            {
                while(y1!=(y2+1))
                    plane[y1++][x2]++;
            }
        }
        else if(y1==y2)
        {
            if(x1>x2)
            {
                while(x2!=(x1+1))
                    plane[y2][x2++]++;
            }
            else if(x2>x1)
            {
                while(x1!=(x2+1))
                    plane[y2][x1++]++;
            }

        }
        else if(x1==x2&&y1==y2)
        {
            plane[y1][x1]++;
        }
        else
        {
                if(y1>y2&&x1>x2){
                    while((y1+1)!=y2&&(x1+1)!=x2)
                        plane[y2++][x2++]++;
                }
                else if(y2>y1&&x2>x1)
                {
                    while((y2+1)!=y1&&(x2+1)!=x1)
                        plane[y1++][x1++]++;
                }
                else if(x1>x2&&y2>y1)
                {
                    while(x2!=(x1+1)&&(y2!=y1-1))
                        plane[y2--][x2++]++;
                }
                else if(x2>x1&&y1>y2)
                {
                    while(x1!=(x2+1)&&y1!=(y2-1))
                        plane[y1--][x1++]++;
                }
        }
    }
    // printPlane(plane);
    count=countDanger(plane);
    cout<<count<<endl;
}
int main()
{
    init_code();
    string str;
    vector< pair< pair<int,int>, pair<int, int>> > start;
    vector<pair<int,int>> end;
    
    int x,y,x2,y2;
    char c1,c2;
    string del;
    int row=INT_MIN,col=INT_MIN;
    while(getline(cin,str))
    {
        stringstream ss(str);
        ss>>x>>c1>>y>>del>>x2>>c2>>y2;
        start.push_back({{x,y},{x2,y2}});
        end.push_back({x2,y2});
        col=max(col,max(x,x2));
        row=max(row,max(y,y2));
    }
    sort(start.begin(), start.end());
    // sort(end.begin(), end.end());
    int n=start.size();
    // cout<<"rows"<<row<<" cols"<<col;
    solve2(start,end,n,row,col);

}