//
//  agendamento.h
//  Coleta Seletiva
//
//  Created by Luis Araújo on 12/11/2018.
//  Copyright © 2018 Lista 1. All rights reserved.
//

#ifndef agendamento_h
#define agendamento_h
#include <string.h>
#include <iostream>
#include "Pessoa.h"
#include "residuo.h"
#include "PontoEntrega.h"
class Agendamento{
private:
    bool coleta;
    bool doador;
    bool receptor;
    std::string evento;
    std::string recolhedor;
    std::string donate;
public:
    
    Agendamento(bool doador, std::string recolhedor, std::string donate){
        this->doador = doador;
        this->recolhedor = recolhedor;
        this->donate = donate;
    }
    void set_receptor(bool receptor){
        this->receptor = receptor;
    }
    void set_doador(bool doador){
        this->doador = doador;
    }
    std::string get_receptor(){
       return this->recolhedor;
    }
    std::string get_donate(){
        return this->donate;
    }
    void checa_agendamento(){
        if(this->doador == true && this->receptor == true){
            coleta = true;
            std::cout <<"Evento confirmado!" << std::endl;
        }
        
    }
};
#endif /* agendamento_h */

