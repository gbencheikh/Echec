#ifndef FOU_H_INCLUDED
#define FOU_H_INCLUDED

#include"Piece.h"
#include"Position.h"
#include"Plateau.h"

class Fou : public virtual Piece
{
public :
    bool FirstMove;

    Fou(bool couleur):Piece(couleur,"Fou"){FirstMove = true;}
    bool isValideMove(Position*,Position*,bool*,Plateau*);

};

#endif // FOU_H_INCLUDED
