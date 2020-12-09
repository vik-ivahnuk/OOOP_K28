#pragma once

#include <SFML/Graphics.hpp>
#include <time.h>
using namespace sf;

struct point
{
    int x, y;
};

class Game {

private:
    Texture t1, t2, t3, t4, t5, t6;
    int x, y, h;
    float dx, dy;
    
    
    point plat[20];
public:
	void menu() {
		RenderWindow app(VideoMode(400, 533), "Doodle Game devolop by viktor ivahnuk");
		app.setFramerateLimit(60);


		t1.loadFromFile("images/background.png");
		t2.loadFromFile("images/platform.png");
		t3.loadFromFile("images/doodle.png");

		t4.loadFromFile("images/New_game_Button.png");

        Sprite sBackground(t1), sPlat(t2), sPers(t3), new_game(t4);

   


        int Game=0;
		while (app.isOpen()) {
           
            Event e;
            while (app.pollEvent(e))
            {
                if (e.type == Event::Closed)
                    app.close();
            }
            if (Game == 0) {
                for (int i = 0; i < 10; i++)
                {
                    plat[i].x = rand() % 400;
                    plat[i].y = rand() % 533;
                }

                x = 100, y = 100, h = 200;
                dx = 0, dy = 0;
                srand(time(0));
                app.clear();
                new_game.setPosition(25, 300);
                app.draw(new_game);
            }
            if (Keyboard::isKeyPressed(Keyboard::Escape))
                Game = -1;
            if (Keyboard::isKeyPressed(Keyboard::Enter))
                Game = 1;

            if (Game > 0) {
                app.clear();
              Game= start_game(app,sPers,sBackground,sPlat);
            }
            if (Game < 0)
                break;
      
            app.display();

		}
		app.close();

	}

	int start_game(RenderWindow& app,Sprite sPers,Sprite sBackground,Sprite sPlat) {
    

        if (Keyboard::isKeyPressed(Keyboard::Right)) x += 3;
        if (Keyboard::isKeyPressed(Keyboard::Left)) x -= 3;
        if (Keyboard::isKeyPressed(Keyboard::Escape))   app.close();

        dy += 0.2;
        y += dy;
        if (y > 500)  dy = -10;

        if (y < h)
            for (int i = 0; i < 10; i++)
            {
                y = h;
                plat[i].y = plat[i].y - dy;
                if (plat[i].y > 533) { plat[i].y = 0; plat[i].x = rand() % 400; }
            }

        for (int i = 0; i < 10; i++)
            if ((x + 50 > plat[i].x) && (x + 20 < plat[i].x + 68)
                && (y + 70 > plat[i].y) && (y + 70 < plat[i].y + 14) && (dy > 0))  dy = -10;

        sPers.setPosition(x, y);



        app.draw(sBackground);
        app.draw(sPers);
        for (int i = 0; i < 10; i++)
        {
            sPlat.setPosition(plat[i].x, plat[i].y);
            app.draw(sPlat);
        }
    
     
        if (sPers.getPosition().y >500) {
       
            return 0;
        }
        else return 1;


	}

	

};
