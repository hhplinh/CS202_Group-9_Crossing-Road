#include "AnimalAbs.hpp"

Animal *AnimalFactory::createRandomAnimal(data *_data)
{
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> distr(0, animalTypes.size() - 1);

  std::string randomAnimalType = animalTypes[distr(gen)];
  return createAnimal(randomAnimalType, _data);
}


Animal *AnimalFactory::createAnimal(const std::string &type, data *_data)
{
  if (type == "cop")
  {
    return new cop(_data);
  }
  else if (type == "tegiac")
  {
    return new tegiac(_data);
  }
  else if (type == "gau")
  {
    return new gau(_data);
  }
  else if (type == "lacda")
  {
    return new lacda(_data);
  }
  else if (type == "voi")
  {
    return new voi(_data);
  }
  else
  {
    throw std::invalid_argument("Invalid animal type");
  }
}