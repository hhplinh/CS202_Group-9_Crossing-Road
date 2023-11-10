#include"gameplay.hpp"

void gameplay :: init()
{
    createmap();
   // player = new maincharacter(_data);
    player->init();

}
void gameplay :: processInput()
{
    player->processInput();
}
void gameplay :: update()
{
    player->update();
}
void gameplay :: draw()
{
    player->draw();
}
void gameplay:: createmap()
{
    
}
