#pragma once
#include "header.h"
#include "gameframe.h"

class RoulettePanel : public wxPanel {
public:
  RoulettePanel(GameFrame* parent);

  wxTextCtrl* m_textCtrl;
  wxButton* exit_button;

private:
  DECLARE_EVENT_TABLE();
  
  GameFrame* parent;

  void onQuitRoulette(wxCommandEvent &WXUNUSED(event));

};
