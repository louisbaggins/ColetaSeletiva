//
//  PaginaUsuario.h
//  Coleta Seletiva
//
//  Created by Luis Araújo on 09/12/2018.
//  Copyright © 2018 Lista 1. All rights reserved.
//

#ifndef PaginaUsuario_h
#define PaginaUsuario_h
#include <string.h>
#include <iostream>
#include "Pessoa.h"
#include "residuo.h"
#include "PontoEntrega.h"
#include "agendamento.h"
struct mensagem{
    std::string user;
    int numero = 0;
    std::string residuo;
    std::string data;
    PontoEntrega *local;
};
class userpage {
private:
public:
    mensagem *msg;
    ~userpage(){

    }
    int get_num(){
        return this->msg->numero;
    }
    void set_numero(){
        this->msg->numero += 1;
    }
    userpage(){
        this->msg->numero = 0;
    }
    userpage(std::string user, std::string residuo, std::string data, std::string local){
        this->msg->user = user;
        this->msg->residuo = "RESIDUOS";
        this->msg->data = data;
        this->msg->local = new PontoEntrega(local);
        
    }
    void set_data(std::string data){
        this->msg->data = data;
    }
    void set_residuo(std::string residuo){
        this->msg->residuo = residuo;
    }
    void get_mensagem(){
        std::cout<< "Mensagem enviada de " << this->msg->user << ":\n" << "OLA, GOSTARIA DE MARCAR O ENCONTRO PARA DOAR " << this->msg->residuo << " NO DIA " << this->msg->data << " NO PONTO DE ENTREGA " << this->msg->local->endereco << std::endl;
    }
    
    void Doar(){};
};
#endif /* PaginaUsuario_h */
