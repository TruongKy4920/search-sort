#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include <math.h>
#include <algorithm>

#define MAX 100
using namespace std;

std::ifstream input("input.txt");
std::ofstream output("output.txt");

int a[MAX];
int b[MAX];
int n,m;

int solution() {
    int i,j,count=0;
    i=j=count;
    sort(a,a+n);
    sort(b,b+n);
    while(i<n && j<m){
        if(a[i]>b[j]){
            j++;
            count++;
        }
        i++;
    }
    return count;
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