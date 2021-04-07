#include <iostream>
#include <vector>

using namespace std;

class Humain
{
public:
    string GetNomHumain(); //Le getter pour le nom de l'humain
	Humain(string nom); //Le constructeur
    void afficher();
    
private:
    string nom;
};

string Humain::GetNomHumain() //Methode du getter pour l'humain
{
    return nom; //On retourne la valeur de nom qui est private
}

Humain::Humain(string nom)
{
    this->nom = nom; //On attribue ici la valeur du parametre "nom" dans le champ nom de la classe Humain
}

void Humain::afficher()
{
    cout << "Bonjour je m'apelle " << this->nom  << " et je suis encore un Humain" << endl; //Affichage de l'humain pour attester de son humanité
}

class Zombie
{
public:
    Zombie(Humain* humain); //Le constructeur
    string GetNomZombie(); //Le getter pour le nom du zombie

private:
    string nom;
};

Zombie::Zombie(Humain* humain)
{
    this->nom = CalculNomZombie(humain->GetNomHumain()); //Ici on recupère le nom de l'humain qui est derière le pointeur que l'on a fait passer en paramettre
}

string Zombie::GetNomZombie() //Methode du getter pour le zombie 
{
    return nom; //Comme pour l'humain on return le nom contenu dans l'attribut nom en parivate de la classe zombie 
}

string CalculNomZombie (string Humain) 
{
    char ch;
    ch = Humain[0] + 32; //On ajoute 32 au caractère ASCII pour le passer en lowercase
    Humain = Humain[0]; //Ici j'ai pris le premier caractère du nom de l'humain en première lettre du nom de Zombie
    Humain += ch;
    Humain += ch; //J'ai fait comme ça parce que sinon ça multipliait la valeur ASCII de mon caractère par 2 au lieu de l'inscrire 2 fois
    return Humain; //Return de l'humain transformé
}

int main()
{
    Humain* humain1 = new Humain("Maurice"); //Nouvelle instance d'un humain avec un pointeur (nom = "Maurice")
    Humain* humain2 = new Humain("Roberto"); //Nouvelle instance d'un humain avec un pointeur (nom = "Roberto")
    humain1->afficher(); //Affichage de l'humain1 (Maurice)
    humain2->afficher(); //Affichage de l'humain2 (Roberto)
    cout << "Oh non !!! Notre humain " << humain1->GetNomHumain() << " s'est transforme en " << CalculNomZombie(humain1->GetNomHumain()) << endl;
}