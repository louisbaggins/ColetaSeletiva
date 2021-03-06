//
//  main.cpp
//  Coleta Seletiva
//
//  Created by Luis Araújo on 12/11/2018.
//  Copyright © 2018 Lista 1. All rights reserved.
//
#include <string.h>
#include <iostream>
#include <vector>
#include <list>
#include "Pessoa.h"
#include "residuo.h"
#include "PontoEntrega.h"
#include "agendamento.h"
int main();
void ImpressaoUsuarios(std::vector<Pessoa*> teste);
void ImpressaoResiduos(std::vector<residuo*> residuos){
        for(unsigned int contador = 0; contador < residuos.size(); contador++){
            std::cout << contador+1 << ") "<< residuos[contador]->nomeResiduo << std::endl;
        }}
void ImpressaoUsuarios(std::vector<Pessoa*> teste){
    for(unsigned int contador = 0; contador < teste.size(); contador++){
        std::cout << "USUARIO(A) - "<< contador+1 << ": "<< teste[contador]->razao << std::endl;
        std::cout << "CONDIÇAO DO(A) USUARIO(A): DOADOR(A)" << std::endl;
        std::cout << "RESIDUO(S) ACEITO(S) PELO(A) USUARIO(A):  ";
        unsigned int temp = 0;
        while(temp < teste[contador]->tipo_residuo.size()){
            std::cout <<teste[contador]->tipo_residuo[temp]->nomeResiduo << std::endl;
            temp++;
        }
        std::cout << "\n--------------------------------------------------------------------------------\n"<< std::endl;
    }
}
int main() {
    static std::vector<residuo*> residuos;
    static std::vector<Pessoa*> teste;
    //Pessoa *pfv = new PessoaFisica("nome", "CPF", "teste", *residuos[0]);
    //std::cout << pfv->CPF;
    std::cout << "ESCOLHA A ACAO QUE DESEJA REALIZAR: \n\n a) Cadastrar residuo \t b) Cadastrar usuario \n c) Cadastrar ponto de entrega\t d) Listar residuos\n e) Listar Usuarios \t f) Listar pontos de entrega" << std::endl;
    char resposta;
    std::cin >> resposta;
    std::string forma_armazenamento;
    char tipoRes;
    //Cadastro de residuos(INICIO) -------------------------------------------------------------------------------
    char cond;
    std::string res;
    std::string tipo;
    std::string quantidade;
    if(resposta == 'a'|| resposta == 'A'){
        cond = 's';
        while(cond == 's' || cond == 'S'){
            std::cout << "Escolha o tipo de residuo que deseja cadastrar: \na)Liquido\nb)Solido\nc)Organico" << std::endl;
            std::cin >> tipoRes;
        if(tipoRes == 'a' || tipoRes == 'A'){
                std::cout << "Qual o nome do residuo?" << std::endl;
                std::cin >> res;
                residuos.push_back(new residuo(res));
            }
    if(tipoRes == 'b' || tipoRes == 'B'){
        std::cout << "Qual o nome do residuo?" << std::endl;
        std::cin >> res;
        residuos.push_back(new residuo(res));
    }
        if(tipoRes == 'c' || tipoRes == 'C'){
            std::cout << "Qual o nome do residuo?" << std::endl;
            std::cin >> res;
            residuos.push_back(new residuo(res));
        }
            std::cout << "\n Deseja realizar o cadastro de mais residuos? \ns) \t n)" << std::endl;
            std::cin >> cond;
        }
        return main();
}
     //Cadastro de residuos(FINAL) -------------------------------------------------------------------------------
   
    //IMPRESSAO DE RESIDUOS(INICIO) ------------------------------------------------------------------------------
    if(resposta == 'd' || resposta == 'D'){
        ImpressaoResiduos(residuos);
        /*
        for(unsigned int contador = 0; contador < residuos.size(); contador++){
            std::cout << "\n" << residuos[0]->nomeResiduo << std::endl;
    }
    char cont;
    std::cin >> cont;
    while (cont == 's'){
        std::cout << "\nDeseja realizar uma nova operação?" << std::endl;
        std::cin >> cont;
        return main();
    }
        }*/
        return main();
    }
         //IMPRESSAO DE RESIDUOS(FINAL) --------------------------------------------------------------------------
        
    //CADASTRO DE USUARIOS(INICIO) -------------------------------------------------------------------------------
    unsigned int k = 0;;
     std::string nome_usuario;
     std::string CPF;
     std::string CNPJ;
     std::string razao;
    int escolha[residuos.size()];
    if(resposta == 'B'|| resposta == 'b'){
        cond = 's';
    while(cond == 's' || cond == 'S'){
        std::cout << "Digite o nome do Usuario a ser cadastrado:  ";
        std::cin >> nome_usuario;
        std::cout << "Quais tipos de residuo serao aceitos?" << std::endl;
        ImpressaoResiduos(residuos);
        std::cin >> escolha[0];
        char lp;
        std::cout << "Deseja incluir mais algum residuo? \nS)        \t N)" << std::endl;
        std::cin >> lp;
        while(lp == 's' || lp == 'S'){
            ImpressaoResiduos(residuos);
            k = 1;
            std::cin >> escolha[k];
            k++;
            std::cout << "Deseja incluir mais algum residuo? \nS)        \t N)" << std::endl;
            std::cin >> lp;
        }
        teste.push_back(new Pessoa(nome_usuario, residuos[escolha[0] - 1]));
        if(k>0){
            unsigned int temp = k;
            k = 1;
            while (k<temp){
                teste[teste.size()-1]->tipo_residuo.push_back(new residuo(residuos[escolha[k]]->nomeResiduo));
                k++;
            }}
        
        std::cout <<"Deseja incluir mais usuarios?" << std::endl;
        std::cin >> cond;
    }}
    
    //CADASTRO DE USUARIOS(FINAL) -------------------------------------------------------------------------------
    
    
    //IMPRESSAO DE USUARIOS(INICIO) ------------------------------------------------------------------------------
        if(resposta == 'e' || resposta == 'E'){
            ImpressaoUsuarios(teste);
            
        }
    return main();
    //IMPRESSAO DE USUARIOS(FINAL) -------------------------------------------------------------------------------
    
    
    
    return 0;
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
}
    
    /*//Pessoa *test = new Pessoa("nome", "razao");
    //std::cout<< "\n" << test->tipo_residuo << std::endl;
    //std::cout<< "\n" <<test->CPF << std::endl;
    std::string tipoResiduo;
    std::string razao;
    std::cout << "\n" << "Deseja realizar o cadastro pessoas?\n\t S) \t N)" << std::endl;
    char k;
    std::cin >> k;
    while(k == 's' || k == 'S'){
        std::cout << "\n" << "Digite o tipo de residuo: " << std::endl;
        std::cin >> tipoResiduo;
        std::cout << "\n" << "Digite se eh doador ou recolhedor: " << std::endl;
        std::cin >> razao;
        teste.push_back(new Pessoa(tipoResiduo, razao));
        std::cout << "\n" << "Deseja realizar o cadastro de mais pessoas?\n\t S) \t N)" << std::endl;
        std::cin >> k;
    }
        /*for( unsigned int o = 0; o < teste.size(); o++){
            
        }
    
    
    if(k == 'n' || k == 'N'){
    for(unsigned int l = 0; l < teste.size(); l++){
        
        std::cout << "\n" << teste[l]->gets_res()<< std::endl;
        std::cout << "\n" << teste[l]->gets_nome()<< std::endl;


    }
        return 0;
    }
    else{
        std::cout << "Digite uma letra valida" << std::endl;
    }
    
    std::cout << "\n" << teste.size() << std::endl;
    
   // std::cout << "\n" << teste[0].razao<< std::endl;
   
    PessoaJuridica *P = new PessoaJuridica("Fisico", "Doador","Apple", "123565478");
    std::cout << "\n" << P->tipoResiduo<< std::endl;
    std::cout << "\n" << P->CNPJ<< std::endl;
    std::cout << "\n" << P->nomeFantasia<< std::endl;
    std::cout << "\n" << P->razao<< std::endl;
    return 0;
    return main();
}*/

