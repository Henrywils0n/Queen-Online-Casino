#include "../include/blackjackpanel.h"

BEGIN_EVENT_TABLE(BlackjackPanel, wxPanel)
//  EVT_SIZE(BlackjackPanel::OnSize)
    EVT_BUTTON(ID_BJQUIT, BlackjackPanel::onQuitBlackjack)
END_EVENT_TABLE()

BlackjackPanel::BlackjackPanel(GameFrame* par) : wxPanel(par) {  
  parent = par;
  wxString backpng = "../resources/back_button.png";

  m_textCtrl = new wxStaticText(this, wxID_ANY, "BLACKJACK", wxDefaultPosition, wxSize(100, wxDefaultCoord));
  exit_button  = new ImageButton(this, ID_BJQUIT,  "MENU", backpng, wxBITMAP_TYPE_PNG, 40, 40);

  wxBoxSizer* menuBox = new wxBoxSizer(wxHORIZONTAL);
  wxBoxSizer* vertBox = new wxBoxSizer(wxVERTICAL);

  menuBox->Add(exit_button, 1, wxSHAPED);
  menuBox->Add(m_textCtrl,1, wxSTRETCH_NOT);
  
  vertBox->Add(menuBox, 7, wxEXPAND);
  
  SetSizer(vertBox);
  vertBox->SetSizeHints(this);
}

void BlackjackPanel::onQuitBlackjack(wxCommandEvent &WXUNUSED(event)){
  parent->returnToMenu();
}
