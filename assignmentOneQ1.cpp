// ASSIGNMENT 1 QUESTION 1
// IDE - xCode
// Author - Leslie M. Musengi (stuID #64977528)
// This is a program to compute and display the charges for a patient’s hospital stay
#include <iostream>

bool admissionStatus(int& ans);
// checks weather user was treated as an in-patient or out-patient using an int
// 1 for in-patient and 0 for out-patient
void getInfo(int& days, double& rate, double& medication, double& service, int& ans);
// gets user information using bool result for admissionStatus() function
// in-patient - get number of days, rate per day, medication cost and service fee
// out-patient - get medication cost and service fee
double calcCharges(int days, double rate, double medication, double service, int ans);
// calculates charges for an in-patient
double calcCharges(double medication, double service, int ans);
// calculates charges for an out-patient

int main()
{
    using namespace std;
    int ans, days;
    double rate, medication, service;
    
    cout << "\nThis program calculates hospital charges for a patient according to "
    << "their admission status (in-patient or out-patient).\n" << endl;
    
    cout << "If you were treated as an in-patient press 1 "
    << "and if you were treated as an out-patient press 0: ";
    cin >> ans;
    
    if (admissionStatus(ans) == 1)
    {
        getInfo(days, rate, medication, service, ans);
        cout << "Your hospital bill is R" << calcCharges(days, rate, medication, service, ans) << endl;
    }
    else
    {
        getInfo(days, rate, medication, service, ans);
        cout << "Your hospital bill is R" << calcCharges(medication, service, ans) << endl;
    }

    return 0;
}
// function definitions
bool admissionStatus(int& ans)
{ // returns true if if user presses 1
    bool status = true;
    if (ans != 1)
    {
        status = false;
    }
    return status;
}

void getInfo(int& days, double& rate, double& medication, double& service, int& ans)
{
    using namespace std;
    if (admissionStatus(ans) == 1)
    { // information for an in-patient
        cout << "Enter number of days spent in hospital: ";
        cin >> days;
        cout << "Enter rate charged per day during admission: R";
        cin >> rate;
        cout << "Enter amount charged for medication: R";
        cin >> medication;
        cout << "Enter fees charged for hospital services: R";
        cin >> service;
    }
    else
    { // information for an out-patient
        cout << "Enter amount charged for medication: R";
        cin >> medication;
        cout << "Enter fees charged for hospital services: R";
        cin >> service;
    }
    
}

double calcCharges(int days, double rate, double medication, double service, int ans)
{ // calculates charges for an in-patient
    double actual_rate = rate * days;
    double charges = 0.00;
    if (admissionStatus(ans))
    {
        charges = actual_rate + medication + service;
    }
    return charges;
}

double calcCharges(double medication, double service, int ans)
{ // calculates charges for an out-patient
    double charges = 0.00;
    if (!(admissionStatus(ans)))
    {
        charges = medication + service;
    }
    return charges;
}
