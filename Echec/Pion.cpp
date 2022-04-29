#include<iostream>
#include"Plateau.h"
#include"Position.h"
#include"Piece.h"
#include"Pion.h"

using namespace std;

bool Pion :: isValideMove(Position *pos1,Position *pos2,bool *isCapture,Plateau *P)
{
    if(*isCapture == true && P->estDedans(pos2)==false)
        return false;
    if(*isCapture == true && P->getPiece(pos2)->estNoir == estNoir)
        return false;
    if(*isCapture == false && P->estDedans(pos2)==true)
        return false;
    int dx;
    // s'il s'agit d'un pion noir, il doit se deplacer en avant
    if( estNoir == true)
        dx = 1;
    // au contraire s'il est blanc, il se déplace vers le bas
    else
        dx = -1;

    if(*isCapture == false)
    {
        if(pos2-> y != pos1->y )
            return false;
        if(FirstMove == true)
        {
            /* Si le deplacement est superieure à deux cases */
            if(dx*(pos2->x - pos1->x) <= 0 || dx*(pos2->x - pos1-> x) > 2)
                return false;

            /* S'il souhaite se déplacer de deux cases , il ne faut pas avoir une piece entre ces deux position (start est fin ) */
            if(pos2->x - pos1->x == dx*2 && P->estDedans(new Position(*pos1,dx,0))==true)
                return false;
        }
        else
            if(dx*(pos2->x - pos1->x) <= 0 || dx*(pos2->x - pos1-> x) > 1)
                return false;
    }
    // un pion attact la piece du coté gauche ou droit

    else
    {
        int dy = pos2->y - pos1->y;
        if(dy != 1 && dy != -1)
            return false;
        if(dx*(pos2->x - pos1->x) <= 0 || dx*(pos2->x - pos1-> x) > 1)
            return false;
    }
    return true;
}
