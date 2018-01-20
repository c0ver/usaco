/*
ID: LGD84711
LANG: C++
TASK: paint
*/
#include <fstream>
using namespace std;

int a, b, c, d, total;

int main()
{
	ifstream fin ("paint.in");
	ofstream fout ("paint.out");
	
	fin >> a >> b >> c >> d;
	if(c<=b && d>=a){
		if(a>c){
			a=c;
		}
		if(b>d){
			d=b;
		}
		fout << d-a << endl;
		return 0;
	}
	total=(b-a)+(d-c);
	fout << total << endl;
}