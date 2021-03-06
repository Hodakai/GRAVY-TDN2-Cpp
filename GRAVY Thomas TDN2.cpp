#include <iostream>
#include <cstdlib>
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
    cout << humain->GetNomHumain() << " s'est transforme en '" << zombie->nom << "' aujourd'hui..." << endl; //Sortie console pour attester de la transformation de notre humain
    free(humain); //Liberation de la memoire alouée à notre humain qui est désormais un zombie
    return zombie;
}

void Zombie::afficher() 
{
    cout << this->nom << " est un Zombie !!!" << endl; //Affichage du zombie pour attester de son non-humanité
}

//////////////////////////////////////////////////////////////////////////         Classe FinDuMonde         //////////////////////////////////////////////////////////////////////////

class FinDuMonde
{
public:
    void ajouterHumain(Humain* humain); //Méthode pour ajouter un humain au vector contenant les humains
    void debutDeLaFin(); //Methode pour créer le premier zombie à partir d'un humain
    void fin();
    

private:
    vector <Humain*> humains; //Vector contenant les humains
    vector <Zombie*> zombies; //Vector contenant les zombies
};

void FinDuMonde::ajouterHumain(Humain* humain)
{
    humains.push_back(humain); //On place l'humain en paramettre à la fin du verctor en attribut dans la classe FinDuMonde
}

void FinDuMonde::debutDeLaFin() 
{
    int random = rand() % (humains.size()); //J'ai décidé ici de désigner le premier humain à se transformer en zombie aléatoirement et en restant dans la taille du vector "humains" grace à la methode humains.size()
    Zombie* zombie = new Zombie(humains[random]); //Création du premier zombie avec l'humain choisi aléatoirement avec l'int "rand"
    zombies.push_back(zombie); //Ajout du zombie à la fin du vector contenant tous les zombies de la partie
    humains.erase(humains.begin() + random); //On supprime l'humain transformé de la liste des humains car le free ne le fait pas à notre place
    //free(humains[random]); //On libère la mémoire alouée pour l'humain qui n'existe plus
}

void FinDuMonde::fin()
{
    int tours = 0;
    while (humains.size() != 0) 
    {
        tours++; //Valeur des tours qui s'incrémente pour voir le nombre de tours ou l'humanité arrive à survivre
        cout << endl << "////////////////////   Jour " << tours << "  ////////////////////" << endl << endl << "Il reste " << humains.size() << " survivants..." << endl << "Et " << zombies.size() << " zombies..." << endl << endl <<
            "////     Les gens transformes aujourd'hui     ////" << endl << endl; // Affichage du total des zombies et des humains
        int nbZombies = zombies.size(); // ici on prend une valeur fixe du nombre de zombies au début du tour
        for (int i = 0; i < nbZombies; i++) 
        {
            if (humains.size() == 0) { //On vérifie ici que le vecteur contenant les humains est vide
                cout << endl << "Le monde est peuple de zombies maintenant !!!" << endl << "L'humanite aura survecu " << tours << " jours..." << endl; //Affichage de fin de jeu
                break; //On sort de la fonction
            }
            int random = rand() % humains.size(); //Ici j'ai décidé de faire un nombre aléatoire qui désignera à chaque fois un humain aléatoire dans la liste à notre disposition
            this->zombies.push_back(this->zombies[i]->manger(this->humains[random])); //Ici on met à la fin du vector qui contient les zombies le résultat du zombie qui mange un humain aléatoire
            this->humains.erase(humains.begin() + random); //On supprime l'humain transformé de la liste des humains car le free ne le fait pas à notre place
            //free(humains[random]); //On libère la mémoire alouée pour l'humain qui n'existe plus
        }
    }
}

//////////////////////////////////////////////////////////////////////////////////         Main         //////////////////////////////////////////////////////////////////////////////////

int main()
{
    cout << "Bienvenue dans The Walking Dad !!!" << endl << endl;
    srand(time(NULL));
    FinDuMonde* Fin = new FinDuMonde(); //Instanciation de la fin du monde
    string prenoms[216] = { "Axel", "Arthur", "Evan", "Adrien", "Alexis", "Antoine", "Adam", "Alexandre", "Baptiste", "Enzo", "Julien", "Leo", "Lucas", "Matteo", "Mael", "Maxime", "Gabriel", "Raphael", "Pierre", 
        "Quentin", "Hugo", "Romain", "Theo", "Tom", "Jules", "Nicolas", "Louis", "Mathis", "Nathan", "Paul", "Valentin", "Ethan", "Kylian", "Matheo", "Aaron", "Antonin", "Anthony", "Ayoub", "Bastien", "Alan",
        "Aymeric", "Bryan", "Charles", "Elias", "Dorian", "Dylan", "Alex", "Augustin", "Alban", "Aurelien", "Benjamin", "Arnaud", "Gael", "Gabin", "Guillaume", "Florian", "Corentin", "Jean", "Jeremy", "Diego", 
        "Emilien", "Esteban", "David", "Etienne", "Damien", "Erwan", "Lukas", "Loic", "Lorenzo", "Mathias", "Matthieu", "Gaetan", "Gaspard", "Morgan", "Rafael", "Kilian", "Samuel", "Simon", "Kevin", "Sacha", 
        "Tristan", "Victor", "Jordan", "Killian", "Marius", "Vincent", "Martin", "Yann", "Mateo", "William", "Luca", "Remi", "Oscar", "Robin", "Noe", "Tony", "Tiago", "Thibaut", "Bilal", "Thibault", "Eliot", 
        "Elouan", "Ilan", "Eliott", "Julian", "Kyllian", "Ewan", "Luka", "Camille", "Anais", "Clara", "Emma", "Charlotte", "Celia", "Eva", "Ambre", "Clemence", "Juliette", "Lena", "Lea", "Jeanne", "Julie",
        "Maeva", "Mathilde", "Louise", "Lucie", "Manon", "Noemie", "Jade", "Ines", "Sarah", "Laura", "Lola", "Oceane", "Pauline", "Romane", "Zoe", "Lina", "Lisa", "Maëlys", "Alicia", "Andrea", "Audrey", "Angele",
        "Adele", "Alexia", "Amandine", "Angelina", "Chiara", "Claire", "Coralie", "Elsa", "Agathe", "Constance", "Eleonore", "Elisa", "Elodie", "Fanny", "Alice", "Anna", "Apolline", "Candice", "Charline", "Elise", 
        "Emilie", "Amelie", "Axelle", "Capucine", "Flavie", "Heloise", "Emeline", "Eloise", "Leonie", "Carla", "Cassandra", "Clarisse", "Elina", "Clementine", "Elena", "Marion", "Melina", "Marine", "Melissa", "Lise", 
        "Mailys", "Melanie", "Flora", "Gabrielle", "Ninon", "Rose", "Salome", "Julia", "Lana", "Valentine", "Sofia", "Justine", "Myriam", "Maelle", "Maud", "Yasmine", "Lucile", "Maya", "Olivia", "Nina", "Sara", "Chaima",
        "Solene", "Clea", "Victoire", "Thomas", "Roberto", "Marc", "Jean", "Sebastien", "Rick", "Michonne"}; //Liste d'une taille de 216 prénoms
    
    for (int i = 0; i < 216; i++) //Petite boucle pour créer notre humanité de jeu avec les noms fournis
    {
        Humain* humain = new Humain(prenoms[i]);
        Fin->ajouterHumain(humain);
    }
    cout << "Pressez 'y' pour continuer ou sur 'n' pour arreter le programme..." << endl;
    char choix;
    cin >> choix;
    if (choix == 'y') 
    {
        system("cls");
        Fin->debutDeLaFin();
        Fin->fin();
        return 0;
    }
    else if (choix == 'n') 
    {
        cout << "D'accord ! Au revoir..." << endl;
        return 0;
    }
    else 
    {
        cout << "Vous avez fait un choix qui n'etait pas propose..." << endl;
        return 0;
    }
}