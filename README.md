# Projet3Graphe

## A faire
- Remplacer tous les NULL par nullptr
- On garde le SOMLireArcEntrant/Sortant(unsigned int uiIndex) ? (l'index a pas beaucoup de sens en dehors du code). Maybe retourner une liste d'arcs ?
- uiDestination au lieu de CArc dans SOMAjouterArc... 

## Codes Exception

|   Classe   | Plage codes exception |
|------------|-----------------------|
| CException |         0 - 9         |
|    CArc    |        10 - 19        |
|  CSommet   |        20 - 29        |
|   CGraph   |        30 - 39        |
|  CLexeur   |        40 - 49        |
|  CParseur  |        50 - 59        |
