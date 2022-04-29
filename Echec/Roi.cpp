#include<iostream>
#include"Plateau.h"
#include"Piece.h"
#include"Roi.h"
#include"Position.h"

using namespace std;

bool Roi :: isValideMove(Position *pos1,Position *pos2,bool *isCapture,Plateau *P)
{
    if(*isCapture == true && P->estDedans(pos2) == false)
        return false;
    if(*isCapture == true && P->getPiece(pos2)->estNoir == estNoir)
        return false;
    if(*isCapture == false && P->estDedans(pos2) == true)
        return false;

    /* le roi ne bouge que par une case */
    int dx = pos2-> x - pos1->x ;
    int dy = pos2-> y - pos1->y;

    if(dx > 1 || dx < -1 || dy > 1 || dy < -1)
    {
        return false;
    }


    /* si on deplace le roi à la position souhaité, il ne faut pas que le roi soit menacé par une pièce adversaire */

    if(P->echec(estNoir,pos2) == true)
    {
        return false;
    }

    /* il faut avoir au moins une case entre les deux roi */
    /* pour cela on cherche la position du roi de l'autre couleur */
    /* si la position de fin est parmi les cases qui l'entour on retourne false */

    for(int i=0; i< 8 ; i++)
    {
        for(int j=0;j<8;j++)
        {
            if(P->estDedans(new Position(i+1,j+1)) == true)
                if(P->getPiece(new Position(i+1,j+1))->nom == "Roi" && P->getPiece(new Position(i+1,j+1))->estNoir != estNoir)
                {
                    int dx = pos1->x - pos2->x ;
                    int dy = pos2->y - pos2->y ;
                    if((dx < 2 || dx > -2) && (dy > 2 || dy < -2))
                    {
                        return false;

                    }
                }
        }
    }

    // On a tester tous les mouvements invalide, s'il arrive à ce point cela veut dire que le mouvement est valide
    return (true);
}
