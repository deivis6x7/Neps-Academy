#include <bits/stdc++.h>
using namespace std;

int main (){
    int m,n,i;
    queue <char> fila;
    char t1,t2;
    for(i='A';i<='P';++i)
        fila.push(i);
    for(i=0;i<15;++i){
        t1 = fila.front();
        fila.pop();
        t2 = fila.front();
        fila.pop();
        cin >> m >> n;
        if(m>n)
            fila.push(t1);
        else    
            fila.push(t2);
    }
   
    cout << fila.front() << endl;

    return 0;
}