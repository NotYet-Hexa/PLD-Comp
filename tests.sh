#!/bin/bash

run_test() {
    expression=`sed '1!d' $1`
    resulthope=`sed '2!d' $1 | tr -d '\r' | tr -d '\n'`

    if [ -z "$resulthope" ]
    then
        echo "Missing new line in $1"
        exit 1
    fi

    result=`echo "$expression" | ./exe`

    result=`echo "$result" | tr -d '\r' | tr -d '\n'`

    if [ "$result" = "$resulthope" ]
    then
        echo "`basename $1` OK"
    else
        echo -e "$1 fail \n\t→ expected : '$resulthope' - actual : '$result'"
        exit 1
    fi
}

if [ ! -f "exe" ]
then
    make
fi

if [ $# -gt 0 ]
then
    for param in $*
    do
        if [ -f $param ]
        then
            run_test $param
        elif [ -f "./Tests/$param" ]
        then
            run_test "./Tests/$param"
        else
            echo "Aucun fichier $param"
            exit 1
        fi
    done
else
    tests=`find ./Tests/test*`
    for test in $tests
    do
        run_test $test
    done
fi
