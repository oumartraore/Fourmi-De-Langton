#include <iostream>
#include <string>

#include "Etat.h"

using namespace std;

Etat::Etat(int c, bool l)
{
    couleur = c;
    libre = l;
}

void Etat::inverser_libre()
{
    if(libre == true)
        libre = false;
    else
        libre = true;
}

// Getter é Setter

int Etat::getCouleur()
{
    return couleur;
}

bool Etat::getLibre()
{
    return libre;
}

void Etat::setLibre(bool a)
{
    libre = a;
}

void Etat::setCouleur(int c)
{
    couleur = c;
}

void Etat::inverse_couleur()
{
    if(couleur == 1)
        couleur = 2;
    else
        couleur = 1;
}
