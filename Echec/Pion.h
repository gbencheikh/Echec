#ifndef PION_H_INCLUDED
#define PION_H_INCLUDED

#include"Piece.h"
#include"Position.h"
#include"Plateau.h"

class Pion : public Piece
{
public :
    bool FirstMove;

    Pion(bool couleur,bool First):Piece(couleur,"Pion"){FirstMove = First;}
    bool isValideMove(Position*,Position*,bool*,Plateau*);

};
#endif // PION_H_INCLUDED
