<h1 align="center">Trabalho Pratico DTI Digital</h1>
Neste projeto estarei resolvendo um problema prático de um orçamento de 3 tipos de petshops, tendo como entrada a data e a quantidade de cachorros de portes pequeno e grande. Ao finalizar o código será possível ter uma saída do petshop com o melhor valor e o valor. Documentação do problema completo se encontra acima com o nome "Teste Prático A - Desenvolvimento".

### Copilação

Programação feita em C++, na plataforma Visual Studio Code, teminal Ubuntu-20.04. Abra o arquivo Mikefile.cpp e copile no terminal:
	
    make clean
    make
    make run

### Explicação do Código

Ao inicializar o programa será requisitado os dados de data e quantidade de animais de porte pequeno e grande, como pode ser visto abaixo: 

![image](https://user-images.githubusercontent.com/84408875/170807132-3029fdd1-4102-432b-8ca3-9543f2bacd6c.png)

Após a inserção dos dados será feita tokenização deles e depois serão enviados para seus respectivos métodos do tipo set. Foi criado os arquivos da classe Orcamento do tipo .cpp e .hpp que neles estaram os métodos para resolver o problema, sendo o principal o método "comparandoOrcamentos();".

No main.cpp, após o envio dos dados de entrada é chamado o método principal da classe, nele serão feitas as movimentações necessárias para resolver o problema. Se olharmos a sua elaboração no orcamento.cpp podemos observar que primeiro é chamado o método "verificarAno();", essa função foi criado para verificar se o primeiro dado, no caso a data, está correta, porque é necessário verificar se o ano é ou não bissexto e se o dia bate com o mês, se estiver correto será chamado o método "verificarDia();".

No método "verificarDia();" será possível saber se o dia é no final de semana ou não, se for vai ser retornado 0, se não for retorna 1. Retornando para o função principal, lá será chamado os metodos "orcamentoMeuCaninoFeliz();", "orcamentoVaiRex();" e "orcamentoChowChawgas();" responsaveis pela realização dos orçamentos de cada petshop. Esses métodos fazem o orçamento de acordo com as especificações dadas na documentação do problema.

Em seguida, a partir dos cálculos feitos de orçamentos, será feita uma comparação dos valores imprimindo na tela o menor valor e seu respectivo local, caso tenha valores iguais, o dado será do local mais perto. Como pode ser visto a abaixo:


![image](https://user-images.githubusercontent.com/84408875/170808434-aec60e82-d186-4eb0-ba23-53a71accb9cd.png)

Como pode ser visto, a partir dos valores de entrada esse foi o resultado da saída, o Vai Rex no valor de R$80.00, só que se pararmos para analisar o Meu Canino Feliz também dava o mesmo valor, porém o Vai Rex é mais perto, então ele vai ser a melhor opção
