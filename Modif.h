#ifndef MODIF_H_INCLUDED
#define MODIF_H_INCLUDED

// Cette classe sert à indiquer quelles modifications seront effectués sur la couleur d'une case
// et sur l'orientation. Elle n'éffectue pas de modification

class Modif
{
protected:
    int modif_couleur; // vaut 1 ou 2 pour indiquer quelle sera sa nouvelle couleur
    int modif_direction; // vaut 1 pour indiquer une rotation de 90° à gauche et 2 pour 90° à droite
public:
    Modif(int c = 2, int d = 1);
    // Getter
    int getModif_couleur();
    int getModif_direction();
};

#endif // MODIF_H_INCLUDED
