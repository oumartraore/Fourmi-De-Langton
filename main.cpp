#include <iostream>
#include <string>
#include <stdlib.h>
#include <unistd.h>

#include "Etat.h"
#include "Plateau.h"
#include "Fourmi.h"
#include "Modif.h"
#include "Modif_schizo.h"
#include "Fourmi_schizo.h"


using namespace std;

void menu(int n)
{
    cout << " --------------------------------------------------" << endl;
    cout << "|              Mini Projet                         |" << endl;
    cout << "|                                                  |" << endl;
    cout << " --------------------------------------------------\n\n" << endl;

    cout << "            ----------------------------              " << endl;
    cout << "           | Nom : TRAORE Oumar         |" << endl;
    cout << "           | IdBooster : 165366         |" << endl;
    cout << "           | Email : 165366@supinfo.com |"  << endl;
    cout << "            ----------------------------\n\n" << endl;

    cout << "Bonjour Bienvenu dans le simulateur" << endl;
    cout << "D'une fourmie de Langton & Generalite Turmite\n" << endl;
    cout << "Entre votre nombre d'iteration : " << n;
}

// Quelques ajouts à nos classes

void mettreCaseNoire(Plateau &plat)
{
    int choix = 0;
    int nombre = 0;
    int x = 0, y = 0;
    cout << "Tapez 1- Pour Mettre des cases en Noires : " << endl;
    cout << "Votre choix : ";
    cin >> choix;

    if(choix == 1)
    {
        cout << "Combien de case souhaitez vous modifiez : ";
        cin >> nombre;

        for(int i = 0; i < nombre; i++)
        {
            cout << "Entre les coordonnees (x,y) = valeur valeur" << endl;
            cout << "Retapez les meme coordonnes pour annuler la couleur" << endl;
            cout << "valeur : ";
            cin >> x;
            cin >> y;
            plat.setCouleur(x,y);
        }
    }
}

void demoLangton()
{
    Plateau plat = Plateau(7, 7); // met 31, 31 pour faire de vrai teste
    int n = 0;
    menu(n);
    cin >> n;
    mettreCaseNoire(plat);
    Fourmi langton = Fourmi(plat);

    plat.affiche();
    for(int i = 0; i < n; i++)
    {
            langton.bord(plat);
            system("Pause");
            system("cls");
            menu(n);
            langton.deplace(plat);
            langton.afficheStatistique();
            plat.affiche();
    }
}

void demoTurmite()
{
    Plateau plat_turmite = Plateau(7,7);
    int n = 0;
    menu(n);
    cin >> n;
    mettreCaseNoire(plat_turmite);

    Fourmi_schizo turmite = Fourmi_schizo(plat_turmite);

    plat_turmite.affiche();
    for(int i = 0; i < n; i++)
    {

            system("Pause");
            system("cls");
            menu(n);
            turmite.deplace(plat_turmite);
            turmite.afficheStatistique();
            plat_turmite.affiche();
    }
}

int main()
{
    int typeFourmi = 0;
    cout << "1- Pour une Fourmi Langton & 2 pour une Turmite " << endl;
    cout << "Votre choix : ";
    cin >> typeFourmi;
    switch(typeFourmi)
    {
        case 1:
            demoLangton();
            break;
        case 2:
            demoTurmite();
            break;
        default:
            demoLangton();
            break;
    }
    return 0;
}
