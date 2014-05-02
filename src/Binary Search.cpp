#include <iostream>
#include <algorithm>
using namespace std;
int num[10]={1,5,31,12,17,23,14,20,49,50};

int findtarget(int t,int a,int b){
    if(a>b)return 0;
    int c = (a+b)/2;
    if(num[c]>t){
        return findtarget(t, a, c-1);
    }
    if(num[c]<t){
        return findtarget(t,c+1,b);
    }
    if(num[c]==t){
        return 1;
    }
}
int main(){
    sort(num,num+10);
    //遞迴版二分搜
    int t,up=0,down=9,flag;
    cin >> t;
    flag = findtarget(t, up, down);
    findtarget(t,up,down);
    if(flag){
        cout << "Find Target" << endl;
    }
    else{
        cout << "Target is not in array" << endl;
    }
    return 0;
}