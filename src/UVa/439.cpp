#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <string>
#include <queue>
#include <string.h>
using namespace std;

int traveling(string start,string end){
    int nowX,nowY,endX,endY,nextX,nextY;
    int step=0;
    int dx[]= {-2,-1, 1, 2, 2,1,-1,-2};
    int dy[]= {-1,-2,-2,-1, 1,2, 2, 1};
    int map[9][9];
    memset(map,-1,sizeof(map));
    queue<int> q1,q2;
    nowX = start.c_str()[0]-'a'+1;
    nowY = start.c_str()[1]-'0';
    map[nowX][nowY]=0;
    endX = end.c_str()[0]-'a'+1;
    endY = end.c_str()[1]-'0';
    q1.push(nowX);
    q2.push(nowY);
    while(!q1.empty()){
        nowX = q1.front();
        nowY = q2.front();
        q1.pop();
        q2.pop();
        if(nowX==endX&&nowY==endY){
            step = map[endX][endY];
            break;
        }
        for(int i = 0 ; i < 8 ; i++){
            nextX = nowX+dx[i];
            nextY = nowY+dy[i];
            if(map[nextX][nextY]!=-1)continue;
            if(nextX>0&&nextX<9){
                if(nextY>0&&nextY<9){
                    q1.push(nextX);
                    q2.push(nextY);
                    map[nextX][nextY]=map[nowX][nowY]+1;
                }
            }
        }
    }
    return step;
}

int main(){
    string s,e;
    while(cin >> s >> e){
        cout << "To get from "<< s <<" to " << e << " takes "<< traveling(s,e) <<" knight moves." << endl;
    }
    return 0;
}
