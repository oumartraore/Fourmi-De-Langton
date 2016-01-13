#ifndef MODIF_SCHIZO_H_INCLUDED
#define MODIF_SCHIZO_H_INCLUDED

#include "Modif.h"

class Modif_schizo: public Modif
{
private:
    int modif_etat; // vaut 1 ou 2 pour indiquer le nouvel Etat de la fourmi apres son deplacement
public:
    Modif_schizo(int c = 2, int d = 1, int e = 1);
    // Getter
    int getModif_etat();
};

#endif // MODIF_SCHIZO_H_INCLUDED
