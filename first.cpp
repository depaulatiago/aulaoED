/*
O dono de um sebo decidiu
controlar melhor seu acervo e seus
negócios. Ele gostaria de manter as
informações sobre com quem ele
negociou, armazenando nome e
telefone para contato, qual foi o
tipo de negócio (compra ou
venda), o valor do negócio (o
quanto foi pago ou recebido) e o
dia da semana em que o negócio
ocorreu.
Ele az negócios de segunda a sexta
e no sábado, ele deseja saber qual
foi o valor movimentado em
compras e em vendas durante a
semana toda e também qual foi o
dia da semana com maior
movimento de vendas.
Desenvolva um programa que o
ajude a cadastrar todos os negócios
que ele realizará.
*/



#include <iostream>

using namespace std;

class transacao
{
private:
    string nome;
    string telefone;
    char tipo;
    float valor;
    int dia;

public:
    transacao();
    ~transacao();
    void cadastrarTransacao(string n, string t, char tp, float v, int d);
    void calcularMovimentacao(float &totalCompra, float &totalVenda);
    int retornarDia() { return dia; }
    void imprimirTransacao();
};

transacao::transacao()
{
    nome = "";
    telefone = "";
    tipo = ' ';
    valor = 0;
    dia = 0;
}

transacao::~transacao()
{
    cout << "Objeto destruido" << endl;
}

void transacao::cadastrarTransacao(string n, string t, char tp, float v, int d)
{
    nome = n;
    telefone = t;
    tipo = tp;
    valor = v;
    dia = d;
}

void transacao::calcularMovimentacao(float &totalCompra, float &totalVenda)
{
    if (tipo == 'C')
    {
        totalCompra += valor;
    }
    else
    {
        totalVenda += valor;
    }
}

void transacao::imprimirTransacao()
{
    cout << "Nome: " << nome << endl;
    cout << "Telefone: " << telefone << endl;
    cout << "Tipo: " << tipo << endl;
    cout << "Valor: " << valor << endl;
    cout << "Dia: " << dia << endl;
}


int main()
{
    transacao negocios[10];
    char operacao, tipo;
    int contador = 0, dia;
    string nome, telefone;
    float val, feriaVenda = 0, feriaCompra = 0;

    cout << "Realizar operacao? (S/N): " << endl;
    cin >> operacao;

    while ((contador < 10) and (operacao == 's'))
    {
        cin >> nome >> telefone >> tipo >> val >> dia;
        negocios[contador].cadastrarTransacao(nome, telefone, tipo, val, dia);
        contador++;
        cout << "Realizar operacao? (S/N): " << endl;
        cin >> operacao;
    }

    contador--;
    while (contador >= 0)
    {
        negocios[contador].calcularMovimentacao(feriaCompra, feriaVenda);
        contador--;
    }

    cout << "Total de compras: " << feriaCompra << endl;
    cout << "Total de vendas: " << feriaVenda << endl;

    contador = 0;
    
    while (contador < 10){
        negocios[contador].imprimirTransacao();
        cout<<endl;
        contador++;
    }
}
