#ifndef CJDKH_H
#define CJDKH_H

#include <string>
#include <vector>
#include <map>

// کلاس پایه برای همه حملات
class Attack {
public:
    virtual void execute() = 0; 
    virtual std::string getType() = 0;
};

// کلاس برای حمله DDoS
class DDoSAttack : public Attack {
public:
    void execute() override;
    std::string getType() override { return "DDoS"; }
};

// کلاس برای حمله SQL Injection
class SQLInjectionAttack : public Attack {
public:
    void execute() override;
    std::string getType() override { return "SQL Injection"; }
};

// کلاس پردازش دستورات
class CommandProcessor {
public:
    CommandProcessor();
    void executeCommand(const std::string& command);
    void listModules();

private:
    std::map<std::string, Attack*> attackModules;
};

#endif