#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void CreateTXT(char* fname)
{
    ofstream fout(fname);
    char ch;
    string s;
    do
    {
        cout << "enter line: ";
        cin.ignore(); // Замінюємо cin.get() і cin.sync() на cin.ignore()
        getline(cin, s);
        fout << s << endl;
        cout << "continue? (y/n): ";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');
    cout << endl;
    fout.close(); // Додаємо закриття файлу
}

void PrintTXT(char* fname) // виведення файлу на екран
{
    ifstream fin(fname);
    string s;
    while (getline(fin, s))
    {
        cout << s << endl;
    }
    cout << endl;
}

int SearchInFile(const char* fname)
{
    ifstream fin(fname);
    string s;
    int count = 0;
    int lineNumber = 1;

    while (getline(fin, s))
    {
        for (size_t i = 0; i < s.length() - 1; i++)
        {
            if (s[i] == ',' && s[i + 1] == '-')
            {
                count++;
                cout << "Found ',-' in line " << lineNumber << " at position " << i + 1 << endl;
            }
        }
        lineNumber++;
    }

    fin.close();
    return count;
}

int main()
{
    char fname[100];
    cout << "Enter file name: ";
    cin >> fname;

    CreateTXT(fname);

    cout << "\nFile content:\n";
    PrintTXT(fname);

    int count = SearchInFile(fname);

    if (count > 0)
        cout << "Total number of ',-' sequences found: " << count << endl;
    else
        cout << "No ',-' sequences found in the file" << endl;

    return 0;
}