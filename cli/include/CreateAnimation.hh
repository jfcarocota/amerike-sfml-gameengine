#include<fstream>
#include<iostream>
#include<string>

void CreateAnimation(char**& argv)
{
  std::string path{argv[2]};
  std::string startFrame{argv[3]};
  std::string endFrame{argv[4]};
  std::string animationDelay{argv[5]};
  std::string currentAnimation{argv[6]};

  std::ofstream* writer{new std::ofstream()};

  writer->open(path + ".anim");
  *writer << startFrame;
  *writer << " " + endFrame;
  *writer << " " + animationDelay;
  *writer << " " + currentAnimation;

  writer->close();

  delete writer;
}
