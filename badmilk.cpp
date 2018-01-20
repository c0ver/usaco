#include <fstream>
#include <algorithm>
using namespace std;

int np, nm, i, s, bm[50], c, milkc;
bool bmc[50], drank[1000], pdrink, bad;

struct structs
{
	int p;
	int milk;
	int time;
};

struct structs1
{
	int ps;
	int sicktime;
};

bool sortw(int first, int second)
{
    return first>second;
}

int main()
{
	ifstream fin ("badmilk.in");
	ofstream fout ("badmilk.out");

	fin >> np >> nm >> i >> s;
	structs instances[1000];
	structs1 people[50];

	for(int x=0; x<i; x++){
		fin >> instances[x].p >> instances[x].milk >> instances[x].time; // input instances
	}
	for(int x=0; x<s; x++){
		fin >> people[x].ps >> people[x].sicktime; // input sick people
	}

	for(int x=0; x<i; x++){ // get milk drunk by sick person 1
		if(people[0].ps==instances[x].p && people[0].sicktime>instances[x].time){
			bm[c]=instances[x].milk;
			c++;
		}
	}
	sort(bm, bm+50, sortw);

	for(int x=0; x<50; x++){
		bad=false;
		for(int y=0; y<s; y++){ // sick people
			pdrink=false;
			//fout << people[y].ps << endl;
			for(int z=0; z<i; z++){ // instances of drinking
				//fout << instances[z].p << endl << endl;
				if(people[y].ps==instances[z].p && people[y].sicktime>instances[z].time && instances[z].milk==bm[x]){
					pdrink=true;
					//fout << instances[z].p << endl;
					break;
				}
			}
			if(pdrink==false){
				bad=false;
				break;
			}
			if(pdrink==true && y==s-1){
				bad=true;
				break;
			}
		}
		if(bad==false){
			bm[x]=0;
		}
	}

	for(int x=0; x<i; x++){
		for(int y=0; y<50; y++){
			//fout << bm[y] << endl;
			if(instances[x].milk==bm[y]){
				drank[instances[x].p]=true;
				//fout << instances[x].p << endl;
			}
		}
		//fout << endl;
	}
	for(int x=0; x<1000; x++){
		if(drank[x]==true){
			milkc++;
		}
	}
	fout << milkc << endl;
}
