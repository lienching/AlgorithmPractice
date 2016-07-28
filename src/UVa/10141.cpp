#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;
int main(){
    string best,temp;
    int N,Q;
    int T = 1;
    while(1){
        cin >> N >> Q;
        if(N==0&&Q==0)break;
        if(T>1)cout << endl;
        cin.ignore();
        for(int i = 0 ; i < N ; i++){
            getline(cin,temp);
        }
        string name;
        float priece,best_priece;
        int req_met,best_req_met;
        //cin.ignore();
        getline(cin,name);
        cin >> priece >> req_met;
        best = name;
        best_req_met = req_met;
        best_priece = priece;
        cin.ignore();
        for(int i = 0 ; i < req_met ; i++){
            getline(cin,temp);
        }
        for(int i = 1 ; i < Q ; i++){
            getline(cin,name);
            cin >> priece >> req_met;
            cin.ignore();
            if(req_met>=best_req_met){
                if(req_met>best_req_met){
                    best = name;
                    best_req_met = req_met;
                    best_priece = priece;
                }
                else if(req_met == best_req_met && best_priece > priece){
                    best = name;
                    best_req_met = req_met;
                    best_priece = priece;
                }
            }
            for(int j = 0 ; j < req_met ; j++){

                getline(cin,temp);
            }
        }
        cout << "RFP #" << T++ << endl;
        cout << best << endl;
    }
    return 0;
}
