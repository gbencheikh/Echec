#include<iostream>
#include<string>
#include"Position.h"
#include"Plateau.h"
#include"Piece.h"
#include"Echiquier.h"
#include"Pion.h"
#include"Tour.h"
#include"Fou.h"
#include"Reine.h"
#include"Cheval.h"
#include"Roi.h"
#include <windows.h>
#include<stdlib.h>
#include<stdio.h>

using namespace std;

void Color(int t,int f)
{
	HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(H,f*16+t);
}
void gotoxy(int x, int y)
{
  COORD coord;
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void Echiquier :: ConditionInititales()
{
    //emplacement des pions, possèdent tous firtMove = true
    for(char c = 'A';c<='H';c++)
    {
        string chaine1,chaine2;
        chaine1 = c; chaine1 +='7';
        chaine2 = c; chaine2 +='2';

        Piece *pi = new Pion(false,true);
        Piece *Pi = new Pion(true,true);

        ajoute(pi,new Position(chaine1));
        ajoute(Pi,new Position(chaine2));
    }
    // emplacement des autres pièces
    ajoute(new Tour(true),new Position("A1"));
    ajoute(new Tour(true),new Position("H1"));
    ajoute(new Tour(false),new Position("A8"));
    ajoute(new Tour(false),new Position("H8"));
    ajoute(new Fou(true),new Position("C1"));
    ajoute(new Fou(true),new Position("F1"));
    ajoute(new Fou(false),new Position("C8"));
    ajoute(new Fou(false),new Position("F8"));
    ajoute(new Reine(true), new Position("D1"));
    ajoute(new Reine(false),new Position("D8"));
    ajoute(new Cheval(true),new Position("B1"));
    ajoute(new Cheval(true),new Position("G1"));
    ajoute(new Cheval(false),new Position("B8"));
    ajoute(new Cheval(false),new Position("G8"));
    ajoute(new Roi(true),new Position("E1"));
    ajoute(new Roi(false),new Position("E8"));
}


bool Echiquier::echec_mat(bool Noir)
{
    // On cherche la position du Roi de couleur Noir
   Position *pos;
    for(int i = 0 ; i < 8 ; i++)
       for(int j = 0 ; j < 8 ; j++)
           if(estDedans(new Position(i+1,j+1)) == true)
               if(getPiece(new Position(i+1,j+1))-> nom == "Roi" && getPiece(new Position(i+1,j+1))->estNoir == Noir)
                   pos = new Position(i+1,j+1);

    //if faut tester les position du roi, s'il est dans les etremiter du plateau
    // si le roi se trouve à l'interieur du plateau, il faut tester tout les cases entouré de lui

    int dx = 1;
    int dy = 1;
    //si il est à l'extremite du plateau, alors:
    if (pos->x == 0 || pos->x == 7) dx = 0;
    if (pos->y == 0 || pos->y == 7) dy = 0;

        if( (estDedans(new Position(*pos,dx*1,dy*1)) == false && getPiece(pos)->isValideMove(pos,new Position(*pos,1*dx,1*dy),new bool(false),this)== false )||
       (estDedans(new Position(*pos,dx*1,dy*0)) == false &&getPiece(pos)->isValideMove(pos,new Position(*pos,1*dx,0),new bool(false),this)== false ) ||
       (estDedans(new Position(*pos,dx*1,dy*(-1))) == false && getPiece(pos)->isValideMove(pos,new Position(*pos,1*dx,-1*dy),new bool(false),this)== false )||
       (estDedans(new Position(*pos,dx*0,dy*1)) == false && getPiece(pos)->isValideMove(pos,new Position(*pos,0,1*dy),new bool(false),this)== false )||
       (estDedans(new Position(*pos,-1*dx,1*dy)) == false && getPiece(pos)->isValideMove(pos,new Position(*pos,-1*dx,1*dy),new bool(false),this)== false) ||
       (estDedans(new Position(*pos,-1*dx,-1*dy)) == false && getPiece(pos)->isValideMove(pos,new Position(*pos,-1*dx,-1*dy),new bool(false),this)== false) ||
       (estDedans(new Position(*pos,0,-1*dy)) == false && getPiece(pos)->isValideMove(pos,new Position(*pos,0*dx,-1*dy),new bool(false),this)== false) ||
       (estDedans(new Position(*pos,-1*dx,0)) == false && getPiece(pos)->isValideMove(pos,new Position(*pos,-1*dx,0),new bool(false),this)== false))
           return false;
         if( (estDedans(new Position(*pos,dx*1,dy*1)) == true && getPiece(new Position(*pos,dx*1,dy*1))->estNoir != Noir && getPiece(pos)->isValideMove(pos,new Position(*pos,1*dx,1*dy),new bool(true),this)== false )||
       (estDedans(new Position(*pos,dx*1,dy*0)) == true && getPiece(new Position(*pos,dx*1,dy*0))->estNoir != Noir &&getPiece(pos)->isValideMove(pos,new Position(*pos,1*dx,0),new bool(true),this)== false ) ||
       (estDedans(new Position(*pos,dx*1,dy*(-1))) == true && getPiece(new Position(*pos,dx*1,dy*(-1)))->estNoir != Noir&& getPiece(pos)->isValideMove(pos,new Position(*pos,1*dx,-1*dy),new bool(true),this)== false )||
       (estDedans(new Position(*pos,dx*0,dy*1)) == true && getPiece(new Position(*pos,dx*0,dy*1))->estNoir != Noir&& getPiece(pos)->isValideMove(pos,new Position(*pos,0,1*dy),new bool(true),this)== false )||
       (estDedans(new Position(*pos,-1*dx,1*dy)) == true && getPiece(new Position(*pos,-1*dx,1*dy))->estNoir != Noir&& getPiece(pos)->isValideMove(pos,new Position(*pos,-1*dx,1*dy),new bool(true),this)== false) ||
       (estDedans(new Position(*pos,-1*dx,-1*dy)) == true && getPiece(new Position(*pos,-1*dx,-1*dy))->estNoir != Noir&& getPiece(pos)->isValideMove(pos,new Position(*pos,-1*dx,-1*dy),new bool(true),this)== false) ||
       (estDedans(new Position(*pos,0,-1*dy)) == true && getPiece(new Position(*pos,0,-1*dy))->estNoir != Noir&& getPiece(pos)->isValideMove(pos,new Position(*pos,0*dx,-1*dy),new bool(true),this)== false) ||
       (estDedans(new Position(*pos,-1*dx,0)) == true && getPiece(new Position(*pos,-1*dx,0))->estNoir != Noir&& getPiece(pos)->isValideMove(pos,new Position(*pos,-1*dx,0),new bool(true),this)== false))
       {
           return false;
       }
   // si on est arrivé à ce point cela veut dire que le roi ne peut pas bouger, alors :
   // En verfie si parmis les pieces de même couleur que le roi courant, s'il elle peuvent déffendre le roi
   // on cherche dans le plateau les pieces de même couleur
   for(int i = 0 ; i < 8 ; i++)
        for(int j = 0 ; j < 8 ; j++)
        {
            //s'il existe une piece dans la position en court, et elle contient une piece de même couleur, alors
            if(estDedans(new Position(i+1,j+1)) == true)
                if(getPiece(new Position(i+1,j+1))->estNoir == Noir && getPiece(new Position(i+1,j+1))->nom != "Roi")
                {
                    // parmis tout les cases de echequier, s'il existe une case dans lequel en deplacant la piece dans la position(i+1,j+1)
                    // le roi ne sera plus en danger
                    for(int k = 0 ; k < 8 ; k++)
                        for(int l = 0 ; l < 8 ; l++)
                        {
                            // si la case est pleine alors ca sera une capture
                            if(estDedans(new Position(k+1,l+1)) == true )
                            {
                                if(getPiece(new Position(i+1,j+1))->isValideMove(new Position(i+1,j+1),new Position(k+1,l+1),new bool(true),this) == true)
                                {
                                    Piece *pi = getPiece(new Position(k+1,l+1));
                                    deplace(new Position(i+1,j+1),new Position(k+1,l+1));
                                    if(echec(Noir,pos) == true)
                                    {
                                        deplace(new Position(k+1,l+1),new Position(i+1,j+1));
                                        ajoute(pi,new Position(k+1,l+1));
                                    }
                                    else
                                    {
                                        deplace(new Position(k+1,l+1),new Position(i+1,j+1));
                                        ajoute(pi,new Position(k+1,l+1));
                                        return false;
                                    }

                                }
                            }
                            //sinon ce n'est pas une capture
                            else
                            {
                                if(getPiece(new Position(i+1,j+1))->isValideMove(new Position(i+1,j+1),new Position(k+1,l+1),new bool(false),this) == true)
                                {
                                    Piece *pi = getPiece(new Position(k+1,l+1));
                                    deplace(new Position(i+1,j+1),new Position(k+1,l+1));
                                    if(echec(Noir,pos) == true)
                                    {
                                        deplace(new Position(k+1,l+1),new Position(i+1,j+1));
                                        ajoute(pi,new Position(k+1,l+1));
                                    }
                                    else
                                    {
                                        deplace(new Position(k+1,l+1),new Position(i+1,j+1));
                                        ajoute(pi,new Position(k+1,l+1));
                                        return false;

                                    }
                                }
                            }

                        }
                }

        }
    return true;
}

void Echiquier :: jouer()
{
    cout<<getSize();
    int i = 0;
    string Joueur[2];
    Joueur[0] = "Blanc :";
    Joueur[1] = "Noir  :";
    bool fin = false; // on initial la variable qui indique si le jeu est terminer ou pas par false
    //tant que le jeu n'est pas terminer
    do
    {
            // cherche la position des deux roi
            for(int i = 0 ; i < 8 ; i++)
                for(int j = 0 ; j < 8 ; j++)
                    if(estDedans(new Position(i+1,j+1)) == true)
                    {
                        if(getPiece(new Position(i+1,j+1))->nom == "Roi")
                        {
                            // si l'un des roi est on mode echec (echec est dans plateau)
                            if(echec(i%2,new Position(i+1,j+1)) == true || echec(i/2,new Position(i+1,j+1)) == true)
                            {
                                if(getPiece(new Position(i+1,j+1))->estNoir == true)
                                {
                                    // si un roi est on mode echec
                                    // tester si c'est un echec est mat ou pas
                                    if(echec_mat(true) == true )
                                    {
                                        fin = true;
                                        cout<<Joueur[0]<<"a gagner"<<endl;
                                    }
                                    else
                                        cout<<"Echec sur le "<<Joueur[1]<<endl;
                                }

                                else
                                {
                                    if(echec_mat(false) == true )
                                    {
                                        fin = true;
                                        cout<<Joueur[1]<<"a gagner"<<endl;
                                    }
                                    else
                                        cout<<"Echec sur le "<<Joueur[0]<<endl;
                                }
                            }
                        }
                    }
        //sinon continue le jeu
        if(fin == false)
        {
            gotoxy(0,4);
            afficher();

            bool joueur = i%2;
            string depart,fin;
            // donner le mouvement
              cout << "Tour " << Joueur[i%2]; cin >> depart; cin >> fin;
              cout << endl;
              cout<<depart<<" "<<fin;
            //lire le mouvement tant qu'il est invalide
            while ( joue(new Position(depart),new Position(fin),i%2) == false )
            {
                 cout << "Tour " << Joueur[i%2]; cin >> depart;cin >> fin;
                 cout << endl;
            }
            // si la piece qu'on vient de deplacer est un pion est que sa valeur de firstmove = true, on lui change cette dernière
            //puisque Piece est virtual, alors on ne peut pas acceder au information de l'objets,
            // d'ou en remplace le pion courant par un nouveau qui n'est pas en mode firstmove
            if(getPiece(new Position(fin))->nom == "Pion")
            {
               Pion *nouveau;
               if( i%2 == 0)
                  nouveau = new Pion(false,false);
               else
                  nouveau = new Pion(true,false);

               ajoute(nouveau,new Position(fin));
            }
            system("cls");
            //afficher le dernier mouvement
            cout << "dernier mouvement du joueur " << Joueur[i%2] << depart << " " << fin <<endl;
            i++;
        }

    }while (fin == false);

}

// La méthode toString demandé

string Echiquier :: toString()
{
    string echec;

    for(int i=8;i>=1;i--)
    {
        // le numéro de la ligne
        echec +='\n';
        echec +='0'+i;
        echec +='|';
        //pour chaque case de la ligne i on :
        for(int j=1;j<=8;j++)
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
    for(char c = 'A';c<='H';c++)
    {
        echec += " ";
        echec += c;
        echec += " ";
    }
    return echec;
}
//fonction affichage
void ligne_pair()
{
    Color(15,0);
            cout<<" ";
            for(int j=0;j<8;j++)
                if(j%2==0)
                {
                    Color(1,104);
                    cout<<"      ";
                }
                else
                {
                    Color(1,103);
                    cout<<"      ";
                }
            Color(15,0);
            cout<<" ";
            cout<<endl;
}
void ligne_impair()
{
    Color(15,0);
            cout<<" ";
            for(int j=0;j<8;j++)
                if(j%2==0)
                {
                    Color(1,103);
                    cout<<"      ";
                }
                else
                {
                    Color(1,104);
                    cout<<"      ";
                }
            Color(15,0);
            cout<<" ";
            cout<<endl;
}

void Echiquier :: afficher()
{
    cout<<endl;
    string espace = "      ";
    system("color F0");
    Color(15,0);
    cout<<" ";

    for(char c='1';c<='8';c++)
       cout<<espace;
    cout<<"  ";
    cout<<endl;

    for(int i=8;i>=1;i--)
    {
        Color(15,0);
        cout<<i;

        if(i%2 == 0)
        {
            ligne_pair();
            Color(15,0);
            cout<<"  ";
            for(int j = 1 ; j <= 8 ; j++)
            {
                if( estDedans(new Position(i,j)) == true)
                   if( getPiece(new Position(i,j))->estNoir == true)
                   {
                       if(j % 2 == 0)
                           Color(1,103);
                        else
                           Color(1,104);
                        cout<<"  "<<getPiece(new Position(i,j))->toString()<<"  ";
                   }
                   else
                   {
                       if(j % 2 == 0)
                           Color(15,103);
                       else
                           Color(15,104);
                       cout<<"  "<<getPiece(new Position(i,j))->toString()<<"  " ;
                   }
                else
                {
                    if(j % 2 == 0)
                       Color(1,103);
                    else
                        Color(1,104);
                    cout<<espace;
                }

            }
            Color(15,0);
            cout<<" "<<endl<<" ";
            ligne_pair();

        }
        else
        {
            ligne_impair();
            Color(15,0);
            cout<<"  ";
            for(int j = 1 ; j <= 8 ; j++)
            {

                if( estDedans(new Position(i,j)) == true)
                   if( getPiece(new Position(i,j))->estNoir == true)
                   {
                       if(j % 2 == 0)
                           Color(1,104);
                        else
                           Color(1,103);
                        cout<<"  "<<getPiece(new Position(i,j))->toString()<<"  ";
                   }
                   else
                   {
                       if(j % 2 == 0)
                           Color(15,104);
                       else
                           Color(15,103);
                       cout<<"  "<<getPiece(new Position(i,j))->toString()<<"  ";
                   }
                else
                {
                    if(j % 2 == 0)
                       Color(1,104);
                    else
                        Color(1,103);
                    cout<<espace;
                }
            }
            Color(15,0);
            cout<<" "<<endl<<" ";
            ligne_impair();
        }

    }

    Color(15,0);
    cout<<"  ";
    for(char c='A';c<='H';c++)
            cout<<"  "<<c<<"   ";
    cout<<" ";
    cout<<endl;
    cout<<endl;
    Color(0,15);
}
