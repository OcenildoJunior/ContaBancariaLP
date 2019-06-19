#include <iostream>
#include <string>
#include <vector>

#include "ContaBancaria.h"

int main(){
	ContaBancaria minhaConta;
	int escolha = menu();
	switch (escolha)
	{
	case 1:
		criarConta(minhaConta);
		menu();
	case 2:
		listarContas(minhaConta);
		menu();
	case 3:
		detalheConta(minhaConta);
		menu();
	case 4:
		alterarConta(minhaConta);
		menu();
	case 5:
		//excluir
	case 6:
		transferencia(minhaConta);
		menu();
	case 7:
		deposito(minhaConta);
		menu();
	case 8:
		saque(minhaConta);
		menu();
	case 9:
		return 0;
	default:
		std::cout << "Opção inválida." << std::endl;
		menu();
	}

	return 0;
}