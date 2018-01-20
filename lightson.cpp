#include <fstream>
using namespace std;

int s, switches, counter, grid[110][110];
bool change;

int main()
{
	ifstream fin ("lightson.in");
	ofstream fout ("lightson.out");
	
	fin >> s >> switches;
	
	int loc[switches][4]; // input location and use of switches
	for(int row=0; row<switches; row++){
		for(int column=0; column<4; column++){
			fin >> loc[row][column];
			//fout << loc[row][column] << " ";
		}
		//fout << endl;
	}
	
	grid[1][1]=2;
	do{
		change=false;
		for(int x=0; x<switches; x++){
			if(grid[loc[x][0]-1][loc[x][1]]==2 || grid[loc[x][0]][loc[x][1]-1]==2 || grid[loc[x][0]+1][loc[x][1]]==2 || grid[loc[x][0]][loc[x][1]+1]==2 || grid[loc[x][0]][loc[x][1]]==2){
				if(grid[loc[x][0]][loc[x][1]]>0 && grid[loc[x][2]][loc[x][3]]==0){
					grid[loc[x][2]][loc[x][3]]=1;
					change=true;					
				}
			}
			for(int row=1; row<s+1; row++){
				for(int column=1; column<s+1; column++){
					if(grid[row][column]==1 && grid[row+1][column]==2){
						grid[row][column]=2;
					}
					if(grid[row][column]==1 && grid[row][column+1]==2){
						grid[row][column]=2;
					}
					if(grid[row][column]==1 && grid[row-1][column]==2){
						grid[row][column]=2;						
					}
					if(grid[row][column]==1 && grid[row][column-1]==2){
						grid[row][column]=2;
					}
				}
			}

		}
	}while(change==true);
	
	for(int row=0; row<s+1; row++){
		for(int column=0; column<s+1; column++){
			//fout << grid[row][column] << " ";
			if(grid[row][column]>0){
				counter++;
			}
		}
		//fout << endl;
	}
	//fout << endl;
	fout << counter << endl;
}