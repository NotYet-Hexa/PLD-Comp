# Makefile

[![Build Status](https://travis-ci.org/NotYet-Hexa/PLD-Comp.svg?branch=master)](https://travis-ci.org/NotYet-Hexa/PLD-Comp)

## Compilation

2 méthodes de compilation maintenant disponible :

- DEBUG : Le mode debug permet d'écrire des cout dans le code bison
qui ne seront afficher qu'en mode debug

- RELEASE : Le mode release n'affiche pas les cout dans le code bison
mais créé un fichier log.txt qui les contient (au cas ou)

### Comment compiler :

Pour compiler en mode release :

	$ make

En mode debug

	$ make mode=debug

## Tests

Pour executer les tests, soit en lançant

	$ make test

soit en passant l'executable à utiliser au script shell

	$ tests/run.sh build/release/exe
	
on peut même n'effectuer que certain tests

	$ tests/run.sh build/release/exe empty.test oneDeclaration.test

## Execution

Plus besoin de chercher dans quel dossier se cache l'executable

	$ make run < program.txt
	$ make run <<< ""
    $ make run mode=debug <<< ""

## Nettoyage

Pour nettoyer le dossier release

	$ make clean
	
Pour nettoyer le dossier debug

	$ make clean mode=debug
