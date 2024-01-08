#include "Animal.hpp"
#include <memory>


class AnimalDecorator : public Animal {
protected:
    std::unique_ptr<Animal> animal;
public:
    AnimalDecorator(std::unique_ptr<Animal> animal) : animal(std::move(animal)) {}
    AnimalDecorator() : Animal() {}
    virtual ~AnimalDecorator() = default;
};

class FastAnimal : public AnimalDecorator {
public:
    FastAnimal(std::unique_ptr<Animal> animal) : AnimalDecorator(std::move(animal)) {}

    void AnimalRun() override;
};