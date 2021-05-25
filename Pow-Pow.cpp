// This program Calculate Employee sallary based on scores
// Each programs run rewrite a csv file, so be carefull and relocate  it to any dir

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

class Employee
{
public:
    Employee()
    {}
    string Name;
    int Score;
    double Sallary;

    void calculateSallary()
    {
        //Here could be any code to calculate ^_^
        this->Sallary = this->Score * 50;
        
    }
    void writeInCSV(ofstream &outData)
    { // The char ";" is delimiter of cell, after ; writing go on the next cell
        outData << this->Name <<";" << this->Score << ";" << this->Sallary << endl;
    }
    void addNewPerson()
    {
            cout << "Input Name : \n";
            cin >> this->Name;
            cout << "Input Score : \n";
            cin >> this->Score;
    }
};

int main()
{
    ofstream outData;
    outData.open("Sallaries.csv", ios::trunc);
    outData << "Name" << ";" << "Score" << ";" << "Sallary" << endl;
    
    string Key = "Start!";

    while (1)
    {
        cout << " Would you like to add new person?\n";
        cin >> Key;
        if (Key == "No")
            break;
        Employee emp1;
        emp1.addNewPerson();
        emp1.calculateSallary();
        emp1.writeInCSV(outData);
    }
    outData.close();
   
    return 0;
}
