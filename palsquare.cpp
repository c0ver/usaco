/*
ID: LGD84711
LANG: C++
TASK: palsquare
*/
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

int numb, y, z, length, divide, p, a;
string basenumb, test, palin[300], base[300];

int main()
{
    ifstream fin ("palsquare.in");
    ofstream fout ("palsquare.out");

    fin >> numb;

    for(int x=1; x<=300; x++){
        y=x*x;
        do{
            z=y%numb;
            y=y/numb;
            ostringstream convert;
            convert << z;
            test=convert.str();
            if(test.length()>1){
                test=(char)(55+z);
            }
            basenumb.insert(0, test);
        }
        while(y>0);
        palin[x-1]=basenumb;
        basenumb.clear();
        a=x;
        do{
            z=a%numb;
            a=a/numb;
            ostringstream convert;
            convert << z;
            test=convert.str();
            if(test.length()>1){
                test=(char)(55+z);
            }
            basenumb.insert(0, test);
        }
        while(a>0);
        base[x-1]=basenumb;
        basenumb.clear();
        }

    for(int x=0; x<300; x++){
        length=palin[x].length();
        divide=length/2;
        for(int a=0; a<divide; a++){
            if(palin[x][a]==palin[x][length-a-1]){
                p=1;
            }
            else{
                p=0;
                break;
            }
        }
        if(p==1||length==1){
            fout << base[x] << " " << palin[x] << endl;
        }
    }
}
