#include <bits/stdc++.h>
using namespace std;

bool exp(string s);

int main (){
    int t,i;
    bool instance;
    string str;
    cin >> t;
    for(i=0;i<t;++i){
        cin >> str;
        instance = exp(str);
        if(instance)  cout << "S\n";
        if(!instance) cout << "N\n";
        str.clear();
    }

    return 0;
}

bool exp(string s){
    stack <char> pil;
    for(int j=0;j<s.length();++j){
        if(s[j]== '(' or s[j] == '[' or s[j]== '{'){
            pil.push(s[j]);
        }else if(s[j]== ')' or s[j] == ']' or s[j]== '}'){
            if(pil.empty())return false;
            if(s[j]== ')'){
                if(pil.top()!='(')return false;
                pil.pop();
            }else if(s[j] == ']'){
                if(pil.top()!='[')return false;
                pil.pop();
            }else if(s[j]=='}'){
                if(pil.top()!='{')return false;
                pil.pop();
            }
        }
    }
    if(pil.empty())return true;
}