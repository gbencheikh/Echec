#include<iostream>
#include<string>
#include"Position.h"
#include"Plateau.h"
#include"Piece.h"
#include"Damier.h"
#include"PionDame.h"
#include"Dame.h"
#include <windows.h>
#include<stdlib.h>
#include<stdio.h>

using namespace std;

void gotoxy2(int x, int y)
{
  COORD coord;
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


void Damier :: ConditionInititales()
{
    for(int i = 0 ; i < 4 ; i++)
    {
        // Si la ligne i est pair on commence le placement des pieces par les cases de colonne d'indice pair
        if(i % 2 == 0)
        for(int j = 0 ; j < 10 ; j++)
          {
              if (j % 2 == 0)
                    ajoute(new PionDame(true),new Position(i+1,j+1));
              else
                    ajoute(new PionDame(false), new Position(10-i,j+1));
          }
        //sinon on commemnce par les cases impaire
        else
            for(int j = 0 ; j < 10 ; j++)
              if(j%2 != 0)
                    ajoute(new PionDame(true),new Position(i+1,j+1));
              else
                    ajoute(new PionDame(false), new Position(10-i,j+1));

    }
}

// La méthode toString demandé

string Damier :: toString()
{
    string echec;

    for(int i=10;i>=1;i--)
    {
        // le numéro de la ligne
        echec +='\n';
        if(i <= 9)
           echec +='0'+i;
        else
            echec += 'K';

        echec +='|';
        //pour chaque case de la ligne i on :
        for(int j=1;j<=10;j++)
        {
            // S'il y a une piece dans la position(i,j) on l'affiche
            Position pos(i,j);
            if(estDedans(&pos)==true)
                echec += getPiece(&pos)->toString();
            // Sinon on l'affiche des espaces
            else
                echec += "  ";
            echec +='|';
        }
    }
    echec +="\n ";
    // la ligne indiquant le nom de chaque colonne de l'echiquier
    for(char c = 'A';c<='J';c++)
    {
        echec += " ";
        echec += c;
        echec += " ";
    }
    return echec;
}

void Damier::jouer()
{
    int i = 0;
    string Joueur[2];
    Joueur[0] = "Blanc :";
    Joueur[1] = "Noir  :";
    bool fin = false;
    do
    {
        if(fin == false)
        {
            gotoxy2(0,4);
            cout<<toString();

            bool joueur = i%2;
            string depart,fin; // chaine de caractère indiquant la position de depart et la position de fin du mouvement
              cout<<endl;
              cout << "Tour " << Joueur[i%2]; cin >> depart; cin >> fin;
              cout << endl;
              cout<<depart<<" "<<fin;
            // On demande à l'utilisateur de donner un chaine tant que le mouvement est invalide ou la chaine donné est incorrect
            while ( joue(new Position(depart),new Position(fin),i%2) == false )
            {
                 cout << "Tour " << Joueur[i%2]; cin >> depart;cin >> fin;
                 cout << endl;
            }
            // si une piece arrive a l'autre coté du plateau elle devient une dame
            Position *pos = new Position(fin);
            if( pos->x == 9 || pos->x == 0)
            {
               Dame *nouveau;
               if( i%2 == 0)
                  nouveau = new Dame(false);
               else
                  nouveau = new Dame(true);
               ajoute(nouveau,new Position(fin));
            }
            system("cls");
            cout << "dernier mouvement du joueur " << Joueur[i%2] << depart << " " << fin <<endl;
            i++;

        }
    }while (fin == false);

}

