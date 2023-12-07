#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctime>
#include "graph.h"

#define V 9
#define MIN 1
using namespace std;
//---------------------------------------------------------------------------
void vInsVrt(Grafo &grafo, int numvrts)
{
int item1;

    if(numvrts > 5)
    {
        printf("\nOs v�rtices ser�o inseridos automaticamente!\n");
        grafo.insereavrtcs();
        printf("\nV�rtices inseridos com sucesso!\n");
        //else
            //exit();
    }
    else
    {
        do
        {
            cout << "Digite o elemento do v�rtice que ser� inserido: ";
            cin >> item1;

            grafo.inserevertice(item1);
        }
        while( grafo.estacheio() != true );

        //grafo.imprimirvertices();
    }
    grafo.imprimirvertices();
}
//---------------------------------------------------------------------------
void shuffle(int *array, int MAX)
{
    for (int i = 0; i < MAX; i++)
        array[i] = i + 1;

    for(int i = 0; i < (MAX * 2); i++)
    {
        int a = rand() % MAX;
        int b = rand() % MAX;

        int tmp = array[a];
        array[a] = array[b];
        array[b] = tmp;
    }
}
//---------------------------------------------------------------------------
void vIRArst(Grafo &grafo, int numvrts, int simdir)
{
char c;

    int num[numvrts];
    srand(time(NULL));

    if(numvrts > 5)
    {
        printf("\nDeseja inserir as arestas automaticamente?\n");
        printf("\nTecle (S)im ou (N)�o: ");
        scanf("%c", &c);

        if( c == 's' || c == 'S')
        {
            shuffle(num, numvrts);
            //for (int k = 0; k < numvrts; k++) printf("%d ", num[k]);

            grafo.insereaarsta(num, simdir);
        }
        else
        {
            grafo.inserearesta(simdir);
        }
    }
    else
    {
        printf("\n\nTecle I(INSERIR) ou R(REMOVER) uma aresta: ");
        scanf("%c", &c);

        if( c == 'i' || c == 'I')
        {
            grafo.inserearesta(simdir);
        }
        else if( c == 'r' || c == 'R')
        {
            grafo.deletearesta(simdir);
        }
        else
            cout << "OPC�O INV�LIDA!\n";
    }
}
//---------------------------------------------------------------------------
int main()
{
int b, numberV, item1, valor, orig, dest;

    setlocale(LC_ALL,"Portuguese_Brazil");

    printf("\n------------------ GRAFOS ------------------\n\n");

    printf("\nDigite o n�mero m�ximo de v�rtices do grafo: ");
    scanf("%d", &numberV);

    Grafo GRAPHS(numberV);

    printf("\nGrafo criado com sucesso!\n");

    do
    {
        printf("\n\n**** MENU DO PROGRAMA - GRAFOS ****\n\n"
                   " 1 - INSERIR V�RTICE\n"
                   " 2 - INSERIR OU REMOVER ARESTAS\n"
                   " 3 - CONSULTAR O GRAU DE UM V�RTICE\n"
                   " 4 - CONSULTAR O GRAU DO GRAFO\n"
                   " 5 - CONSULTAR OS VIZINHOS DE UM V�RTICE\n"
                   " 6 - VERIFICAR SE O GRAFO � CONEXO\n"
                   " 7 - VERIFICAR SE O GRAFO � REGULAR\n"
                   " 8 - VERIFICAR SE O GRAFO � COMPLETO\n"
                   " 9 - BUSCA EM PROFUNDIDADE\n"
                   "10 - BUSCA EM LARGURA\n"
                   "11 - EXIST�NCIA DE CAMINHO ENTRE V�RTICES\n"
                   "12 - VISUALIZA��O\n"
                   "13 - DIJKSTRA\n"
                   " 0 - SAIR DO PROGRAMA\n\n"
                   "     TECLE SUA ESCOLHA: ");

        scanf("%d", &b);
        fflush(stdin);

        if(b != 0)
        {
            system("CLS");

            if(b ==  1)
            {
                vInsVrt(GRAPHS, numberV);

            } else
            if((GRAPHS.estacheio()) && ((b >= 2) && (b <= 13)))
            {
                if(b ==  2)
                {
                    int sd;

                    printf("\nDigite 0 -> Grafo Simples ou 1 -> Grafo dirigido: ");
                    scanf("%d", &sd);
                    fflush(stdin);

                    vIRArst(GRAPHS, numberV, sd);
                    GRAPHS.imprimirmatriz();
                } else
                if(b ==  3)
                {
                    cout << "Digite o v�rtice que ser� calculado o grau: ";
                    cin >> item1;
                    valor = GRAPHS.obtergrauVertc(item1);
                    cout << "O grau desse vertice : " << valor << endl;
                } else
                if(b ==  4)
                {
                    valor = GRAPHS.obtergrauGraph();
                    cout << "O grau do GRAFO �: " << valor << endl;
                } else
                if((b ==  5) || (b == 12))
                {
                    cout << "     VERIFICAR OS VIZINHOS DE V�RTICES\n";
                    cout << "Digite o n�mero do v�rtice ou 0(zero) para todos: ";
                    cin >> item1;
                    GRAPHS.obteradjacentM(item1);
                    GRAPHS.imprimirmatriz();
                } else
                if(b ==  6)
                {
                    cout << "N�O IMPLEMENTADO\n";
                } else
                if(b ==  7)
                {
                    cout << "N�O IMPLEMENTADO\n";
                } else
                if(b ==  8)
                {
                    cout << "N�O IMPLEMENTADO\n";
                } else
                if(b ==  9)
                {
                    cout << "Digite o vertice de origem:\n";
                    cin >> orig;
                    cout << "Digite o vertice de destino:\n";
                    cin >> dest;

                    GRAPHS.DFSSearch( orig, dest );
                } else
                if(b == 10)
                {
                    cout << "Digite o vertice de origem:\n";
                    cin >> orig;
                    cout << "Digite o vertice de destino:\n";
                    cin >> dest;

                    GRAPHS.BFSSearch( orig, dest );
                } else
                if(b == 11)
                {
                    cout << "N�O IMPLEMENTADO\n";
                }else
                if(b == 13)
                {
                    /*int graph[V][V] =
                        { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };*/

                    GRAPHS.dijkstra(0);
                }
            }else
            if((!GRAPHS.estacheio()) && ((b >= 2) && (b <= 13)))
            {
                cout << "\nVoc� precisa inserir os v�rtices para usar essa op��o!";
            }
            else
            printf("\nOP��O INV�LIDA!");

        }
    } while(b != 0);

    printf("\nSaindo...\n\n");

    return 0;
}
//---------------------------------------------------------------------------
