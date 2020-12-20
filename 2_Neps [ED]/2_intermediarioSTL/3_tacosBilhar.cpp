#include <bits/stdc++.h>

using namespace std;

int main() {
    set <int> s;
    int C,num,ct=0; 
    cin >> C;
    for(int i=0;i<C;++i){
        cin >> num;
        if(s.find(num)!=s.end()){
            s.erase(num);
        }else{
            s.insert(num);
            ct+=2;
        }
    }
    cout << ct << endl;
    
    return 0;
}