#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ifstream Fin;
    ofstream Fout;
    
    Fin.open("input.txt");
    Fout.open("output.txt");
    
    ifstream a("input.txt");
    string b, c;
    int m1=1, m2=1;
    Fin >> b;
    for (int i=1; i<=b.length(); i++){
        if (b[i]==b[i-1]){
            m2++;
            if (m2>m1){
                m1=m2;
                c=b[i];
            }
        }
        else{
           m2 = 1;
        }
    }
cout << c << " " << m1;
}