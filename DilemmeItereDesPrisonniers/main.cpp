#include "Strategies.h"
#include "Tournoi.h"
#include <iostream>

using namespace std;

int main() {
  Strategies::Initializer();

  int nombreDeTours;
  cout << "entrer le nombre de tours: ";
  cin >> nombreDeTours;

  Tournoi tournoi(nombreDeTours);

  IStrategie* strategies[] = {
    Strategies::gentille,
    Strategies::mechante,
    Strategies::donnantDonnant,
    Strategies::donnantDonnantDur,
    Strategies::mefiante,
    Strategies::rancuniere,
    Strategies::periodiqueMechante,
    Strategies::periodiqueGentille,
    Strategies::majoriteMou,
    Strategies::majoriteDur,
    Strategies::dur,
    Strategies::sondeur4Coups,
    Strategies::donnantDonnantAvecSeuil,
    Strategies::graineDeChampion
  };
  constexpr size_t NUM_STRATEGIES = sizeof(strategies) / sizeof(strategies[0]);

  int indice = 1;
  while (true) {
    for (int i = 0; i < NUM_STRATEGIES; i++) {
      cout << i + 1 << ": " <<  strategies[i]->nom() << endl;
    }
    cout << "selectionner une strategie ou 0 pour terminer la selection: ";
    cin >> indice;
    if (indice == 0)
      break;
    else if (indice < 1 || indice > NUM_STRATEGIES)
      cout << "indice invalide\n";
    else
      tournoi.ajouterStrategie(strategies[indice - 1]);
  }

  tournoi.commencer();

  tournoi.afficherResultats();

  tournoi.sauvegarder("tournoi.bin");

  Strategies::Liberer();
}