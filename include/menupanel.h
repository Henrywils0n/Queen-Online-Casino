#pragma once
#include "imagepanel.h"
#include "gameframe.h"
#include <sstream>

class MenuPanel : public wxPanel {
public:
  MenuPanel(GameFrame* parent);

  ImagePanel* m_title;
  wxButton* roulette_button;
  wxButton* blackjack_button;
  wxButton* oddsare_button;
  wxStaticText* score_static;
  
  void updateBalance(wxShowEvent &event);
  
private:
  GameFrame* parent;
  
  void OnPlayRoulette(wxCommandEvent &event);
  void OnPlayBlackjack(wxCommandEvent &event);
  void OnPlayOddsAre(wxCommandEvent &event);

  DECLARE_EVENT_TABLE()
};
