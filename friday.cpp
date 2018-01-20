/*
ID: LGD84711
LANG: C++
TASK: friday
*/
#include <iostream>
#include <fstream>
using namespace std;

int years, counts, week[7], months, place, y, yplace, seem, leap;

struct structs
{
    int month;
    int day;
};

int main()
{
    ifstream fin ("friday.in");
    ofstream fout ("friday.out");

    fin >> years;
    structs year[200000];
    counts=2;
    months=1;
    y=1900;
    for(int counter=0; counter<200000; counter++){
        year[counter].day=counts;
        counts++;
        if(counts==8){
            counts=1;
        }
    }
    counts=1;
    for(int counter=0; counter<200000; counter++){
        seem=0;
        year[counter].month=counts;
        counts++;
        if(y%4==0){
            seem=1;
            if(y%100==0 && y%400!=0){
                seem=0;
            }
        }
        if(months==2 && seem==0){
            if(counts==29){
                months++;
                counts=1;
            }
        }
        if(months==2 && seem==1){
            if(counts==30){
                months++;
                counts=1;
            }
        }
        if(months==4 || months==6 || months==9 || months==11){
            if(counts==31){
                months++;
                counts=1;
            }
        }
        else{
            if(counts==32){
                months++;
                counts=1;
            }
        }
        if(months==13){
            months=1;
            y++;
        }
    }
    leap=years/4;
    for(int counter=0; counter<years*365+leap; counter++){
        if(year[counter].month==13){
            place=year[counter].day;
            week[place-1]++;
        }
    }
    fout << week[6];
    for(int counter=0; counter<6; counter++){
        fout << " " << week[counter];
    }
    fout << endl;
}
