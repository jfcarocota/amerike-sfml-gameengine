#include<fstream>
#include<iostream>
#include<string>

void CreateGameObject(std::string assetName)
{
  std::string replaceWord{"TemplateName"};

  std::ifstream* reader{new std::ifstream()};
  std::ofstream* writer{new std::ofstream()};

  std::string currentLine{};

  /*Creating HH file*/

  reader->open("cli/templates/GameObjectHH.template");
  writer->open("include/" + assetName + ".hh");

  while(std::getline(*reader, currentLine))
  {
    size_t pos{currentLine.find(replaceWord)};

    if(pos != std::string::npos)
    {
      currentLine.replace(pos, replaceWord.length(), assetName);
    }
    *writer << currentLine << '\n';
  }

  reader->close();
  writer->close();

  /*creating CC file*/

  reader->open("cli/templates/GameObjectCC.template");
  writer->open("src/" + assetName + ".temp");

  while(std::getline(*reader, currentLine))
  {
    size_t pos{currentLine.find(replaceWord)};

    if(pos != std::string::npos)
    {
      currentLine.replace(pos, replaceWord.length(), assetName);
    }
    *writer << currentLine << '\n';
  }

  reader->close();
  writer->close();

  reader->open("src/" + assetName + ".temp");
  writer->open("src/" + assetName + ".cc");

  while(std::getline(*reader, currentLine))
  {
    size_t pos{currentLine.find(replaceWord)};

    if(pos != std::string::npos)
    {
      currentLine.replace(pos, replaceWord.length(), assetName);
    }
    *writer << currentLine << '\n';
  }

  reader->close();
  writer->close();

  std::string removeFile{"src/" + assetName + ".temp"};
  std::remove(removeFile.c_str());


  delete reader;
  delete writer;
}