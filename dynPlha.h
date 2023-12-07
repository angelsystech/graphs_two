#ifndef DYNPLHA_H
#define DYNPLHA_H

#include <iostream>
#include "vrtce.h"

using namespace std;
//---------------------------------------------------------------------------
class dynPilha
{
private:
    vertc* TopVrtc;                 // Topo

//---------------------------------------------------------------------------
public:
    dynPilha();                //construtor //dynamic stack
    ~dynPilha();               //destrutor
    bool PilhaVazia();               //isempty
    bool PilhaCheia();               //tem memória //isfull
    void InsertItm(int item);    //push
     int DeleteItm();             //pop
    void ImprimirP();                //print
};
//---------------------------------------------------------------------------
#endif // DYNPLHA_H
