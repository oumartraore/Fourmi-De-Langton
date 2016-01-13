#ifndef FOURMI_SCHIZO_H_INCLUDED
#define FOURMI_SCHIZO_H_INCLUDED

#include "Plateau.h"
#include "Modif_schizo.h"
#include "Fourmi.h"

class Fourmi_schizo: public Fourmi
{
private:
    Modif_schizo regles[2][2];
    int etat_fourmi;
public:
    Fourmi_schizo(Plateau &plat, int c11 = 2, int d11 = 1, int e11 = 2, int c12 = 2, int d12 = 2, int e12 = 2, int c21 = 1, int d21 = 1, int e21 = 2, int c22 = 1, int d22 = 1, int e22 = 1);
    void change_etat(int c);
    void deplace(Plateau &plat);
};

#endif // FOURMI_SCHIZO_H_INCLUDED
