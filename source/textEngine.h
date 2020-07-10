#pragma once

#include <string>
#include <vector>

using namespace std;

class TextEngine {
  private:
    vector<string> textLines;

  public:
    TextEngine();
    void addText(string text);
    void insertText(int i, string text);
    void editText(int i, string text);
    vector<string> getTextLines();
    int size();
};
