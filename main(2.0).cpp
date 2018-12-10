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
#include <string>
#include "Pessoa.h"
#include "residuo.h"
#include "PontoEntrega.h"
#include "agendamento.h"
#include "PaginaUsuario.h"

int main();
void ImpressaoPontoEntrega(std::vector<PontoEntrega*> Locais){
    for (unsigned int impem = 0; impem < Locais.size(); impem++){
        std::cout << impem+1 << ")" << Locais[impem]->endereco << std::endl;
    }
    }

void ImpressaoUsuarios(std::vector<Pessoa*> teste);
void ImpressaoResiduos(std::vector<residuo*> residuos){
        for(unsigned int contador = 0; contador < residuos.size(); contador++){
            std::cout << contador+1 << ") "<< residuos[contador]->nomeResiduo << std::endl;
        }}
void ImpressaoUsuarios(std::vector<Pessoa*> teste){
    for(unsigned int contador = 0; contador < teste.size(); contador++){
        std::cout << "USUARIO(A) - "<< contador+1 << ": "<< teste[contador]->gets_nome() << std::endl;
        if(teste[contador]->get_id() == 1){
            std::cout << "CNPJ: "<< teste[contador]->get_identificaçao()<< std::endl;
        }
        else{
            std::cout << "CPF: "<< teste[contador]->get_identificaçao()<< std::endl;
        }
        std::cout << "CONDIÇAO DO(A) USUARIO(A): "<<teste[contador]->gets_razao()<< "(A)" << std::endl;
        std::cout << "RESIDUO(S) ACEITO(S) PELO(A) USUARIO(A):  ";
        unsigned int temp = 0;
        while(temp < teste[contador]->gets_tipo_residuo().size()){
            std::cout <<teste[contador]->gets_tipo_residuo()[temp]->nomeResiduo << std::endl;
            temp++;
        }
        std::cout << "\n--------------------------------------------------------------------------------\n"<< std::endl;
    }
}
int main() {
    static std::vector<Agendamento*> eventos;
    static std::vector<residuo*> residuos;
    static std::vector<Pessoa*> Usuarios;
    static std::vector<PontoEntrega*> Locais;
    std::cout << "ESCOLHA A ACAO QUE DESEJA REALIZAR: \n\n a) Cadastrar residuo \t b) Cadastrar usuario \n c) Cadastrar ponto de entrega\t d) Listar residuos\n e) Listar Usuarios \t f) Listar pontos de entrega\ng)Finalizar programa\th)Pagina do Usuario(Agendar doaçoes)" << std::endl;
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
            std::cout << "Informe a quantidade(em litros): " ;
            std::cin >> quantidade;
            std::cout << "Informe a maneira que o residuo deve ser armazenado: " << std::endl;
            std::getline(std::cin, forma_armazenamento);
            residuos.push_back(new liquido(quantidade, forma_armazenamento, res));
            }
    if(tipoRes == 'b' || tipoRes == 'B'){
        std::cout << "Qual o nome do residuo?" << std::endl;
        std::cin >> res;
        std::cout << "Informe a quantidade(em kg): " ;
        std::cin >> quantidade;
        std::cout << "Informe a maneira que o residuo deve ser armazenado: " << std::endl;
        std::getline(std::cin, forma_armazenamento);
        residuos.push_back(new solido(quantidade, forma_armazenamento, res));
    }
        if(tipoRes == 'c' || tipoRes == 'C'){
            std::cout << "Qual o nome do residuo?" << std::endl;
            std::cin >> res;
            std::cout << "Informe a quantidade(em kg): " ;
            std::cin >> quantidade;
            std::cout << "Informe a maneira que o residuo deve ser armazenado: " << std::endl;
            std::getline(std::cin, forma_armazenamento);
            residuos.push_back(new organico(quantidade, forma_armazenamento, res));
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
        return main();
    }
         //IMPRESSAO DE RESIDUOS(FINAL) --------------------------------------------------------------------------
        
   
    
    //CADASTRO DE USUARIOS(INICIO) -------------------------------------------------------------------------------
    unsigned int k = 0;;
     std::string nome_usuario;
     std::string CPF;
     std::string CNPJ;
     std::string razao;
    char sit;
    int escolha[residuos.size()];
    if(resposta == 'B'|| resposta == 'b'){
        cond = 's';
    while(cond == 's' || cond == 'S'){
        std::cout << "Deseja cadastrar uma empresa ou pessoa fisica?\na)Empresa \t b)Pessoa Fisica" <<std::endl;
        std::cin >> sit;
        std::cout << "Digite o nome do Usuario a ser cadastrado:  ";
        std::cin >> nome_usuario;
        std::cout << "O usuario e doador ou receptor?" << std::endl;
        std::cin >> razao;
        std::cout << "Quais tipos de residuo serao aceitos?" << std::endl;
        ImpressaoResiduos(residuos);
        std::cin >> escolha[0];
        char lp;
        std::cout << "Deseja incluir mais algum residuo? \nS)        \t N)" << std::endl;
        std::cin >> lp;
        while(lp == 's' || lp == 'S'){
            ImpressaoResiduos(residuos);
            std::cin >> escolha[k+1];
            k++;
            std::cout << "Deseja incluir mais algum residuo? \nS)        \t N)" << std::endl;
            std::cin >> lp;
        }
        if(sit == 'b' || sit == 'B'){
            std::cout << "Digite o CPF do usuario: " << std::endl;
            std::cin >> CPF;
            Usuarios.push_back(new PessoaFisica(CPF, nome_usuario,razao,*residuos[escolha[0] - 1], Usuarios.size()));
        if(k>0){
            unsigned int temp = k;
            k = 1;
            while (k<temp){
                if(residuos[escolha[k]-1]->gets_id() == 0){
                    Usuarios[Usuarios.size()-1]->tipo_residuo.push_back(new liquido(residuos[escolha[k]-1]->gets_quantidade(), residuos[escolha[k]]->informaArmazenamento(residuos[escolha[k] -1 ]->gets_nome()), residuos[escolha[k]-1]->gets_nome() ));
                
            }
                    if(residuos[escolha[k]-1]->gets_id() == 1){
                    Usuarios[Usuarios.size()-1]->tipo_residuo.push_back(new solido(residuos[escolha[k]-1]->gets_quantidade(), residuos[escolha[k]]->informaArmazenamento(residuos[escolha[k] -1 ]->gets_nome()), residuos[escolha[k]-1]->gets_nome()));
                    
                }
                    if(residuos[escolha[k]-1]->gets_id() == 3){
                    Usuarios[Usuarios.size()-1]->tipo_residuo.push_back(new organico(residuos[escolha[k]-1]->gets_quantidade(), residuos[escolha[k]-1]->informaArmazenamento(residuos[escolha[k]-1]->gets_nome()), residuos[escolha[k]-1]->gets_nome() ));
                    
                }
                k++;
                
            }}}
        if (sit == 'A' || sit == 'a'){
            std::cout << "Digite o CNPJ do usuario: " << std::endl;
            std::cin >> CNPJ;
            Usuarios.push_back(new PessoaJuridica(CNPJ, nome_usuario,razao,*residuos[escolha[0] - 1], Usuarios.size()));
            if(k>0){
                unsigned int temp = k;
                k = 1;
                while (k<temp){
                    if(residuos[escolha[k]]->gets_id() == 0){
                        Usuarios[Usuarios.size()-1]->tipo_residuo.push_back(new liquido(residuos[escolha[k]]->gets_quantidade(), residuos[escolha[k]]->informaArmazenamento(residuos[escolha[k]]->gets_nome()), residuos[escolha[k]]->gets_nome() ));
                        
                    }
                    if(residuos[escolha[k]]->gets_id() == 1){
                        Usuarios[Usuarios.size()-1]->tipo_residuo.push_back(new solido(residuos[escolha[k]]->gets_quantidade(), residuos[escolha[k]]->informaArmazenamento(residuos[escolha[k]]->gets_nome()), residuos[escolha[k]]->gets_nome() ));
                        
                    }
                    if(residuos[escolha[k]]->gets_id() == 3){
                        Usuarios[Usuarios.size()-1]->tipo_residuo.push_back(new organico(residuos[escolha[k]]->gets_quantidade(), residuos[escolha[k]]->informaArmazenamento(residuos[escolha[k]]->gets_nome()) ,residuos[escolha[k]]->gets_nome()) );
                        
                    }
                    k++;}}}
    
    
        
        std::cout <<"Deseja incluir mais usuarios?" << std::endl;
        std::cin >> cond;}
   return main(); }
    
    //CADASTRO DE USUARIOS(FINAL) -------------------------------------------------------------------------------
    
    
    //IMPRESSAO DE USUARIOS(INICIO) ------------------------------------------------------------------------------
        if(resposta == 'e' || resposta == 'E'){
            ImpressaoUsuarios(Usuarios);
            return main();
        }
    
    //IMPRESSAO DE USUARIOS(FINAL) -------------------------------------------------------------------------------
    
    
    //CADASTRO PONTOS DE ENTREGA(INICIO) -------------------------------------------------------------------------
   if(resposta == 'c' || resposta == 'C'){
       std::string local;
       char esclh = 's';
       while(esclh == 's' || esclh == 'S'){
       std::cout << "Qual o endereço do ponto de entrega: ";
           std::cin.ignore(1000,'\n');
           std::getline (std::cin, local);
       Locais.push_back(new PontoEntrega(local));
       std::cout << "Deseja cadastrar mais algum ponto?\nS)\tN) " << std::endl;
       std::cin >> esclh;
       }
       return main();
   }
    //CADASTRO PONTOS DE ENTREGA(FINAL) --------------------------------------------------------------------------
    
    
    //IMPRESSAO PONTOS DE ENTREGA(INICIO) ------------------------------------------------------------------------
    if(resposta == 'f' || resposta == 'F'){
        ImpressaoPontoEntrega(Locais); return main();}
    
    //IMPRESSAO PONTOS DE ENTREGA(FINAL) ------------------------------------------------------------------------
    
    
    //PAGINA DO USUARIO(INICIO) ------------------------------------------------------------------------
    std::string dadosResiduo;
    std::string dadosLocal;
    std::string horario; //CONFERIR
    std::string senha;
    std::string acesso;
    std::string Donirone;
    int notf;
    int num;
    unsigned int T = 0;
    if(resposta == 'h' || resposta == 'H'){
    char kp = 'S';
    while(kp == 's' || kp == 'S'){
    std::cout <<"Digite o primeiro nome e o cpf para acessar sua pagina: " << std::endl;
    std::cout <<"Nome: ";
    std::cin >> acesso;
    std::cout<<""<<std::endl;
    std::cout <<"CPF: ";
    std::cin >> senha;
    int aviso = 0;
    while(T < Usuarios.size() && (senha != Usuarios[T]->get_identificaçao() && acesso != Usuarios[T]->gets_nome() )){
        
        if(senha == Usuarios[T]->get_identificaçao()){
            aviso = 1;
        }
        T++;
    }
    if(T == Usuarios.size() && aviso != 1){
        std::cout << "Usuario nao encontrado, deseja realizar uma nova busca? \nS)\tN)" << std::endl;
        std::cin >> kp;
    }
    else{kp = 'n';}
    }
        
            std::cout << "---------------------PAGINA DO USUARIO----------------------\n---------------------BEM VINDO DE VOLTA "<< Usuarios[T]->gets_nome()<< "----------------------" << std::endl;
        std::cout << "USUARIO(A) - "<< T+1 << ": "<< Usuarios[T]->gets_nome() << std::endl;
        Donirone = Usuarios[T]->gets_nome();
        if(Usuarios[T]->get_id() == 1){
            std::cout << "CNPJ: "<< Usuarios[T]->get_identificaçao()<< std::endl;
        }
        else{
            std::cout << "CPF: "<< Usuarios[T]->get_identificaçao()<< std::endl;
        }
        std::cout << "CONDIÇAO DO(A) USUARIO(A): "<<Usuarios[T]->gets_razao()<< "(A)" << std::endl;
        std::cout << "RESIDUO(S) ACEITO(S) PELO(A) USUARIO(A):  ";
        unsigned int temp = 0;
        while(temp < Usuarios[T]->gets_tipo_residuo().size()){
            std::cout <<Usuarios[T]->gets_tipo_residuo()[temp]->nomeResiduo << std::endl;
            temp++;
        }
        std::cout << "\n--------------------------------------------------------------------------------"<< std::endl;
        notf = 0;//Usuarios[T]->page.msg->numero;

        std::cout << "OPÇOES\nA)Agendar\nB)Mensagens("<< notf <<")\nC)Retornar ao Menu"<<std::endl;
        char vf;
        std::cin >> vf;
       //AGENDAMENTO(PRIMEIRA PARTE)-----------------------------------------------------------------------------------------------------
        if(vf == 'A' || vf == 'a'){
            std::cout << "Qual o local do ponto de entrega?" <<std::endl;
            ImpressaoPontoEntrega(Locais);
            int mb;
            std::cin >> mb;
            dadosLocal = Locais[mb-1]->endereco;
            std::cout << "Qual residuo voce deseja doar?"<< std::endl;
            ImpressaoResiduos(residuos);
            std::cin >> num;
            dadosResiduo = residuos[num-1]->gets_nome();
            std::cout << "Usuarios que aceitam doaçoes deste residuo: "<< std::endl;
           
            for(unsigned int contador2 = 0; contador2 < Usuarios.size(); contador2++){
                unsigned int temp2 = 0;
                while(temp2 < Usuarios[contador2]->gets_tipo_residuo().size()){
                    if(Usuarios[contador2]->gets_tipo_residuo()[temp2]->gets_nome() == residuos[num-1]->gets_nome()){
                        std::cout << "ID -  "<< Usuarios[contador2]->get_log()<<": USUARIO(A) - "<< contador2+1 << ": "<< Usuarios[contador2]->gets_nome() << std::endl;
                if(Usuarios[contador2]->get_id() == 1){
                    std::cout << "CNPJ: "<< Usuarios[contador2]->get_identificaçao()<< std::endl;
                }
                else{
                    std::cout << "CPF: "<< Usuarios[contador2]->get_identificaçao()<< std::endl;
                }
                std::cout << "CONDIÇAO DO(A) USUARIO(A): "<<Usuarios[contador2]->gets_razao()<< "(A)\n\n" << std::endl;
        }
        temp2++;
        
                }}
            int _log;
            int indicador = 0;
            int goku = 0;
            std::cout << "Digite a id do usuario que deseja doar: ";
            std::cin >> _log;
            if(Usuarios[goku]->get_log() == _log){
                std::cout << " Qual a data do encontro?\n ";
                std::cin.ignore(1000,'\n');
                std::getline(std::cin, horario);
                Usuarios[goku]->page = new userpage(Donirone, dadosResiduo, horario, dadosLocal);
                Usuarios[goku]->page->set_numero();
                std::cout<< "Mensagem enviada para " << Usuarios[goku]->gets_nome()<< ":\n" << "OLA, GOSTARIA DE MARCAR O ENCONTRO PARA DOAR " << "OS RESIDUOS" << " NO DIA " << horario << " NO PONTO DE ENTREGA " << dadosLocal << std::endl;
                indicador = 1;
            }
            while (goku < Usuarios.size() && _log != Usuarios[goku]->get_log()){
                if(Usuarios[goku]->get_log() == _log){
                    std::cout << " Qual a data do encontro?\n ";
                    std::cin.ignore(1000,'\n');
                    std::getline(std::cin, horario);
                    Usuarios[goku]->page = new userpage(Donirone, dadosResiduo, horario, dadosLocal);
                    std::cout<< "Mensagem enviada para " << Usuarios[goku]->gets_nome()<< ":\n" << "OLA, GOSTARIA DE MARCAR O ENCONTRO PARA DOAR " << "OS RESIDUOS" << " NO DIA " << horario << " NO PONTO DE ENTREGA " << dadosLocal << std::endl;
                    eventos.push_back(new Agendamento(true, Usuarios[goku]->gets_nome(), Donirone));
                    indicador = 1;
                    break;
                    
                }
                goku++;
            }
            if(indicador != 1){
                std::cout << " USUARIO NAO ENCONTRADO\n ";
                return main();
            }
        }
        //AGENDAMENTO PRIMEIRA PARTE(FINAL)----------------------------------------------------------------------------------------------
        //AGENDAMENTO SEGUNDA PARTE(INICIO)----------------------------------------------------------------------------------------------
        if (vf == 'B' || vf == 'b'){
            char confirmacao;
            std::cout << "----------------------------------------------------SUAS       MENSAGENS----------------------------------------------------\n" << std::endl;
            Usuarios[T]->page->get_mensagem();
            std::cout << "Deseja aceitar o evento?\nS)\tN)" << std::endl;
            std::cin >> confirmacao;
            if(confirmacao == 's' || confirmacao =='S'){
                unsigned int lastone = 0;
                    while( lastone < eventos.size() && (eventos[lastone]->get_receptor() != Usuarios[T]->gets_nome() && eventos[lastone]->get_donate() != Donirone)){
                        lastone++;
                        if(eventos[lastone]->get_receptor() == Usuarios[T]->gets_nome() && eventos[lastone]->get_donate() == Donirone){
                            eventos[lastone]->set_receptor(true);
                            eventos[lastone]->checa_agendamento();
                        }
                    }
                }
            else{
                unsigned int lastone2 = 0;
                while( lastone2 < eventos.size() && (eventos[lastone2]->get_receptor() != Usuarios[T]->gets_nome() && eventos[lastone2]->get_donate() != Donirone)){
                    lastone2++;
                    if(eventos[lastone2]->get_receptor() == Usuarios[T]->gets_nome() && eventos[lastone2]->get_donate() == Donirone){
                        eventos[lastone2]->set_receptor(false);
                    }}}
        }
        //AGENDAMENTO SEGUNDA PARTE(FINAL)----------------------------------------------------------------------------------------------
        if (vf == 'c' || vf == 'C'){
            return main();
        }
    }
    if(resposta == 'g' || resposta == 'G'){
        return 0;
    }
    
    return main();
    
    return 0;
}
