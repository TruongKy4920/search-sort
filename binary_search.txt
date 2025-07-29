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
int n,x;
int a[MAX];


int main(){
    std::string line;
    input>>n>>x;
      for(int i=0;i<n;i++){
        input>>a[i];
      }
      int start=0;
      int end= n-1;

      for(;start<=end;){
        int mid=(start+end)/2;   
        
        if(a[mid]==x)  output<<a[mid];
    

        if(x> a[mid])
          start = mid+1;         
        else          
          end = mid-1;       
        }
      
      
      
}