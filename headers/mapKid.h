#pragma once
#include "mapeasy.hpp"

class mapKid : public mapeasy
{
private:
  bool isPlayerVisible;
  sf::Clock aliveDuration;
  sf::Clock visiblePlayerDuration;

public:
  mapKid(data *_data) : mapeasy(_data), isPlayerVisible(true)
  {
  }

  ~mapKid() {}

  bool isImmortal() const;

  void draw();
};