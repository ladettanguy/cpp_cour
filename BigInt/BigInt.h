#include <iostream>
#include <vector>
using namespace std;

class BigInt{
    private:
        vector<int> value;
        vector<int> power;
        bool sign;
        int find(const int power);
    public:
        BigInt();
        BigInt(bool sign, int value, int power);
        BigInt(const BigInt &b);
        void supprimer(int power);
        void ajouter(int val, int power);
        void changer(int power, int newVal);
        int val(int power);
        int maxPuissance();
        bool zero();

        bool operator==(const BigInt &b);
        BigInt operator+(const BigInt &b);

        friend ostream& operator<<(ostream& cout, const BigInt &b);
        friend istream& operator>>(istream& in, BigInt &b);
};