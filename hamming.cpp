#include <iostream>
#include <fstream>
#include <bitset>
using namespace std;

int N, B, D;

int main()
{
	ifstream fin ("hamming.in");
	ofstream fout ("hamming.out");

	fin >> N >> B >> D;

	int potential[N];

	int N_found = 0;
	int counter = 0;
	
	while(N_found < N){
		string binary = bitset<8>(counter).to_string();
		cout << binary << endl;
	    cout << counter << endl << endl;

	    bool ok_distance = true;
	    for(int x=0; x<counter; x++){

	    }
	    if(ok_distance == true){
	    	potential[N_found] = counter;
	    }

	    counter++;
	    N_found++;
    }
}