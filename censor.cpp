#include <fstream>
#include <string>
using namespace std;

string text, cut, result;
int lc, lt, found;

int main()
{
    ifstream fin ("censor.in");
    ofstream fout ("censor.out");

    fin >> text >> cut;
    lc=cut.length();
    lt=text.length();
    for(int x=0; x<lt; x++){
        result+=text[x];
        if (result.size()>=cut.size() && result.substr(result.size()-cut.size())==cut) {
            result.resize(result.size() - cut.size());
        }
    }
    fout << result << endl;
}
