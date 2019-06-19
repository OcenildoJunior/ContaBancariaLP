#include "ContaBancaria.h"

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>


void criarConta(ContaBancaria& contaB){
    std::string palavra;
    std::cout << "Digite o número da conta: ";
    std::cin >> palavra;
    contaB.conta.push_back(palavra);
    std::cout << "Digite o nome do correntista: ";
    std::cin >> palavra;
    contaB.nome.push_back(palavra);
    std::cout << "Digite o valor do saldo: ";
    std::cin >> palavra;
    contaB.saldo.push_back(palavra);
}

void listarContas(ContaBancaria& contaB){
    for (int i = 0; i < contaB.conta.size(); i++)
    {
        std::cout << "**************************" << std::endl;
        std::cout << "Correntista: " << contaB.nome.at(i) << std::endl;
        std::cout << "Conta: " << contaB.conta.at(i) << std::endl;
        std::cout << "**************************" << std::endl << std::endl;
    }   
}

void detalheConta(ContaBancaria& contaB){
    bool encontrado;
    std::string verificador;
    std::vector<std::string>::iterator iterator;
    std::cout << "Entre com o número da conta: ";
    std::cin >> verificador;
    for (int i = 0; i < contaB.conta.size(); i++)
    {
        if (verificador == contaB.conta.at(i))
        {
            std::cout << "**************************" << std::endl;
            std::cout << "Correntista: " << contaB.nome.at(i) << std::endl;
            std::cout << "Conta: " << contaB.conta.at(i) << std::endl;
            std::cout << "Saldo: " << contaB.saldo.at(i) <<std::endl;
            std::cout << "**************************" << std::endl << std::endl;
            encontrado = true;
        }
    }
    if (!encontrado)
    {
        std::cout << "Conta não encontrada." << std::endl;
    }
    
}

void alterarConta(ContaBancaria& contaB){
    bool encontrado;
    std::string verificador;
    std::string palavra;
    std::cout << "Informe o número da conta: ";
    std::cin >> verificador;
    for (int i = 0; i < contaB.conta.size(); i++)
    {
        if (verificador == contaB.conta.at(i))
        {
            std::cout << "Digite o nome do correntista: ";
            std::cin >> palavra;
            contaB.nome.at(i).swap(palavra);
            std::cout << "Digite o valor do saldo: ";
            std::cin >> palavra;
            contaB.saldo.at(i).swap(palavra);
            encontrado = true;
        }
    }
    if (!encontrado)
    {
        std::cout << "Conta não encontrada." << std::endl;
    }
}

/*void excluirConta(ContaBancaria& contaB){
    std::string verificador;
    std::string palavra;
    char escolha;
    bool encontrado;
    std::cout << "Digite o número da conta: ";
    std::cin >> verificador;
    for (int i = 0; i < contaB.conta.size(); i++)
    {
        if (verificador == contaB.conta.at(i))
        {
            std::cout << "Deseja realmente excluir essa conta? (S/N) ";
            std::cin >> escolha;
            if (escolha=='s' || escolha=='S')
            {
                contaB.conta.at(i).clear();
                contaB.nome.at(i).clear();
                contaB.saldo.at(i).clear();
            }
            encontrado=true;
        }
    }
    if(!encontrado){
        std::cout << "Conta não encontrada." << std::endl;
    }
} */

void transferencia(ContaBancaria& contaB){
    std::string verificador;
    std::string verificador2;
    int valor;
    int novovalor;
    std::string new_valor;
    bool encontrado1;
    bool encontrado2;
    std::cout << "Digite o número da conta de origem: ";
    std::cin >> verificador;
    for (int i = 0; i < contaB.conta.size(); i++)
    {
        if (verificador==contaB.conta.at(i))
        {
            std::cout << "Digite o número da conta destino: ";
            std::cin >> verificador2;
            for (int j = 0; j < contaB.conta.size(); j++)
            {
                if (verificador2==contaB.conta.at(j))
                {
                    std::cout << "Digite o valor da transferência: ";
                    std::cin >> valor;
                    if(valor<=stoi(contaB.saldo.at(i))){
                        novovalor = stoi(contaB.saldo.at(i))-valor;
                        new_valor = std::to_string(novovalor);
                        contaB.saldo.at(i).swap(new_valor);
                        novovalor = stoi(contaB.saldo.at(j))+valor;
                        new_valor = std::to_string(novovalor);
                        contaB.saldo.at(j).swap(new_valor);
                    }else{
                        std::cout << "Saldo insuficiente." << std::endl;
                    }
                    encontrado2 = true;
                }
            }
            if (!encontrado2)
            {
                std::cout << "Conta não encontrada" << std::endl;
            }
            encontrado1 = true;
        }
    }
    if (!encontrado1)
    {
        std::cout << "Conta não encontrada" << std::endl;
    }
}

void deposito(ContaBancaria& contaB){
    std::string verificador;
    int valor;
    int novovalor;
    bool encontrado;
    std::cout << "Digite o numero da conta: ";
    std::cin >> verificador;
    for (int i = 0; i < contaB.conta.size(); i++)
    {
        if (verificador==contaB.conta.at(i))
        {
            std::cout << "Digite o valor do deposito: ";
            std::cin >> valor;
            novovalor = (stoi(contaB.saldo.at(i)))+valor;
            std::string palavra = std::to_string(novovalor);
            contaB.saldo.at(i).swap(palavra);
            encontrado=true;
        }   
    }
    if (!encontrado)
    {
        std::cout << "Conta não encontrada." << std::endl;
    }
}

void saque(ContaBancaria& contaB){
    std::string verificador;
    int valor;
    int novovalor;
    bool encontrado;
    std::cout << "Digite o numero da conta: ";
    std::cin >> verificador;
    for (int i = 0; i < contaB.conta.size(); i++)
    {
        if (verificador==contaB.conta.at(i))
        {
            std::cout << "Digite o valor do saque: ";
            std::cin >> valor;
            if(valor<=stoi(contaB.saldo.at(i))){
                novovalor = (stoi(contaB.saldo.at(i)))-valor;
                std::string palavra = std::to_string(novovalor);
                contaB.saldo.at(i).swap(palavra);
            }else{
                std::cout << "Saldo insuficiente." << std::endl;
            }
            encontrado=true;
        }   
    }
    if (!encontrado)
    {
        std::cout << "Conta não encontrada." << std::endl;
    }
}

int menu(){
    int escolha;
    std::cout << "CONTA BANCÁRIA" << std::endl; std::cout << std::endl;
    std::cout << "Selecione uma opção: " << std::endl;
    std::cout << "1. Criar Conta" << std::endl;
    std::cout << "2. Listar Contas" << std::endl;
    std::cout << "3. Detalhes De Uma Conta" << std::endl;
    std::cout << "4. Alterar Conta" << std::endl;
    std::cout << "5. Excluir Conta" << std::endl;
    std::cout << "6. Realizar Transferência" << std::endl;
    std::cout << "7. Realizar Depósito" << std::endl;
    std::cout << "8. Realizar Saque" << std::endl;
    std::cout << std::endl;
    std::cout << "9. Sair" << std::endl;
    std::cin >> escolha;
    return escolha;
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

