#include <fstream>
#include <iostream>
#include <cmath>
using namespace std;

ifstream fin ("moocast.in");
ofstream fout ("moocast.out");

int N;

struct cow_stats{
	int x;
	int y;
	int power;
};
cow_stats cow[200];

bool cow_check[200];

void find_max_cows(int start) {
	cow_check[start] = true;
	for(int x=0; x<N; x++) {
		if(cow_check[x] == true) continue;
		double distance = sqrt((cow[start].x - cow[x].x) * (cow[start].x - cow[x].x) + (cow[start].y - cow[x].y) * (cow[start].y - cow[x].y));
		if(distance < cow[start].power){
			find_max_cows(x);
		}
	}
}

int main()
{
	fin >> N;
	
	for(int x=0; x<N; x++) {
		fin >> cow[x].x >> cow[x].y >> cow[x].power;
	}

	int max_cows = 0;
	for(int x=0; x<N; x++) {
		find_max_cows(x);
		int numb = 0;
		for(int y=0; y<N; y++) {
			if(cow_check[y] == true) {
				numb++;
				cow_check[y] = false;
			}
		}
		if(numb > max_cows) max_cows = numb;
	}
	cout << max_cows << endl;
	fout << max_cows << endl;
}