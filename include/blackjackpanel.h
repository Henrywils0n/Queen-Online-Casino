#pragma once
#include "header.h"
#include "gameframe.h"

class BlackjackPanel : public wxPanel {
public:
  BlackjackPanel(GameFrame* parent);
  

  wxTextCtrl* m_textCtrl;
  wxButton* exit_button;

private:
  GameFrame* parent;
  void onQuitBlackjack(wxCommandEvent &WXUNUSED(event));

  DECLARE_EVENT_TABLE();
};
