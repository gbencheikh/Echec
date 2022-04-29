#ifndef REINE_H_INCLUDED
#define REINE_H_INCLUDED

#include "Piece.h"
#include"Position.h"
#include"Plateau.h"
#include"Tour.h"
#include"Fou.h"

class Reine : public Tour , public Fou
{
public :
    Reine(bool couleur):Piece(couleur,"Reine"),Tour(couleur),Fou(couleur){}
    bool isValideMove(Position*,Position*,bool*,Plateau*);
};

#endif // REINE_H_INCLUDED
