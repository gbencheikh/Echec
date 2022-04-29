#include<iostream>
#include"Plateau.h"
#include"Piece.h"
#include"Tour.h"
#include"Position.h"

using namespace std;

bool Tour :: isValideMove(Position *pos1,Position *pos2,bool *isCapture,Plateau *P)
{
    if(*isCapture == true && P->estDedans(pos2) == false)
        return false;
    if(*isCapture == true && P->getPiece(pos2)->estNoir == estNoir)
        return false;
    if(*isCapture == false && P->estDedans(pos2) == true)
        return false;

    int dfx = pos2->x - pos1->x;
    int dfy = pos2->y - pos1->y;
    //la tour se déplace le long des colonnes ou des rangées
    if(pos1->x != pos2->x && pos1->y != pos2->y)
        return false;
    if(dfx == dfy)
        return false;
    // s'il se deplace haurizontalement
    if(dfx==0)
    {
        int dy;
        if(dfy > 0) dy = 1; else dy = -1;

        // S'il existe une piece dans le chemin
        for(int i = 1 ; i < dy*dfy ; i++)
            if(P->estDedans(new Position(*pos1,0,dy*i))==true)
                return false;
    }
    //s'il se deplace verticalement
    else
    {
        int dx;
        if(dfx > 0) dx = 1; else dx = -1;
        for(int i = 1 ; i < dx*dfx ; i++)
            if(P->estDedans(new Position(*pos1,dx*i,0))==true)
                 return false;
    }
    return true;
}
