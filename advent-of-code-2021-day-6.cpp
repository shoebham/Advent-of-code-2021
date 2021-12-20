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

void solve(vector<int> arr, int days)
{
	int size=arr.size();
	int sum=0;
	// cout<<"Day "<<0<<": ";
 //    for(auto x:arr)cout<<x<<",";
 //    cout<<endl;
    for(int i=1;i<=days;i++)
    {
		// cout<<"Day "<<i<<": ";
    	size=arr.size();
    	for(int j=0;j<size;j++)
    	{
    		if(arr[j]==0)
    		{
    			arr[j]=6;
    			arr.push_back(8);
    			continue;
    		}
    		else
    			arr[j]--;
    	}
    	// for(auto x:arr)cout<<x<<",";
    	// 	cout<<endl;
    }
    
   	cout<<arr.size()<<"\n";
}

int main()
{
    init_code();
  	string del;
  	string in;
  	int n;
  	vector<int> arr;
  	cin>>in;
  	stringstream ss(in);
  	while(ss>>n)
  	{
  		arr.push_back(n);
  		if(ss.peek()==',')
  			ss.ignore();
  	}
  	int days=80;
  	solve(arr,days);
    return 0;
}