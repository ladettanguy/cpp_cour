#include "BigInt.h"
#include <string>

BigInt::BigInt(): sign(true)
{}

BigInt::BigInt(bool sign, int value, int power): sign(sign)
{
    this -> value.push_back(value);
    this -> power.push_back(power);
}

BigInt::BigInt(const BigInt &b)
{
    int i = 0;
    while (i < b.value.size()){
        this -> value.push_back(b.value[i]);
        i++;
    }
    i = 0;
    while (i < b.power.size()){
        this -> power.push_back(b.power[i]);
        i++;
    }
    this -> sign = b.sign;
}

int BigInt::find(const int power)
{
    int i=0;
    while (i < this -> power.size()){
        if(this -> power[i] == power){
            return i;
        }
        i++;
    }
    return -1;
}

void BigInt::supprimer(int power)
{
    int index = this -> find(power);
    if(index != -1){
        this -> power.erase(this -> power.begin() + index);
        this -> value.erase(this -> value.begin() + index);
    }
}

void BigInt::ajouter(int val, int power)
{
    int index = this -> find(power);
    if(index == -1){
        this -> power.push_back(power);
        this -> value.push_back(val);
    }
}

void BigInt::changer(int power, int newVal)
{
    int index = this -> find(power);
    if(index != -1)
    {
        this -> supprimer(power);
    }
    this -> ajouter(newVal, power);
}

int BigInt::val(int power)
{
    int index = this -> find(power);
    if(index != -1){
        return this -> value[index];
    }
    return -1;
}

int BigInt::maxPuissance()
{
    int i=0;
    int max = 0;
    while (i < this -> power.size()){
        if(this -> power[i] > max){
            max = this -> power[i];
        }
        i++;
    }
    return max;
}

bool BigInt::zero()
{
    return this -> value.size() == 0;
}

bool BigInt::operator==(const BigInt &b)
{
    BigInt copi(b);
    int i = 0;
    while (i < this -> power.size()){
        int index = copi.find(this -> power[i]);
        if(index != -1){
            if(this -> value[index] != b.value[index]){
                return false;
            }
        }
        else{
            return false;
        }
        i++;
    }
    i = 0;
    while (i < b.power.size()){
        int index = this -> find(b.power[i]);
        if(index != -1){
            if(this -> value[index] != b.value[index]){
                return false;
            }
        }
        else{
            return false;
        }
        i++;
    }
    return true;
}

BigInt BigInt::operator+(const BigInt &b)
{
    BigInt bi;
    BigInt copi(b);
    int i = 0;
    while (i < this -> power.size()){
        int pow = this -> power[i];
        int val = this -> value[i];
        int index = bi.find(pow);
        if(index != -1) {
            val += copi.val(pow);
        }
        bi.changer(pow, val);
        i++;
    }
    i = 0;
    while (i < copi.power.size()){
        int pow = copi.power[i];
        int val = copi.value[i];
        int index = this -> find(pow);
        if(index != -1) {
            bi.ajouter(val,pow);
        }
        i++;
    }
    return bi;
}

ostream& operator<<(ostream& cout, const BigInt &b)
{
    char sign = '-';
    if(b.sign){
        sign = '+';
    }
    cout << sign << "(";
    int i = 0;
    string s = "";
    while (i < b.power.size()){
        cout << " + " << b.value[i];
        cout << "x10^" << b.power[i];
        i++;
    }
    cout << ")" << endl;
    return cout;
}

istream& operator>>(istream& in, BigInt &b)
{
    BigInt temp;
    b = temp;
    int val;
    int pow;
    cout << "Ecrivez une valeur à ajouter ou -1 pour terminer" << endl;
    in >> val;

    while(val != -1){
        cout << "Ecrivez une puissance pour votre valeur" << endl;
        in >> pow;

        b.changer(pow, val);
        cout << "Ecrivez une valeur à ajouter ou -1 pour terminer" << endl;
        in >> val;
    }

    return in;
}

int main() {
    BigInt E1;                // zero, tableaux vides
    BigInt E2(true, 100, 4);  // initialisation par le premier element signe, clé, val
    cout << E2 << endl;       // affichage
    BigInt E3(false, 202, 7);
    BigInt E4(E2);             //copie
    cout << E4 << endl;
    E1 = E2 + E3;              //somme 
    cout << E1 << endl;
    cout << E1.maxPuissance() << endl;
    E3.ajouter(4,3);          // ajouter un élément
    E2.ajouter(4,5);
    unsigned int valeur = E2.val(4); // trouver le chiffre associé à 10^4 
    E2.changer(4,9);  // changer le chiffre à la position 10^4 contre 9
    cout << E3 << endl;
    E3.supprimer(202);   // supprimer cette puissance
    if (E3 == E2)  cout << "egalite " << endl; //comparer deux BigInts
    cout << E3 << endl;
    cin >> E1;                 // lecture
    if ( ! E1.zero())
        cout << E1 << endl;
}