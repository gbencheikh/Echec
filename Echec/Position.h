#ifndef POSITION_H_INCLUDED
#define POSITION_H_INCLUDED
#include<string>
using namespace std;
class Position
{
public :
    int x;
    int y;

    Position(int,int);
    Position(Position,int,int);
    Position(string);
    string toString();
};

#endif // POSITION_H_INCLUDED
