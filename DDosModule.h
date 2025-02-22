#ifndef DDOSMODULE_H
#define DDOSMODULE_H

#include "Module.h"
#include <iostream>
#include <thread>
#include <chrono>

class DDoSModule : public Module {
public:
    void execute() override {
        std::cout << "Starting DDoS attack..." << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(5));
        std::cout << "DDoS attack completed." << std::endl;
    }

    std::string getName() const override { return "DDoS Attack"; }
    std::string getDescription() const override { return "Launches a DDoS attack on the target."; }
};

#endif