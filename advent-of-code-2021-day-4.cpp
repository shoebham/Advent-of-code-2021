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

void printb(vector<vector<int>> board)
{
	for(auto x:board)
	{
		for(auto y:x)
		{
			cout<<y<<" ";
		}
		cout<<endl;
	}
}

// part 1
pair<vector<vector<int>>,int> solve(vector<vector<vector<int>>> boards, vector<int> in)
{
	// int x=0;
	bool win=false;
	vector<vector<int>> winner;
	rep(x,in.size())
	{
		// cout<<"x= "<<in[x]<<"\n";
		rep(i, boards.size())
		{
			int col=0,row=0;
			win=false;
			rep(j,boards[i].size())
			{
				rep(k,boards[i][j].size())
				{
					// cout<<boards[i][j][k]<<" ";
					// cout<<boards[i][j][k]<<" ";
					if(boards[i][j][k]==in[x])
					{
						boards[i][j][k]=-1;
					}
					if(boards[i][j][k]==-1)
					{
						while(boards[i][j][col]==-1)
						{
							col++;
							if(col==5)
							{
								// cout<<"Column matches";
								win=true;
								winner=boards[i];
								return {winner,in[x]};
							}
						}
						row=0;col=0;
						while(boards[i][row][k]==-1)
						{
						
							row++;
							if(row==5)
							{
								// cout<<in[x]<<" ";
								// cout<<boards[i][row][k]<<"\n";
								// cout<<"i= "<<i<<" j= "<<j<<" k="<<k<<endl;
								// cout<<"-------\n";

								// cout<<"Row matches";
								// cout<<in[x]<<" ";
								winner=boards[i];
								win=true;
								return {winner,in[x]};
							}
						}
						row=0;col=0;
					}
				}
				// cout<<endl;
			}
			// cout<<endl;
		}
	}

	// rep(i,winner.size())
	// {
	// 	rep(j,winner[i].size())
	// 	{
	// 		cout<<winner[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }
	// int q=0;
	// int p=0;
	// int count=0;
	// bool win=false;
	// 	rep(i,board.size())
	// 	{
	// 		rep(j,board[i].size())
	// 		{
	// 			if(board[i][j]==-1&&i%5!=0)
	// 			{
	// 				while(board[i][q++]==-1)
	// 				{
	// 					count++;
	// 					if(count==5)
	// 					{
	// 						win=true;
	// 						break;
	// 					}
	// 				}
	// 			}
	// 			if(board[i][j]==-1&&i%5==0)
	// 			{
	// 				while(board[p++][j]==-1)
	// 				{
	// 					count++;
	// 					if(count==5)
	// 					{
	// 						win=true;
	// 						break;

	// 					}
	// 				}
	// 			}
	// 		}
	// 	}
	// 	printb(board);
}

int board_sum_unmarked(vector<vector<int>> board)
{
	int sum=0;
	rep(i, board.size())
	{
		rep(j,board[i].size())
		{
			if(board[i][j]!=-1)
				sum+=board[i][j];
		}
	}
	return sum;
}
int main()
{
    init_code();
    vector<int> in;
    string str;
    getline(cin,str);

    stringstream ss(str);
    int x;
    while(ss>>x)
    {
    	in.push_back(x);
    	if(ss.peek()==',')
    		ss.ignore();
    }
    // for(auto x:in)cout<<x<<" ";
    vector<vector<int>> board(5,vector<int>(5));
	vector<vector<vector<int>>> boards;
    int row=5, col=5;
	int n;
	int i=0,j=0;
	while(cin>>n)
	{
		if(j==5)
		{
			j=0;
			i++;
		}
		if(i==5)
		{
			boards.push_back(board);
			i=0;
			j=0;
		}
		board[i][j++]=n;
	}
	boards.push_back(board);
	pair<vector<vector<int>>,int> winner;
	winner = solve(boards,in);
	int number_called=winner.second;
	int sum_unmarked =  board_sum_unmarked(winner.first);
	// printb(winner.first);
	int ans = sum_unmarked*number_called;
	cout<<ans;
}