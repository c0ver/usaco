/*
ID: LGD84711
LANG: C++
TASK: namenum
*/
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int length, z;
long long numb;
string names[5000], nnames[5000], test;

int main()
{
    ifstream fin ("dict.txt");
    ofstream fout ("namenum.out");

    for(int x=0; x<5000; x++){
        fin >> names[x];
        nnames[x]=names[x];
    }
    for(int x=0; x<5000; x++){
        length=names[x].length();
        for(int y=0; y<length; y++){
            if(names[x][y]=='A'||names[x][y]=='B'||names[x][y]=='C'){
                nnames[x][y]='2';
            }
            else if(names[x][y]=='D'||names[x][y]=='E'||names[x][y]=='F'){
                nnames[x][y]='3';
            }
            else if(names[x][y]=='G'||names[x][y]=='H'||names[x][y]=='I'){
                nnames[x][y]='4';
            }
            else if(names[x][y]=='J'||names[x][y]=='K'||names[x][y]=='L'){
                nnames[x][y]='5';
            }
            else if(names[x][y]=='M'||names[x][y]=='N'||names[x][y]=='O'){
                nnames[x][y]='6';
            }
            else if(names[x][y]=='P'||names[x][y]=='R'||names[x][y]=='S'){
                nnames[x][y]='7';
            }
            else if(names[x][y]=='T'||names[x][y]=='U'||names[x][y]=='V'){
                nnames[x][y]='8';
            }
            else if(names[x][y]=='W'||names[x][y]=='X'||names[x][y]=='Y'){
                nnames[x][y]='9';
            }
        }
    }
    ifstream fin2 ("namenum.in");

    fin2 >> numb;
    ostringstream convert;
    convert << numb;
    test=convert.str();
    z=0;
    for(int x=0; x<5000; x++){
        if(test==nnames[x]){
            fout << names[x] << endl;
            z=1;
        }
    }
    if(z==0){
        fout << "NONE" << endl;
    }
}
