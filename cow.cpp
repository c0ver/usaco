#include <fstream>
#include <string>
using namespace std;

string code;
int l, n, c, o, w, n1;
long long total;

int main()
{
    ifstream fin ("cow.in");
    ofstream fout ("cow.out");
    fin >> l >> code;

    for(int x=0; x<l; x++){
        if(code[x]=='C'){
            for(int x1=x; x1<l; x1++){
                if(code[x1]=='O'){
                    for(int x2=x1; x2<l; x2++){
                        if(code[x2]=='W'){
                            total++;
                        }
                    }
                }
            }
        }
    }
    fout << total << endl;
}
