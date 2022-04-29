#ifndef ROI_H_INCLUDED
#define ROI_H_INCLUDED


#include"Piece.h"
#include"Position.h"
#include"Plateau.h"

class Roi : public virtual Piece
{
public :


    Roi(bool couleur):Piece(couleur,"Roi"){}
    bool isValideMove(Position*,Position*,bool*,Plateau*);

};


#endif // ROI_H_INCLUDED
