//
//  Pessoa.h
//  Coleta Seletiva
//
//  Created by Luis Araújo on 12/11/2018.
//  Copyright © 2018 Lista 1. All rights reserved.
//

#ifndef Pessoa_h
#define Pessoa_h
#include <string.h>
#include <iostream>
#include "residuo.h"
#include "PontoEntrega.h"
#include "agendamento.h"
class Pessoa{
private:
public:
    std::string razao;
    residuo *tipo_residuo;
    ~Pessoa(){
    }
    Pessoa (){
        
    }
    Pessoa(std::string nome, residuo *tipo){
        this->razao = nome;
        this->tipo_residuo = tipo;
    }
    virtual std::string gets_res(){
        return tipo_residuo->nomeResiduo;
    }
    
    virtual std::string gets_nome(){
        return this->razao;
    }
    virtual void set_nome(std::string nome){
        this->razao = nome;
    }
    virtual void set_tipo_residuo(std::string tipo){
        this->tipo_residuo->nomeResiduo = tipo;
    }
};
class PessoaFisica : public Pessoa {
private:
public:

     std::string nome;
     std::string CPF;
    //bool VerificaCPF(std::string CPF);
    PessoaFisica(std::string nome, std::string CPF,std::string razao, residuo &tipo_residuo ): Pessoa(razao, &tipo_residuo){
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
    PessoaJuridica(std::string nomeFantasia, std::string CNPJ, residuo &tipo_residuo, std::string razao) : Pessoa( razao, &tipo_residuo){
        this->nomeFantasia = nomeFantasia;
        this->CNPJ = CNPJ;
    }
};

#endif /* Pessoa_h */
