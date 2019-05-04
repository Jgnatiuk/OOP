#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>
#include "snakeObjects.h"
using namespace sf;

int N = 30, M = 20;
int size = 16;
int w = size * N;
int h = size * M;
bool isDead = false;

int dir, num = 4;

// Declare snake object
Snake s[100];

// Declare fruit object
Fruit f;

struct Map
{


  Texture t1, t2, t3, gameOver;
  Sprite sprite1, sprite2, sprite3, gameOverSprite;
  RenderWindow window;

  Map()
   : window(VideoMode(w, h), "Snake Game!")
  {}

  void loadAssets()
  {
    t1.loadFromFile("images/white.png");
    t2.loadFromFile("images/red.png");
    t3.loadFromFile("images/green.png");
    gameOver.loadFromFile("images/GAMEOVER.png");

    sprite1.setTexture(t1);
    sprite2.setTexture(t2);
    sprite3.setTexture(t3);

    gameOverSprite.setTexture(gameOver);
  }

  void buildMap()
  {
    ////// draw  ///////
    window.clear();

    ///// draw playing area /////
    for (int i = 0; i < N; i++)
      for (int j = 0; j < M; j++) {
        sprite1.setPosition(i * size, j * size);
        window.draw(sprite1);
      }

    ///// draw snake /////
    for (int i = 0; i < num; i++)
    {
      sprite2.setPosition(s[i].x * size, s[i].y * size);
      window.draw(sprite2);
      std::cout << s[i].x << " " << s[i].y << std::endl;
    }

    ///// draw fruit /////
    sprite3.setPosition(f.x * size, f.y * size);
    window.draw(sprite3);

    window.display();
  }

  void death()
  {
    ////// draw  ///////
    window.clear();

    ///// draw playing area /////
    for (int i = 0; i < N; i++)
      for (int j = 0; j < M; j++)
      {
        sprite1.setPosition(i * size, j * size);
        window.draw(sprite1);
      }

      ///// draw fruit /////
    sprite3.setPosition(f.x * size, f.y * size);
    window.draw(sprite3);

      ///// draw game over button /////
    gameOverSprite.setPosition(w/4, h/3);
    window.draw(gameOverSprite);

    window.display();
  }
  void pollWindowEvent()
  {

    Event e;
    while (window.pollEvent(e))
    {
        if (e.type == Event::Closed)
            window.close();

        if (e.type == Event::MouseButtonPressed)
        {
            if(e.mouseButton.button == Mouse::Left)
            {
                isDead = false;
                num = 4;
                dir = 0;
                for(int j = 0; j < num; j++)
                {
                    s[j].x = 0;
                    s[j].y = 0;
                }
            }

        }
    }
  }



};



int getDirection()
{
    if (Keyboard::isKeyPressed(Keyboard::Left))
    {
      // if going right, can't go left, keep going right
      if(dir == 2) dir = 2;
      // else go left
      else dir = 1;
    }
    if (Keyboard::isKeyPressed(Keyboard::Right))
    {
      // if going left, can't go right, keep going left
      if(dir == 1) dir = 1;
      // else go right
      else dir = 2;
    }
    if (Keyboard::isKeyPressed(Keyboard::Up))
    {
      // if going down, can't go up, keep going down
      if(dir == 0) dir = 0;
      // else go up
      else dir = 3;
    }
    if (Keyboard::isKeyPressed(Keyboard::Down))
    {
      // if going up, can't go down, keep going up
      if(dir == 3) dir = 3;
      // else go down
      else dir = 0;
    }
};
void Tick(bool &death, int direction)
{

  for (int i = num; i > 0; --i)
  {
    s[i].x = s[i - 1].x;
    s[i].y = s[i - 1].y;
  }

  if (dir == 0)
    s[0].y += 1;
  if (dir == 1)
    s[0].x -= 1;
  if (dir == 2)
    s[0].x += 1;
  if (dir == 3)
    s[0].y -= 1;

  if ((s[0].x == f.x) && (s[0].y == f.y))
  {
    num++;
    f.x = rand() % N;
    f.y = rand() % M;
    f.fruitTimer = 0;
  }

  if (s[0].x > N)
  {

    death = true;
  }
  if (s[0].x < 0)
  {
    death = true;
  }
  if (s[0].y > M)
  {
    death = true;
  }
  if (s[0].y < 0)
  {
    death = true;
  }

  for (int i = 1; i < num; i++)
    if (s[0].x == s[i].x && s[0].y == s[i].y)
      death = true;



  // Increment fruit timer
  f.fruitTimer += 1;

  // If fruit has not been obtained in 5 seconds, regenerate fruit
  if(f.fruitTimer == 50)
  {
    f.x = rand() % N;
    f.y = rand() % M;
    f.fruitTimer = 0;
  }

}

void reset(Map &map, bool&isDead)
{
    isDead = false;

}

int
main()
{
  srand(time(0));

  Map gameGrid;

  gameGrid.loadAssets();
  gameGrid.buildMap();


  Clock clock;
  float timer = 0, delay = 0.1;

  f.x = 10;
  f.y = 10;

  while (gameGrid.window.isOpen())
  {
    float time = clock.getElapsedTime().asSeconds();
    clock.restart();
    timer += time;

    gameGrid.pollWindowEvent();

    if(isDead == false)
    {

        if (timer > delay)
        {
            timer = 0;
            Tick(isDead, getDirection());
        }

        gameGrid.buildMap();

    }

    else

        gameGrid.death();

  }

  return 0;
}
