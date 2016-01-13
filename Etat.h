#ifndef ETAT_H_INCLUDED
#define ETAT_H_INCLUDED

class Etat
{
private:
    int couleur;
    bool libre;
public:
    Etat(int c = 1, bool l = true);
    void inverser_libre();
    void inverse_couleur();
    // Getter & Setter
    int getCouleur();
    bool getLibre();

    // Fonction à moi
    void setLibre(bool a);
    void setCouleur(int c);
    //void setCouleur(int c);
};

#endif // ETAT_H_INCLUDED
