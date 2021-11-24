#include<fstream>
#include<iostream>
#include<string>

void CreateTileGroup(std::string path)
{
  std::ofstream* writer{new std::ofstream()};

  writer->open(path + ".grid");

  writer->close();

  delete writer;
}