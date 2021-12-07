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

}
pair<vector<vector<int>>,pair<int,int>> solve2(vector<vector<int>> board, vector<int> in)
{
	vector<vector<int>> winner;
	int winningnum=0;
	int row=0;
	int col=0;
	int count=0;
	rep(x,in.size())
	{
		rep(i,board.size())
		{
			count=0;		
			rep(j,board[i].size())
			{
				// cout<<board[i][j]<<" "; 
				
					if(board[i][j]==in[x])
						board[i][j]=-1;
					if(board[i][j]==-1)
					{
						while(board[i][col]==-1)
						{
							col++;
							if(col==5)
							{
								winner=board;
								winningnum=in[x];
								count=x;
								return {winner,{in[x],count}};
							}
						}
						col=0;row=0;
						while(board[row][j]==-1)
						{
							row++;

							if(row==5)
							{
								winner=board;
								winningnum=in[x];
								count=x;
								return {winner,{in[x],count}};

							}
							
						}
						col=0;row=0;
					}

				}
			}	
		}
	return {winner,{in[0],count}};
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
	int lastNum = in.back();

	pair<vector<vector<int>>,pair<int,int>> winner;
	vector<vector<int>> winnerboard;

	int bestCount=0;
	rep(i,boards.size())
	{
		winner = solve2(boards[i],in);
		// printb(winner.first);
		// cout<<winner.second.first<<" "<<winner.second.second<<"\n";
		if(winner.second.second>bestCount)
		{
			winnerboard=winner.first;
			lastNum=winner.second.first;
		}
		bestCount=max(bestCount,winner.second.second);
		
	}
	// printb(winnerboard);
	int sum_unmarked = board_sum_unmarked(winnerboard);
	cout<<sum_unmarked<<" "<<lastNum<<" ";
	int ans = sum_unmarked*lastNum;
	cout<<ans<<endl;
	// pair<vector<vector<int>>,int> winner;
	// winner = solve1(boards,in);
	// // int number_called=winner.second;
	// // int sum_unmarked =  board_sum_unmarked(winner.first);
	// printb(winner.first);
	// // int ans = sum_unmarked*number_called;
	// // cout<<ans;
}