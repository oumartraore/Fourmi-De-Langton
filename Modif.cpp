#include <iostream>
#include <string>

#include "Modif.h"

using namespace std;

Modif::Modif(int c, int d):modif_couleur(c), modif_direction(d)
{
}

// Getter pour la classe
int Modif::getModif_couleur()
{
    return modif_couleur;
}

int Modif::getModif_direction()
{
    return modif_direction;
}
