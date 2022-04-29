#ifndef TOUR_H_INCLUDED
#define TOUR_H_INCLUDED

#include"Piece.h"
#include"Position.h"
#include"Plateau.h"

class Tour : public virtual Piece
{
public:
    Tour(bool couleur):Piece(couleur,"Tour"){}
    bool isValideMove(Position*,Position*,bool*,Plateau*);
};
#endif // TOUR_H_INCLUDED
