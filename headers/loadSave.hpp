#pragma once

#include <iostream>

// Forward declaration of classes
class easyLevel;
class hardLevel;

// Visitor interface
class Visitor {
public:
    virtual void visit(easyLevel& Level) = 0;
    virtual void visit(hardLevel& Level) = 0;
};

// Level interface
class Level {
public:
    virtual void accept(Visitor& visitor) = 0;
};

// Concrete Levels
class easyLevel : public Level {
public:
    void accept(Visitor& visitor) override {
        visitor.visit(*this);
    }
    std::string operationA() {
        return "LevelA";
    }
};

class hardLevel : public Level {
public:
    void accept(Visitor& visitor) override {
        visitor.visit(*this);
    }
    std::string operationB() {
        return "LevelB";
    }
};

// Concrete visitor
class LoadSaveVisitor : public Visitor {
public:
    void visit(easyLevel& Level) override {
        std::cout << "Load and save operation on " << Level.operationA() << std::endl;
    }
    void visit(hardLevel& Level) override {
        std::cout << "Load and save operation on " << Level.operationB() << std::endl;
    }
};

// Client code
int main() {
    //dùng unique ptr
    Level* Levels[] = {new easyLevel(), new hardLevel()};
    Visitor* visitor = new LoadSaveVisitor();
    for (Level* Level : Levels) {
        Level->accept(*visitor);
    }
    delete visitor;
    delete Levels[0];
    delete Levels[1];
    return 0;
}
