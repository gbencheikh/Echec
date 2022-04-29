#ifndef PLATEAU_H_INCLUDED
#define PLATEAU_H_INCLUDED
#include"Position.h"

class Piece;
class Plateau
{
protected :

    Piece ***plateau;
    Plateau(int,int);
    void ajoute(Piece*,Position*);
    void deplace(Position*,Position*);


public :
    bool jeu;
    int getSize();
    virtual void ConditionInititales() = 0;
    bool estDedans(Position*);
    Piece* getPiece(Position*);
    bool joue(Position*,Position*,bool);
    bool echec(bool,Position*);
    void jouer();

};
#endif // PLATEAU_H_INCLUDED
