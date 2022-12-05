#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

vector<string> result;
ifstream input_file;

int count1 = 0, count2 = 0;
int set1First = 0, set1Last = 0, set2First = 0, set2Last = 0;
string set1, set1_last, set2, set2_last;
string text;

void part1()
{
    for (int x = 0; x < text.find(","); x++) {
        set1 += text[x];
    }
        
    for (int x = set1.find("-") + 1; x < set1.size(); x++) {
        set1_last += set1[x];
    }

    for (int x = text.find(",") + 1; x < text.size(); x++) {
        set2 += text[x];
    }

    for (int x = set2.find("-") + 1; x < set2.size(); x++) {
        set2_last += set2[x];
    }

    set1First = stoi(set1);
    set1Last = stoi(set1_last);
    set2First = stoi(set2);
    set2Last = stoi(set2_last);

    if (set1First <= set2First && set1Last >= set2Last) {
         count1++;
    }
    else if (set2First <= set1First && set2Last >= set1Last) {
         count1++;
    }

    set1.erase();
    set1_last.erase();
    set2.erase();
    set2_last.erase();
}

void part2()
{
    for (int x = 0; x < text.find(","); x++) {
        set1 += text[x];
    }
        
    for (int x = set1.find("-") + 1; x < set1.size(); x++) {
        set1_last += set1[x];
    }

    for (int x = text.find(",") + 1; x < text.size(); x++) {
        set2 += text[x];
    }

    for (int x = set2.find("-") + 1; x < set2.size(); x++) {
        set2_last += set2[x];
    }

    set1First = stoi(set1);
    set1Last = stoi(set1_last);
    set2First = stoi(set2);
    set2Last = stoi(set2_last);
    
    if (set1Last >= set2First && set1Last <= set2Last) {
        count2++;
    }
    else if (set2Last >= set1First && set2Last <= set1Last) {
        count2++;
    }

    set1.erase();
    set1_last.erase();
    set2.erase();
    set2_last.erase();
}

int main()
{
    input_file.open("aoc_input.txt");
    while (getline(input_file, text)) {
        part1();
        part2();
    }
    input_file.close();
    cout << "part1(): " << count1 << endl;
    cout << "part2(): " << count2 << endl;
}