#ifndef DAME_H_INCLUDED
#define DAME_H_INCLUDED
#include"Piece.h"

class Dame : public Piece
{
public :
    Dame(bool couleur): Piece(couleur,"Dame"){}
    bool isValideMove(Position*,Position*,bool*,Plateau*);

};

#endif // DAME_H_INCLUDED
