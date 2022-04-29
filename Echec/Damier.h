#ifndef DAMIER_H_INCLUDED
#define DAMIER_H_INCLUDED

class Damier : public Plateau
{
public :
    Damier():Plateau(10,10){}
    void ConditionInititales();
    string toString();
    void afficher();
    void jouer();

};

#endif // DAMIER_H_INCLUDED
