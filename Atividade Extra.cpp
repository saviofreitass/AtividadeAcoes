#include <iostream>
#include <string.h>

using namespace std;

struct Acao{
 char ticket[6];
 float precoCompra;
 int quantidade;
};

int verificaAcao(Acao lista[100], char nome[6]){
    for(int i=0; i<100; i++){
        if(strcmp(lista[i].ticket, nome) == 0){
            return i;
        }
    }
    return -1;
}

void registrarVenda(Acao (&lista)[100]){
    Acao acaoVenda;

    fflush(stdin);
     cout << "Informe o ticket da empresa: ";
    cin.getline(acaoVenda.ticket,6);

    int index = verificaAcao(lista, acaoVenda.ticket);

    if(index == -1){
        cout << "Voce nao possui essa acao para vender\n\n";
    }else{
        cout << "Digite a quantidade que deseja vender: ";
        cin >> acaoVenda.quantidade;
        cout << "Digite o preco que esta vendendo: ";
        cin >> acaoVenda.precoCompra;
    }

    lista[index].quantidade -= acaoVenda.quantidade;

    if(lista[index].quantidade == 0){
        lista[index].precoCompra = 0;
    }
}

void registrarCompra(Acao (&lista)[100], int &i){
    Acao acao;
    fflush(stdin);
    cout << "Informe o ticket da empresa: ";
    cin.getline(acao.ticket,6);
    cout << "Informe a quantidade comprada: ";
    cin >> acao.quantidade;
    cout << "Informe o valor pago por cada acao: ";
    cin >> acao.precoCompra;

    int index = verificaAcao(lista, acao.ticket);

    if(index != -1){
        lista[index].precoCompra = ((lista[index].precoCompra * lista[index].quantidade) + (acao.precoCompra * acao.quantidade))/(lista[index].quantidade + acao.quantidade);
        lista[index].quantidade += acao.quantidade;
    }else{
        lista[i]=acao;
        i++;
    }

}

void verSaldo(Acao lista[100]){
    char ticket[6];
    fflush(stdin);
    cout << "\nDigite a acao para ver o saldo: ";
    cin.getline(ticket,6);

    int index = verificaAcao(lista,ticket);

    if(index != -1){
        cout << "Ticket da acao: " << lista[index].ticket<<endl;
        cout << "Quantidade: " << lista[index].quantidade<<endl;
        cout << "Preco medio: " << lista[index].precoCompra<<endl;
       } else{
            cout << "Voce nao possui essa acao!\n\n";
        }

}

int imprimePatrimonio(Acao lista[100]){
    for(int i=0; i<100; i++){
        if(strcmp(lista[i].ticket, "")== 0){
            return 0;
        }else{
            cout << "\n\nAcao " << i<< endl;
            cout << "Ticket da acao: " << lista[i].ticket<<endl;
            cout << "Quantidade: " << lista[i].quantidade<<endl;
            cout << "Preco medio: " << lista[i].precoCompra<<endl;
        }
    }
    return 0;
}

void menuOpcoes(Acao (&lista)[100], int i){

    system("pause");
    system("cls");

    int opcao;
    cout << "\n1-Registrar compra\n2-Registrar venda\n3-Ver o saldo de um ativo\n4-Listar patrimonio\n5-Sair\nEscolha uma opcao: ";
    cin >> opcao;

    switch(opcao){
    case 1:
        registrarCompra(lista, i);
        menuOpcoes(lista, i);
        break;
    case 2:
        registrarVenda(lista);
        menuOpcoes(lista, i);
        break;
    case 3:
        verSaldo(lista);
        menuOpcoes(lista, i);
        break;
    case 4:
        imprimePatrimonio(lista);
        menuOpcoes(lista, i);
        break;
    case 5:
        cout << "\nFalou!\n\n";
        break;
    default:
        cout << "\nOpcao invalida\n\n";
        menuOpcoes(lista, i);
    }
}

int main(){

    int i=0;
    Acao lista[100];
    menuOpcoes(lista, i);

    system("pause");

    return 0;
}
