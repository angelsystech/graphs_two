#include <iostream>
#define V 9
using namespace std;
//---------------------------------------------------------------------------
class Grafo
{
private:
     int maxvertices; //numero maximo de vertices
     int numvertices;
     int* vertices;
     int** matrizadjacencias;
    bool* marker;
//---------------------------------------------------------------------------
public:
    Grafo(int numver);
    ~Grafo();

     int obterindice(int item);
     int obterpeso(int Nosaida, int Noentrada);
     int obtergrauGraph();
     int obtergrauVertc(int item);
    bool estacheio();
    void inserevertice(int item);
    void insereavrtcs();
    void inserearesta(int simpledirec);
    void deletearesta(int simpledirec);
    void insereaarsta(int *array, int simpledirec);
    void obteradjacentM(int item);
    void obteradjacentD(int item);
    void imprimirmatriz();
    void imprimirvertices();
    void ClearMarker();
    void BFSSearch(int orig, int dest); //busca pela largura
    void DFSSearch(int orig, int dest); //busca pela profundidade
    //dijkstra
     int minDistance(int dist[], bool sptSet[]);
    void printSolution(int dist[], int n);
    void dijkstra(int src);
    //void dijkstra(int graph[V][V], int src);
};
//---------------------------------------------------------------------------
