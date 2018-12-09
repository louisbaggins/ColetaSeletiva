//
//  residuo.h
//  Coleta Seletiva
//
//  Created by Luis Araújo on 12/11/2018.
//  Copyright © 2018 Lista 1. All rights reserved.
//

#ifndef residuo_h
#define residuo_h
#include <string.h>
#include <iostream>
#include "Pessoa.h"
#include "PontoEntrega.h"
#include "agendamento.h"
class residuo{
private:
public:
    std::string nomeResiduo;
    residuo(){
    }
    virtual ~residuo(){};
    residuo(std::string nomeResiduo){
        this->nomeResiduo = nomeResiduo;
    }
    virtual std::string gets_nome(){
        return this->nomeResiduo;
    }
    virtual std::string informaArmazenamento(std::string nomeResiduo) = 0;
    virtual std::string gets_quantidade() = 0;
    virtual int gets_id() = 0;
};
class liquido : public residuo{
private:
    int _id = 0;
    std::string quantidade;
    std::string formaArmazenamento;
public:
    liquido(std::string quantidade, std::string formaArmazenamento, std::string nomeResiduo) : residuo(nomeResiduo){
        this->quantidade = quantidade;
        this->formaArmazenamento = formaArmazenamento;
    }
    std::string gets_quantidade() override {
        return this->quantidade;
    }
    virtual std::string informaArmazenamento(std::string nomeResiduo) override{
        //std::cout << this->formaArmazenamento << std::endl;
        return this->formaArmazenamento;
    }
    int gets_id() override {
        return this->_id;
    }
};
class solido : public residuo{
private:
    int _id = 1;
    std::string quantidade;
    std::string formaArmazenamento;
public:
    solido(std::string quantidade, std::string formaArmazenamento, std::string nomeResiduo) : residuo(nomeResiduo){
        this->quantidade = quantidade;
        this->formaArmazenamento = formaArmazenamento;
    }
    std::string gets_quantidade() override {
        return this->quantidade;
    }
    std::string informaArmazenamento(std::string nomeResiduo) override{
        //std::cout << this->formaArmazenamento << std::endl;
        return  this->formaArmazenamento;
    }
    int gets_id() override {
        return this->_id;
    }
};
class organico : public residuo{
private:
    int _id = 3;
    std::string quantidade;
    std::string formaArmazenamento;
public:
    organico(std::string quantidade, std::string formaArmazenamento, std::string nomeResiduo) : residuo(nomeResiduo){
        this->quantidade = quantidade;
        this->formaArmazenamento = formaArmazenamento;
    }
    std::string gets_quantidade() override {
        return this->quantidade;
    }
    std::string informaArmazenamento(std::string nomeResiduo) override{
        //std::cout << this->formaArmazenamento << std::endl;
        return this->formaArmazenamento;
    }
    int gets_id() override {
        return this->_id;
    }
};

#endif /* residuo_h */
