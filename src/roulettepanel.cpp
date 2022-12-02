#include "../include/roulettepanel.h"

BEGIN_EVENT_TABLE(RoulettePanel, wxPanel)
//  EVT_BUTTON(RoulettePanel::paintEvent)
//  EVT_BUTTON(RoulettePanel::OnSize)
    EVT_BUTTON(ID_RLQUIT, RoulettePanel::onQuitRoulette)
END_EVENT_TABLE()

RoulettePanel::RoulettePanel(GameFrame* par) : wxPanel(par) {
  parent = par;
  wxString backpng = "../resources/back_button.png";

  m_textCtrl = new wxStaticText(this, wxID_ANY, "ROULETTE", wxDefaultPosition, wxSize(100, wxDefaultCoord));
  exit_button  = new ImageButton(this, ID_RLQUIT,  "MENU", backpng, wxBITMAP_TYPE_PNG, 40, 40);
  
  wxBoxSizer* menuBox = new wxBoxSizer(wxHORIZONTAL);
  wxBoxSizer* vertBox = new wxBoxSizer(wxVERTICAL);

  menuBox->Add(exit_button, 1, wxSHAPED);
  menuBox->Add(m_textCtrl, 1, wxSTRETCH_NOT);

  vertBox->Add(menuBox, 7, wxEXPAND);

  SetSizer(vertBox);
  vertBox->SetSizeHints(this);
}

void RoulettePanel::onQuitRoulette(wxCommandEvent &WXUNUSED(event)){
  parent->returnToMenu();
}
