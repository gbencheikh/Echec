#ifndef PIONDAME_H_INCLUDED
#define PIONDAME_H_INCLUDED

#include"Piece.h"

class PionDame : public Piece
{
public :

    PionDame(bool couleur):Piece(couleur,"Pion"){}
    bool isValideMove(Position*,Position*,bool*,Plateau*);
};

#endif // PIONDAME_H_INCLUDED
