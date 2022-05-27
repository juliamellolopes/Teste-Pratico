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
    int dia, mes, ano, porte_pequeno, porte_grande, formula, dia_semana;
    float orcamento1, orcamento2, orcamento3;
public:
    Orcamento();
    // verificar se é ou não final de semana
    bool verificarDia();
    // verficar se o ano é bisexto
    void verfificarAno();
    // orçamento do MeuCaninoFeliz
    void orcamentoMeuCaninoFeliz();
    // orçamento do VaiRex
    void orcamentoVaiRex();
    // orçamento ChowChawgas
    void orcamentoChowChawgas();
    // comparando orcamentos
    void comparandoOrcamentos();
    // metodos set
    void setDia(int dia);
    void setMes(int mes);
    void setAno(int ano);
    void setPorte_pequeno(int porte_pequeno);
    void setPorte_grande(int porte_grandes);
};

#endif