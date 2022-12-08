#include "../include/menupanel.h"

BEGIN_EVENT_TABLE(MenuPanel, wxPanel)
  EVT_BUTTON(ID_ROULETTE, MenuPanel::OnPlayRoulette)
  EVT_BUTTON(ID_BLACKJACK, MenuPanel::OnPlayBlackjack)
  EVT_BUTTON(ID_ODDSARE, MenuPanel::OnPlayOddsAre)
END_EVENT_TABLE()

MenuPanel::MenuPanel(GameFrame* par) : wxPanel(par) {
  parent = par;
  
  wxString gametitle = "../resources/gametitle.png";
  
  m_title = new ImagePanel(this, gametitle, wxBITMAP_TYPE_PNG);
  wxBoxSizer* titleBox = new wxBoxSizer(wxHORIZONTAL);

  titleBox->AddSpacer(30);
  titleBox->Add(m_title, 1, wxEXPAND);
  titleBox->AddSpacer(30);

  roulette_button  = new wxButton(this, ID_ROULETTE,  "PLAY ROULETTE");
  blackjack_button = new wxButton(this, ID_BLACKJACK, "PLAY BLACKJACK");
  oddsare_button   = new wxButton(this, ID_ODDSARE,   "PLAY ODDS ARE");
  
  // Set up the sizers
  wxBoxSizer* inputBox = new wxBoxSizer(wxHORIZONTAL);
  wxBoxSizer* vertBox = new wxBoxSizer(wxVERTICAL);

  inputBox->AddSpacer(20);
  inputBox->Add(roulette_button,  1, wxEXPAND);
  inputBox->AddSpacer(20);
  inputBox->Add(blackjack_button, 1, wxEXPAND);
  inputBox->AddSpacer(20);
  inputBox->Add(oddsare_button,   1, wxEXPAND);
  inputBox->AddSpacer(20);
  
  vertBox->AddSpacer(30);
  vertBox->Add(titleBox, 10, wxEXPAND);
  vertBox->Add(inputBox, 1, wxEXPAND);
  vertBox->AddSpacer(20);
  
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