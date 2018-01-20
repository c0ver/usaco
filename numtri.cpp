/*
ID: LGD84711
LANG: C++
TASK: numtri
*/
#include <fstream>
using namespace std;

ifstream fin ("numtri.in");
ofstream fout ("numtri.out");

struct structtriangle
{
    int row[1000];
};


int r;

int main()
{
    fin >> r;
    structtriangle tri[r+1];
    for(int x=1; x<=r; x++){
        for(int y=0; y<x; y++){
            fin >> tri[x].row[y];
            //fout << tri[x].row[y] << " ";
        }
        //fout << endl;
    }

    for(int x=r; x!=0; x--){
        for(int y=0; y<x; y++){
            if(tri[x].row[y]>tri[x].row[y+1]){
                tri[x-1].row[y]+=tri[x].row[y];
            }
            else{
                tri[x-1].row[y]+=tri[x].row[y+1];
            }
        }
    }
    fout << tri[1].row[0] << endl;
    return 0;
}
