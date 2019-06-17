#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

struct ContaBancaria{
	std::string nome;
	std::vector<std::string> conta;
	float saldo; 
    int qtde_contas = 0;
};

void criarConta(ContaBancaria& conta);
void listarContas(ContaBancaria& conta);
void detalheConta(ContaBancaria& conta);
/*void saque(ContaBancaria& conta, int valor);
void deposito(ContaBancaria& conta, int valor);
void transferencia(ContaBancaria& origem, ContaBancaria& destino, int valor);
void imprimeSaldo(ContaBancaria& conta); */