#include "../include/gameframe.h"
#include "../include/menupanel.h"
#include "../include/roulettepanel.h"
#include "../include/oddsarepanel.h"
#include "../include/blackjackpanel.h"

wxIMPLEMENT_DYNAMIC_CLASS(GameFrame, wxFrame);
BEGIN_EVENT_TABLE(GameFrame, wxFrame)
  EVT_MENU(ID_ABOUT, GameFrame::OnAbout)
  EVT_MENU(ID_QUIT, GameFrame::OnQuit)
  EVT_MENU(ID_RESETBAL, GameFrame::OnReset)
END_EVENT_TABLE()

GameFrame::GameFrame() : wxFrame(nullptr, wxID_ANY, "Casino Game", wxPoint(30, 30), wxSize(1000, 700)) {
  
  // Set the menu bar for the entire application.
  wxMenuBar *menu_bar = new wxMenuBar();
  
  wxMenu *menuImage = new wxMenu;
  menuImage->Append( ID_ABOUT, "&About\tF1");
  menuImage->AppendSeparator();
  menuImage->Append( ID_QUIT, "&Exit\tCtrl-Q");
  menuImage->Append( ID_RESETBAL, "&Reset Balance");
  menu_bar->Append(menuImage, "&Menu");
  SetMenuBar(menu_bar);
  
  // Initialize balance. (This will need to change to use File I/O
  balance = 500;

//  roulettePanel = new RoulettePanel();
//  blackjackPanel = new BlackjackPanel();
//  oddsArePanel = new OddsArePanel();
  
  // Create and show the menu panel.
  menuPanel = new MenuPanel(this);
  blackjackPanel = new BlackjackPanel(this);
  roulettePanel = new RoulettePanel(this);
  oddsArePanel = new OddsArePanel(this);

  menuPanel->SetBackgroundColour(wxColour(46, 103, 40, wxALPHA_OPAQUE));
  blackjackPanel->SetBackgroundColour(wxColour(46, 103, 40, wxALPHA_OPAQUE));
  roulettePanel->SetBackgroundColour(wxColour(46, 103, 40, wxALPHA_OPAQUE));
  oddsArePanel->SetBackgroundColour(wxColour(46, 103, 40, wxALPHA_OPAQUE));

  menuPanel->Show(true);
  blackjackPanel->Show(false);
  roulettePanel->Show(false);
  oddsArePanel->Show(false);
  
  wxBoxSizer* gameBox = new wxBoxSizer(wxVERTICAL);
  
  gameBox->Add(menuPanel, 1, wxEXPAND);
  gameBox->Add(blackjackPanel, 1, wxEXPAND);
  gameBox->Add(roulettePanel, 1, wxEXPAND);
  gameBox->Add(oddsArePanel, 1, wxEXPAND);
  
  SetSizer(gameBox);
  
  gameBox->SetSizeHints(this);
}

void GameFrame::OnQuit(wxCommandEvent &WXUNUSED(event)) {
  Close(true);
}

void GameFrame::OnAbout(wxCommandEvent &WXUNUSED(event)) {
  wxArrayString array;
  
  array.Add("Casino Game");
  array.Add("(c) Team 23 Montreal 2022");
  
  (void)wxMessageBox(wxJoin(array, '\n'), "About Game", wxICON_INFORMATION | wxOK );
}

void GameFrame::OnReset(wxCommandEvent &WXUNUSED(event)) {
  balance = 500;
}

void GameFrame::setBalance(int val) {
  balance = val;
}
int  GameFrame::getBalance() {
  return balance;
}

void GameFrame::playRoulette() {
  menuPanel->Show(false);
  roulettePanel->Show(true);
}
void GameFrame::playBlackjack() {
  menuPanel->Show(false);
  blackjackPanel->Show(true);
}
void GameFrame::playOddsAre() {
  menuPanel->Show(false);
  oddsArePanel->Show(true);
}

void GameFrame::returnToMenu() {
  oddsArePanel->Show(false);
  roulettePanel->Show(false);
  blackjackPanel->Show(false);
  menuPanel->Show(true);
}
