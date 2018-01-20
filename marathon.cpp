#include <fstream>
#include <cmath>
using namespace std;

int numb, total, distanc, skip, m;

struct structs
{
    int x;
    int y;
    int d;
};

structs checkpoints[100000];

int main()
{
    ifstream fin ("marathon.in");
    ofstream fout ("marathon.out");

    fin >> numb >> checkpoints[0].x >> checkpoints[0].y;
    for(int c=1; c<numb; c++){
        fin >> checkpoints[c].x >> checkpoints[c].y;
        checkpoints[c].d=abs(checkpoints[c].x-checkpoints[c-1].x)+abs(checkpoints[c].y-checkpoints[c-1].y);
        total+=checkpoints[c].d;
    }
    distanc=total;

    for(int c=1; c<numb-1; c++){
        skip=abs(checkpoints[c-1].x-checkpoints[c+1].x)+abs(checkpoints[c-1].y-checkpoints[c+1].y);
        m+=total+skip-checkpoints[c].d-checkpoints[c+1].d;
        if(distanc>m){
            distanc=m;
        }
        m=0;
    }
    fout << distanc << endl;
}
