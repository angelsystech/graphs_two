#include <iostream>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include "graph.h"
#include "dynFila.h"
#include "dynPlha.h"

using namespace std;
//---------------------------------------------------------------------------
Grafo::Grafo(int numver) //construtor
{
maxvertices = numver;
marker      = new bool[maxvertices];
vertices    = new  int[maxvertices];

        matrizadjacencias = new int*[maxvertices];

        for(int i = 0; i < maxvertices; i++)
        {
            matrizadjacencias[i] = new int[maxvertices];
        }

        for(int i = 0; i < maxvertices; i++)
        {
            for (int j = 0; j < maxvertices; j++)
            {
                matrizadjacencias[i][j] = 0;
            }
        }
}
//---------------------------------------------------------------------------
Grafo::~Grafo() //destrutor
{
    delete [] marker;
    delete [] vertices;

    for(int i = 0; i < maxvertices; i++)
    {
        delete [] matrizadjacencias[i];
    }
        delete [] matrizadjacencias;
}
//---------------------------------------------------------------------------
int Grafo::obterindice(int item)
{
int indice = 0;

        while(item != vertices[indice])
        {
            indice++;
        }
        return indice;
}
//---------------------------------------------------------------------------
bool Grafo::estacheio()
{
    return(numvertices == maxvertices);
}
//---------------------------------------------------------------------------
void Grafo::inserevertice(int item)
{
    if(estacheio())
    {
        cout << "O numero maximo de vertices foi alcancado!\n";
    }
    else
    {
        vertices[numvertices] = item;
        numvertices++;
    }
}
//---------------------------------------------------------------------------
void Grafo::insereavrtcs()
{
    for (int i = 1; i < maxvertices + 1; i++)
        inserevertice(i);
}
//---------------------------------------------------------------------------
void Grafo::inserearesta(int simpledirec)
{
int r, linha, coluna, Nosaida, Noentrada, peso;

    do
    {
        cout << "\n  Digite o vértice de saida: ";
        cin >> Nosaida;
        cout << "\nDigite o vértice de entrada: ";
        cin >> Noentrada;
        cout << "\n Digite o peso desta aresta: ";
        cin >> peso;

        linha = obterindice(Nosaida);
        coluna = obterindice(Noentrada);

        if(simpledirec == 0)
        {
            matrizadjacencias[linha][coluna] = peso;
            matrizadjacencias[coluna][linha] = peso;
        }
        else
            matrizadjacencias[linha][coluna] = peso;

        printf("\nDeseja inserir outra aresta? Tecle 0 - NÃO ou 1 - SIM: ");
        scanf("%d", &r);

    }while(r != 0);
}
//---------------------------------------------------------------------------
void Grafo::insereaarsta(int *array, int simpledirec)
{
int linha, coluna;

    for (int i = 0; i < maxvertices; i++)
    {
        linha = obterindice(i + 1);
        coluna = obterindice(array[i]);

        if(simpledirec == 0)
        {
            if(linha == coluna)
            {
                matrizadjacencias[linha][coluna] = 0;
                matrizadjacencias[coluna][linha] = 0;
            }
            else
            {
                matrizadjacencias[linha][coluna] = 1;
                matrizadjacencias[coluna][linha] = 1;
            }
        }
        else
        {
            if(linha == coluna)
                matrizadjacencias[linha][coluna] = 0;
            else
                matrizadjacencias[linha][coluna] = 1;
        }
    }
}
//---------------------------------------------------------------------------
void Grafo::deletearesta(int simpledirec)
{
int linha, coluna, Nosaida, Noentrada;

    cout << "Digite o vértice de saida: ";
    cin >> Nosaida;
    cout << "Digite o vértice de entrada: ";
    cin >> Noentrada;

    linha = obterindice(Nosaida);
    coluna = obterindice(Noentrada);

    if(simpledirec == 0)
    {
        matrizadjacencias[linha][coluna] = 0;
        matrizadjacencias[coluna][linha] = 0;
    }
    else
        matrizadjacencias[linha][coluna] = 0;
}
//---------------------------------------------------------------------------
int Grafo::obterpeso(int Nosaida, int Noentrada)
{
int linha = obterindice(Nosaida);
int coluna = obterindice(Noentrada);

    return (matrizadjacencias[linha][coluna]);
}
//---------------------------------------------------------------------------
int Grafo::obtergrauVertc(int item)
{
int linha = obterindice(item);
int grau = 0;

    for (int i = 0; i < maxvertices; i++)
    {
        if(matrizadjacencias[linha][i] != 0)
            grau++;
    }
    return grau;
}
//---------------------------------------------------------------------------
int Grafo::obtergrauGraph()
{
int linha;
int grau = 0;

    for (int i = 0; i < maxvertices; i++)
    {
        linha = obterindice(i + 1);

        for (int j = 0; j < maxvertices; j++)
            if(matrizadjacencias[linha][j] != 0)
                grau++;
    }
    return grau;
}
//---------------------------------------------------------------------------
void Grafo::obteradjacentM(int item)
{
int linha = obterindice(item);

    if(item != 0)
    {
        linha = obterindice(item);

        printf("%6d%s", vertices[linha], ":");
        obteradjacentD(linha);
    }
    else
    {
        for (int i = 0; i < maxvertices; i++)
        {
            linha = obterindice(i + 1);

            printf("%6d%s", vertices[linha], ":");
            obteradjacentD(linha);
            printf("\n");
        }
    }
    printf("\n\n");
}
//---------------------------------------------------------------------------
void Grafo::obteradjacentD(int item)
{
    for (int i = 0; i < maxvertices; i++)
    {
        if(matrizadjacencias[item][i] != 0)
            printf(" %d", vertices[i]);
    }
}
//---------------------------------------------------------------------------
void Grafo::imprimirmatriz()
{
int i, j;

    if(maxvertices > 100)
    {
        printf("\nMATRIZ DE ADJACÊNCIAS\n");
        printf("\n\nO número de linhas e colunas é superior ao permitido visualizar!");
    }
    else
    {
        cout << "\nMATRIZ DE ADJACÊNCIAS\n";

        for( i = 0; i < maxvertices; i++)
        {
            for( j = 0; j < maxvertices; j++)
            {
                cout << matrizadjacencias[i][j] << " ";
            }
            cout << endl;
        }
    }
}
//---------------------------------------------------------------------------
void Grafo::imprimirvertices()
{
    cout << "\nLISTA DE VÉRTICES\n";

    for(int i = 0; i < numvertices; i++)
    {
        printf("%6d%s", vertices[i], ": ");
    }
}
//---------------------------------------------------------------------------
void Grafo::ClearMarker()
{
    for(int i = 0; i < maxvertices; i++)
    {
        marker[i] = false;
    }
}
//---------------------------------------------------------------------------
void Grafo::BFSSearch(int orig, int dest)
{
dynFila VrtcFila; //fila de vertices
bool VFound = false;

    ClearMarker();
    VrtcFila.InsertItm( orig );

    do
    {
        int VrtcAtual = VrtcFila.DeleteItm();

        if ( VrtcAtual == dest )
        {
            cout << "Visitando: " << VrtcAtual << endl;
            cout << "Caminho encontrado!\n";
            VFound = true;
        }
        else
        {
            int indice = obterindice(VrtcAtual);

            cout << "Visitando: " << VrtcAtual << endl;
            for( int i = 0; i < maxvertices; i++)
            {
                if(matrizadjacencias[indice][i] != 0)
                {
                    if(!marker[i])
                    {
                        cout << "Enfileirando: " << vertices[i] << endl;
                        VrtcFila.InsertItm( vertices[i] );
                        marker[i] = true;
                    }
                }
            }
        }
    } while (!VrtcFila.FilaVazia() && !VFound);

    if( !VFound )
        {
            cout << "Caminho nao encontrado!\n";
        }
}
//---------------------------------------------------------------------------
void Grafo::DFSSearch(int orig, int dest)
{
dynPilha VrtcPilha;
bool VFound = false;

    ClearMarker();
    VrtcPilha.InsertItm( orig );

    do
    {
        int VrtcAtual = VrtcPilha.DeleteItm();

        if( VrtcAtual == dest )
        {
            cout << "Visitando: " << VrtcAtual << endl;
            cout << "Caminho encontrado!\n";
            VFound = true;
        }
        else
        {
            int indice = obterindice(VrtcAtual);

            cout << "Visitando: " << VrtcAtual << endl;

            for(int i = 0; i < maxvertices; i++)
            {
                if (matrizadjacencias[indice][i] != 0)
                {
                    if (!marker[i])
                    {
                        cout << "Empilhando: " << vertices[i] << endl;

                        VrtcPilha.InsertItm(vertices[i]);
                        marker[i] = true;
                    }
                }
            }
        }
    }
    while( !VrtcPilha.PilhaVazia() && !VFound );

    if ( !VFound )
    {
        cout << "Caminho não encontrado!\n";
    }
}
//---------------------------------------------------------------------------
// A utility function to find the vertex with minimum distance value, from
// the set of vertices not yet included in shortest path tree
int Grafo::minDistance(int dist[], bool sptSet[])
{
    // Initialize min value
    int min = INT_MAX, min_index;

    for (int v = 0; v < maxvertices; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}
//---------------------------------------------------------------------------
// A utility function to print the constructed distance array
void Grafo::printSolution(int dist[], int n)
{
    printf("Vértice  Distância da Origem\n");
    for (int i = 0; i < maxvertices; i++)
        printf("%4d\t\t%d\n", vertices[i], dist[i]);
}
//---------------------------------------------------------------------------

// Function that implements Dijkstra's single source shortest path algorithm
// for a graph represented using adjacency matrix representation
void Grafo::dijkstra(int src)
{
int graph[maxvertices][maxvertices];

    for(int i = 0; i < maxvertices; i++)
    {
        for (int j = 0; j < maxvertices; j++)
        {
            graph[i][j] = matrizadjacencias[i][j];
        }
    }

    int dist[maxvertices]; // The output array.  dist[i] will hold the shortest
    // distance from src to i

    bool sptSet[maxvertices]; // sptSet[i] will be true if maxverticesertex i is included in shortest
    // path tree or shortest distance from src to i is finalized

    // Initialize all distances as INFINITE and stpSet[] as false
    for (int i = 0; i < maxvertices; i++)
        dist[i] = INT_MAX, sptSet[i] = false;

    // Distance of source maxverticesertex from itself is always 0
    dist[src] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < maxvertices - 1; count++) {
        // Pick the minimum distance vertex from the set of vertices not
        // yet processed. u is always equal to src in the first iteration.
        int u = minDistance(dist, sptSet);

        // Mark the picked vertex as processed
        sptSet[u] = true;

        // Update dist value of the adjacent vertices of the picked vertex.
        for (int v = 0; v < maxvertices; v++)

            // Update dist[v] only if is not in sptSet, there is an edge from
            // u to v, and total weight of path from src to  v through u is
            // smaller than current value of dist[v]
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
                && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    // print the constructed distance array
    printSolution(dist, maxvertices);
}
//---------------------------------------------------------------------------
