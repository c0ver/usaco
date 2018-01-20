#include <fstream>
using namespace std;

int n, id, longest;
long long add[50000];

int main()
{
    ifstream fin ("div7.in");
    ofstream fout ("div7.out");

    fin >> n >> add[0];
    //fout << add[0] << endl;
    for(int x=1; x<n; x++){
        fin >> id;
        add[x] = add[x-1] + id;
        //fout << add[x] << endl;
    }
    //fout << endl;

    for(int x=n-1; x>0; x--){
        for(int y=0; y<x; y++){
            if(x - y <= longest){
                if(y == 0){
                    fout << longest << endl;
                    return 0;
                }
                break;
            }
            //fout << x << " " << y << endl;
            if((add[x] - add[y]) % 7 == 0 && x - y > longest){
                longest = x - y;
                //fout << longest << endl;
            }
            //fout << endl;
        }
    }
    fout << longest << endl;
}
