#pragma once
#include "header.h"

class GameFrame : public wxFrame {
public:
  GameFrame();
  
  wxPanel* menuPanel;
  wxPanel* roulettePanel;
  wxPanel* blackjackPanel;
  wxPanel* oddsArePanel;
  
  void setBalance(int val);
  int  getBalance();
  
  void playRoulette();
  void playBlackjack();
  void playOddsAre();
  void returnToMenu();
  
  void OnAbout(wxCommandEvent &event);
  void OnQuit(wxCommandEvent &event);
  void OnReset(wxCommandEvent &event);

private:
  wxDECLARE_DYNAMIC_CLASS(GameFrame);
  wxDECLARE_EVENT_TABLE();
  
  int balance;
};
