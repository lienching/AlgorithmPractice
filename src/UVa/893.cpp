#include <cstdio>
#include <cstdlib>
bool checkyear(long a){
    if ( ((a % 4 == 0) && (a % 100 != 0)) || (a % 400 == 0) )
        return true;
    return false;
}
int getdays(int mm, bool leap){
    switch(mm){
        case 1:
            return 31;
            break;
        case 2:
            if(leap) return 29;
            else return 28;
            break;
        case 3:
            return 31;
            break;
        case 4:
            return 30;
            break;
        case 5:
            return 31;
            break;
        case 6:
            return 30;
            break;
        case 7:
            return 31;
            break;
        case 8:
            return 31;
            break;
        case 9:
            return 30;
            break;
        case 10:
            return 31;
            break;
        case 11:
            return 30;
            break;
        case 12:
            return 31;
            break;
    }
    return -1;
}
int main(){
    int day;
    int dd,mm,yyyy;
    while(~scanf("%d %d %d %d",&day,&dd,&mm,&yyyy)){
        if(day == dd && mm == yyyy && yyyy == 0)break;
        while(day>0){
            bool isLeap = checkyear(yyyy);
            int DoM = getdays(mm,isLeap);
            if((DoM-dd)<day){
                day -= (DoM-dd+1);
                dd = 1;
                mm++;
                if(mm>12){
                    mm = 1;
                    yyyy++;
                }
            }
            else{
                dd += day;
                break;
            }
        }
        printf("%d %d %d\n",dd,mm,yyyy);
    }
    return 0;
}
