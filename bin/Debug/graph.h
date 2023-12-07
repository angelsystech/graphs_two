#ifndef GRAPH_H
#define GRAPH_H
//---------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
/*
#define true 1
#define false 0

typedef int bool;
typedef int PESO;

typedef struct adjacencia {
	int vertice;                //vert. destino
	PESO peso; 	                //peso da aresta do vertice de destino
	struct adjacencia *prox;    //proximo elemento da lista de adjacencia
} ADJACENCIA;

typedef struct vertice {
	ADJACENCIA *base;           //possui a base da lista de adjacencia
} VERTICE;

*/
typdef struct grafoG {
	int   vrtces;                 //numero de vertices do grafo
	int   arstas;                 //numero de arestas do grafo
	int **adjcnt;                  //arranjo de vertices da estrutura
} GRAFOG;
//---------------------------------------------------------------------------
grafoG IniGph(int numvtc )
{
    GRAFOG grafoT = malloc( sizeof *grafoT);
    grafoT->vrtces = numvtc;
    grafoT->arstas = 0;
    grafoT->adjcnt = IniMat(numvtc, numvtc, 0);

    return grafoT;
}
//---------------------------------------------------------------------------
static int **IniMat( int Row, int Col, int val)  //Matriz de Adjacências
{
int i, j;

   int **Matrix = malloc( Row * sizeof (int *));
   for ( i = 0; i < Row; ++i)
      Matrix[i] = malloc( Col * sizeof (int));
   for ( i = 0; i < Row; ++i)
      for ( j = 0; j < Col; ++j)
         Matrix[i][j] = val;
   return Matrix;
}
//---------------------------------------------------------------------------
void InsrtA( GRAFOG G, int v, int w) {
   if (G->adj[v][w] == 0) {
      G->adj[v][w] = 1;
      G->A++;
   }
}
//---------------------------------------------------------------------------
/* REPRESENTAÇÃO POR MATRIZ DE ADJACÊNCIAS: A função GRAPHremoveArc() remove do grafo G o arco v-w. A função supõe que v e w são distintos, positivos e menores que G->V. Se não existe arco v-w, a função não faz nada. */
void RemovA( GRAFOG G, int v, int w) {
   if (G->adj[v][w] == 1) {
      G->adj[v][w] = 0;
      G->A--;
   }
}
//---------------------------------------------------------------------------
#endif // GRAPH_H_INCLUDED
