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
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
#endif
    
}

int solve(vector<int> &arr)
{
	int ans=0;
	// part 1 
    for(int i=1;i<arr.size();i++)
    {
    	if(arr[i]>arr[i-1])
    	{
    		// cout<<arr[i]<<endl;
    		ans++;
    	}
    }

	int prevsumofthree=INT_MAX;
	int currsumofthree=0;
	int ans2=0;
    // part 2
    for(int i=0;i<arr.size()-2;i++)
    {
    	currsumofthree = arr[i]+arr[i+1]+arr[i+2];
    	if(prevsumofthree<currsumofthree)
    		ans2++;
    	prevsumofthree=currsumofthree;
    }
    return ans2;
}

int main()
{
    init_code();
    int t=2000;
    vector<int> arr(t);
    rep(i,t)
    {
    	int n;
    	cin>>arr[i];
    	
    }
    cout<<solve(arr);
    return 0;
}