#include <iostream>
#include "Position.h"
#include "Piece.h"
#include "Plateau.h"
#include "Echiquier.h"
#include "Damier.h"
#include"Pion.h"
#include<string>
#include<math.h>
#include <windows.h>
#include<stdlib.h>
#include<stdio.h>

using namespace std;

int main()
{


    try{
        system("color F0");
        int choix;
        cout<< " Menu : "<<endl;
        cout<< " \t 1- Jeu d'echec " << endl;
        cout<< " \t 2- Jeu de dames " << endl;
        cout<< " Veuillez saisir votre choix : "; cin>> choix;
        if( choix != 1 && choix != 2)
            throw 33;
        if( choix == 1 )
        {
            Echiquier Q;
            Q.jeu = true;
            Q.ConditionInititales();
            Q.jouer();

        }
        if (choix == 2)
        {
            Damier D;
            D.jeu = false;
            D.ConditionInititales();
            cout<<D.toString();
            D.jouer();

        }
    }catch(int x){
        cout<<" Erreur !! choix invalide " << endl;
    }

    return 0;
}
