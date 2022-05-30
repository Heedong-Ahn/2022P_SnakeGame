#include "GameScene.h"
#include "Snake.h"
#include "map.h"
#include "Position.h"

#include <unistd.h>
#include <vector>
#include <ncurses.h>
using namespace std;

map *m;
Snake *snake;

GameScene::GameScene(){
  srand(time(NULL));

  player = new Player();

  //mapManager를 먼저 생성시켜줘야함
  m = new map();
  // m->Load();

  snake = new Snake();

  InitGameWindow();
  refresh();
}

GameScene::~GameScene()
{
  //delete m;
  nodelay(stdscr, false);
  endwin();
}

// initialise the game window
void GameScene::InitGameWindow()
{
  initscr(); // initialise the screen
  nodelay(stdscr, TRUE);
  keypad(stdscr, true);                  // initialise the keyboard: we can use arrows for directions
  noecho();                              // user input is not displayed on the screen
  curs_set(0);                           // cursor symbol is not not displayed on the screen (Linux)
  return;
}

void GameScene::Render()
{
  // format->Render();

  for (int i = 0; i < HEIGHT; i++)
  {
    for (int j = 0; j < WIDTH; j++)
    {
      switch (m->data[i][j])
      {
      case '0':
        mvaddch(i, j, ' ');
        break;
      case '1':
        mvaddch(i, j, '-');
        break;
      case '2':
        mvaddch(i, j, 'X');
        break;
      case '3':
        mvaddch(i, j, 'H');
        break;
      case '4':
        mvaddch(i, j, 'B');
        break;
      case '5':
        mvaddch(i, j, 'G');
        break;
      case '6':
        mvaddch(i, j, 'P');
        break;
      case '7':
        mvaddch(i, j, '?');
        break;
      case '8':
        mvaddch(i, j, ' ');
      }
    }
  }

  refresh();
}

// void GameScene::Update(float eTime)
// {
//   //여기에서 chagneScene을 걸어준다.
//   if (isClear())
//   {
//     stage->nowStage++;
//     ChangeScene(new GameScene());
//   }
//
//   player->SetLengthScore(snake->entire.size());
//   player->SetTotalScore(stage->nowStage);
//
//   snake->Update(eTime);
//   if (snake->IsCollision())
//   {
//     ProcessCollision();
//   }
//   if (snake->isDied)
//   {
//     ChangeScene(new GameOverScene());
//   }
//   snake->PushData();
//   format->Update(eTime);
//   itemManager->Update(eTime);
//   gateManager->Update(eTime);
//   //* float eTime test code *//
//   // move((maxheight-2)/2,(maxwidth-5)/2);
//   // printw("%f",eTime);
//   usleep(150000);
// }
