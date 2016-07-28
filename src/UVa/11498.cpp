#include <cstdio>
#include <cstdlib>

int main(){
  int n;
  while(~scanf("%d",&n)){
    if(n == 0)break;
    int cx,cy;
    int px,py;
    scanf("%d %d",&cx,&cy);
    while(n--){
      scanf("%d %d",&px,&py);
      int dx,dy;
      dx = px - cx;
      dy = py - cy;
      if(dx==0||dy==0){
        printf("divisa\n");
        continue;
      }
      if(dx>0){
        if(dy>0){
          printf("NE\n");
        }
        else{
          printf("SE\n");
        }
      }
      else{
        if(dy>0){
          printf("NO\n");
        }
        else{
          printf("SO\n");
        }
      }
    }
  }
  return 0;
}
