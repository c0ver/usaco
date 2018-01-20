#include <fstream>
using namespace std;

int cow, query, breed[100000], interval[100000][2], a[100000], b[200000], c[200000], a1, b1, c1;

int main()
{
	ifstream fin ("bcount.in");
	ofstream fout ("bcount.out");

	fin >> cow >> query;
	for(int x=0; x<cow; x++){
		fin >> breed[x];
	}
	for(int x=0; x<query; x++){
		fin >> interval[x][0] >> interval[x][1];
	}

		for(int x=0; x<cow; x++){
			if(breed[x]==1){
				a1++;
			}			
			else if(breed[x]==2){					
				b1++;
			}
			else if(breed[x]==3){
				c1++;
			}
			a[x]=a1;
			b[x]=b1;
			c[x]=c1;
			//fout << x << " " << a1 << " " << b1 << " " << c1 << endl;
		}
		//fout << endl;
		for(int x=0; x<query; x++){
			if(interval[x][0]>1){
				a1=a[interval[x][1]-1]-a[interval[x][0]-2];
				//fout << a[interval[x][1]-1] << " " << a[interval[x][0]-2] << endl;
				b1=b[interval[x][1]-1]-b[interval[x][0]-2];
				c1=c[interval[x][1]-1]-c[interval[x][0]-2];
			}
			else{
				a1=a[interval[x][1]-1];
				b1=b[interval[x][1]-1];
				c1=c[interval[x][1]-1];
			}
			fout << a1 << " " << b1 << " " << c1 << endl;
		}
}
