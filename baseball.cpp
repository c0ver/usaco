#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int position[1001], counts;

int main()
{
    ifstream fin ("baseball.in");
    ofstream fout ("baseball.out");

    int numb, n1, n2, n3;
    fin >> numb;
    for(int counter=0; counter<numb; counter++){
        fin >> position[counter];
    }
    sort(position, position+numb);
    for(int counter=0; counter<numb; counter++){
        n1=position[counter];
        for(int counter1=counter+1; counter1<numb; counter1++){
            n2=position[counter1];
            for(int counter2=counter1+1; counter2<numb; counter2++){
                n3=position[counter2];
                if((n3-n2)>=(n2-n1) && (n3-n2)<=(n2-n1)*2){
                    counts++;
                }
            }
        }
    }
    fout << counts << endl;
}
