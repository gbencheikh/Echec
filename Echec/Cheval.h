#ifndef CHEVAL_H_INCLUDED
#define CHEVAL_H_INCLUDED

#include"Position.h"
#include"Piece.h"
#include"Plateau.h"

class Cheval : public Piece
{
public:
    Cheval(bool couleur):Piece(couleur,"Cheval"){}
    bool isValideMove(Position*,Position*,bool*,Plateau*);
};
#endif // CHEVAL_H_INCLUDED
