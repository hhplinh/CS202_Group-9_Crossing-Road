#include "mapeasy.hpp"
#include "resumeScreen.hpp"
#include <fstream>

class mapeasyLoad : public mapeasy
{
private:
  int numScreenDrawn = 0;

public:
  mapeasyLoad(data *_data) : mapeasy(_data)
  {
    player = new maincharactereasy(_data);
    player->init();
    isCountdownNeeded = true;
  }

  void init();
  void draw();
};

class mapLoad : public map
{
private:
  int numScreenDrawn = 0;

public:
  mapLoad(data *_data) : map(_data)
  {
    player = new maincharacter(_data);
    player->init();
    isCountdownNeeded = true;
  }

  void init();
  void draw();
};