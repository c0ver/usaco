/*
ID: LGD84711
LANG: C++
TASK: beads
*/
#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;

int numb, maximum, amount, pre, previous;
string beads;
char bead;

int main()
{
    ifstream fin ("beads.in");
    ofstream fout ("beads.out");

    fin >> numb >> beads;
    previous=beads.length();
    beads=beads+beads;
    maximum=beads.length();
    int mid = 0;
    for(int counter=0; counter<maximum; counter++){
        pre++;
        bead=beads[counter];
        for(int counters=counter; counters<maximum; counters++){
            if(bead=='w'){
                bead=beads[counters+1];
            }
            if(bead==beads[counters+1] || beads[counters+1]=='w'){
                pre++;
            }
            else{
                break;
            }
        }
        bead=beads[counter-1];
        pre++;
        for(int counters=counter-1; counters>=1; counters--){
            if(bead=='w'){
                bead=beads[counters-1];
            }
            if(bead==beads[counters-1] || beads[counters-1]=='w'){
                pre++;
            }
            else{
                break;
            }
        }
        if(amount<pre){
            mid = counter;
            amount=pre;
        }
        pre=0;
    }
    if(amount>previous){
        amount=previous;
    }
    fout << amount << endl;
}

