#include "CJDKH.h"

int main() {
    CommandProcessor processor;

    // نمایش ماژول‌های موجود
    processor.listModules();

    // پردازش دستورات
    processor.executeCommand("attack ddos");
    processor.executeCommand("attack sql");

    return 0;
}
#include "CommandProcessor.h"

int main() {
    CommandProcessor processor;
    std::string command;

    std::cout << "Welcome to CJDKH! Enter 'list' to see available modules." << std::endl;

    while (true) {
        std::cout << "> ";
        std::getline(std::cin, command);

        if (command == "exit") {
            break;
        }

        processor.executeCommand(command);
    }

    return 0;
}