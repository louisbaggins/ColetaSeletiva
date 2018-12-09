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
    std::string razao;
    int _id;
    std::string nome;
public:
    std::vector<residuo*> tipo_residuo;
    virtual ~Pessoa(){};
    Pessoa (){};
    Pessoa(std::string nome, std::string razao, residuo *tipo){
        this->nome = nome;
        this->tipo_residuo.push_back(tipo);
        this->razao = razao;
    }
    virtual std::string get_identificaçao() = 0;
    virtual std::vector<residuo*> gets_tipo_residuo(){
        return tipo_residuo;
    }
    virtual std::string gets_res(std::string tipo){
        unsigned int p = 0;
        while(tipo_residuo[p]->nomeResiduo != tipo){
            p++;
        }
        return tipo_residuo[p]->nomeResiduo;
    }
    
    virtual std::string gets_nome(){
        return this->nome;
    }
    virtual std::string gets_razao(){
        return this->razao;
    }
    virtual void set_nome(std::string nome){
        this->nome = nome;
    }
    virtual void set_tipo_residuo(residuo *tipo){
        this->tipo_residuo.push_back(tipo);
    }
    virtual int get_id() = 0;
    
};
class PessoaFisica : public Pessoa {
private:
    std::string CPF;
    int _id = 0;
public:
    //bool VerificaCPF(std::string CPF);
    PessoaFisica(std::string CPF,std::string nome,std::string razao, residuo &tipo_residuo): Pessoa(nome, razao, &tipo_residuo){
        this->CPF = CPF;
    }
    virtual std::string get_identificaçao() override{
        return this->CPF;
    }
    int get_id() override{
        return _id;
    }
};
class PessoaJuridica : public Pessoa {
private:
    std::string CNPJ;
    int _id = 1;
public:
    //bool VerificaCNPJ(std::string CPF);
    PessoaJuridica(std::string CNPJ, std::string nomeFantasia, std::string razao, residuo &tipo_residuo) : Pessoa(nomeFantasia, razao, &tipo_residuo){
        this->CNPJ = CNPJ;
    }
    virtual std::string get_identificaçao() override{
        return this->CNPJ;
    }
    int get_id() override{
        return _id;
    }
};

#endif /* Pessoa_h */
