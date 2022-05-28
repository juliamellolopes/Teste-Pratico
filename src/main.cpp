#include "orcamento.hpp"

typedef struct ItensEntrada {
    int dia;
    int mes;
    int ano;
    int p_p;
    int p_g;
} ItensEntrada;

void menu() {
    cout << "\t\t-----------------INICIALIZANDO PROGRAMA-------------------------" << endl;
    cout << "Informe os dados a segui: <data> <quantidade de cães pequenos> <quantidade cães grandes>" << endl;
    cout << "Exemplo de entrada: 03/08/2018 3 5" << endl;
}

void token(char *str, ItensEntrada *item) {
    const char sep[] = "/ ";
    char *tokens;
    int cont = 0;

    tokens = strtok(str, sep);

    while (tokens != NULL) {                  // a medida que o token vai quebrando a string o contador vai organizando
        if (cont == 0)      item->dia = atoi(tokens);
        else if (cont == 1) item->mes = atoi(tokens);
        else if (cont == 2) item->ano = atoi(tokens);
        else if (cont == 3) item->p_p = atoi(tokens);
        else if (cont == 4) item->p_g = atoi(tokens);
        tokens = strtok(NULL, sep);
        cont++;
    }
}

int main() {
    char entrada[15];
    ItensEntrada item;
    Orcamento o;

    // vou receber as informações <data> <quantidade de cães pequenos> <quantidade cães grandes>
    menu();
    cin.getline(entrada, 15);

    // toquenikar as informações
    token(entrada, &item);

    // enviar os dados de entrada
    o.setDia(item.dia);
    o.setMes(item.mes);
    o.setAno(item.ano);
    o.setPorte_pequeno(item.p_p);
    o.setPorte_grande(item.p_g);

    o.comparandoOrcamentos();
    return 0;
}