# PLD Compilateur

## TODO

- Ecriture de la grammaire
- Identification des expressions régulières
- Conception des structures de données
- Implémentation de l'analyseur avec flex/bison
- Constructure de la représentation en mémoire
- Résolution de portée de variable
- Vérification statique du programme (optionnel)
- Définition des structures de données pour une représentation intermédiaire linéaire
- Transformation de l'AST vers la représentation linéaire
- Génération de code assembleur à partir de la représentation linéaire
- Gestion des appels de procédures
- Outil en ligne de commande - intégration
- Optimisations (facultatif mais recommandé)

## grammaire

E' → E;

D → T | L

N → (\w+) eps | [Nb]
Nb → eps | (\d+)


## Operator

/ * + - % ++ -- 
== != > < >= <= 
&& || !
& | ^ ~ << >>
= += -= *= /= %= <<= >>= &= ^= |=
sizeof()  pas de pointeurs donc pas & * 
ternary expression ? :
