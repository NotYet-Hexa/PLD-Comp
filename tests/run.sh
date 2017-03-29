#!/bin/bash

nbArgs=`wc -w <<< "${*:2}"`

if [ $# -eq 0 ]
then
    echo "Please pass the executable as first parameter"
    exit 1
fi

exe="$1"

if ! [ -f "$exe" ]
then
    if [ -f "../$exe" ]
    then
        exe="../$exe"
    else
        echo "Can't find executable"
        echo "We are here : `pwd`"
        echo "Path used : $exe & ../$exe"
        exit 1
    fi
fi

result_from_test() {
    name="$1"
    path=`echo "$1" | sed -n "s/^\(.*\).test$/\1/p"`
    resultname="$path"".res"
    echo $resultname
}


run_test() {

    result=`$exe < "$1"`

    diff=`diff -u -w $2 <(echo -e "$result")`


    if [ "$diff" == "" ]
    then
        echo -e "→ `basename $1 | sed -n "s/^\(.*\).test$/\1/p"` \xE2\x9C\x93"
    else
        echo "$1 fail"
        echo "$diff"
        exit 1
    fi
}

if [ $nbArgs -gt 0 ]
then
    for param in ${*:2}
    do
        if [ -f $param ]
        then
            resultname=$(result_from_test "$param")
            if [ -f $resultname ]
            then
                run_test "$param" "$resultname"
            else
                echo -e "$param \t was ignored → $resultname \t missing"
            fi
        elif [ -f "./tests/$param" ]
        then
            param="./tests/$param"
            resultname=$(result_from_test "$param")
            if [ -f "$resultname" ]
            then
                run_test "$param" "$resultname"
            else
                echo -e "$param \t was ignored → $resultname \t missing"
            fi
        else
            echo "Aucun fichier $param, chemin essayé :"
            echo -e "\t → $param"
            echo -e "\t → ./tests/$param"
            exit 1
        fi
    done
else
    tests=`find . -type f -name '*.test'`
    for test in $tests
    do
        resultname=$(result_from_test "$test")
        if [ -f $resultname ]
        then
            run_test $test $resultname
        else
            echo -e "$test \t was ignored → $resultname \t missing"
        fi
    done
fi