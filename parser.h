//
// Created by trykr on 24.01.2023.
//

#ifndef TR6_PARSER_H
#define TR6_PARSER_H
#include <iostream>
#include <fstream>
#include <vector>
#include <map>


//E::= T | T = E | C
//T ::= ++S | S
//C::= S++ | I

enum class Token
{
    PlusPlus, // ++
    S,
    Equals, // =
    I,
    Empty,
};

class Parser
{
private:
    std::string currentLine;
    Token token;
    std::ifstream file;
    std::map<std::string, int> S;
    std::string buf;
    Token scan();
    int Efunc();
    int TFunc(bool isPrecrement);
    int CFunc(bool isPostcrement);
    void match();

public:
    Parser(std::string filename);
    ~Parser();

    bool parse();
    void printVars();


};


#endif //TR6_PARSER_H
