#include <bits/stdc++.h>
using namespace std;

int main (){
    int n,i;
    string str;
    stack <char> pil;
    cin >> n;

    while(getline(cin,str)){
        for(i=0;i<str.size();++i){
            if(str[i]=='{'){
                pil.push(str[i]);
            }else
                if(str[i]=='}'){
                    if(pil.empty()){
                        pil.push('f');
                        break;
                    }
                    pil.pop();
                }
        }
    }

    cout << (pil.empty() ? "S\n" : "N\n");
    
    return 0;
}