#include "../include/blackjackpanel.h"

BEGIN_EVENT_TABLE(BlackjackPanel, wxPanel)
//  EVT_SIZE(BlackjackPanel::OnSize)
    EVT_BUTTON(ID_BJQUIT, BlackjackPanel::onQuitBlackjack)
END_EVENT_TABLE()

BlackjackPanel::BlackjackPanel(GameFrame* par) : wxPanel(par) {  
  parent = par;
  m_textCtrl = new wxTextCtrl(this, wxID_ANY, "ODDS ARE", wxDefaultPosition, wxSize(100, wxDefaultCoord));
  exit_button  = new wxButton(this, ID_BJQUIT,  "MENU");

  wxBoxSizer* menuBox = new wxBoxSizer(wxHORIZONTAL);
  wxBoxSizer* vertBox = new wxBoxSizer(wxVERTICAL);

  menuBox->Add(m_textCtrl,1, wxSTRETCH_NOT);
  menuBox->Add(exit_button, 1, wxSTRETCH_NOT);

  vertBox->Add(menuBox, 1, wxEXPAND);
  
  SetSizer(vertBox);
  vertBox->SetSizeHints(this);
}

void BlackjackPanel::onQuitBlackjack(wxCommandEvent &WXUNUSED(event)){
  parent->returnToMenu();
}
