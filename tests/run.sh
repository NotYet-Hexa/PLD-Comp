#!/bin/bash

nbArgs=`wc -w <<< "${*:2}"`
message="$TRAVIS_COMMIT_MESSAGE\n"
fail=0
RED='\033[1;31m'
NC='\033[0m'

nb_success_test=0
nb_fail_test=0

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
        message+=":small_blue_diamond: `basename $1 | sed -n "s/^\(.*\).test$/\1/p"` :heavy_check_mark: \n"
        nb_success_test=`expr $nb_success_test + 1`
    else
        printf "$RED"
        echo -e "$1 \xE2\x9C\x96"
        echo "$diff" | sed -e 's/^/\t/g'
        printf "$NC"

        message+=":small_blue_diamond: `basename $1 | sed -n "s/^\(.*\).test$/\1/p"` :x: \n"
        fail=1
        nb_fail_test=`expr $nb_fail_test + 1`
    fi
}

format_message() {
    color="#36a64f"
    title="$nb_success_test tests succeeded !"
    titlelink="https://travis-ci.org/NotYet-Hexa/PLD-Comp"
    text=`echo "$message" | sed 's/\\\x/%/g'`
    # text=`echo "$message" | sed 's%\\\x%\\\\\\\x%g'`
    if [ $fail -eq 1 ]
    then
        color="#ff0000"
        title="$nb_fail_test tests failed $nb_success_test succeeded"
    fi

    json='{'
    json+='"attachments": ['
    json+='    {'
    json+='        "color": "'$color'",'
    json+='        "title": "'$title'",'
    json+='        "title_link": "'$titlelink'",'
    json+='        "text": "'$text'"'
    json+='    }'
    json+=']'
    json+='}'

    echo "$json"
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
    format_message > slack_result.json
    if [ $fail -eq 1 ]
    then
        false
    fi
else
    tests=`find ./tests/ -type f -name '*.test'`
    nbtest=`wc -w <<< "$tests"`
    if [ $nbtest -eq 0 ]
    then
        tests=`find . -type f -name '*.test'`
    fi
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
    format_message > slack_result.json
    if [ $fail -eq 1 ]
    then
        false
    fi
fi