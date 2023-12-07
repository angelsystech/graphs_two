#include <iostream>
#include <new>
#include <cstddef> //NULL
#include "dynPlha.h"

using namespace std;
//---------------------------------------------------------------------------
dynPilha::dynPilha()
{
    TopVrtc = NULL;
}
//---------------------------------------------------------------------------
dynPilha::~dynPilha()
{
    vertc* VTmp;

    while(TopVrtc != NULL)
    {
        VTmp = TopVrtc;
        TopVrtc = TopVrtc->next;
        delete VTmp;
    }
}
//---------------------------------------------------------------------------
bool dynPilha::PilhaVazia()
{
    return( TopVrtc == NULL );
}
//---------------------------------------------------------------------------
bool dynPilha::PilhaCheia()
{
    vertc* NewVrtc;

    try
    {
        NewVrtc = new vertc;
        delete NewVrtc;
        return false;
    }
    catch(bad_alloc(exception))
    {
        return true;
    }
}
//---------------------------------------------------------------------------
void dynPilha::InsertItm(int item)
{
    if( PilhaCheia())
    {
        cout << "A Pilha está cheia!\n";
        cout << "Não foi possível inserir este elemento!\n";
    }
    else
    {
        vertc* NewVrtc = new vertc;
        NewVrtc->valor = item;
        NewVrtc->next = TopVrtc;
        TopVrtc = NewVrtc;
    }
}
//---------------------------------------------------------------------------
int dynPilha::DeleteItm()
{
    if( PilhaVazia() )
    {
        cout << "A Pilha está vazia!\n";
        cout << "Não foi possível remover nenhum elemento!\n";
        return 0;
    }
    else
    {
        vertc* VTmp;
        VTmp = TopVrtc;
        int item = TopVrtc->valor;
        TopVrtc = TopVrtc->next;
        delete VTmp;
        return item;
    }
}
//---------------------------------------------------------------------------
void dynPilha::ImprimirP()
{
    vertc* VTmp = TopVrtc;

    cout << "Pilha: [ ";

    while( VTmp != NULL )
    {
        cout << VTmp->valor << " ";
        VTmp = VTmp->next;
    }
    cout << "]\n";
}
//---------------------------------------------------------------------------
