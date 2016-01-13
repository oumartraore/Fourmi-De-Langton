#ifndef PLATEAU_H_INCLUDED
#define PLATEAU_H_INCLUDED

#include "Etat.h"

class Plateau
{
private:
    int hauteur;
    int largeur;
    // tab de type Etat** (Relation de compositionà) entre les 2 classes;
    Etat **tab;
public:
    void affiche();
    void affiche_fichier();
    Plateau();
    Plateau(int h = 21, int l = 51);
    Plateau(const Plateau &obj); //Constructeur par copie
    Plateau& operator=(const Plateau &obj); // Operateur d'affectation
    Plateau& operator++(void); // Surcharge de l'opérateur++
    // Getter é
    int getHauteur();
    int getLargeur();
    int getCouleur(int i, int j);

    void setCouleur(int i, int j);
    void setFourmi(int i, int j);
    ~Plateau();
};


#endif // PLATEAU_H_INCLUDED
