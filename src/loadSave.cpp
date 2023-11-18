/*
Biến toàn cục: current index //khối cuối màn hình

-Block size
-> top -> end of stack
Mỗi stack block có position x, y -> vector 2f

-Enemies
Cụ thể: size + x,y mỗi phần tử
Car: size
Animal: size

-player: x,y


Load # chơi bth: load cái gần nhất
Load: class loadMap:  kế thừa map
player-> init đổi thành player->setPosition
createMap-> loadMap

ktra file có tồn tại ko, nv chết thì xóa file
chỉnh isGameSaved
*/


#include "loadSave.hpp"
#include <iostream>
#include <vector>
#include <string>

loadSave::loadSave(std::string path)
{
    this->path = path;
}

loadSave::~loadSave()
{
}

void loadSave::load()
{
    file.open(path, std::ios::in);
    if (file.is_open())
    {
        while (getline(file, line))
        {
            name = line.substr(0, line.find('='));
            value = line.substr(line.find('=') + 1, line.length());
            data[name] = value;
        }
        file.close();
    }
    else
    {
        std::cerr << "Unable to open file: " << path << std::endl;
    }
}

void loadSave::save()
{
    file.open(path, std::ios::out);
    if (file.is_open())
    {
        for (auto &i : data)
        {
            file << i.first << "=" << i.second << std::endl;
        }
        file.close();
    }
    else
    {
        std::cerr << "Unable to open file: " << path << std::endl;
    }
}

void loadSave::set(std::string name, std::string value)
{
    data[name] = value;
}

std::string loadSave::get(std::string name)
{
    return data[name];
}

void loadSave::print()
{
    for (auto &i : data)
    {
        std::cerr << i.first << "=" << i.second << std::endl;
    }
}