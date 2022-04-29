#include<iostream>
#include"Plateau.h"
#include"Position.h"
#include"Piece.h"
#include"Dame.h"
using namespace std;

bool Dame :: isValideMove(Position *pos1,Position *pos2,bool *isCapture,Plateau *P)
{
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
    int k = 0;
    for(int i = 1 ; i < dx*df1 ; i++)
    {
        if(P->estDedans(new Position(*pos1,dx*i,dy*i))==true)
            if(P->getPiece(new Position(*pos1,dx*i,dy*i))->estNoir == estNoir)
               return false;
            else
                k++;
    }
    // si c'est une capture alors le nombre de pièces entre la position de départ et la position d'arrivée est égale à 1
    if (*isCapture == true && k != 1)
        return false;
    if(*isCapture == false && k != 0 )
        return false;
}
