#include "../include/app.h"
#include "../include/gameframe.h"

IMPLEMENT_APP(CasinoApp)

bool CasinoApp::OnInit() {
  if (!wxApp::OnInit()) {
    return false;
  }
  
  wxInitAllImageHandlers();
  
  GameFrame *myGame = new GameFrame();
  myGame->Show(true);

  return true;
}
