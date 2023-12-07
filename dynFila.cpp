#include <iostream>
#include <cstddef>
#include <new>
#include "dynFila.h"

using namespace std;
//---------------------------------------------------------------------------
dynFila::dynFila()
{
    first = NULL;
    _last = NULL;
}
//---------------------------------------------------------------------------
dynFila::~dynFila()
{
    vertc* tmp;

    while( first != NULL )
    {
        tmp = first;
            first = first->next;
            delete tmp;
        }
        _last = NULL;
}
//---------------------------------------------------------------------------
bool dynFila::FilaVazia()
{
    return( first == NULL );
}
//---------------------------------------------------------------------------
bool dynFila::FilaCheia()
{
    vertc* tmp;

    try
    {
        tmp = new vertc;

        delete tmp;
        return false;
    }
    catch(bad_alloc(exception))
    {
        return true;
    }
}
//---------------------------------------------------------------------------
void dynFila::InsertItm( int item)
{
    if( FilaCheia())
    {
            cout << "A Fila está cheia!\n";
            cout << "Não foi possível inserir este elemento!\n";
    }
    else
    {
            vertc* NewVrtc = new vertc;
            NewVrtc->valor = item;
            NewVrtc->next = NULL;

            if( first == NULL )
            {
                first = NewVrtc;
            }
            else
            {
                _last->next = NewVrtc;
            }
            _last = NewVrtc;
    }
}
//---------------------------------------------------------------------------
int dynFila::DeleteItm()
{
    if( FilaVazia())
    {
        cout << "A fila está vazia!\n";
        cout << "Não tem elemento a ser removido!\n";
        return 0;
    }
    else
    {
            vertc* tmp = first;
            int item = first->valor;
            first = first->next;
            if( first == NULL )
            {
                _last = NULL;
            }
            delete tmp;
            return item;
    }
}
//---------------------------------------------------------------------------
void dynFila::ImprimirF()
{
    vertc* tmp = first;

    cout << "Fila= [ ";

    while (tmp != NULL)
    {
        cout << tmp->valor << " ";
        tmp = tmp->next;
    }
        cout << "]\n";
}  //---------------------------------------------------------------------------
