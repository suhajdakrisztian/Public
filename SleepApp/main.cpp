#include <Windows.h>
#include <iostream>
#include <chrono> 
#include <ctime> 
#include <iostream> 

using namespace std;

void MouseMove() {

  unsigned int fScreenWidth = ::GetSystemMetrics( SM_CXSCREEN )-1;
  unsigned int fScreenHeight = ::GetSystemMetrics( SM_CYSCREEN )-1;

  unsigned int nextWidth = rand() % (unsigned int)fScreenWidth + 1;
  unsigned int nextHeight = rand() % (unsigned int)fScreenHeight + 1;

  SetCursorPos(nextWidth, nextHeight);
  Sleep(rand() % 5000 + 1000);
}

void Greetings() {

  auto timenow = chrono::system_clock::to_time_t(chrono::system_clock::now()); 
  
  cout << "SleepApp is running" << endl;
  cout << "Press CTRL + C for exit" << endl;
  cout << "You are idle since: " << ctime(&timenow);
}

int main() {

  Greetings();

  while(true)
    MouseMove();
}
