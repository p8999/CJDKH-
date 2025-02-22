// cjdkh.cpp

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <thread>
#include <chrono>
#include <map>

// کلاس پایه برای حملات
class Attack {
public:
    virtual void execute() = 0;
    virtual std::string getType() = 0;
};

// کلاس حمله DDoS
class DDoSAttack : public Attack {
private:
    std::string target;
    int port;
    int duration;

public:
    DDoSAttack(const std::string& target, int port, int duration)
        : target(target), port(port), duration(duration) {}

    void execute() override {
        std::cout << "Executing DDoS attack on " << target << " at port " << port << " for " << duration << " seconds..." << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(duration));
        std::cout << "DDoS attack completed." << std::endl;
    }

    std::string getType() override {
        return "DDoS";
    }
};

// کلاس حمله SQL Injection
class SQLInjectionAttack : public Attack {
private:
    std::string target;
    std::string payload;

public:
    SQLInjectionAttack(const std::string& target, const std::string& payload)
        : target(target), payload(payload) {}

    void execute() override {
        std::cout << "Executing SQL Injection attack on " << target << " with payload: " << payload << std::endl;
    }

    std::string getType() override {
        return "SQL Injection";
    }
};

// پردازش دستورات
class CommandProcessor {
public:
    std::map<std::string, Attack*> attackMap;

    CommandProcessor() {
        // ماژول‌های پیش‌فرض
        attackMap["ddos"] = nullptr;
        attackMap["sql"] = nullptr;
    }

    void executeCommand(const std::string& command) {
        std::istringstream stream(command);
        std::string action;
        stream >> action;

        if (action == "attack") {
            std::string attackType;
            stream >> attackType;

            if (attackType == "ddos") {
                std::string target;
                int port, duration;
                stream >> target >> port >> duration;

                DDoSAttack* attack = new DDoSAttack(target, port, duration);
                attack->execute();
                attackMap["ddos"] = attack;
            }
            else if (attackType == "sql") {
                std::string target, payload;
                stream >> target >> payload;

                SQLInjectionAttack* attack = new SQLInjectionAttack(target, payload);
                attack->execute();
                attackMap["sql"] = attack;
            }
            else {
                std::cout << "Unknown attack type: " << attackType << std::endl;
            }
        }
        else {
            std::cout << "Unknown command!" << std::endl;
        }
    }

    // لیست حملات انجام‌شده
    void listAttacks() {
        std::cout << "Active Attacks:" << std::endl;
        for (const auto& entry : attackMap) {
            if (entry.second != nullptr) {
                std::cout << "Attack Type: " << entry.second->getType() << std::endl;
            }
        }
    }
};

// پردازش ورودی
int main() {
    CommandProcessor processor;

    // دستور برای اجرای حمله DDoS
    std::string inputCommand = "attack ddos 192.168.1.1 80 10";
    processor.executeCommand(inputCommand);

    // دستور برای اجرای حمله SQL Injection
    inputCommand = "attack sql 192.168.1.1 \"DROP TABLE users\"";
    processor.executeCommand(inputCommand);

    // لیست کردن حملات انجام‌شده
    processor.listAttacks();

    return 0;
}