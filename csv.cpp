#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{

    ifstream f("C:/Users/Othman/Desktop/etudiantt.csv");
    if (f)                                                         // si l'ouverture a réussi
    {
        string ligne;
        while(getline(f,ligne))
        {
            cout << ligne << endl;
          
        }
          f.close();
        
    }
    else
    {
        cout << " erreur" << endl;
    }
    return 0;
}
