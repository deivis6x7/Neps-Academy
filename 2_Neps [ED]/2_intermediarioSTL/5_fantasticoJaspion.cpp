#include <bits/stdc++.h>

using namespace std;

int main() {
    int t,m,n,r;
    string str1,str2;
    cin >> t;
    while(t--){
        map <string,string> ms;
        cin >> m >> n;
        cin.ignore();
        while(m--){
            getline(cin,str1);
            getline(cin,str2);
            ms.insert(make_pair(str1,str2));
        }
        while(n--){
            getline(cin,str1);
            stringstream ss;
            r=0;
            ss << str1; //operador de inserção: string -> ss
            while(ss >> str2){ //operador de extração (enquanto conseguir extrair)
                if(r)cout << " ";
                if(ms.find(str2)!=ms.end()){
                    cout << ms[str2];
                }else{
                    cout << str2;
                }
                r=1;
            }
            cout << endl;
        }
        cout << endl;
    }   
    return 0;
}