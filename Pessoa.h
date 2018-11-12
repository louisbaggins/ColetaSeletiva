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
    std::string tipoResiduo;
    std::string razao;
    Pessoa(std::string tipo, std::string razao){
        this->tipoResiduo = tipo;
        this->razao = razao;
    }
};
class PessoaFisica : public Pessoa {
private:
public:
    std::string nome;
    std::string CPF;
    //bool VerificaCPF(std::string CPF);
    PessoaFisica(std::string nome, std::string CPF, std::string tipoResiduo, std::string razao) : Pessoa(tipoResiduo, razao){
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
