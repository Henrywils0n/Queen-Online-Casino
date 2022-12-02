#include "../include/oddsarepanel.h"

BEGIN_EVENT_TABLE(OddsArePanel, wxPanel)
  EVT_BUTTON(ID_OAQUIT, OddsArePanel::onExitOddsAre)
END_EVENT_TABLE()

OddsArePanel::OddsArePanel(GameFrame* par) : wxPanel(par) {
  parent = par;
  wxString backpng = "../resources/back_button.png";
  
  m_textCtrl = new wxStaticText(this, wxID_ANY, "ODDS ARE", wxDefaultPosition, wxSize(100, wxDefaultCoord));
  exit_button  = new ImageButton(this, ID_OAQUIT,  "MENU", backpng, wxBITMAP_TYPE_PNG, 40, 40);
  
  wxBoxSizer* menuBox = new wxBoxSizer(wxHORIZONTAL);
  wxBoxSizer* vertBox = new wxBoxSizer(wxVERTICAL);
  
  menuBox->Add(exit_button, 1, wxSHAPED);
  menuBox->Add(m_textCtrl, 1, wxSTRETCH_NOT);

  vertBox->Add(menuBox, 7, wxEXPAND);
  
  SetSizer(vertBox);
  vertBox->SetSizeHints(this);
}

void OddsArePanel::onExitOddsAre(wxCommandEvent &WXUNUSED(event)) {
  parent->returnToMenu();
}
