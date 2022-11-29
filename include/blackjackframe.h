#pragma once
#include "game.h"

class BlackjackFrame: public wxFrame {
public:
  BlackjackFrame();
  
  void OnAbout(wxCommandEvent &event);
  void OnQuit(wxCommandEvent &event);
  void setRouter(Game* router);
  
  /*
  ImagePanel* m_title;
  wxButton* roulette_button;
  wxButton* blackjack_button;
  wxButton* oddsare_button;
  wxTextCtrl* m_textCtrl;
   */
  
private:
  wxDECLARE_DYNAMIC_CLASS(BlackjackFrame);
  wxDECLARE_EVENT_TABLE();
  Game *router;
};

enum {
  ID_BJQUIT,
  ID_BJABOUT,
};
