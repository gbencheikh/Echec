#include<iostream>
#include<string>
#include"Position.h"
using namespace std;
Position::Position(int X,int Y)
{
    x = X-1;
    y = Y-1;
}
Position::Position(Position Pos,int dx,int dy)
{
    x = Pos.x + dx;
    y = Pos.y + dy;
}
Position::Position(string chaine)
{
    char a,b;
    a = chaine[0];
    b = chaine[1];

    char chiffre[11],lettre[11];
    char c = '1';char l='A';
    for(int i=1;i<=9;i++)
    {
        chiffre[i]=c;
        lettre[i]=l;
        c++;l++;
    }
    chiffre[10] = 'K';
    lettre[10] = 'J';

    for(int i=1;i<=10;i++)
    {
        if(a == lettre[i])
           y = i-1;
        if(b == chiffre[i])
           x = i-1;
    }
}
string Position::toString()
{
    string chaine;

    char chiffre[11],lettre[11];
    char c = '1';char l='A';
    for(int i=1;i<=9;i++)
    {
        chiffre[i]=c;
        lettre[i]=l;
        c++;l++;
    }
    chiffre[10]='K';
    lettre[10]='I';

    chaine = lettre[y+1];
    chaine += chiffre[x+1];

    return chaine;
}
