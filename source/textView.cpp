#include <stdio.h>
#include <string>
#include <vector>
#include "textView.h"
#include "keyapi.h"
#include "textEngine.h"
#include "inputView.h"

int line = 1;
int selector = 1;
int lastLine = 0;
TextEngine activeTX;

static int countLines(string text){
  int lines;
  if ((text.length() + 5) % 33 == 0){
    lines = (text.length() + 5) / 33;
  }
  else {
    lines = (text.length() + 5) / 33;
    lines++;
  }
  return lines;
}

static void showText(){
  iprintf("\x1b[2J");
  int activeLine = 1;
  int renderedLines = 0;
  bool breakFlag = false;
  for (string text : activeTX.getTextLines()){
    if (activeLine < line){
      activeLine++;
      continue;
    }
    renderedLines+= countLines(text);
    if (renderedLines > 18){
      lastLine = activeLine;
      if (selector > lastLine)selector = lastLine;
      breakFlag = true;
      }
    if (selector == activeLine){
      iprintf("*%d:%s\n",activeLine,text.c_str());
    }
    else {
      iprintf("%d:%s\n",activeLine,text.c_str());
    }
    if (breakFlag)break;
    activeLine++;
  }
  //Debug
  //iprintf("\x1b[0;5HDebug:L %d|S %d|LL %d",line,selector,lastLine);
}

static void keyboardHandler(){
  short key = 0;
  while (key < 1){
    key = getKey();
  }

  switch (key){
    case 'A' + 'U':
      if (selector == 1)break;
      if (selector == line){
        line--;
      }
      selector--;
      break;
    case 'A' + 'D':
      if (selector == activeTX.size())break;
      if (selector == lastLine){
        line++;
      }
      selector++;
      break;
    case 'B':
      //activeTX.addText("");
      activeTX.insertText(selector," ");
      selector++;
      break;
    case 'A':
      //activeTX.addText("");
      activeTX.editText(selector-1,inputView(activeTX.getTextLines()[selector-1]));
      break;
    default:
      break;
  }
}

//H-30
//V-19

void textView(){
  while (true)
  {
  showText();
  keyboardHandler();
  }
}

