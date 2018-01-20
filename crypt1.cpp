/*
ID: LGD84711
LANG: C++
TASK: crypt1
*/
#include <fstream>
#include <string>
#include <cstdlib>
#include <sstream>
using namespace std;

ifstream fin ("crypt1.in");
ofstream fout ("crypt1.out");

int n, mult1, mult2, prod1, prod2, totalprod, cl, total;
string multiply1, multiply2, checking;
bool same, same1, same2;

int main()
{
    fin >> n;
    if(n>5){
        //return 0;
    }
    char check[n];
    for(int x=0; x<n; x++){
        fin >> check[x];
    }

    for(int x1=0; x1<n; x1++){
        for(int x2=0; x2<n; x2++){
            for(int x3=0; x3<n; x3++){
                for(int x4=0; x4<n; x4++){
                    for(int x5=0; x5<n; x5++){
                        //fout << x5 << endl;
                        same2=true;
                        multiply1.clear();
                        multiply2.clear();
                        multiply1+=check[x1];
                        multiply1+=check[x2];
                        multiply1+=check[x3];
                        multiply2+=check[x4];
                        multiply2+=check[x5];
                        mult1=atoi(multiply1.c_str());
                        mult2=atoi(multiply2.c_str());
                        totalprod=mult2*mult1;
                        checking=static_cast<ostringstream*>( &(ostringstream() << totalprod) )->str();
                        cl=checking.length();
                        same=false;
                        for(int x=0; x<cl; x++){
                            same1=false;
                            for(int y=0; y<n; y++){
                                if(checking[x]==check[y]){
                                    same=true;
                                    same1=true;
                                    break;
                                }
                            }
                            if(same1==false){
                                same=false;
                                break;
                            }
                        }
                        if(same==false){
                            same2=false;
                        }
                        //fout << endl;
                        //fout << checking << endl;

                        multiply2.clear();
                        multiply2+=check[x4];
                        mult2=atoi(multiply2.c_str());
                        prod1=mult2*mult1;
                        checking=static_cast<ostringstream*>( &(ostringstream() << prod1) )->str();
                        cl=checking.length();
                        if(cl>3){
                           same2=false;
                        }
                        same=false;
                        for(int x=0; x<cl; x++){
                            same1=false;
                            for(int y=0; y<n; y++){
                                if(checking[x]==check[y]){
                                    same=true;
                                    same1=true;
                                    break;
                                }
                            }
                            if(same1==false){
                                same=false;
                                break;
                            }
                        }
                        if(same==false){
                            same2=false;
                        }
                        //fout << checking << endl;

                        multiply2.clear();
                        multiply2+=check[x5];
                        mult2=atoi(multiply2.c_str());
                        prod2=mult2*mult1;
                        checking=static_cast<ostringstream*>( &(ostringstream() << prod2) )->str();
                        cl=checking.length();
                        if(cl>3){
                           same2=false;
                        }
                        same=false;
                        for(int x=0; x<cl; x++){
                            same1=false;
                            for(int y=0; y<n; y++){
                                if(checking[x]==check[y]){
                                    same=true;
                                    same1=true;
                                    break;
                                }
                            }
                            if(same1==false){
                                same=false;
                                break;
                            }
                        }
                        if(same==false){
                            same2=false;
                        }
                        if(same2==true){
                            total++;
                            //fout << checking << endl;
                        }
                    }
                }
            }
        }
    }
    fout << total << endl;
}
