#include "../include/blackjackpanel.h"

BEGIN_EVENT_TABLE(BlackjackPanel, wxPanel)
//  EVT_SIZE(BlackjackPanel::OnSize)
END_EVENT_TABLE()

BlackjackPanel::BlackjackPanel(GameFrame* par) : wxPanel(par) {  
  m_textCtrl = new wxTextCtrl(this, wxID_ANY, "ODDS ARE", wxDefaultPosition, wxSize(200, wxDefaultCoord));
  
  wxBoxSizer* vertBox = new wxBoxSizer(wxVERTICAL);
  vertBox->Add(m_textCtrl, 1, wxEXPAND);
  
  SetSizer(vertBox);
  
  vertBox->SetSizeHints(this);
}
