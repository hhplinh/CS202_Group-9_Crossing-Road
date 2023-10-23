#include"player.hpp"
   void player:: LoadContent(string path)
    {   
        if( !texture.loadFromFile(path)) 
        cout<<" can't load player texture"<<endl;
        p.setTexture(texture);
        //p.setSize(Vector2f(100,150));
        
        texture.getSize();
        Vector2u size = texture.getSize();
        size.x /=4;
        size.y /=4;
        p.setTextureRect(IntRect(0,size.y*2,size.x,size.y));


    }
    void player:: draw(RenderWindow &window)
    {
        window.draw(p);
    }
    
   player:: player(string path)
    {
        LoadContent(path);
    }
   
    void player:: move(int x,int y)
    {
        p.move(x,y); 
    }
    void player:: setPosition(int x,int y)
    {
        p.setPosition(x,y);
    
    }
    Vector2f player:: getPosition()
    {
        return p.getPosition();
    }
  