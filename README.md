# PLD Compilateur

[![Build Status](https://travis-ci.org/NotYet-Hexa/PLD-Comp.svg?branch=master)](https://travis-ci.org/NotYet-Hexa/PLD-Comp)

## TODO

- [x] Ecriture de la grammaire
- [ ] Identification des expressions régulières J+Q
- [ ] Conception des structures de données 
    + Programme + declaration et definition fonction → N+C
    + boucle + structure conditionnelle + appel de function → M+T+T
- [ ] Implémentation de l'analyseur avec flex/bison J+Q
- [ ] Construction et représentation en mémoire : programme de test → sur papier, représentation de la mémoire et du parcours du compilateur
    + Programme + declaration et definition fonction → N+C
    + boucle + structure conditionnelle + appel de function → M+T+T

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
