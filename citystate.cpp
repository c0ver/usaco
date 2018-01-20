#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct place{
	string city;
	string state;
};

bool sort_states(const place &w, const place &w1)
{
    return w.state<w1.state;
}

bool sort_within(const place &w, const place &w1)
{
    if(w.state == w1.state) {
        return w.city < w1.city;
    }
}

int main()
{
	ifstream fin ("citystate.in");
	ofstream fout ("citystate.out");
	int N;
	fin >> N;
	place loc[N];
	for(int x=0; x<N; x++) {
		fin >> loc[x].city >> loc[x].state;
	}
	sort(loc, loc + N, sort_states);
    sort(loc, loc + N, sort_within);

	/*for(int x=0; x<N; x++) {
		cout << loc[x].city << " " << loc[x].state << endl;
	}*/

	int count = 0;
	for(int x=0; x<N; x++) {
		int start = 0;
		int upto = N;
		bool goUp = false;
        while(start < upto) {
            int mid = (start + upto) / 2;
            cout << mid << endl;
            string initial = loc[x].city.substr(0, 2);
            if(initial == loc[mid].state) {
            	cout << "FOUND INITIAL" << endl;
            	for(int y=mid; y<N; y++) {
            		if(initial != loc[y].state) break;
            		string initial2 = loc[y].city.substr(0, 2);
            		if(initial2 == loc[x].state && loc[x].state != loc[y].state){
            			count++;
            			cout << "FOUND1" << endl;
            		}
            	}
            	for(int y=mid-1; y>=0; y--) {
            		if(initial != loc[y].state) break;
            		string initial2 = loc[y].city.substr(0, 2);
            		if(initial2 == loc[x].state && loc[x].state != loc[y].state){
            			count++;
            			cout << "FOUND2" << endl;
            		}
            	}
            	break;
            }
            else if(initial > loc[mid].state) {
                start = mid + 1;
            }
            else if(initial < loc[mid].state) {
                upto = mid;
            }
        }
        cout << endl;
	}
	if(count % 2 != 0) cout << "ERROR" << endl;
	cout << count / 2 << endl;
	fout << count / 2 << endl;
}