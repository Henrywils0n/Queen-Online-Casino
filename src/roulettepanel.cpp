#include "../include/roulettepanel.h"

BEGIN_EVENT_TABLE(RoulettePanel, wxPanel)
//  EVT_BUTTON(RoulettePanel::paintEvent)
//  EVT_BUTTON(RoulettePanel::OnSize)
    EVT_BUTTON(ID_RLQUIT, RoulettePanel::onQuitRoulette)
END_EVENT_TABLE()

RoulettePanel::RoulettePanel(GameFrame* par) : wxPanel(par) {
  parent = par;

  m_textCtrl = new wxTextCtrl(this, wxID_ANY, "ROULETTE", wxDefaultPosition, wxSize(100, wxDefaultCoord));
  exit_button  = new wxButton(this, ID_RLQUIT,  "MENU");
  
  wxBoxSizer* menuBox = new wxBoxSizer(wxHORIZONTAL);
  wxBoxSizer* vertBox = new wxBoxSizer(wxVERTICAL);

  menuBox->Add(m_textCtrl, 1, wxSTRETCH_NOT);
  menuBox->Add(exit_button, 1, wxSTRETCH_NOT);

  vertBox->Add(menuBox, 7, wxEXPAND);

  SetSizer(vertBox);
  vertBox->SetSizeHints(this);
}

void RoulettePanel::onQuitRoulette(wxCommandEvent &WXUNUSED(event)){
  parent->returnToMenu();
}