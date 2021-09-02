#include <iostream>

using namespace std;

int main() {
	int N;
	cin>>N;

	int matriz[N][N];
	int total=0;
	for(int i=0;i<N;++i) {
		for(int j=0;j<N;++j) {
			cin>>matriz[i][j];
			total += matriz[i][j];
		}
	}

	bool quad=true;
	int som = total/N;
	int somaDig1=0, somaDig2=0;

	for(int i=0;i<N;++i) {
		int j = (N-1)-i;
		somaDig1 += matriz[i][i];
		somaDig2 += matriz[i][j];
	}
	if (somaDig1!=som || somaDig2!=som) quad=false;

	for(int i=0;i<N;++i) {
		int somaLinha=0;
		int somaCol=0;
		for(int j=0;j<N;++j) {
			somaLinha += matriz[i][j];
			somaCol += matriz[j][i];
		}
		if (somaLinha!=som || somaCol!=som) {
			quad = false;
			break;
		}
	}

	if(quad) cout<<som;
	else cout<<"-1";
	return 0;
}