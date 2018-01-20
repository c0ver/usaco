#include <fstream>
#include <algorithm>
using namespace std;

int high, card[50000], my[50000], point;
int c1; //counter for player1
int c2; //counter for player2

int main()
{
	ifstream fin ("highcard.in");
	ofstream fout ("highcard.out");
	
	fin >> high;
	for(int x=0; x<high; x++){
		fin >> card[x];	
	}
	sort(card, card+high);
	
	for(int x=1; x<=2*high; x++){
		if(card[c1]!=x){
			my[c2]=x;
			c2++;
		}
		else{
			c1++;
		}
	}
	
	c1=0;
	c2=0;
	for(int x=0; x<high; x++){
		if(my[c2]>card[c1]){
			point++;
			c1++;
			c2++;
		}
		else{
			c2++;
		}
	}
	fout << point << endl;
}