#include "mapeasy.hpp"
#include <fstream>

class mapeasyLoad : public mapeasy
{
private:
  bool isEasyLevel = true;

public:
  mapeasyLoad(data *_data) : mapeasy(_data)
  {
  }

  void init();
};

class mapLoad : public map
{
private:
  bool isEasyLevel = true;

public:
  mapLoad(data *_data) : map(_data)
  {
  }

  void init();
};