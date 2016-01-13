#include <iostream>
#include <string>
#include <fstream> //Pour la lecture et l'écriture dans les fichiers

#include "Plateau.h"
//#include "Etat.h"

using namespace std;

Plateau::Plateau(int h, int l)
{
    if(h > 0 && (h % 2 != 0))
        hauteur = h;
    if(l > 0 && (l % 2 != 0))
        largeur = l;
    tab = new Etat*[hauteur]; //Declaration du nombre de ligne
    for(int i = 0; i < hauteur; i++)
        tab[i] = new Etat[largeur]; //Declaration du nombre de colonne pour chaque ligne

    for(int i = 0; i < hauteur; i++)
    {
        for(int j = 0; j < largeur; j++)
            tab[i][j] = Etat(1, true);
    }
}

// Forme canonique de Coplien.

// Constructeur par defaut

Plateau::Plateau()
{
    hauteur = 21;
    largeur = 51;

    tab = new Etat*[hauteur]; //Declaration du nombre de ligne
    for(int i = 0; i < hauteur; i++)
        tab[i] = new Etat[largeur]; //Declaration du nombre de colonne pour chaque ligne
    for(int i = 0; i < hauteur; i++)
    {
        for(int j = 0; j < largeur; j++)
            tab[i][j] = Etat(1, true);
    }
}

// Constructeur par copie

Plateau::Plateau(const Plateau &obj)
{
    hauteur = obj.hauteur;
    largeur = obj.largeur;
    tab = new Etat*[hauteur];
    for(int i = 0; i < hauteur; i++)
        tab[i] = new Etat[largeur]; //Declaration du nombre de colonne pour chaque ligne

    for(int i = 0; i < hauteur; i++)
    {
        for(int j = 0; j < largeur; j++)
            tab[i][j] = obj.tab[i][j];
    }
}

// operateur d'affectation

Plateau&Plateau::operator=(const Plateau &obj)
{
    hauteur = obj.hauteur;
    largeur = obj.largeur;
    tab = new Etat*[hauteur];
    for(int i = 0; i < hauteur; i++)
        tab[i] = new Etat[largeur]; //Declaration du nombre de colonne pour chaque ligne

    for(int i = 0; i < hauteur; i++)
    {
        for(int j = 0; j < largeur; j++)
            tab[i][j] = obj.tab[i][j];
    }

    return *this;
}

// Destructeur

Plateau::~Plateau()
{
    for(int i = 0; i < hauteur; i++)
        delete [] tab[i];
    delete [] tab;
}

void Plateau::affiche()
{
    for(int i = 0; i < hauteur; i++)
    {
        for(int j = 0; j < largeur; j++)
        {
            if(tab[i][j].getLibre())
            {
                if(tab[i][j].getCouleur() == 1)
                    cout << "   ";
                else
                    cout << " . ";
            }
            else
                cout << " o ";
        }
        cout << "\n";
    }
}

void Plateau::affiche_fichier()
{
    ofstream Fichier("File/fourmi.txt");
    if(Fichier)
    {
        for(int i = 0; i < hauteur; i++)
        {
            for(int j = 0; i < largeur; j++)
            {
                if(tab[i][j].getLibre())
            {
                if(tab[i][j].getCouleur() == 1)
                    Fichier << "   ";
                else
                    Fichier << " . ";
            }
            else
                Fichier << " o ";
            }
            Fichier << "\n";
        }
    }
    else
    {
        cout << "Erreur lors de l'acces au Fichier fourmi.txt" << endl;
    }
}

// Surcharge de l'opérateur ++

Plateau& Plateau::operator++()
{
    hauteur += 2;
    largeur += 2;

    Etat **tab2;
    tab2 = new Etat*[hauteur]; //Declaration du nombre de ligne
    for(int i = 0; i < hauteur; i++)
        tab2[i] = new Etat[largeur]; //Declaration du nombre de colonne pour chaque ligne

    for(int i = 0; i < hauteur; i++)
    {
        for(int j = 0; j < largeur; j++)
            tab2[i][j] = Etat(1, true);
    }

    for(int i = 0; i < hauteur-2; i++)
    {
        for(int j = 0; j < largeur-2; j++)
        {
            tab2[i+1][j+1].setCouleur(tab[i][j].getCouleur());
            tab2[i+1][j+1].setLibre(tab[i][j].getLibre());
        }
    }

    tab = tab2;

    return *this;
}

// Getter & Setter

int Plateau::getHauteur()
{
    return hauteur;
}

int Plateau::getLargeur()
{
    return largeur;
}

void Plateau::setFourmi(int i, int j)
{
    tab[i][j].inverser_libre();
}

int Plateau::getCouleur(int i, int j)
{
    return tab[i][j].getCouleur();
}

void Plateau::setCouleur(int i, int j)
{
    tab[i][j].inverse_couleur();
}
