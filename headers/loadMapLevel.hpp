#include "mapeasy.hpp"
#include "resumeScreen.hpp"
#include <fstream>

class mapeasyLoad : public mapeasy
{
private:
  bool isCountdownScreenNeeded = true;
  int numScreenDrawn = 0;

public:
  mapeasyLoad(data *_data) : mapeasy(_data)
  {
  }

  void init();
  void draw();
};

class mapLoad : public map
{
private:
  bool isCountdownScreenNeeded = true;

public:
  mapLoad(data *_data) : map(_data)
  {
  }

  void init();
  void draw();
};