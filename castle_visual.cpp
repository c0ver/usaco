//this prints a representation of the castle in the castle problem in USACO
#include <fstream>
#include <iostream>
using namespace std;

int col, row;

int main()
{
    ifstream fin ("castle.in");

    fin >> col >> row;

    for(int x=1; x<=col; x++) cout << "   " << x;
    cout << endl;
    cout << "  #";
    for(int x=0; x<col; x++) cout << "####";
    cout << endl;

    for(int y=1; y<=row; y++){
        int walls;
        bool S[50] = { false};
        cout << y << " #";
        for(int x=1; x<=col; x++){
            bool E;
            E = false;
            fin >> walls;
            while(walls != 0){
                if(walls >= 8){
                    S[x] = true;
                    walls -= 8;
                }
                if(walls >= 4){
                    E = true;
                    walls -= 4;
                }
                if(walls >= 2){
                    walls -= 2; // useless
                }
                if(walls >= 1){
                    walls -= 1;
                }             
            }
            cout << "   ";
            if(E == true) cout << "#";
            else cout << "|";
        }
        cout << endl;
        cout << "  ";
        for(int x=1; x<=col; x++){
            cout << "#";
            if(S[x] == true) cout << "###";
            else cout << "---";
        }
        cout << "#";
        cout << endl;
    }
}