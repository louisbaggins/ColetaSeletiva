//
//  main.cpp
//  Coleta Seletiva
//
//  Created by Luis Araújo on 12/11/2018.
//  Copyright © 2018 Lista 1. All rights reserved.
//

/*#include <string.h>
#include <iostream>
#include "residuo.h"
#include "PontoEntrega.h"
#include "agendamento.h"
int main(){
}*/
//
//  Pessoa.h
//  Coleta Seletiva
//
//  Created by Luis Araújo on 12/11/2018.
//  Copyright © 2018 Lista 1. All rights reserved.
//
#include <string.h>
#include <iostream>
#include "residuo.h"
#include "PontoEntrega.h"
#include "agendamento.h"
#ifndef Pessoa_h
#define Pessoa_h
class Pessoa{
private:
public:
    std::string nome;
    std::string tipo_residuo;
    ~Pessoa(){
    }
    Pessoa (){
        
    }
    Pessoa(std::string nome, std::string tipo){
        this->nome = nome;
        this->tipo_residuo = tipo;
    }
    virtual std::string gets_res(){
        return this->tipo_residuo;
    }
    
    virtual std::string gets_nome(){
        return this->nome;
    }
    virtual void set_nome(std::string nome){
        this->nome = nome;
    }
    virtual void set_tipo_residuo(std::string tipo){
        this->tipo_residuo = tipo;
    }
};
class PessoaFisica : public Pessoa {
private:
public:

    std::string nome;
    std::string CPF;
    //bool VerificaCPF(std::string CPF);
    PessoaFisica(std::string nome, std::string CPF, std::string tipoResiduo, std::string razao ) : Pessoa(tipoResiduo, razao){
        this->nome = nome;
        this->CPF = CPF;
    }
};
class PessoaJuridica : public Pessoa {
private:
public:
    std::string nomeFantasia;
    std::string CNPJ;
    //bool VerificaCNPJ(std::string CPF);
    PessoaJuridica(std::string nomeFantasia, std::string CNPJ, std::string tipoResiduo, std::string razao) : Pessoa(tipoResiduo, razao){
        this->nomeFantasia = nomeFantasia;
        this->CNPJ = CNPJ;
    }
};
#endif /* Pessoa_h */
