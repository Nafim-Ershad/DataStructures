#include <iostream>
#include <string>

using namespace std;

int main(){
    int number;

    cout << "How many Cars do you own?: \t";
    cin >> number;

    cin.ignore(); // Clears the buffer

    string* pCars = new string[number];

    for(int i = 0; i < number; i++)
    {
        cout << "Enter Car #" << i+1 << " ";
        getline(cin, pCars[i]);
    }
    cout << "Your Garage:\n";
    cout << "-----------------------------------------------------------------\n";

    for(int i = 0; i < number; i++)
    {
        cout << "Car #" << i + 1 << ": " << pCars[i] << "\t";
    }

    return 0;
}