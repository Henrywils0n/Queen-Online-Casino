#include "app.h"

IMPLEMENT_APP(CasinoApp)

bool CasinoApp::OnInit() {
  if (!wxApp::OnInit()) {
    return false;
  }
  
  wxInitAllImageHandlers();
  
  Game *myGame = new Game();

  return true;
}
