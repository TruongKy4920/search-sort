#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include <math.h>
#define MAX 100
using namespace std;

std::ifstream input("input.txt");
std::ofstream output("output.txt");

int a[MAX];
int b[MAX];
int n,m;

int layMAX(){
    for(int i=1;i<n;i++){
        if(a[0]<a[i]){
            a[0]=a[i];
        }
    }
    return a[0];
}
int layMIN(){
    for(int i=1;i<m;i++){
        if(b[0]>b[i]){
            b[0]=b[i];
        }
    }
    return b[0];
}

int solution() {
    int x=layMAX();
    int y=layMIN();
    return x*y;
}

int main(){
    std::string line;
    input>>n>>m;
      for(int i=0;i<n;i++){
        input>>a[i];
      }
     for(int i=0;i<m;i++){
        input>>b[i];
      }
    
    output<<solution();

    
      
      
      
} 