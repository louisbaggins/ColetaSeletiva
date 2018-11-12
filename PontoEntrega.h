//
//  PontoEntrega.h
//  Coleta Seletiva
//
//  Created by Luis Araújo on 12/11/2018.
//  Copyright © 2018 Lista 1. All rights reserved.
//

#ifndef PontoEntrega_h
#define PontoEntrega_h
#include <string.h>
#include <iostream>
#include "Pessoa.h"
#include "residuo.h"
#include "agendamento.h"
class PontoEntrega {
private:
public:
    std::string endereco;
    PontoEntrega(std::string endereco){
        this->endereco = endereco;
    }
};
#endif /* PontoEntrega_h */
