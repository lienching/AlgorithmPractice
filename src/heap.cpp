#include <cstdio>
#include <cstring>

int heap[1000000+10];
int p=1;

void swap(int a,int b){
    int t=heap[a];
    heap[a]=heap[b];
    heap[b]=t;
}
void push(int data){
    heap[p++]=data;
    int next=p-1;
    while(next>=1&&heap[next]<heap[next/2]){
        swap(next,next/2);
        next /=2;
    }
}
int top(){
    return heap[1];
}
void pop(){
    heap[1]=heap[--p];
    int pos = 1;
    int next = 1;
    while(1){
        if(next*2>=p)break;
        next=next*2;
        if(heap[next]>heap[next+1]){
            next++;
        }
        if(heap[pos]>heap[next]){
            swap(pos,next);
            pos = next;
        }
        else{
            break;
        }
    }
}
