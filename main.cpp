#include <iostream>
#include <string>
#include <vector>

#include "ContaBancaria.h"

int main(){
	ContaBancaria minhaConta;
	
    criarConta(minhaConta);

	criarConta(minhaConta);

	listarContas(minhaConta);

	detalheConta(minhaConta);

	/*deposito(minhaConta, 200);

	imprimeSaldo(minhaConta);
*/
	return 0;
}