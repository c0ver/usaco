/*
ID: LGD84711
LANG: C++
TASK: transform
*/
#include <iostream>
#include <fstream>
using namespace std;

int numb, er;
char first[10][10], last[10][10] , changed[10][10];

int main()
{
    ifstream fin ("transform.in");
    ofstream fout ("transform.out");

    fin >> numb;
    for(int x=0; x<numb; x++){
        for(int y=0; y<numb; y++){
            fin >> first[x][y];
        }
    }
    for(int x=0; x<numb; x++){
        for(int y=0; y<numb; y++){
            fin >> last[x][y];
        }
    }

    //Test #1
    for(int x=0; x<numb; x++){
        for(int y=0; y<numb; y++){
            if(first[x][y]!=last[y][numb-x-1]){
                //fout << x << " " << y << endl;
                er=1;
                break;
            }
        }
        if(er==1){
            break;
        }
    }
    if(er==0){
        fout << 1 << endl;
        return 0;
    }
    er=0;

    //Test #2
    for(int x=0; x<numb; x++){
        for(int y=0; y<numb; y++){
            if(first[x][y]!=last[numb-x-1][numb-y-1]){
                //fout << x << " " << y << endl;
                er=1;
                break;
            }
        }
        if(er==1){
            break;
        }
    }
    if(er==0){
        fout << 2 << endl;
        return 0;
    }
    er=0;

    //Test #3
    for(int x=0; x<numb; x++){
        for(int y=0; y<numb; y++){
            if(first[x][y]!=last[numb-y-1][x]){
                //fout << x << " " << y << endl;
                er=1;
                break;
            }
        }
        if(er==1){
            break;
        }
    }
    if(er==0){
        fout << 3 << endl;
        return 0;
    }
    er=0;

    //Test #4
    for(int x=0; x<numb; x++){
        for(int y=0; y<numb; y++){
            if(first[x][y]!=last[x][numb-y-1]){
                //fout << x << " " << y << endl;
                er=1;
                break;
            }
        }
        if(er==1){
            break;
        }
    }
    if(er==0){
        fout << 4 << endl;
        return 0;
    }
    er=0;

    //Test #5
    for(int x=0; x<numb; x++){
        for(int y=0; y<numb; y++){
            changed[x][y]=first[x][numb-y-1];
        }
    }
    for(int x=0; x<numb; x++){
        for(int y=0; y<numb; y++){
            if(changed[x][y]!=last[y][numb-x-1]){
                //fout << x << " " << y << endl;
                er=1;
                break;
            }
        }
        if(er==1){
            break;
        }
    }
    if(er==0){
        fout << 5 << endl;
        return 0;
    }
    er=0;
    for(int x=0; x<numb; x++){
        for(int y=0; y<numb; y++){
            if(changed[x][y]!=last[numb-x-1][numb-y-1]){
                //fout << x << " " << y << endl;
                er=1;
                break;
            }
        }
        if(er==1){
            break;
        }
    }
    if(er==0){
        fout << 5 << endl;
        return 0;
    }
    er=0;
    for(int x=0; x<numb; x++){
        for(int y=0; y<numb; y++){
            if(changed[x][y]!=last[numb-y-1][x]){
                //fout << x << " " << y << endl;
                er=1;
                break;
            }
        }
        if(er==1){
            break;
        }
    }
    if(er==0){
        fout << 5 << endl;
        return 0;
    }
    er=0;

    //Test #6
    for(int x=0; x<numb; x++){
        for(int y=0; y<numb; y++){
            if(first[x][y]!=last[x][y]){
                //fout << x << " " << y << endl;
                er=1;
                break;
            }
        }
        if(er==1){
            break;
        }
    }
    if(er==0){
        fout << 6 << endl;
        return 0;
    }
    fout << 7 << endl;
}
