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

int n, p;
int a[MAX];
int min_list[MAX]; // min_list[i] sẽ lưu giá trị nhỏ nhất trong dãy a[1], a[2],... a[i]

int min(int u, int v) {
    return u < v ? u : v;
}
//minlist= 4 3 3 2 2 2 
//         1 2 3 4 5 6 
int binary_search(int i, int j) { // Tìm
    int start = i; //1
    int end = j-1; //1
    int x = j; //2 

    while (start <= end) {
        int mid = (start+end)/2; //1


        if(a[j] - min_list[mid] < p) {  // 3-4 
            start = mid + 1;
        }
        else {
            x = mid; //x=1
            end = mid - 1; //end =0
        }
    }
    return x;
}


void solution() {
    min_list[1] = a[1];
    for(int i = 2; i <=n; i++)
        min_list[i] = min(min_list[i-1], a[i]);

    int result = 0;
   
    for(int j = 2; j <= n; j++) {
        int i = binary_search(1, j);
        if (j-i > result)
            result = j-i;
    }
    std::cout << result;
}


int main(){
    std::string line;
    input>>n>>p;
      for(int i=1;i<=n;i++){
        input>>a[i];
      }
     
    
    
    output<<solution();

    
      
      
      
} 