#include <iostream>
#include <vector>

using namespace std;

class Humain
{
public:
    string GetNom(); //Le getter
	Humain(string nom); //Le constructeur
    
private:
    string nom;
};

string Humain::GetNom ()
{
    return nom; //On retourne la valeur de nom qui est private
}

Humain::Humain(string nom)
{
    this->nom = nom; //On attribue ici la valeur du parametre "nom" dans le champ nom de la classe Humain
}


string CalculNomZombie (string Humain) {
    char ch;
    ch = Humain[0] + 32; //On ajoute 32 au caractère ASCII pour le passer en lowercase
    string Zombie;
    Zombie = Humain[0]; //Ici j'ai pris le premier caractère du nom de l'humain en première lettre du nom de Zombie
    Zombie += ch;
    Zombie += ch; //J'ai fait comme ça parce que sinon ça multipliait la valeur ASCII de mon caractère par 2 au lieu de l'inscrire 2 fois
    return Zombie; //Return de l'humain transformé
}

int main()
{
    string Humain;
    Humain = "Michel";
    string Zombie;
    Zombie = CalculNomZombie(Humain);
    cout << "Ah non !!! " << Humain << " s'est transforme en " << Zombie << endl;
}
