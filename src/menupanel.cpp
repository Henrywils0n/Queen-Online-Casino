#include "../include/menupanel.h"

BEGIN_EVENT_TABLE(MenuPanel, wxPanel)
  EVT_BUTTON(ID_ROULETTE, MenuPanel::OnPlayRoulette)
  EVT_BUTTON(ID_BLACKJACK, MenuPanel::OnPlayBlackjack)
  EVT_BUTTON(ID_ODDSARE, MenuPanel::OnPlayOddsAre)
  EVT_SHOW(MenuPanel::updateBalance)
END_EVENT_TABLE()

MenuPanel::MenuPanel(GameFrame* par) : wxPanel(par) {
  parent = par;
  
  wxString gametitle = "../resources/gametitle.png";
  
  m_title = new ImagePanel(this, gametitle, wxBITMAP_TYPE_PNG);
  score_static = new wxStaticText(this, ID_MENUSCORE, "CURRENT SCORE: 500", wxDefaultPosition, wxSize(100, wxDefaultCoord));
  
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
  
  vertBox->Add(m_title, 10, wxEXPAND);
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

void MenuPanel::updateBalance(wxShowEvent &WXUNUSED(event)) {
    if (score_static) {
      std::wstringstream contents;
      contents << "CURRENT SCORE: " << parent->getBalance();
      score_static->SetLabel(contents.str());
    }
}