#include "CommandProcessor.h"
#include "DDoSModule.h"
#include "SQLInjectionModule.h"

CommandProcessor::CommandProcessor() {
    loadModules();
}

CommandProcessor::~CommandProcessor() {
    for (auto& module : modules) {
        delete module;
    }
}

void CommandProcessor::loadModules() {
    modules.push_back(new DDoSModule());
    modules.push_back(new SQLInjectionModule());
}

void CommandProcessor::executeCommand(const std::string& command) {
    if (command == "list") {
        listModules();
    } else {
        bool found = false;
        for (auto& module : modules) {
            if (command == module->getName()) {
                module->execute();
                found = true;
                break;
            }
        }
        if (!found) {
            std::cout << "Unknown command!" << std::endl;
        }
    }
}

void CommandProcessor::listModules() {
    std::cout << "Available modules:" << std::endl;
    for (auto& module : modules) {
        std::cout << "- " << module->getName() << ": " << module->getDescription() << std::endl;
    }
}