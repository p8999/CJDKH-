#include "CJDKH.h"
#include <iostream>
#include <sstream>
#include <thread>
#include <chrono>

// پیاده‌سازی حمله DDoS
void DDoSAttack::execute() {
    std::cout << "Executing DDoS attack..." << std::endl;
    // عملیات حمله DDoS شبیه‌سازی می‌شود.
    std::this_thread::sleep_for(std::chrono::seconds(5));
    std::cout << "DDoS attack completed." << std::endl;
}

// پیاده‌سازی حمله SQL Injection
void SQLInjectionAttack::execute() {
    std::cout << "Executing SQL Injection attack..." << std::endl;
    // عملیات حمله SQL Injection شبیه‌سازی می‌شود.
    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::cout << "SQL Injection attack completed." << std::endl;
}

// ساختار پردازش دستور
CommandProcessor::CommandProcessor() {
    // ماژول‌های پیش‌فرض
    attackModules["ddos"] = new DDoSAttack();
    attackModules["sql"] = new SQLInjectionAttack();
}

// پردازش دستور واردشده
void CommandProcessor::executeCommand(const std::string& command) {
    std::istringstream stream(command);
    std::string action;
    stream >> action;

    if (action == "attack") {
        std::string attackType;
        stream >> attackType;

        if (attackModules.find(attackType) != attackModules.end()) {
            attackModules[attackType]->execute();
        } else {
            std::cout << "Unknown attack type: " << attackType << std::endl;
        }
    } else {
        std::cout << "Unknown command!" << std::endl;
    }
}

// لیست کردن ماژول‌ها
void CommandProcessor::listModules() {
    std::cout << "Available attack modules:" << std::endl;
    for (const auto& module : attackModules) {
        std::cout << module.first << std::endl;
    }
}