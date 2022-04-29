#ifndef ECHIQUIER_H_INCLUDED
#define ECHIQUIER_H_INCLUDED

class Echiquier : public Plateau
{
public :
    Echiquier():Plateau(8,8){}
    void ConditionInititales();
    string toString();
    void afficher();
    void jouer();
    bool echec_mat(bool);
};

#endif // ECHIQUIER_H_INCLUDED
