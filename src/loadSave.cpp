// /*
// Biến toàn cục: current index //khối cuối màn hình

// -Block size
// -> top -> end of stack
// Mỗi stack block có position x, y -> vector 2f

// -Enemies
// Cụ thể: size + x,y mỗi phần tử
// Car: size
// Animal: size

// -player: x,y


// Load # chơi bth: load cái gần nhất
// Load: class loadMap:  kế thừa map
// player-> init đổi thành player->setPosition
// createMap-> loadMap

// ktra file có tồn tại ko, nv chết thì xóa file
// chỉnh isGameSaved
// */

#include <iostream>

// Forward declaration of classes
class ElementA;
class ElementB;

// Visitor interface
class Visitor {
public:
    virtual void visit(ElementA& element) = 0;
    virtual void visit(ElementB& element) = 0;
};

// Element interface
class Element {
public:
    virtual void accept(Visitor& visitor) = 0;
};

// Concrete elements
class ElementA : public Element {
public:
    void accept(Visitor& visitor) override {
        visitor.visit(*this);
    }
    std::string operationA() {
        return "ElementA";
    }
};

class ElementB : public Element {
public:
    void accept(Visitor& visitor) override {
        visitor.visit(*this);
    }
    std::string operationB() {
        return "ElementB";
    }
};

// Concrete visitor
class LoadSaveVisitor : public Visitor {
public:
    void visit(ElementA& element) override {
        std::cout << "Load and save operation on " << element.operationA() << std::endl;
    }
    void visit(ElementB& element) override {
        std::cout << "Load and save operation on " << element.operationB() << std::endl;
    }
};

// Client code
int main() {
    //dùng unique ptr
    Element* elements[] = {new ElementA(), new ElementB()};
    Visitor* visitor = new LoadSaveVisitor();
    for (Element* element : elements) {
        element->accept(*visitor);
    }
    delete visitor;
    delete elements[0];
    delete elements[1];
    return 0;
}
