#include <iostream>
#include <fstream>
using namespace std;

string letters;
int length;

int main()
{
    ifstream fin ("scode.in");
    ofstream fout ("scode.out");

    fin >> letters;
    length=letters.length();
    if(length%2==0){
        fout << 0 << endl;
    }
    else if(letters[0]!=letters[length-1]){
        fout << length << endl;
    }
    else{
        fout << length+1 << endl;
    }
}
