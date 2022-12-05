#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

vector<string> result;
ifstream input_file;
string text;
char currentChar;
int total = 0, count = 0;

void part1()
{
    string whole, output1, output2;

    for (int x = 0; x < text.size()/2; x++) {
        output1 += text[x];
        output2 += text[x + text.size()/2];
    }
    whole = output1 + output2;

    for (int x = 0; x < whole.size(); x++) {
        for (int y = 0; y < output1.size(); y++) {
            if (output1[y] == whole[x]) {
                currentChar = output1[y];
            }
        }
    }

    if (currentChar < 97) {
        total += currentChar - 38;
    }
    else {
        total += currentChar - 96;
    }
}

void part2()
{
    string output1, output2, output3;

    if (output1.empty()) {
        for (int x = 0; x < text.size(); x++) {
            output1 += text[x];
        }
    }
    else if (output2.empty()) {
        for (int x = 0; x < text.size(); x++) {
            output2 += text[x];
        }
    }
    else if (output3.empty()) {
        for (int x = 0; x < text.size(); x++) {
            output3 += text[x];
        }
    }

    count++;
        
    if (count == 3) {
        for (int x = 0; x < output1.size(); x++) {
            for (int y = 0; y < output2.size(); y++) {
                if (output1[x] == output2[y]) {
                    currentChar = output1[x];
                }
            }

            for (int z = 0; z < output3.size(); z++) {
                if (output3[z] == currentChar) {
                    currentChar = output3[z];
                }
            }
        }
            
        count = 0;
        output1.erase();
        output2.erase();
        output3.erase();
            
        if (currentChar < 97) {
            total += currentChar - 38;
        }
        else {
            total += currentChar - 96;
        } 
    }
}

int main()
{
    input_file.open("aoc_input.txt");
    while (getline(input_file, text)) {
        result.push_back(text);
        part1();
        part2();
    }
    input_file.close();
    cout << "Part1(): " << total << endl;
    cout << "Part2(): " << total << endl;
}