#include "AnimalDec.h"

void AnimalDecorator::AnimalRun()
{
    AnimalDecorator::AnimalRun();
    animal->setSpeed(animal->getSpeed() * 2);
}