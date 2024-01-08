#include "AnimalDec.h"

void AnimalDecorator::AnimalRun override()
{
    animal->setSpeed(animal->getSpeed() * 2);

}