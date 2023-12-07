#ifndef DYNFILA_H
#define DYNFILA_H

#include <iostream>
#include "vrtce.h"

using namespace std;
//---------------------------------------------------------------------------
class dynFila
{
private:
    vertc* first; //front
    vertc* _last; //rear
//---------------------------------------------------------------------------
public:
    dynFila();                  // Constructor
    ~dynFila();                 // Destrutor
    bool FilaVazia();           // isEmpty
    bool FilaCheia();           // isFull
    void InsertItm( int item);  // enqueue //push
     int DeleteItm();           //dequeue //pop
    void ImprimirF();            //print
};
//---------------------------------------------------------------------------
#endif // DYNFILA_H
