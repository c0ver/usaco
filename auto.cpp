#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int words, letters, numb, length;
string dictionary[1000], pre;

int main()
{
    ifstream fin ("auto.in");
    ofstream fout ("auto.out");

    fin >> words >> letters;
    for(int counter=0; counter<words; counter++){
        fin >> dictionary[counter];
    }
    sort(dictionary, dictionary+words);
    for(int counter=0; counter<letters; counter++){
        fin >> numb >> pre;
        length=pre.length();
        numb=numb-1;
        for(int counters=0; counters<words; counters++){
            if(pre==dictionary[counters].substr(0, length)){
                counters=counters+numb;
                if(counters>=words){
                    fout << -1 << endl;
                    break;
                }
                if(pre==dictionary[counters].substr(0, length)){
                    fout << numb << endl;
                    break;
                }
                else{
                    fout << -1 << endl;
                    break;
                }
            }
        }
    }
}
