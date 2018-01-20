#include <fstream>
using namespace std;

struct road
{
	int segment;
	int limit;
};

struct travel
{
	int length;
	int mph;
};

int n, m, nc, mc, over, speed, control;

int main()
{
	ifstream fin ("speeding.in");
	ofstream fout ("speeding.out");

	fin >> n >> m;
	road problem[n];
	travel travel1[m];

	for(int x=0; x<n; x++){
		fin >> problem[x].segment >> problem[x].limit;
	}
	for(int x=0; x<m; x++){
		fin >> travel1[x].length >> travel1[x].mph;
	}

	for(int x=1; x<=100; x++){
		if(x>travel1[mc].length){
			mc++;
			travel1[mc].length+=travel1[mc-1].length;
		}
		speed=travel1[mc].mph;
		if(x>problem[nc].segment){
			nc++;
			problem[nc].segment+=problem[nc-1].segment;
		}
		control=problem[nc].limit;

		if(over<(speed-control)){
			over=speed-control;
		}
	}
	fout << over << endl;
}
