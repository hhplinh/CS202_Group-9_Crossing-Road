#include"player.hpp"

void player:: initvariables()
{

}
void player:: initshape()
{
this->shape.setFillColor(sf::Color::Green);
this->shape.setSize(sf::Vector2f(100.f,100.f));
this->texture.loadFromFile("resources/orge.png");
this->p.setTexture(this->texture);

}
/*player::player(std::string path)
{   this->LoadContent(path);
    this->initvariables();
    this->initshape();
}*/
 /* void player:: LoadContent(std::string path , int col , int row )
    {   
        if( !texture.loadFromFile(path)) 
       std:: cout<<" can't load player texture"<<std::endl;
        p.setTexture(texture);
        //p.setSize(Vector2f(100,150));
        
        texture.getSize();
        sf::Vector2u size = texture.getSize();
        size.x /=col;
        size.y /=row;
        p.setTextureRect(sf::IntRect(0,size.y*2,size.x,size.y));


    }
    void player:: drawchar(sf::RenderWindow &window)
    {
        window.draw(p);
    }
    
 
   */
    void player:: move()
    {   sf::Vector2u size = texture.getSize();
        size.x /=4;
        size.y /=4;
        sf::RenderWindow window; 
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {  
        int xtexture=0;
        xtexture=(int)getPosition().x/20%4;
        xtexture*=size.x;

        p.setTextureRect(sf::IntRect(xtexture,size.y*2,size.x,size.y));
        p.move(0.5,0);
        


        
        }
         if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {  p.setTextureRect(sf::IntRect(size.x*3,size.y*3,size.x,size.y));

        int xtexture=0;
        xtexture=(int)getPosition().y/60%4;
        xtexture*=size.x;

        p.setTextureRect(sf::IntRect(xtexture,size.y*3,size.x,size.y));
        p.move(0,-0.5);

        
        }
         if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {  
        p.setTextureRect(sf::IntRect(size.x*3,size.y,size.x,size.y));
        int xtexture=0;
        xtexture=(int)getPosition().x/20%4;
        xtexture*=size.x;

        p.setTextureRect(sf::IntRect(xtexture,size.y,size.x,size.y));
        p.move(-0.5,0);


        
        }
         if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {  
        
        p.setTextureRect(sf::IntRect(0,0,size.x,size.y));

        int ytexture=0;
        ytexture=(int)getPosition().y/20%4;
        ytexture*=size.x;

        p.setTextureRect(sf::IntRect(ytexture,0,size.x,size.y));

        p.move(0,0.5);

        
        }
    }
    void player:: setPosition(int x,int y)
    {
        p.setPosition(x,y);
    
    }
    sf::Vector2f player:: getPosition()
    {
        return p.getPosition();
    }
 player:: player(data* data)
 {
        _data=data;
 }
    
    void player:: init()
    {std::cin>>row>>col;
        this->initshape(   );
        this->initvariables();
        //this->LoadContent(path, col , row);
    

    }
	void player::processInput()
    {
 
    }
	void player::update()
    {

    }
	void player::draw()
    {

    }
     //