#include <cstdio>
#include <cstdlib>

void swap(int *a, int *b){
    int temp = *b;
    *b = *a;
    *a = temp;
}
int find(int p1, int p2 ,int p3){
  if(p1>p2)swap(&p1,&p2);
  if(p2>p3)swap(&p2,&p3);
  if(p1>p2)swap(&p1,&p2);
  return p2;
}
int main(){
  int n;
  int T=1;
  while(~scanf("%d",&n)){
    int p1,p2,p3;
    while(n--){
      scanf("%d %d %d",&p1,&p2,&p3);
      printf("Case %d: %d\n",T++,find(p1,p2,p3));
    }
  }
  return 0;
}
