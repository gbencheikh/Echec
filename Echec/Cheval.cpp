#include<iostream>
#include"Plateau.h"
#include"Position.h"
#include"Piece.h"
#include"Cheval.h"

using namespace std;

bool Cheval :: isValideMove(Position *pos1,Position *pos2,bool *isCapture,Plateau *P)
{
    if(*isCapture == true && P->estDedans(pos2)==false)
        return false;
    if(*isCapture == true && P->getPiece(pos2)->estNoir == estNoir)
        return false;
    if(*isCapture == false && P->estDedans(pos2)==true)
        return false;

    int dx = pos1->x - pos2->x;
    int dy = pos1->y - pos2->y;
    // un cheval soit saute deux cases puis tourne une case
    //Soit le contraire
    if (dx == 2 || dx == -2 )
       if(dy != 1 && dy != -1)
        return false;
    if(dy == 2 || dy == -2 )
       if(dx != 1 && dx != -1)
        return false;
    if(dy != 2 && dy != -2 && dx != 2 && dx != -2)
       return false;
    return true;
}
