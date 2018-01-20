#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;

struct query {
	int a;
	int b;
};

int main()
{
	ifstream fin ("haybales.in");
	ofstream fout ("haybales.out");

	int N, Q;
	fin >> N >> Q;
	int position[N];
	query ask[Q];
	for(int x=0; x<N; x++) fin >> position[x];
	for(int x=0; x<Q; x++) fin >> ask[x].a >> ask[x].b;

	sort(position, position + N);
	
	for(int x=0; x<Q; x++) {
		bool none = false;
		int low = 0, high = 0;
		int start = 0;
        int upto = N;
        while(start < upto) {
            int mid = (start + upto) / 2;
            if(ask[x].a > position[mid - 1] && ask[x].a <= position[mid]) {
            	low = mid;
            	break;
            }
            else if(ask[x].a > position[mid]) {
                start = mid;
            }
            else if(ask[x].a <= position[mid]) {
                upto = mid;
            }
            if(ask[x].a > position[N - 1]) {
            	none = true;
            	break;
        	}
            if(ask[x].a <= position[0]) break;
        }

        start = 0;
        upto = N;
		while(start < upto) {
            int mid = (start + upto) / 2;
            //cout << mid << endl;
            if(ask[x].b >= position[mid] && ask[x].b < position[mid + 1]) {
            	high = mid;
            	break;
            }
            else if(ask[x].b < position[mid]) {
                upto = mid;
            }
            else if(ask[x].b >= position[mid]) {
                start = mid;
            }
            if(ask[x].b >= position[N - 1]){
            	high = N - 1;
            	break;
        	}
            if(ask[x].b <= position[0]){
            	none = true;
            	break;
        	}
        }

		if(none == true) fout << 0 << endl;
		else fout << high - low + 1 << endl;

		/*if(none == true) cout << 0 << endl;
		else cout << high - low + 1 << endl;
		cout << low << " " << high << endl << endl;*/
	}
}