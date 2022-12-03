#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> elf;
    int amountOfCalories = 0;

    ifstream input_file;
    string text;
    input_file.open("aoc_input.txt");

    while (getline(input_file, text)) {
        if (text.compare("")) {
            amountOfCalories += stoi(text);
        }
        else {
            elf.push_back(amountOfCalories);
            amountOfCalories = 0;
        }
    }
    input_file.close();

    sort(elf.begin(), elf.end(), greater<int>());
    cout << "Elf has " << elf[0] << endl;
    cout << "Combined Elf total is " << elf[0] + elf[1] + elf[2] << endl;
}