#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

std::unordered_map<Bloc*,int> map;

int main()
{
    int t = 5^2*3+3*2^5;
    // d'abord multiplication puis xor
    cout << t << endl;
    int a = 5;
    int *a_pointeur;
    a_pointeur = &a;
    
    std::pair<int*,double> a_pair (a_pointeur,1);
    map.insert(a_pair);
    int *b_pointeur = &a;
    int value;
    //std::unordered_map<int*,int>::const_iterator got = map.find(a_pointeur);
    std::unordered_map<int*,int>::const_iterator got = map.find(b_pointeur);

    if ( got == map.end() )
        std::cout << "not found";
    else
        std::cout << got->first << " is " << got->second;

    std::cout << std::endl;
}


bool chercherVariable(int *contexteCourant,string nomVariable)
{
    unordered_map<int*,int>::const_iterator trouve = map.find(contexteCourant);
    if (trouve == map.end())
        return false;
    else
        return true;
}

string returnVariableType(int *contexteCourant,string nomVariable)
{

}