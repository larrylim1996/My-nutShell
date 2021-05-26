#pragma once
#include <string>
#include <vector>
#include <map>

struct Line {
    struct CMD {
        std::string command;
        std::vector<std::string> args;
    };
	bool isWildcard = false;
    bool inputRedirect = false;
    std::string input;
    bool outputRedirect = false;
    std::string output;
    int i = -1;
    std::vector<CMD> commands;

    void addCommand(std::string _command) {
        CMD c;
        c.command = _command;
        commands.push_back(c);
        ++i;
    }

    void addArg(std::string _arg) {
		if(wildCard == true){
			char currPath(PATH_MAX);
			findFile(getcwd(currPath,PATH_MAX),_arg);
		}
        commands.at(i).args.push_back(_arg);
    }

    void reset() {
        inputRedirect = false;
        outputRedirect = false;
        i = -1;
        commands.clear();
        input.clear();
        output.clear();
    }
};

extern Line line;

extern std::map<std::string, std::string> aliases;

extern std::map<std::string, std::string> envs;

std::string expandVars(std::string s);

void parseLine();

bool comparePattern(std::string s, std::string pattern);

std::string removePattern(std::string p);

std:: string findFile(std::string path, std::string s);
