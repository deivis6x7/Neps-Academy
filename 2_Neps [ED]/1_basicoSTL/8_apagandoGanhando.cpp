#include <bits/stdc++.h>
using namespace std;

/* paradigma - metodo guloso / greedy */

int main (){
    int n,d,apagados,top;
    char ch;
    string str;
    stack <char> pil;
    while((cin >> n >> d) and (n+d)){
      apagados=0;
      for(int i=0,top=-1;i<n;++i){
        cin >> ch;
        // não entra na primeira iteração devido ao top>-1
        // ENQUANTO: há número na pilha, ainda não houver d apagados e a entrada atual for maior que o topo da pilha
        while(top>-1 and apagados<d and ch>pil.top()){
          pil.pop();
          top--;
          apagados++;
        }
        if(top+1 < n-d){
          pil.push(ch);
          top++;
        }
      }
      while(!pil.empty()){
        str+= pil.top();
        pil.pop();
      }
      reverse(str.begin(),str.end());
      cout << str << endl;
      str.clear();
    }
    
    return 0;
}