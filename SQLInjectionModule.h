#ifndef SQLINJECTIONMODULE_H
#define SQLINJECTIONMODULE_H

#include "Module.h"
#include <iostream>
#include <thread>
#include <chrono>

class SQLInjectionModule : public Module {
public:
    void execute() override {
        std::cout << "Executing SQL Injection..." << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(3));
        std::cout << "SQL Injection attack completed." << std::endl;
    }

    std::string getName() const override { return "SQL Injection"; }
    std::string getDescription() const override { return "Performs a SQL injection attack."; }
};

#endif