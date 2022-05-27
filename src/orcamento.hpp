#ifndef ORCAMENTO_HPP
#define ORCAMENTO_HPP

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>

using namespace std;

class Orcamento
{
    private:

    public:
        // verificar se é ou não final de semana
            bool verificarDia();
        // orçamento do MeuCaninoFeliz
            float orcamentoMeuCaninoFeliz();
        // orçamento do VaiRex
            float orcamentoVaiRex();
        // orçamento ChowChawgas
            float orcamentoChowChawgas();
        // imprimindo resultado
            void imprimirResultado();
        // comparando orcamentos
            void comparandoOrcamentos();
};

#endif