#include <bits/stdc++.h>

using namespace std;

int P, M, N;
int congruencia(int x){
	if(x>=0){
		return x%P;
	}
	else{
		while(x<0){
			x+=P;
		}
		return x%P;
	}
}

int main(){
	vector<int> resposta;
	while(true){
		cin >> P >> M >> N;
		if(P==0 and M==0 and N==0){
			break;
		}
		else{
			vector<int> saque;
			for(int i=0; i<N; i++){
				int valor;
				char nipe;
				cin >> valor >> nipe;
				if(nipe=='C'){
					saque.push_back(10*valor+1);
				}
				else if(nipe=='D'){
					saque.push_back(10*valor+2);
				}
				else if(nipe=='H'){
					saque.push_back(10*valor+3);
				}
				else if(nipe=='S'){
					saque.push_back(10*valor+4);
				}
			}
			
			vector<int> jogador[P];
			for(int i=0; i<P; i++){
				for(int j=0; j<M; j++){
					jogador[i].push_back(saque[0]);
					saque.erase(saque.begin());
				}
				sort(jogador[i].begin(), jogador[i].end());
			}
			
			int cartajogada=saque[0];
			saque.erase(saque.begin());
			int p=0;
			int sentido=1;
			
			if(cartajogada/10==12){
				sentido=-1;
			}
			else if(cartajogada/10==1){
				jogador[0].push_back(saque[0]);
				saque.erase(saque.begin());
				sort(jogador[0].begin(), jogador[0].end());
				p++;
			}
			else if(cartajogada/10==7){
				jogador[0].push_back(saque[0]);
				saque.erase(saque.begin());
				jogador[0].push_back(saque[0]);
				saque.erase(saque.begin());
				sort(jogador[0].begin(), jogador[0].end());
				p++;
			}
			else if(cartajogada/10==11){
				p++;
			}
			
			bool naoacabou=true;
			while(naoacabou){
				bool tem=false;
				for(int i=jogador[p].size()-1; i>=0; i--){
					if(jogador[p][i]/10==cartajogada/10 or jogador[p][i]%10==cartajogada%10){
						tem=true;
						cartajogada=jogador[p][i];
						jogador[p].erase(jogador[p].begin()+i);
						if(jogador[p].size()==0){
							naoacabou=false;
							resposta.push_back(p+1);
						}
						else if(cartajogada/10==12){
							if(sentido==1){
								sentido=-1;
							}
							else if(sentido==-1){
								sentido=1;
							}
						}
						else if(cartajogada/10==1){
							if(sentido==1){
								p++;
								jogador[congruencia(p)].push_back(saque[0]);
								saque.erase(saque.begin());
								sort(jogador[congruencia(p)].begin(), jogador[congruencia(p)].end());
							}
							else{
								p--;
								jogador[congruencia(p)].push_back(saque[0]);
								saque.erase(saque.begin());
								sort(jogador[congruencia(p)].begin(), jogador[congruencia(p)].end());
							}
						}
						else if(cartajogada/10==7){
							if(sentido==1){
								p++;
								jogador[congruencia(p)].push_back(saque[0]);
								saque.erase(saque.begin());
								jogador[congruencia(p)].push_back(saque[0]);
								saque.erase(saque.begin());
								sort(jogador[congruencia(p)].begin(), jogador[congruencia(p)].end());
							}
							else{
								p--;
								jogador[congruencia(p)].push_back(saque[0]);
								saque.erase(saque.begin());
								jogador[congruencia(p)].push_back(saque[0]);
								saque.erase(saque.begin());
								sort(jogador[congruencia(p)].begin(), jogador[congruencia(p)].end());
							}
						}
						else if(cartajogada/10==11){
							if(sentido==1){
								p++;
							}
							else{
								p--;
							}
						}
						break;
					}
				}
				if(tem==false){
					if(saque[0]/10==cartajogada/10 or saque[0]%10==cartajogada%10){
						cartajogada=saque[0];
						saque.erase(saque.begin());
						if(cartajogada/10==12){
							if(sentido==1){
								sentido=-1;
							}
							else if(sentido==-1){
								sentido=1;
							}
						}
						else if(cartajogada/10==1){
							if(sentido==1){
								p++;
								jogador[congruencia(p)].push_back(saque[0]);
								saque.erase(saque.begin());
								sort(jogador[congruencia(p)].begin(), jogador[congruencia(p)].end());
							}
							else if(sentido==-1){
								p--;
								jogador[congruencia(p)].push_back(saque[0]);
								saque.erase(saque.begin());
								sort(jogador[congruencia(p)].begin(), jogador[congruencia(p)].end());
							}
						}
						else if(cartajogada/10==7){
							if(sentido==1){
								p++;
								jogador[congruencia(p)].push_back(saque[0]);
								saque.erase(saque.begin());
								jogador[congruencia(p)].push_back(saque[0]);
								saque.erase(saque.begin());
								sort(jogador[congruencia(p)].begin(), jogador[congruencia(p)].end());
							}
							else if(sentido==-1){
								p--;
								jogador[congruencia(p)].push_back(saque[0]);
								saque.erase(saque.begin());
								jogador[congruencia(p)].push_back(saque[0]);
								saque.erase(saque.begin());
								sort(jogador[congruencia(p)].begin(), jogador[congruencia(p)].end());
							}
						}
						else if(cartajogada/10==11){
							if(sentido==1){
								p++;
							}
							else if(sentido==-1){
								p--;
							}
						}
					}
					else{
						jogador[p].push_back(saque[0]);
						saque.erase(saque.begin());
						sort(jogador[p].begin(), jogador[p].end());
					}
				}
				if(sentido==1){
					p++;
					p=congruencia(p);
				}
				else if(sentido==-1){
					p--;
					p=congruencia(p);
				}
			}
		}
	}
	for(int i=0; i<resposta.size(); i++){
		cout << resposta[i] << "\n";
	}
	return 0;	
}