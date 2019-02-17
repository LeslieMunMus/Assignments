// LESLIE M. MUSENGI_64977528_ASSIGNMENT 1
// IDE – xCode

// QUESTION 2

// This program validates whether a matric student qualifies
// to register for the BSc Computer Science degree
#include <iostream>
#include <cassert>

void getInfo(int& maths, int& physical_science, int& english);
// gets student marks for the subjects maths, physical science
// and english and asserts the marks are less than or equal to 100
bool registration(int maths, int physical_science, int english);
// evalutes whether the marks are above 60 or if there is any below
// 60. If any, student cannot register for BSc Comp Sci
void displayOutcome(int maths, int physical_science, int english);
// displays information of the outcome

int main()
{
    using namespace std;
    int maths, physical_science, english;
    
    cout << "\nThis program validates whether a matric student "
    << "qualifies to register for the BSc Computer Science degree.\n"
    << endl;
    
    getInfo(maths, physical_science, english);
    displayOutcome(maths, physical_science, english);
    
    return 0;
}

void getInfo(int& maths, int& physical_science, int& english)
{ // gets marks as type int and asserts none is above 100
    using namespace std;
    cout << "Enter your marks for Maths: ";
    cin >> maths;
    assert(maths <= 100);
    cout << "Enter your marks for Physical Science: ";
    cin >> physical_science;
    assert(physical_science <= 100);
    cout << "Enter your marks for English: ";
    cin >> english;
    assert(english <= 100);
}

bool registration(int maths, int physical_science, int english)
{ // evaluates if all marks are above 60 or if any that's not
    bool results = true;
    if (maths < 60 || physical_science < 60 || english < 60)
    {
        results = false;
    }
    return results;
}

void displayOutcome(int maths, int physical_science, int english)
{ // displays the outcome
    using namespace std;
    if (registration(maths, physical_science, english))
    {
        cout << "\nCONGRATULATIONS!!! You qualify for registration.\n";
    }
    else
    {
        cout << "\nUnfortunately you do not qualify for registration.\n";
    }
}

