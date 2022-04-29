#include<iostream>
#include"Plateau.h"
#include"Position.h"
#include"Piece.h"
#include"PionDame.h"
using namespace std;

bool PionDame :: isValideMove(Position *pos1,Position *pos2,bool *isCapture,Plateau *P)
{
    if(*isCapture == true)
    {
        // Si la piece est de couleur noir, elle faut qu'elle se deplace vers le haut
        // et qu'elle saut deuxx case, puisque c'est une capture
        if(P->getPiece(pos1)->estNoir == true)
        {
            if(pos2->x - pos1->x < 0)
            {

                return false;

            }
        }

        // si la piece est de couleur blanche, alors elle doit se deplacer vers le bas, de deux cases
        // si ce n'est pas le cas alors le mouvement est invalide
        else
            if(pos2->x - pos1->x > 0)
            {
                return false;

            }

        if(pos2->y - pos1->y != 2 && pos2->y - pos1->y != -2)
        {
            return false;

        }

            int dy;

            if(pos2->y - pos1->y > 0)
                dy = 1;
            else
                dy = -1;
            // Un pion effectue une prise en passant au-dessus d'un pion adverse.
            // si la position entre le point de depart et le point d'arriver est vide, le mouvement est invalide
            if(P->estDedans(new Position(*pos1,1,1*dy)) == false)
            {
                return false;

            }
            if(P->getPiece(new Position(*pos1,1,1*dy))->estNoir == P->getPiece(pos1)->estNoir)
            {
                return false;

            }
            if(P->estDedans(pos2) == true)
            {
                return false;

            }
    }
    else
    {
        cout<<"test";
        // si ce n'est pas une capture, il doit se deplacer par une seule case
        if(pos2->y - pos1->y !=1 && pos2->y - pos1->y != -1)
        {
            return false;

        }
        if(P->estDedans(pos2) == true)
        {
            return false;

        }
        if(P->getPiece(pos1)->estNoir == true)
        {
            if(pos2->x - pos1->x != 1)
            {
                return false;

            }
        }

        else
            if(pos2->x - pos1->x != -1)
            {
                return false;

            }
    }
    return true;
}
