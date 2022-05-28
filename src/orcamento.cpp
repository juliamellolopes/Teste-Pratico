#include "orcamento.hpp"

using namespace std;

Orcamento::Orcamento() {
    dia = mes = ano = porte_pequeno = porte_grande, formula, dia_semana = orcamento1 = orcamento2 = orcamento3 = 0;
}

// implementação dos metodos set
void Orcamento::setDia(int dia) {this->dia = dia;}
void Orcamento::setMes(int mes) {this->mes = mes;}
void Orcamento::setAno(int ano) {this->ano = ano;}
void Orcamento::setPorte_pequeno(int porte_pequeno) {this->porte_pequeno = porte_pequeno;}
void Orcamento::setPorte_grande(int porte_grande) {this->porte_grande = porte_grande;}

// verificar se é ou não final de semana onde vai retornar 0 ou 1,
// em que o 1 é para se for final de semana, senão retorna 0
bool Orcamento::verificarDia() {

    if (mes == 01){ // mês de janeiro será o mês 13 do ano anterior
        mes = 13;
        ano = ano - 1;
    }
    if (mes == 02){ // mês de favereiro será o mês 14 do ano anterior
        mes = 14;
        ano = ano - 1;
    }

    // calculo do dia da semana
    formula = dia + 2 * mes + (3 * (mes + 1) / 5) + ano + ano / 4 - ano / 100 + ano / 400 + 2;
    dia_semana = formula % 7;

    if (dia_semana == 0 || dia_semana == 1) return 0;
    else                                    return 1;

    return 0;
}

void Orcamento::verificarAno() {

    // verifica se o ano é ou não Bissexto e se a data é valida
    if ((ano % 4 == 0 && (ano % 400 == 0 || ano % 100 != 0)) && (dia > 0 && dia <= 31) && (mes > 0 && mes <= 12)) {
        if (mes == 2 && dia > 29 || mes == 4 && dia > 30 || mes == 6 && dia > 30 || mes == 9 && dia > 30 || mes == 11 && dia > 30) {
            cout << "\n[ERRO]: A data informada nao existe no calendario Gregoriano \n";
            exit;
        } else verificarDia();
    } else if (!(ano % 4 == 0 && (ano % 400 == 0 || ano % 100 != 0)) && (dia > 0 && dia <= 31) && (mes > 0 && mes <= 12)) {
        if (mes == 2 && dia > 29 || mes == 4 && dia > 30 || mes == 6 && dia > 30 || mes == 9 && dia > 30 || mes == 11 && dia > 30) {
            cout << "\n[ERRO]: A data informada nao existe no calendario Gregoriano \n";
            exit;
        } else verificarDia();
    } else 
        cout << "\n[ERRO]: A data informada nao existe no calendario Gregoriano \n";
}

// metodo de orçamento do MeuCaninoFeliz
void Orcamento::orcamentoMeuCaninoFeliz() {

    // calculo do orcamento em dias uteis
    orcamento1 = (porte_pequeno * 20) + (porte_grande * 40);

    // se for final de semana o orcamento tera um aumento de 20%
    if(verificarDia() == 1) orcamento1;
    else                    orcamento1 =+ orcamento1+(orcamento1*0.20);
}

// metodo de orçamento do VaiRex
void Orcamento::orcamentoVaiRex() {
    if (verificarDia() == 1) orcamento2 = (porte_pequeno * 15) + (porte_grande * 50); // calculo do orcamento em dias uteis
    else                     orcamento2 = (porte_pequeno * 20) + (porte_grande * 55); // calculo do orcamento nos finais de semana
}

// metodo de orçamento ChowChawgas
void Orcamento::orcamentoChowChawgas() {
    orcamento3 = (porte_pequeno * 30) + (porte_grande * 45); // calculo do orcamento
}

// comparando orcamentos é o metodo principal, dele sera chamado o metodo de verificarAno, a apartir do dia vamos
// para a chamada os metodos de  orcamentos de cada local. Depois de comparar as respostas sera impresso o resultado
void Orcamento::comparandoOrcamentos() {
    
    // chamada dos metodos para serem feitos os calculos
    verificarAno();
    orcamentoMeuCaninoFeliz();
    orcamentoVaiRex();
    orcamentoChowChawgas();
    
    if (orcamento1 < orcamento2 && orcamento1 < orcamento3)         printf("\n\tResultado: Meu Canino Feliz - R$ %.2f", orcamento1);
    else if (orcamento2 < orcamento1 && orcamento2 < orcamento3)    printf("\n\tResultado: Vai Rex - R$ %.2f",orcamento2);
    else if (orcamento3 < orcamento1 && orcamento3 < orcamento2)    printf("\n\tResultado: ChowChawgas - R$ %.2f", orcamento3);
    else if (orcamento1 == orcamento2)                              printf("\n\tResultado: Vai Rex - R$ %.2f",orcamento2);                              
    else if (orcamento2 == orcamento3)                              printf("\n\tResultado: ChowChawgas - R$ %.2f", orcamento3);
    else if (orcamento1 == orcamento3)                              printf("\n\tResultado: ChowChawgas - R$ %.2f", orcamento3);
    else if (orcamento1 == orcamento2 || orcamento1 == orcamento3)  printf("\n\tResultado: ChowChawgas - R$ %.2f", orcamento3);
    else                                                            cout << "\n[ERRO]:Nao foi possivel calcular o orcamento";
    cout << endl;
}