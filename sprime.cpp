/*
ID: LGD84711
LANG: C++
TASK: sprime
*/
#include <fstream>
#include <cmath>
#include <algorithm>
using namespace std;

ifstream fin ("sprime.in");
ofstream fout ("sprime.out");

int n, primec, start[4], numbc, counter;
int numb1[4], numb2[20], numb3[100], numb4[500], numb5[2500], numb6[12500], numb7[62500], numb8[62500*5];
bool pcheck;

bool sortw(int a1, int b1){
    return a1>b1;
}

int main()
{
    fin >> n;

    start[0]=2;
    start[1]=3;
    start[2]=5;
    start[3]=7;

    int x, x2;
    for(x=0; x<4; x++){ // digit 1
        numb1[x]=start[x];
    }
    if(n==1){
        for(int x=0; x<4; x++){
            fout << numb1[x] << endl;
        }
        return 0;
    }

    numbc=0;
    for(int z=0; z<x; z++){
        for(int y=1; y<=9; y+=2){ // digit 2
            numb2[numbc]=numb1[z]*10+y;
            //fout << numb2[numbc] << endl;
            numbc++;
        }
    }
    counter=numbc-1;
    for(int x=0; x<numbc; x++){
        pcheck=true;
        for(int z=3; z<=sqrt(numb2[x]); z+=2){
            if(numb2[x]%z==0){
                pcheck=false;
                break;
            }
        }
        if(pcheck==false){
            numb2[x]=0;
            counter--;
        }
    }
    sort(numb2, numb2+numbc, sortw);
    sort(numb2, numb2+counter+1);
    if(n==2){
        for(int x=0; x<=counter; x++){
            fout << numb2[x] << endl;
        }
        return 0;
    }

    numbc=0;
    for(x2=0; x2<=counter; x2++){
        for(int y=1; y<=9; y+=2){ // digit 3
            numb3[numbc]=numb2[x2]*10+y;
            //fout << numb3[numbc] << endl;
            numbc++;
        }
    }
    counter=numbc-1;
    for(int x=0; x<numbc; x++){
        pcheck=true;
        int z;
        for(z=3; z<=sqrt(numb3[x]); z+=2){
            if((numb3[x]%z)==0){
                pcheck=false;
                break;
            }
        }
        if(pcheck!=true){
            //fout << numb3[x] << " " << z << endl;
            numb3[x]=0;
            counter--;
        }
    }
    sort(numb3, numb3+numbc, sortw);
    sort(numb3, numb3+counter+1);
    //fout << counter << endl;
    if(n==3){
        for(int x=0; x<=counter; x++){
            fout << numb3[x] << endl;
        }
        return 0;
    }

    numbc=0;
    for(x2=0; x2<=counter; x2++){
        for(int y=1; y<=9; y+=2){ // digit 4
            numb4[numbc]=numb3[x2]*10+y;
            //fout << numb4[numbc] << endl;
            numbc++;
        }
    }
    counter=numbc-1;
    for(int x=0; x<numbc; x++){
        pcheck=true;
        for(int z=3; z<=sqrt(numb4[x]); z+=2){
            if(numb4[x]%z==0){
                pcheck=false;
                break;
            }
        }
        if(pcheck!=true){
            numb4[x]=0;
            counter--;
        }
    }
    sort(numb4, numb4+numbc, sortw);
    sort(numb4, numb4+counter+1);
    if(n==4){
        for(int x=0; x<=counter; x++){
            fout << numb4[x] << endl;
        }
        return 0;
    }

    numbc=0;
    for(x2=0; x2<=counter; x2++){
        for(int y=1; y<=9; y+=2){ // digit 5
            numb5[numbc]=numb4[x2]*10+y;
            //fout << numb5[numbc] << endl;
            numbc++;
        }
    }
    counter=numbc-1;
    for(int x=0; x<numbc; x++){
        pcheck=true;
        for(int z=3; z<=sqrt(numb5[x]); z+=2){
            if(numb5[x]%z==0){
                pcheck=false;
                break;
            }
        }
        if(pcheck!=true){
            numb5[x]=0;
            counter--;
        }
    }
    sort(numb5, numb5+numbc, sortw);
    sort(numb5, numb5+counter+1);
    if(n==5){
        for(int x=0; x<=counter; x++){
            fout << numb5[x] << endl;
        }
        return 0;
    }

    numbc=0;
    for(x2=0; x2<=counter; x2++){
        for(int y=1; y<=9; y+=2){ // digit 6
            numb6[numbc]=numb5[x2]*10+y;
            //fout << numb6[numbc] << endl;
            numbc++;
        }
    }
    counter=numbc-1;
    for(int x=0; x<numbc; x++){
        pcheck=true;
        for(int z=3; z<=sqrt(numb6[x]); z+=2){
            if(numb6[x]%z==0){
                pcheck=false;
                break;
            }
        }
        if(pcheck!=true){
            numb6[x]=0;
            counter--;
        }
    }
    sort(numb6, numb6+numbc, sortw);
    sort(numb6, numb6+counter+1);
    if(n==6){
        for(int x=0; x<=counter; x++){
            fout << numb6[x] << endl;
        }
        return 0;
    }

    numbc=0;
    for(x2=0; x2<=counter; x2++){
        for(int y=1; y<=9; y+=2){ // digit 7
            numb7[numbc]=numb6[x2]*10+y;
            //fout << numb7[numbc] << endl;
            numbc++;
        }
    }
    counter=numbc-1;
    for(int x=0; x<numbc; x++){
        pcheck=true;
        for(int z=3; z<=sqrt(numb7[x]); z+=2){
            if(numb7[x]%z==0){
                pcheck=false;
                break;
            }
        }
        if(pcheck!=true){
            numb7[x]=0;
            counter--;
        }
    }
    sort(numb7, numb7+numbc, sortw);
    sort(numb7, numb7+counter+1);
    if(n==7){
        for(int x=0; x<=counter; x++){
            fout << numb7[x] << endl;
        }
        return 0;
    }

    numbc=0;
    for(x2=0; x2<=counter; x2++){
        for(int y=1; y<=9; y+=2){ // digit 8
            numb8[numbc]=numb7[x2]*10+y;
            //fout << numb8[numbc] << endl;
            numbc++;
        }
    }
    sort(numb8, numb8+numbc-1);

    for(int x=0; x<numbc; x++){
        pcheck=true;
        for(int z=3; z<=sqrt(numb8[x]); z+=2){
            if(numb8[x]%z==0){
                pcheck=false;
                //fout << "hi" << endl;
                break;
            }
        }
        if(pcheck==true){
            fout << numb8[x] << endl;
        }
    }
}
