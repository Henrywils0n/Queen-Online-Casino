#pragma once
#include "header.h"
#include "gameframe.h"
#include "imagebutton.h"

class RoulettePanel : public wxPanel {
public:
  RoulettePanel(GameFrame* parent);

  wxStaticText* m_textCtrl;
  ImageButton* exit_button;

private:
  GameFrame* parent;
  void onQuitRoulette(wxCommandEvent &WXUNUSED(event));

  DECLARE_EVENT_TABLE();
};
