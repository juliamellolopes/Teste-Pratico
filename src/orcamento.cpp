#include "orcamento.hpp"

using namespace std;

Orcamento()
{
    dia = mes = ano = porte_pequeno = porte_grande, formula, dia_semana = orcamento1 = orcamento2 = orcamento3 = 0;
}

// verificar se é ou não final de semana onde vai retornar 0 ou 1,
// em que o 1 é para se for final de semana, senão retorna 0
bool verificarDia()
{
    if (mes == 01) // mês de janeiro será o mês 13 do ano anterior.
    {
        mes = 13;
        ano = ano - 1;
    }

    if (mes == 02) // mês de favereiro será o mês 14 do ano anterior.
    {
        mes = 14;
        ano = ano - 1;
    }

    // calculo do dia da semana
    formula = dia + 2 * mes + (3 * (mes + 1) / 5) + ano + ano / 4 - ano / 100 + ano / 400 + 2;
    dia_semana = formula % 7;

    if (mes == 13) // Se for mês de janeiro, coloca o valor certo do mês e do ano para mostrar na tela.
    {
        mes = 1;
        ano = ano + 1;
    }
    if (mes == 14) // Se for mês de fevereiro, coloca o valor certo do mês e do ano para mostrar na tela.
    {
        mes = 2;
        ano = ano + 1;
    }

    if (dia_semana == 0 && dia_semana == 1)
        return 0 else return 1
}

void verfificarAno()
{
    // verifica se o ano é ou não Bissexto e se a data é valida
    if ((ano % 4 == 0 && (ano % 400 == 0 || ano % 100 != 0)) && (dia > 0 && dia <= 31) && (mes > 0 && mes <= 12))
    {
        if (mes == 2 && dia > 29 || mes == 4 && dia > 30 || mes == 6 && dia > 30 || mes == 9 && dia > 30 || mes == 11 && dia > 30)
        {
            cout << "\nA data informada nao existe no calendario Gregoriano. \n";
            exit;
        }
        else
            verfificarDia();
    }
    else if (!(ano % 4 == 0 && (ano % 400 == 0 || ano % 100 != 0)) && (dia > 0 && dia <= 31) && (mes > 0 && mes <= 12))
    {
        if (mes == 2 && dia > 29 || mes == 4 && dia > 30 || mes == 6 && dia > 30 || mes == 9 && dia > 30 || mes == 11 && dia > 30)
        {
            cout << "\nA data informada nao existe no calendario Gregoriano. \n";
            exit;
        }
        else
            verfificarDia();
    }
    else
        cout << "\nA data informada nao existe no calendario Gregoriano. \n";
}

// metodo de orçamento do MeuCaninoFeliz
void orcamentoMeuCaninoFeliz()
{
    // calculo do orcamento em dias uteis
    orcamento1 = (porte_pequeno * 20) + (porte_grande * 40);

    if (verificarDia())
        return orcamento;
    else
        return orcamento = +(orcamento * 0.20); // se for final de semana o orcamento tera um aumento de 20%
}

// metodo de orçamento do VaiRex
void orcamentoVaiRex()
{
    if (verificarDia())
        return orcamento2 = (porte_pequeno * 15) + (porte_grande * 50); // calculo do orcamento em dias uteis
    else
        return orcamento2 = (porte_pequeno * 20) + (porte_grande * 55); // calculo do orcamento nos finais de semana
}

// metodo de orçamento ChowChawgas
void orcamentoChowChawgas()
{
    orcamento3 = (porte_pequeno * 30) + (porte_grande * 45); // calculo do orcamento
}

// comparando orcamentos é o metodo principal, dele sera chamado o metodo de verificarAno, a apartir do dia vamos
// para a chamada os metodos de  orcamentos de cada local. Depois de comparar as respostas sera impresso o resultado
void comparandoOrcamentos()
{
    // chamada dos metodos para serem feitos os calculos
    verificarAno();
    orcamentoMeuCaninoFeliz();
    orcamentoVaiRex();
    orcamentoChowChawgas();
    if (orcamento1 < orcamento2 || orcamento1 < orcamento3) // se o orcamento 1 for o maior
    {
        cout << "\n\tResultado: Meu Canino Feliz - %f" << orcamento1;
    }
    else if (orcamento2 < orcamento1 || orcamento2 < orcamento3) // se o orcamento 2 for o maior
    {
        cout << "\n\tResultado: Vai Rex - %f" << orcamento2;
    }
    else if (orcamento3 < orcamento1 || orcamento3 < orcamento2) // se o orcamento 3 for o maior
    {
        cout << "\n\tResultado: ChowChawgas - %f" << orcamento3;
    }
    else if (orcament1 == orcamento2 && orcamento2 == orcamento3 && orcamento1 == orcamento3) // se existirem orcamentos iguais
    {
        if (orcament1 == orcamento2) // se 1 e 2 forem iguais
            cout << "\n\tResultado: Vai Rex - %f" << orcamento2;
        if (orcamento2 == orcamento3) // se 3 e 2 forem iguais
            cout << "\n\tResultado: ChowChawgas - %f" << orcamento3;
        if (orcamento1 == orcamento3) // se 1 e 3 forem iguais
            cout << "\n\tResultado: ChowChawgas - %f" << orcamento3;
        if (orcamento1 == orcamento2 || orcamento1 == orcamento3)
            cout << "\n\tResultado: ChowChawgas - %f" << orcamento3;
    }
    else
        cout << "\n[ERRO]:Nao foi possivel calcular o orcamento";
}

// implementação dos metodos set
void setDia(int dia)
{
    this->dia = dia;
}
void setMes(int mes)
{
    this->mes = mes;
}
void setAno(int ano)
{
    this->ano = ano;
}
void setPorte_pequeno(int porte_pequeno)
{
    this->porte_pequeno = porte_pequeno;
}
void setPorte_grande(int porte_grande)
{
    this->porte_grande = porte_grande;
}
