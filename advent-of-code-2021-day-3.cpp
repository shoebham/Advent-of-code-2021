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

// part 1
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

void solve2(vector<string> arr,int size)
{
	map<string,int> count_one;
	map<string,int> count_zero;
	vector<string> one;
	vector<string> zero;
	int c0=0;
	int c1=0;
	vector<string> newarr=arr;
	string oxy;
	string co2;
		// oxygen generator rating
		rep(j,arr[0].length())
		{
			one.clear();
			c1=0;
			c0=0;
			zero.clear();
			size=arr.size();
			rep(i,size)
			{
				if(arr[i][j]=='1')
				{
					one.push_back(arr[i]);		
					c1++;
				}
				else
				{
					zero.push_back(arr[i]);
					c0++;
				}
			}
			// cout<<"j "<<j<<" ";
			// cout<<"c1 "<<c1<<" c0 "<<c0<<endl;
			// for(auto x:arr)cout<<x<<"\n";
			// for(auto x:one)cout<<x<<"\n";
			if(c1>=c0)
			{
				arr.clear();
				arr.resize(one.size());
				rep(k,one.size())
				{
					arr[k]=one[k];
				}
			}
			else
			{
				arr.clear();
				arr.resize(zero.size());
				rep(k,zero.size())
				{
					arr[k]=zero[k];
				}	
			}
		}
		// for(auto x:arr)cout<<x<<"\n";
		oxy=arr[0];
		one.clear();
		zero.clear();
		c0=0;
		c1=0;
		// co2 scrubber rating 
		rep(j,newarr[0].length())
		{
			one.clear();
			c1=0;
			c0=0;
			zero.clear();
			size=newarr.size();
			rep(i,size)
			{
				if(newarr[i][j]=='1')
				{
					one.push_back(newarr[i]);		
					c1++;
				}
				else
				{
					zero.push_back(newarr[i]);
					c0++;
				}
			}
			// cout<<"j "<<j<<" ";
			// cout<<"c1 "<<c1<<" c0 "<<c0<<endl;
			// for(auto x:arr)cout<<x<<"\n";
			// for(auto x:one)cout<<x<<"\n";
			if(c1>=c0)
			{
				newarr.clear();
				newarr.resize(zero.size());
				rep(k,zero.size())
				{
					newarr[k]=zero[k];
				}
			}
			else
			{
				newarr.clear();
				newarr.resize(one.size());
				rep(k,one.size())
				{
					newarr[k]=one[k];
				}	
			}
		}
		co2=newarr[0];
		// cout<<oxy<< " "<<co2;
		int oxygen=stoi(oxy,0,2);
		int carbon=stoi(co2,0,2);

		cout<<oxygen*carbon;
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
    solve2(arr,size);
    return 0;
}