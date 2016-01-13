#include <iostream>
#include <string>

#include "Modif_schizo.h"
#include "Modif.h"

using namespace std;


Modif_schizo::Modif_schizo(int c, int d, int e):Modif(c, d), modif_etat(e)
{
}

int Modif_schizo::getModif_etat()
{
    return modif_etat;
}
