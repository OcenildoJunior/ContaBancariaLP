#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

struct ContaBancaria{
	std::vector<std::string> nome;
	std::vector<std::string> conta;
	std::vector<std::string> saldo; 
};

int menu();
void criarConta(ContaBancaria& contaB);
void listarContas(ContaBancaria& contaB);
void detalheConta(ContaBancaria& contaB);
void alterarConta(ContaBancaria& contaB);
//void excluirConta(ContaBancaria& contaB);
void transferencia(ContaBancaria& contaB);
void deposito(ContaBancaria& contaB);
void saque(ContaBancaria& contaB);