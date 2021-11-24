#include<iostream>
#include "CreateGameObject.hh"
#include "CreateAnimation.hh"
#include "CreateTileGroup.hh"

int main(int argc, char** argv)
{
  std::string action{argv[1]};

  switch (argc)
  {
  case 3:
    if(action == "creategameobject")
    {
      CreateGameObject(argv[2]);
    }
    if(action == "createtilegroup")
    {
      CreateTileGroup(argv[2]);
    }
    break;
  case 7:
    if(action == "createanimation")
    {
      CreateAnimation(argv);
    }
  break;
  default:
    break;
  }

  return 0;
}