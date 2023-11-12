#include"map.hpp"
#include<iostream>
#include<random>
#include"endgameMenu.hpp"
void map::init()
{   player = new maincharacter(_data);
    player->init();
    this->blocks.clear();

   this->currentIndex=0;
    //set player position to the bottom of the screen
    this->river.clear();
    this->length = 10;
    createmap();
    background.setSize(sf::Vector2f(1920,1080));
    background.setFillColor(sf::Color::White);
}
void map::processInput()
{  // sf::Event event;
	//while (_data->_window->pollEvent(event))
	//{
		//switch (event.type)
		//{
		//case sf::Event::Closed:
		//	_data->_window->close();
		//	break;
       // }
    //}
    player->processInput();
}
void map::update()
{   float prePos= player->getPosition().y;
    player->update();
    float pos= player->getPosition().y;
    
    std:: cout<< blocks.size()<<std::endl;
    float i = ( pos/1080.0 +1)*6;
    float j=-i;
    int k= int (i);
    int f= int (j);
    if(k>this->currentIndex)
    {
        this->currentIndex=k;
      
    }
    if( ((i-k)<0.2&& pos>0)||(j-f>0.7&&(j-f)<0.8&&pos<0))
    {
        int z;
        for( int i=0;i<1;i++){
         z=rand()%3;

        if(z==0)
        {
            addblock("road");
        }
        else if(z==1)
        {
            addblock("grass");
        }
        else if(z==2)
        {
            addblock("river");
        }
  
        }
    }


   sf:: Vector2f pos1(0.0f,906.0f);


river.clear();

for (int i = currentIndex; i < blocks.size(); i++) 
{
   blocks[i]->setpos(pos1);
  if(blocks[i]->getTerrainName()=="river")
  {
        river.push_back(pos1);
  }
    pos1.y -= 174.0;
    
}  
     sf::Vector2f screenSize(1920, 1080); // Adjust this based on your screen size
     
      for (const auto& riverBlockPos : river) {
        float riverBlockHeight = /* height of your river blocks */174;
        
        // Check if player is within the vertical span of the river block
        if ( (player->getPosition().y +143 ) > riverBlockPos.y &&
             (player->getPosition().y +143 ) < (riverBlockPos.y + riverBlockHeight)) {
            // Collision detected, player is in the river
            player->setPosition(0,prePos);
            return;  // Exit the update function
        }
    }
}





void map::draw()
{  
    _data->_window->clear();
   
    _data->_window->draw(background);
\

for (int i = currentIndex; i < blocks.size(); i++) {
    //blocks[i]->setpos(pos);
    blocks[i]->draw();
  
}  

//set player position to the bottom of the screen
    std::cout<<blocks.size()<<std::endl;
    player->draw();
    _data->_window->display();
    //detect player in river
  


}
void map::createmap()
{
  
    int z;
    for(int i=0;i<length;i++)
    {    z=rand()%3;
        if(z==0)
        {
            addblock("road");
        }
        else if(z==1)
        {
            addblock("grass");
        }
        else if(z==2)
        {
            addblock("river");
        }
    }
   
    

     //   blocks[0]->draw();
        
    
}
void map::addblock( std:: string terrainName )
{   block * newblock = new block(_data);
    sf::Vector2f poss(0,0);
    newblock->init(terrainName , poss, true , false);
    blocks.push_back(newblock);

}
map :: map( data* data)
{
    _data = data;
}