#ifndef MODULE_H
#define MODULE_H

#include <string>

class Module {
public:
    virtual void execute() = 0;
    virtual std::string getName() const = 0;
    virtual std::string getDescription() const = 0;
};

#endif