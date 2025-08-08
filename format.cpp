#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include <math.h>
#include <map>
#include <algorithm>

#define MAX 100
using namespace std;

std::ifstream input("input.txt");
std::ofstream output("output.txt");

int n;

int a[MAX];
map <int,int> m;
int length=0;
void swap(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
}
int partition(int start, int end){
    int pivot_value=a[end];
    int i_divider=start-1;
    for(int i=start;i<end;i++){
        if(m[ a[i] ] > m[ pivot_value ]) 
            swap(a[++i_divider],a[i]);
        else if(m[ a[i] ] == m[ pivot_value ] && a[i]< pivot_value) 
            swap(a[++i_divider],a[i]);
    }
    swap(a[i_divider+1],a[end]);
    return i_divider+1;
}
void quick_sort(int start,int end){
    if(start>=end) return;

    int pivot= partition(start,end);
    quick_sort(start,pivot-1);
    quick_sort(pivot+1,end);
}
int main() {

    input >> n;
    int x;
    //dem so lan moi phan tu xuat hien bang map
    for(int i=0;i<n;i++){
        input>>x; 
        if(m.count(x)==0) m[x]=1; //ktra key x co trong map không
        //nếu chưa thì cho key đó vào map với value 1;
        else  m[x]++; //sau khi cho key vao map -> moi lan key x xuat hien
            //tang value cua key x len 1 trong map  
    }
    
    //sau khi liet ke cac lan xuat hien cua key x thi ta dung mang a
    //de luu lai cac key khac nhau trong map
    for(const auto& pair :m){
        int key=pair.first; //lay key tu trong map;
        a[length++]= key; //luu Key vao mang a de sort
    }
   
    //sap xep mang theo yeu cau cua de
    quick_sort(0,length-1);
   
    for(int i=0;i<length;i++){
        for(int j=0;j<m[a[i]];j++){
            output<<a[i]<<" ";
        }
    }
   
}