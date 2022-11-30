#include "../include/roulettepanel.h"

BEGIN_EVENT_TABLE(RoulettePanel, wxPanel)
//  EVT_BUTTON(RoulettePanel::paintEvent)
//  EVT_BUTTON(RoulettePanel::OnSize)
END_EVENT_TABLE()

RoulettePanel::RoulettePanel(GameFrame* parent) : wxPanel(parent) {
  m_textCtrl = new wxTextCtrl(this, wxID_ANY, "ROULETTE", wxDefaultPosition, wxSize(200, wxDefaultCoord));
  
  wxBoxSizer* vertBox = new wxBoxSizer(wxVERTICAL);
  vertBox->Add(m_textCtrl, 1, wxEXPAND);
  
  SetSizer(vertBox);
  
  vertBox->SetSizeHints(this);
}
