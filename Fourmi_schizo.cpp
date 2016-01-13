#include <iostream>
#include <string>

#include "Plateau.h"
#include "Modif_schizo.h"
#include "Fourmi.h"

#include "Fourmi_schizo.h"

using namespace std;

Fourmi_schizo::Fourmi_schizo(Plateau &plat, int c11, int d11, int e11, int c12,
                             int d12, int e12, int c21, int d21, int e21, int c22,
                             int d22, int e22): Fourmi(plat, c11, d11, d11, d12)
{
    etat_fourmi = 1;
    regles[0][0] = Modif_schizo(c11, d11, e11);
    regles[0][1] = Modif_schizo(c12, d12, e12);
    regles[1][0] = Modif_schizo(c21, d21, e21);
    regles[1][1] = Modif_schizo(c22, d22, e22);
}

void Fourmi_schizo::change_etat(int c)
{
    if(c == regles[1][1].getModif_etat())
        etat_fourmi = 1;
    else
        etat_fourmi = 2;
}

// On va en quelque sorte surcharger notre methode deplacer pour une Fourmi_schieo

void Fourmi_schizo::deplace(Plateau &plat)
{
    if(plat.getCouleur(i, j) == regles[0][0].getModif_couleur()) // On regarde quelle est la couleur de la case
    {
        switch(etat_fourmi)
        {
            case 1:
                Fourmi_schizo::change_etat(regles[0][0].getModif_etat());
                Fourmi::change_direction(regles[0][0].getModif_direction());
                break;
            case 2:
                Fourmi_schizo::change_etat(regles[0][1].getModif_etat());
                Fourmi::change_direction(regles[0][1].getModif_direction());
                break;
        }
    }
    else
    {
        switch(etat_fourmi)
        {
            case 1:
                Fourmi_schizo::change_etat(regles[1][0].getModif_etat());
                Fourmi::change_direction(regles[1][0].getModif_direction());
                break;
            case 2:
                Fourmi_schizo::change_etat(regles[1][1].getModif_etat());
                Fourmi::change_direction(regles[1][1].getModif_direction());
                break;
        }
    }
    plat.setCouleur(i, j);
    plat.setFourmi(i, j);
    switch(direction)
    {
        case 1:
            i--;
            break;
        case 2:
            j--;
            break;
        case 3:
            i++;
            break;
        case 4:
            j++;
            break;
    }
    Fourmi::bord(plat);
    nbDeplacement++;
    plat.setFourmi(i, j);
}

