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
    residuo(std::string nomeResiduo){
        this->nomeResiduo = nomeResiduo;
    }
    virtual void informaArmazenamento(std::string nomeResiduo){
    }
};
class liquido : public residuo{
private:
public:
    int quantidade;
    std::string formaArmazenamento;
    liquido(int quantidade, std::string formaArmazenamento, std::string nomeResiduo) : residuo(nomeResiduo){
        this->quantidade = quantidade;
        this->formaArmazenamento = formaArmazenamento;
    }
};
class solido : public residuo{
private:
public:
    int quantidade;
    std::string formaArmazenamento;
    solido(int quantidade, std::string formaArmazenamento, std::string nomeResiduo) : residuo(nomeResiduo){
        this->quantidade = quantidade;
        this->formaArmazenamento = formaArmazenamento;
    }
};

#endif /* residuo_h */
