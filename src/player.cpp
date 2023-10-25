#include"player.hpp"
   void player:: LoadContent(string path )
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
    void player:: drawchar(RenderWindow &window)
    {
        window.draw(p);
    }
    
   player:: player(string path)
    {
        LoadContent(path);
    }
   
    void player:: move()
    {   Vector2u size = texture.getSize();
        size.x /=4;
        size.y /=4;
        RenderWindow window; 
        if(Keyboard::isKeyPressed(Keyboard::Right))
        {  
        int xtexture=0;
        xtexture=(int)getPosition().x/20%4;
        xtexture*=size.x;

        p.setTextureRect(IntRect(xtexture,size.y*2,size.x,size.y));
        p.move(5,0);
        


        
        }
         if(Keyboard::isKeyPressed(Keyboard::Up))
        {  p.setTextureRect(IntRect(size.x*3,size.y*3,size.x,size.y));

        int xtexture=0;
        xtexture=(int)getPosition().y/60%4;
        xtexture*=size.x;

        p.setTextureRect(IntRect(xtexture,size.y*3,size.x,size.y));
        p.move(0,-5);

        
        }
         if(Keyboard::isKeyPressed(Keyboard::Left))
        {  
        p.setTextureRect(IntRect(size.x*3,size.y,size.x,size.y));
        int xtexture=0;
        xtexture=(int)getPosition().x/20%4;
        xtexture*=size.x;

        p.setTextureRect(IntRect(xtexture,size.y,size.x,size.y));
        p.move(-5,0);


        
        }
         if(Keyboard::isKeyPressed(Keyboard::Down))
        {  
        
        p.setTextureRect(IntRect(0,0,size.x,size.y));

        int ytexture=0;
        ytexture=(int)getPosition().y/20%4;
        ytexture*=size.x;

        p.setTextureRect(IntRect(ytexture,0,size.x,size.y));

        p.move(0,5);

        
        }
    }
    void player:: setPosition(int x,int y)
    {
        p.setPosition(x,y);
    
    }
    Vector2f player:: getPosition()
    {
        return p.getPosition();
    }
  