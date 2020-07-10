#include "inputView.h"
#include <stdio.h>

string activeTextLine;
int textOffset = 0;
int textSelector = 0;
int exitInput = 0;

void handleKey(){
  short key = 0;
  while (key < 1){
    key = getKey();
  }

  switch (key){
    case 'A' + 'R':
      if (textSelector + textOffset == activeTextLine.length() - 1){
        break;
      }
      if (textSelector == 29){
        textOffset++;
        break;
      }
      textSelector++;
      break;
    case 'A' + 'L':
      if (textSelector == 0 && textOffset > 0){
        textOffset--;
      }
      if (textSelector == 0)break; 
      textSelector--;
      break;
    case 'A' + 'U':
      switch (activeTextLine[textOffset + textSelector]){
      case '9':
        activeTextLine[textOffset + textSelector] = 'A';
        break;
      case 'Z':
        activeTextLine[textOffset + textSelector] = ' ';
        break;
      case ' ':
        activeTextLine[textOffset + textSelector] = '0';
        break;
      default:
        activeTextLine[textOffset + textSelector]++;
      }  
      break;
    case 'A' + 'D':
      switch (activeTextLine[textOffset + textSelector]){
      case '0':
        activeTextLine[textOffset + textSelector] = ' ';
        break;
      case 'A':
        activeTextLine[textOffset + textSelector] = '9';
        break;
      case ' ':
        activeTextLine[textOffset + textSelector] = 'Z';
        break;
      default:
        activeTextLine[textOffset + textSelector]--;
      }  
      break;
    case 'A':
      exitInput = 1;
      break;
    case 'B':
      auto iter = activeTextLine.begin();
      int sz = textOffset + textSelector;
      activeTextLine.insert(iter+sz+1,' ');
      break;
  }
  
}

void showInputView(){
  int sz = 0;
  //U
  for (char c : activeTextLine){
    if (sz < textOffset){
      sz++;
      continue;
    }
    if (sz == 30 + textOffset)break;
    iprintf("%c",c);
    sz++;
  }
  if (sz < 30){
    iprintf("\n");
  }
  //L
  for (int i = 0;i < 30;i++){
    if (i == textSelector){
      iprintf("-");
    }
    else {
      iprintf(" ");
    }
  }
}

string inputView(string textLine){
  activeTextLine = textLine;
  while (exitInput < 1)
  {
    iprintf("\x1b[2J");
    showInputView();
    handleKey();
  }
  exitInput = 0;
  textSelector = 0;
  return activeTextLine;
}