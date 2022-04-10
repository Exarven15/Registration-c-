#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	int choice = 0;
	int min_lenght = 4;
	while (choice != 2) {

		cout << "1 : Inscrivez vous ! " << endl;
		cout << "2 : Acceder a votre session ! " << endl;
		cout << "Choississez (1 ou 2) ";
		cin >> choice;
		cout << endl;
		if (choice == 1)
		{
			string user, mdp;

			cout << "Entrez votre username : ";
			cin >> user;
			cout << "Entrez votre mot de passe : ";
			cin >> mdp; cout << endl;
			if (user.length() > min_lenght && mdp.length() > min_lenght)
			{
				ofstream file("log.txt");
				file << user << endl << mdp;
				file.close();
				cout << "Inscription reussite !" << endl;
				continue;
			}
			else
			{
				cout << "ERROR : Username ou mot de passe pas assez long !" << endl;
				break;
			}
		}

		else if (choice == 2)
		{
			string user, mdp;
			string userLog, mdpLog;

			cout << "Entrez votre username : "; cin >> user;
			cout << "Entrez votre mot de passe : "; cin >> mdp;
			cout << endl;

			ifstream readFile("log.txt");
			getline(readFile, userLog);
			getline(readFile, mdpLog);

			for (int test = 0; test < 3; test++)
			{
				if (userLog != user || mdpLog != mdp and test != 3)
				{
					cout << "ERROR : Mauvais username ou mauvais mot de passe !" << endl;
					cout << "Entrez votre username : "; cin >> user;
					cout << "Entrez votre mot de passe : "; cin >> mdp;

					ifstream readFile("log.txt");
					getline(readFile, userLog);
					getline(readFile, mdpLog);
				}
				else if (userLog != user || mdpLog != mdp and test == 3)
				{
					cout << "ERROR : Vous avez essaye trop de fois !" << endl;
					cout << "Deconnexion ...";
				}
				else if (userLog == user && mdpLog == mdp)
				{
					int choix = 0;

					cout << "Que voulez vous faire ? " << endl << endl;
					cout << "1 : Ecrire un message." << endl;
					cout << "2 : Se Deconnecter." << endl;
					cout << "3 : Supprimer mon compte." << endl;
					cout << "Choississez (1, 2 ou 3) ";
					cin >> choix;

					if (choix == 1)
					{

						choix = 0;

						ofstream messageFile("message.txt");
						ifstream readMessage("message.txt");
						string message;

						cout << "Entrer votre message : ";
						cin >> message;
						cout << user << " -> " << message;
						getline(cin, message);
						messageFile << message;

						cout << message << endl;

						readMessage.close();
						messageFile.close();

					}
					else if (choix == 2)
					{
						cout << "Deconnection ...";
						break;
					}
					else if (choix == 3)
					{
						string supprUser = "", supprMdp = "";
						ofstream file("log.txt");
						file << supprUser << endl << supprMdp;
						file.close();
						cout << "Suppression de compte ..." << endl;
						cout << "Votre compte est supprime !!!";
					}
				}
				else
				{
					cout << "ERROR : Compte inexistant !";
				}

			}
			readFile.close();
		}
		else
		{
			cout << "ERROR : Mauvaise saisie !";
		}
    
		return 0;
	}
}
