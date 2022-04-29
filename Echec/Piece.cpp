#include<string>
#include<iostream>
#include"Piece.h"

Piece::Piece(bool Noir,string name)
{
    nom = name;
    estNoir = Noir;
}
string Piece :: toString()
{
    string chaine;
    int i=0;
    while(nom[i]==' ')
        i++;
    if(estNoir == true)
        chaine=nom[i];
        //convertire du majuscule au miniscule
    else
        chaine=nom[i]+32;
    chaine+=nom[i+1];
    return chaine;
}
