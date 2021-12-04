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

void solve(vector<string> arr,int size)
{
	vector<int> count_one(arr[0].length(),0);
	vector<int> count_zero(arr[0].length(),0);
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<arr[i].length();j++)
		{
			// cout<<arr[i][j]<<endl;
			if(arr[i][j]=='1')
				count_one[j]++;
			else
				count_zero[j]++;
		}
	}
	string ans="";
	string ans2="";
	for(int i=0;i<count_one.size();i++)
	{
		// cout<<count_one[i];
		if(count_one[i]>count_zero[i])
		{
			ans+='1';
			ans2+='0';
		}
		else
		{	
			ans+='0';
			ans2+='1';
		}
	}
	int gamma = stoi(ans,0,2);
	int epsilon = stoi(ans2,0,2);
	cout<<gamma*epsilon<<endl;
}

int main()
{
    init_code();
    string s;
    vector<string> arr;
    int size=0;
    int num;
    while(cin>>s)
    {
    	arr.push_back(s);
    	size++;
    	// cout<<arr[size++]<<endl;
    	// num = stoi(n,0,2);
    	// size++;
    	// cout<<num<<endl;
    	// arr.push_back(num);
    }
    solve(arr,size);
    return 0;
}