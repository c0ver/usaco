/*
ID: LGD84711
LANG: C++
TASK: dualpal
*/
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int numb, low, found, remain, more, place, length, divide, p, d, alm;
string palin, test;

int main()
{
    ifstream fin ("dualpal.in");
    ofstream fout ("dualpal.out");

    fin >> numb >> low;

    more=low+1;
    for(int x=0; x<numb; x++){
        d=0;
        found=0;
        while(found<2){
            place=more;
            //fout << endl;
            //fout << more << endl;
            for(int y=2; y<=10; y++){
                do{
                    remain=more%y;
                    more=more/y;
                    ostringstream convert;
                    convert << remain;
                    test=convert.str();
                    palin.insert(0, test);
                }while(more>0);
                //fout << palin << endl;
                more=place;
                length=palin.length();
                divide=length/2;
                if(divide==0){
                    divide=1;
                }
                for(int a=0; a<divide; a++){
                    if(palin[a]==palin[length-a-1]){
                        p=1;
                    }
                    else{
                        p=0;
                        break;
                    }
                }
                //fout << divide << endl;
                palin.clear();
                if(p==1){
                    found++;
                }
                p=0;
                if(found>1){
                    fout << more << endl;
                    break;
                }
                if(y==10){
                    d=1;
                    break;
                }
            }
            if(d==1){
                x=x-1;
                break;
            }
            //fout << endl;
        }
        more=place+1;
    }
}
