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

void solve()
{
    
}

int main()
{
    init_code();
 	string s;
 	int n;
 	int x=0;
 	int y=0;
 	// ------part 1-------
 	// f 5 x+5
 	// u 5 y-5
 	// d 5 y+5
 	// while(cin>>s>>n)
 	// {
 	// 	if(s=="forward")
 	// 		x+=n;
 	// 	if(s=="up")
 	// 		y-=n;
 	// 	if(s=="down")
 	// 		y+=n;
 	// }
 	// int ans=x*y;
 	// cout<<ans<<endl;
 	// ------------------- 	
 	// ------Part 2---------
 	int aim=0;
 	while(cin>>s>>n)
 	{
 		if(s=="forward")
 		{
 			x+=n;
 			y+= aim*n;
 		}
 		if(s=="down")
 			aim+=n;
 		if(s=="up")
 			aim-=n;
 	}
 	int ans=x*y;
 	cout<<ans<<endl;
    return 0;
}