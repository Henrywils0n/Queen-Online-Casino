#include "../include/menupanel.h"

BEGIN_EVENT_TABLE(MenuPanel, wxPanel)
  EVT_BUTTON(ID_ROULETTE, MenuPanel::OnPlayRoulette)
  EVT_BUTTON(ID_BLACKJACK, MenuPanel::OnPlayBlackjack)
  EVT_BUTTON(ID_ODDSARE, MenuPanel::OnPlayOddsAre)
END_EVENT_TABLE()

MenuPanel::MenuPanel(GameFrame* par) : wxPanel(par) {
  parent = par;
  
  wxString dir = "../resources/gametitle.png";
  
  m_title = new ImagePanel(this, dir, wxBITMAP_TYPE_PNG);
  
  roulette_button  = new wxButton(this, ID_ROULETTE,  "PLAY ROULETTE");
  blackjack_button = new wxButton(this, ID_BLACKJACK, "PLAY BLACKJACK");
  oddsare_button   = new wxButton(this, ID_ODDSARE,   "PLAY ODDS ARE");
  
  m_textCtrl = new wxTextCtrl(this, wxID_ANY, "Button has never been clicked.", wxDefaultPosition, wxSize(200, wxDefaultCoord));
  
  // Set up the sizers
  wxBoxSizer* inputBox = new wxBoxSizer(wxHORIZONTAL);
  wxBoxSizer* vertBox = new wxBoxSizer(wxVERTICAL);
  
  inputBox->Add(roulette_button,  1, wxEXPAND);
  inputBox->Add(blackjack_button, 1, wxEXPAND);
  inputBox->Add(oddsare_button,   1, wxEXPAND);
  
  vertBox->Add(m_title, 10, wxEXPAND);
  vertBox->Add(inputBox, 1, wxEXPAND);
  vertBox->Add(m_textCtrl, 1, wxEXPAND);
  
  SetSizer(vertBox);
  
  vertBox->SetSizeHints(this);
}

void MenuPanel::OnPlayRoulette(wxCommandEvent &WXUNUSED(event)) {
  parent->playRoulette();
}

void MenuPanel::OnPlayBlackjack(wxCommandEvent &WXUNUSED(event)) {
  parent->playBlackjack();
}

void MenuPanel::OnPlayOddsAre(wxCommandEvent &WXUNUSED(event)) {
  parent->playOddsAre();
}
