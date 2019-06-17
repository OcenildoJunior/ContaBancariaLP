#include "ContaBancaria.h"
#include <iostream>
#include <string>
#include <vector>


void criarConta(ContaBancaria& conta){
    std::string palavra;
    std::cout << "Digite seu nome: ";
    std::cin >> conta.nome;
    std::cout << "Digite o número da conta: ";
    std::cin >> palavra;
    conta.conta.push_back(palavra);
    std::cout << "Digite o saldo inicial: ";
    std::cin >> conta.saldo;
    conta.qtde_contas++;
}

void listarContas(ContaBancaria& conta){
    for (int i = 0; i < conta.qtde_contas; i++)
    {
        std::cout << "**************************" << std::endl;
        std::cout << "Correntista: " << conta.nome << std::endl;
        std::cout << "Conta: " << conta.conta.back() << std::endl;
        std::cout << "**************************" << std::endl << std::endl;
    }   
}

void detalheConta(ContaBancaria& conta){
    std::string verificador;
    std::vector<std::string>::iterator iterator;
    std::cout << "Entre com o número da conta: ";
    std::cin >> verificador;
    iterator = std::find(conta.conta.begin(), conta.conta.end(), verificador);
    if (iterator!=conta.conta.end())
    {
        std::cout << "**************************" << std::endl;
        std::cout << "Correntista: " << conta.nome << std::endl;
        std::cout << "AG: " << *iterator << std::endl;
        std::cout << "Saldo: " << conta.saldo << std::endl;
        std::cout << "**************************" << std::endl << std::endl;
    }else{
        std::cout << "Conta não encontrada!" << std::endl;
    }
    
}
/*
void saque(ContaBancaria& conta, int valor){
	if (valor > conta.saldo){
		return;
	}
	conta.saldo -= valor;
}

void deposito(ContaBancaria& conta, int valor){
	conta.saldo += valor;
}

void transferencia(ContaBancaria& origem, ContaBancaria& destino, int valor){
	if (valor > origem.saldo){
		return;
	}
	saque(origem, valor);
	deposito(destino,valor);
}

void imprimeSaldo(ContaBancaria& conta){
	std::cout << "**************************" << std::endl;
	std::cout << "Correntista: " << conta.nome << std::endl;
	std::cout << "AG: " << conta.conta << " - CC: " << conta.conta << std::endl;
	std::cout << "Saldo: R$ " << conta.saldo << std::endl;
	std::cout << "**************************" << std::endl << std::endl;
} */