#include<iostream>
#include<string>
#include"Piece.h"
#include"Position.h"
#include"Plateau.h"
#include"Reine.h"
#include"Tour.h"
#include"Fou.h"

using namespace std;

bool Reine :: isValideMove(Position *pos1,Position *pos2,bool *isCapture,Plateau *P)
{
    // une reine se deplace comme un fou et une tour
    return Fou::isValideMove(pos1,pos2,isCapture,P)+Tour::isValideMove(pos1,pos2,isCapture,P);
}
