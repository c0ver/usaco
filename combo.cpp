/*
ID: LGD84711
LANG: C++
TASK: combo
*/
#include <fstream>
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    ifstream fin ("combo.in");
    ofstream fout ("combo.out");

    int maxN, setLock[3], masterLock[3], total = 0;
    fin >> maxN;
    for(int x=0; x<3; x++) fin >> setLock[x];
    for(int x=0; x<3; x++) fin >> masterLock[x];

    int x[3];
    for(x[0]=1; x[0]<=maxN; x[0]++) {
        for(x[1]=1; x[1]<=maxN; x[1]++) {
            for(x[2]=1; x[2]<=maxN; x[2]++) {
                bool incorrect = false;
                for(int i=0; i<3; i++) {
                    if(abs(x[i] - setLock[i]) < maxN - 2 && abs(x[i] - setLock[i]) > 2){
                        incorrect = true;
                        break;
                    }
                }
                if(incorrect == false){
                    total++;
                    continue;
                }

                incorrect = false;
                for(int i=0; i<3; i++) {
                    if(abs(x[i] - masterLock[i]) < maxN - 2 && abs(x[i] - masterLock[i]) > 2){
                        incorrect = true;
                        break;
                    }
                }
                if(incorrect == false){
                    total++;
                }
            }
        }
    }
    fout << total << endl;
}