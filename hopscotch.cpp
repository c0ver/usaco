#include <fstream>
using namespace std;

int x, y, total;
char table[15][15], first;

int main()
{
    ifstream fin ("hopscotch.in");
    ofstream fout ("hopscotch.out");

    fin >> x >> y;
    for(int n=0; n<x; n++){
        for(int n1=0; n1<y; n1++){
            fin >> table[n][n1];
        }
    }

    first=table[0][0];

    for(int n=1; n<x-1; n++){
        for(int n1=1; n1<y-1; n1++){
            if(first!=table[n][n1]){
                total++;
            }
        }
    }

    if(x==2 && y==2 && first!=table[1][1]){
        fout << 1 << endl;
        return 0;
    }

    if(x==3 && y==2 && first!=table[2][1]){
        fout << 1 << endl;
        return 0;
    }

    if(x==2 && y==3 && first!=table[1][2]){
        fout << 1 << endl;
        return 0;
    }

    if(x==3 && y==3 && first!=table[1][1] && first==table[2][2]){
        fout << 1 << endl;
        return 0;
    }

    fout << total << endl;

}
