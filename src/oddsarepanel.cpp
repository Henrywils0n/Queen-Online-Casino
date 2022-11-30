#include "../include/oddsarepanel.h"

BEGIN_EVENT_TABLE(OddsArePanel, wxPanel)
  EVT_BUTTON(ID_OAQUIT, OddsArePanel::onExitOddsAre)
END_EVENT_TABLE()

OddsArePanel::OddsArePanel(GameFrame* par) : wxPanel(par) {
  parent = par;
  m_textCtrl = new wxTextCtrl(this, wxID_ANY, "ODDS ARE", wxDefaultPosition, wxSize(100, wxDefaultCoord));
  exit_button  = new wxButton(this, ID_OAQUIT,  "MENU");
  
  wxBoxSizer* menuBox = new wxBoxSizer(wxHORIZONTAL);
  wxBoxSizer* vertBox = new wxBoxSizer(wxVERTICAL);
  
  menuBox->Add(m_textCtrl, 1, wxSTRETCH_NOT);
  menuBox->Add(exit_button, 1, wxSTRETCH_NOT);

  vertBox->Add(menuBox, 7, wxEXPAND);
  
  SetSizer(vertBox);
  vertBox->SetSizeHints(this);
}

void OddsArePanel::onExitOddsAre(wxCommandEvent &WXUNUSED(event)) {
  parent->returnToMenu();
}