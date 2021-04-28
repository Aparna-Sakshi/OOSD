#include <bits/stdc++.h>
using namespace std;

//dynamic programming
int dp[pow(3,9)];

void initializedp()
{
	for(i=0; i< pow(3,9);i++)
	{
		dp[i]=-2;
	}
}

int** initState()
{
	int** new_state = (int**)malloc(sizeof(int*)*3);
	for(i=0;i<3;i++)
	{
		new_state[i] = (int*)malloc(sizeof(int)*3);
		
	}
	return new_state;
}

int hashState(int **state)
{
	pow3=1;
	hashcode = 0;

	for(i=0;i<3;i++)
	{
		for(j=0; j<3; j++)
		{
			hashcode += pow3*((state[i][j]+3)%3)
			pow*=3;
		}
	}
	return hashcode;
}

int getState(int hashcode)
{
	state = initState();
	for(i=0;i<3;i++)
	{
		for(j=0; j<3; j++)
		{

			state[i][j] = hashcode%3;
			if(state[i][j] == 2)
			{
				state[i][j] = -1;
			}
			hashcode/=3;
		}
	}
	return state;
}


int gameWon(int p, int **arr)//Checks for game won, p=1 for X, p=-1 for Y
{
	//check for all 3 rows and col
    for(int i=0;i<3;i++)
    {
        if((arr[i][0]==p && arr[i][0]==arr[i][1] && arr[i][1]==arr[i][2]) || (arr[0][i]!=p && arr[0][i]==arr[1][i] && arr[1][i]==arr[2][i])) 
            return 1;
    }
    
    //check for diagonal
    if(arr[0][0]==p&&arr[0][0]==arr[1][1]&&arr[1][1]==arr[2][2])  
    {
        return 1;
    }
    //check for other diagonal
    else if(arr[0][2]==p&&arr[0][2]==arr[1][1]&&arr[1][1]==arr[2][0]) 
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int computerMove(int** state, int i, int j)//1 if X's chance, -1 if players chance
{
	bool flag;
	
	if(i=0;)
	//computer moves
	state[i][j] = 1;
	int hashcode = hashState(state);
	if(dp[hashcode]!=-2)
	{
		return dp[hashcode];
	}
	//computer wins		
	if(gameWon(1, arr))
	{
		
		dp[hashcode] = 1; 
		return 1;
	}


	//player wins
	if(gameWon(-1,arr))
	{
		
		dp[hashcode] = -1; 
		return -1;
	}

	/*int** new_state = (int**)malloc(sizeof(int*)*3);
	for(i=0;i<3;i++)
	{
		new_state[i] = (int*)malloc(sizeof(int)*3);
		for(j=0;j<3;j++)
		{
			new_state[i][j] = state[i][j];
		}
	}*/

	int num1;
	for(int i1=0; i1<3; i1++)
	{
		for(int j1=0;j1<3;j1++)
		{
			if(state[i1][j1]==0)
			{
				int num2;
				int val1 = computerMove(state, i1, j1);
				int num2i, num2j;
				for(int i2=0; i2<3; i2++)
				{
					for(int j2=0; j2<3;j2++)
					{
						if(state[i2][j2]==0)							
						{
							int** new_state = (int**)malloc(sizeof(int*)*3);
							for(i=0;i<3;i++)
							{
								new_state[i] = (int*)malloc(sizeof(int)*3);
								for(j=0;j<3;j++)
								{
									new_state[i][j] = state[i][j];
								}
							}
							new_state[i1][j1] = -1;
							int val2 = computerMove(new_state, i2, j2);
							if(num2<val2)
							{
								num2 = val2;
								num2j = j2;
								num2i = i2;
							}
						}
					}
				}

			}
		}
	}
}


int main()
{
	int choice;
	cout<<"Please choose you want to play first or second. Enter 1 to play first and 2 to play second: "<<endl;
	cin>>choice;


	return 0;
}