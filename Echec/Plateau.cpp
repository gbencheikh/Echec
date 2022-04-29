#include<iostream>
#include<string>
#include"Position.h"
#include"Plateau.h"
#include"Piece.h"
#include"Roi.h"
using namespace std;

Plateau :: Plateau(int H,int W)
{
    //allocation
    plateau = new Piece**[H];
    for(int i=0;i<H;i++)
        plateau[i]= new Piece*[W];

    for(int i=0;i<H;i++)
        for(int j=0;j<W;j++)
            plateau[i][j]=NULL;
}
int Plateau :: getSize()
{
    // jeu est une variable qui m'indique si l'utilisateur a choisit le jeu echec ou dame
    if(jeu == true)
        return 8;
    else
        return 10;
}
void Plateau :: ajoute(Piece *pi,Position *pos)
{
    plateau[pos->x][pos->y]=pi;
}
void Plateau :: deplace(Position *pos1,Position *pos2)
{
    plateau[pos2->x][pos2->y]=plateau[pos1->x][pos1->y];
    plateau[pos1->x][pos1->y]=NULL;
}
bool Plateau :: estDedans(Position *pos)
{
    return (plateau[pos->x][pos->y]!=NULL);
}
Piece* Plateau :: getPiece(Position *pos)
{
    try{
        if(pos->x <0 || pos->x > getSize() || pos->y <0 || pos->y > getSize())
            throw 11;
        else
            return plateau[pos->x][pos->y];
    }catch(int x){
        cout<<"invalide position"<<endl;
    }
}

bool Plateau :: joue(Position *start, Position *fin, bool turnNoir)
{
    try
    {
        if(estDedans(start)==false)
            throw 22;
        if(getPiece(start)->estNoir!=turnNoir)
            throw 33;
        if(estDedans(fin)==true)
            if(getPiece(fin)->estNoir == turnNoir)
                throw 44;
        bool *Capture = new bool;
        //s'il s'agit du jeu echec
        if(jeu == true)
        {
            *Capture = estDedans(fin);
            if(getPiece(start)->isValideMove(start,fin,Capture,this)==false)
               throw 55;
            //si le mouvement est valide on deplace la piece
            deplace(start,fin);
            return true;
        }
        else
        {
            if(getPiece(start)->isValideMove(start,fin,new bool(true),this)==false && getPiece(start)->isValideMove(start,fin,new bool(false),this)==false)
               throw 55;

            if(getPiece(start)->isValideMove(start,fin,new bool(true),this)==true)
            {
                Piece *pi = NULL;
                if(fin->x - start->x < 0)
                   if(fin->y - start->y < 0)
                     ajoute(pi,new Position(*start,-1,-1));
                   else
                     ajoute(pi,new Position(*start,-1,1));
                else
                     if(fin->y - start->y < 0)
                        ajoute(pi,new Position(*start,1,-1));
                     else
                       ajoute(pi,new Position(*start,1,1));
            }
            deplace(start,fin);
            return true;
        }
    }catch(int x){
        cout<<"Invalide Move ERROR NUMBER : "<<x ;
        return false;
    }
}
bool Plateau::echec(bool Noir,Position *pos2)
{
    // on cherche dans tous le plateau, s'il existe une piece qui peut se deplacer vers la position du roi
    for(int i = 0 ; i< 8 ; i++)
    {
         for(int j = 0 ; j < 8 ; j++)
         {
             if(this-> estDedans(new Position(i+1,j+1))==true)
             {
                 Piece *pi = this->getPiece(new Position(i+1,j+1));
                 Position *pos = new Position(i+1,j+1);

                 if(pi->nom != "Roi")
                 {
                     if(estDedans(pos2) == true)
                     {
                        if(pi->isValideMove(new Position(i+1,j+1),pos2,new bool(true),this) == true)
                        {
                           return true;
                        }
                     }
                     else
                        if(pi->isValideMove(new Position(i+1,j+1),pos2,new bool(false),this) == true)
                           return true;
                 }

             }
         }
    }
    return false;
}
