#include <iostream>
#include <vector>

using namespace std;

//////////////////////////////////////////////////////////////////////////         Classe Humain         //////////////////////////////////////////////////////////////////////////

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

//////////////////////////////////////////////////////////////////////         Fonction CalculNomZombie         ///////////////////////////////////////////////////////////////////

string CalculNomZombie(string Humain)
{
    char ch;
    ch = Humain[0] + 32; //On ajoute 32 au caractère ASCII pour le passer en lowercase
    Humain = Humain[0]; //Ici j'ai pris le premier caractère du nom de l'humain en première lettre du nom de Zombie
    Humain += ch;
    Humain += ch; //J'ai fait comme ça parce que sinon ça multipliait la valeur ASCII de mon caractère par 2 au lieu de l'inscrire 2 fois
    return Humain; //Return de l'humain transformé
}

//////////////////////////////////////////////////////////////////////////         Classe Zombie         //////////////////////////////////////////////////////////////////////////

class Zombie
{
public:
    Zombie(Humain* humain); //Le constructeur
    string GetNomZombie(); //Le getter pour le nom du zombie
    Zombie* manger(Humain* humain);
    void afficher();

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

Zombie* Zombie::manger(Humain* humain) 
{
    Zombie* zombie = new Zombie(humain); //Création du nouveau zombie
    cout << "Oh non !!! Notre humain " << humain->GetNomHumain() << " s'est transforme en " << zombie->nom << endl; //Sortie console pour attester de la transformation de notre humain
    free(humain); //Liberation de la memoire alouée à notre humain qui est désormais un zombie
    return zombie;
}

void Zombie::afficher() 
{
    cout << this->nom << " est un Zombie !!!" << endl; //Affichage du zombie pour attester de son non-humanité
}

//////////////////////////////////////////////////////////////////////////         Fonctions et Main         //////////////////////////////////////////////////////////////////////////

int main()
{
    Humain* humain1 = new Humain("Maurice"); //Nouvelle instance d'un humain avec un pointeur (nom = "Maurice")
    Zombie* zombie1 = new Zombie(humain1);
    Humain* humain2 = new Humain("Roberto"); //Nouvelle instance d'un humain avec un pointeur (nom = "Roberto")
    humain2->afficher(); //Affichage de l'humain2 (Roberto)
    Zombie* zombie2 = zombie1->manger(humain2); //Attribution du nouveau zombie créé à un nouveau zombie
    zombie2->afficher();
}