#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int total_score = 0;
int win = 0, loss = 0, draw = 0;
vector<string> result;

void part1() 
{
    for (int x = 0; x < result.size(); x++) {
        string line = result[x];
        char oppMove = line[0], yourMove = line[2];

        switch (yourMove) {
            case 'X': //you're rock
                switch (oppMove) {
                case 'A': //they're rock
                    draw++;
                    total_score += 1 + 3;
                    break;
                case 'B': //they're paper
                    loss++;
                    total_score += 1;
                    break;
                case 'C': //they're scissor
                    win++;
                    total_score += 6 + 1;
                    break;
                }
                break;
            case 'Y': //you're paper
                switch (oppMove) {
                case 'A': //they're rock
                    win++;
                    total_score += 6 + 2;
                    break;
                case 'B': //they're paper
                    draw++;
                    total_score += 2 + 3;
                    break;
                case 'C': //they're scissor
                    loss++;
                    total_score += 2;
                    break;
                }
                break;
            case 'Z': //you're scissor
                switch (oppMove) {
                case 'A': //they're rock
                    loss++;
                    total_score += 3;
                    break;
                case 'B': //they're paper
                    win++;
                    total_score += 6 + 3;
                    break;
                case 'C': //they're scissor
                    draw++;
                    total_score += 3 + 3;
                    break;
                }
                break;
        }
    }
}

void part2()
{
    for (int x = 0; x < result.size(); x++) {
        string line = result[x];
        char oppMove = line[0], yourMove = line[2];

        switch (yourMove) {
            case 'X': //lose
                switch(oppMove) {
                    case 'A': //they're rock
                        total_score += 3; //you're scissor
                        break;
                    case 'B': //they're paper
                        total_score += 1; //you're rock
                        break;
                    case 'C': //they're scissor
                        total_score += 2; //you're paper
                        break;
                }

                loss++;
                break;
            case 'Y': //draw
                switch(oppMove) {
                    case 'A': //they're rock
                        total_score += 1 + 3;
                        break;
                    case 'B': //they're paper
                        total_score += 2 + 3;
                        break;
                    case 'C': //they're scissor
                        total_score += 3 + 3;
                        break;
                }

                draw++;
                break;
            case 'Z': //win
                switch(oppMove) {
                    case 'A': //they're rock
                        total_score += 2 + 6; //you're paper
                        break;
                    case 'B': //they're paper
                        total_score += 3 + 6; //you're scissor
                        break;
                    case 'C': //they're scissor
                        total_score += 1 + 6; //you're rock
                        break;
                }

                win++;
                break;
        }
    }
}

int main()
{
    ifstream input_file;
    string text;
    input_file.open("aoc_input.txt");

    while (getline(input_file, text)) {
        result.push_back(text);
    }
    input_file.close();

    part1();
    part2();

    cout << "The amount of win: " << win << endl;
    cout << "The amount of loss: " << loss << endl;
    cout << "The amount of draw: " << draw << endl;
    cout << "The total score:  " << total_score << endl;
}