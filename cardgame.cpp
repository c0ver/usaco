#include <fstream>
#include <algorithm>
using namespace std;

ifstream fin ("cardgame.in");
ofstream fout ("cardgame.out");

int n, you[50000], myhigh[25000], mylow[25000], point;
int c1; //counter for player1
int c2; //counter for player2

int main()
{
    fin >> n;
	for(int x=0; x<n; x++){
		fin >> you[x];
	}
	sort(you, you+n);

	for(c2<n;){
		if(you[c1]!=x){
			mylow[c2]=x;
            fout << mylow[c2] << endl;
			c2++;
		}
		else{
			c1++;
		}
	}
    fout << endl;
    for(c2<n*2;){
		if(you[c1]!=x){
			myhigh[c2]=x;
            fout << myhigh[c2] << endl;
			c2++;
		}
		else{
			c1++;
		}
	}


	fout << point << endl;
}
