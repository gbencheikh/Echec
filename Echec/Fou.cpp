#include<iostream>
#include"Plateau.h"
#include"Position.h"
#include"Piece.h"
#include"Fou.h"

using namespace std;

bool Fou :: isValideMove(Position *pos1,Position *pos2,bool *isCapture,Plateau *P)
{
    // test de validiter trivial
    if(*isCapture == true && P->estDedans(pos2)==false)
        return false;
    if(*isCapture == true && P->getPiece(pos2)->estNoir == estNoir)
        return false;
    if(*isCapture == false && P->estDedans(pos2)==true)
        return false;

    int df1 = pos2->x - pos1->x;
    int df2 = pos2->y - pos1->y;

    // il se deplace sur la diagonale
    if( (df1 != df2 && df1 != -df2))
        return false;

    // calculer la dirrection du mouvement sur l'axe des x et de y
    int dx,dy;
    if(df1 > 0) dx = 1; else dx = -1;
    if(df2 > 0) dy = 1; else dy = -1;

    // chercher s'il y a un obstacle sur le chemin
    for(int i = 1 ; i < dx*df1 ; i++)
    {
        if(P->estDedans(new Position(*pos1,dx*i,dy*i))==true)
        {
            return false;
        }
    }

    return true;
}
