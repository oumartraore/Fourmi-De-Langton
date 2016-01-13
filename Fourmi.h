#ifndef FOURMI_H_INCLUDED
#define FOURMI_H_INCLUDED

#include "Modif.h"
#include "Plateau.h"

// Cette classe s'occupe de gérer tout ce qui concerne notre fourmi

class Fourmi
{
protected:
    // Les attributs i et j repèrent sa position
    int i;
    int j;
    int direction; // vaut 1, 2, 3 ou 4 (respectivement pour nord, ouest, sud, est)
    Modif regles[2];
    int nbDeplacement; //Compteur de deplacement
    double statistique[4]; // Statistique sur nos direction
    int mobile; // Pour determiner si c'est une fourmi modile c'est un attribut d'une fourmi
public:
    // Le constructeur de cette classe fait en sorte de positionner notre fourmi au centre du plateur
    Fourmi(Plateau &plat, int c1 = 2, int d1 = 1, int c2 = 1, int d2 = 2);
    // Prends un entier supposé être 1 ou 2 et réalise une rotation de 90° vers la gauche s'il vaut 1
    // et de 90° vers la droite s'il vaut 2, il modifie donc l'attibut direction
    void change_direction(int c);
    void deplace(Plateau &plat);
    void afficheStatistique();
    // Si la fourmi s'approche du bord on n'agrandira le plateau à l'aide de la surcharge de l'opérateur ++
    void bord(Plateau &plat);
};


#endif // FOURMI_H_INCLUDED
