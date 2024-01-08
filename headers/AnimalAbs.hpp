#include <vector>
#include <string>
#include <random>
#include <stdexcept>
#include "Animal.hpp"

class Animal;

class AnimalFactory
{
private:
  std::vector<std::string> animalTypes = {"cop", "tegiac", "gau", "lacda", "voi"};

public:
  virtual Animal *createAnimal(const std::string &type, data *_data);

  virtual Animal *createRandomAnimal(data *_data);
};