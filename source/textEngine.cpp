#include "textEngine.h"

TextEngine::TextEngine(){
  string text = " ";
  this->textLines.push_back(text);
}

void TextEngine::addText(string text){
  this->textLines.push_back(text);
}

void TextEngine::insertText(int i, string text){
  auto iter = this->textLines.begin() + i;
  this->textLines.insert(iter,text);
}

void TextEngine::editText(int i, string text){
  this->textLines[i] = text;
}

vector<string> TextEngine::getTextLines(){
  return this->textLines;
}

int TextEngine::size(){
  return this->textLines.size();
}