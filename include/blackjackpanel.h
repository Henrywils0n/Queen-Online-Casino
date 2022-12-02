#pragma once
#include "header.h"
#include "gameframe.h"
#include "imagebutton.h"

class BlackjackPanel : public wxPanel {
public:
  BlackjackPanel(GameFrame* parent);

  wxStaticText* m_textCtrl;
  ImageButton* exit_button;

private:
  GameFrame* parent;
  void onQuitBlackjack(wxCommandEvent &WXUNUSED(event));

  DECLARE_EVENT_TABLE();
};
