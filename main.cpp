#include <iostream>
#define unt unsigned int
using namespace std;

unt Num, Case = 1, linea[500] = {1};

bool esPrimo(unt a){
    if (a>1){
        for (unt i = 2; i < a; i++)
            if(a%i==0) return false;
    }
    else return false;
    return true;
}

void backtracking(unt length, bool pasa[]){
    if (length == Num) {
        if (!esPrimo(linea[Num-1] + 1))
            return;
        cout<<"1";
        for (int i = 1; i < Num; ++i)
            cout<<" "<<linea[i];
        cout<<'\n';
        return;
    }
    for (unt i = 2; i <= Num; ++i) {
        if (pasa[i]) continue;
        if (esPrimo(i + linea[length - 1])) {
            pasa[i] = true;
            linea[length] = i;
            backtracking(length + 1, pasa);
            pasa[i] = false;
        }
    }
}

int main(){
    while (cin>>Num) {
        if (Case>1) cout<<'\n';
        cout<<"Case " <<Case<<":\n";
        bool pasa[500] = {false};
        backtracking(1, pasa);
        Case++;
    }
}