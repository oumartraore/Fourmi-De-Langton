#include <iostream>
#include <string>

#include "Fourmi.h"
#include "Modif.h"

using namespace std;

Fourmi::Fourmi(Plateau &plat, int c1, int d1, int c2, int d2)
{
    i = (plat.getHauteur()/2) + 1; // On positionne la fourmi avec ses coordonnée au centre du plateau
    j = (plat.getLargeur()/2) + 1;

    i--;
    j--;
    direction = 1; // {1, 2, 3, 4} = {Nord, Ouest, Sud, Est}

    regles[0] = Modif(c1, d1); // Cas d'une case Blanche on parametre nos règles avec les valeurs c1, d1, c2, d2
    regles[1] = Modif(c2, d2);

    nbDeplacement = 0;
    for(int k = 0; k < 4; k++)
        statistique[k] = 0;

    cout << "Votre fourmi est elle mobile ? 1- Non, 2- Oui" << endl;
    cout << "Votre choix : ";
    cin >> mobile;

    plat.setFourmi(i, j);
}

void Fourmi::change_direction(int c)
{
    if(c == regles[0].getModif_couleur())
    {
        if(direction == 4)
            direction = 1;
        else
            direction++;
    }
    if(c == regles[1].getModif_couleur())
    {
        if(direction == 1)
            direction = 4;
        else
            direction--;
    }
    // Comptage de statistique
    switch(direction)
    {
        case 1:
            statistique[0]++;
            break;
        case 2:
            statistique[1]++;
            break;
        case 3:
            statistique[2]++;
            break;
        case 4:
            statistique[3]++;
            break;
    }
}

void Fourmi::afficheStatistique()
{
    cout << "\n\nStatistique de direction : Nombre de Deplacement = " << nbDeplacement << endl;
    cout << "Nord : " << statistique[0]/nbDeplacement << endl;
    cout << "Ouest : " << statistique[1]/nbDeplacement << endl;
    cout << "Sud : " << statistique[2]/nbDeplacement << endl;
    cout << "Est : " << statistique[3]/nbDeplacement << endl;
}

void Fourmi::bord(Plateau &plat)
{
    if(i == (plat.getHauteur() - 2) || j == (plat.getLargeur() - 2) || i <= 2 || j <= 2)
    {
        ++plat;
        i++;
        j++;
    }
}

void Fourmi::deplace(Plateau &plat)
{
    if(plat.getCouleur(i, j) == regles[1].getModif_couleur()) // On regarde quelle est la couleur de la case 1 (blanche pour le changement)
    {
        Fourmi::change_direction(regles[1].getModif_direction());
    }
    else
    {
        Fourmi::change_direction(regles[0].getModif_direction());
    }
    plat.setCouleur(i, j);
    plat.setFourmi(i, j);
    if(mobile == 1)
    {
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
    }
    else
    {
        switch(direction)
        {
            case 1:
                i -= 2;
                break;
            case 2:
                j -= 2;
                break;
            case 3:
                i += 2;
                break;
            case 4:
                j += 2;
                break;
        }
    }
    nbDeplacement++; // On compte le nombre de deplacement
    plat.setFourmi(i, j);
}
