#include "../include/oddsarepanel.h"

BEGIN_EVENT_TABLE(OddsArePanel, wxPanel)
END_EVENT_TABLE()

OddsArePanel::OddsArePanel(GameFrame* parent) : wxPanel(parent) {
  m_textCtrl = new wxTextCtrl(this, wxID_ANY, "ODDS ARE", wxDefaultPosition, wxSize(200, wxDefaultCoord));
  
  wxBoxSizer* vertBox = new wxBoxSizer(wxVERTICAL);
  vertBox->Add(m_textCtrl, 1, wxEXPAND);
  
  SetSizer(vertBox);
  
  vertBox->SetSizeHints(this);
}
