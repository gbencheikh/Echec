#ifndef PIECE_H_INCLUDED
#define PIECE_H_INCLUDED
#include<string>
#include<iostream>
#include"Position.h"
#include"Plateau.h"
using namespace std;

class Piece
{
public:
    string nom;
    bool estNoir;

    Piece(bool,string);
    virtual bool isValideMove(Position*,Position*,bool*,Plateau*)=0;
    string toString();

};
#endif // PIECE_H_INCLUDED
