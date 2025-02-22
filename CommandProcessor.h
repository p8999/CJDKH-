#ifndef COMMANDPROCESSOR_H
#define COMMANDPROCESSOR_H

#include "Module.h"
#include <vector>
#include <string>
#include <iostream>

class CommandProcessor {
public:
    CommandProcessor();
    ~CommandProcessor();

    void executeCommand(const std::string& command);
    void listModules();
    void loadModules();

private:
    std::vector<Module*> modules;
};

#endif