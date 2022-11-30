#include "../include/blackjackpanel.h"

BEGIN_EVENT_TABLE(BlackjackPanel, wxPanel)
	EVT_BUTTON(ID_BJDEAL, BlackjackPanel::onDeal)
END_EVENT_TABLE()

BlackjackPanel::BlackjackPanel(GameFrame* par) : wxPanel(par) {  

    // Declare sizers
    gameSizer = new wxBoxSizer(wxVERTICAL);
    buttonSizer = new wxBoxSizer(wxHORIZONTAL);

    tempText = new wxTextCtrl(this, -1, "My text.", wxDefaultPosition, wxSize(100, 60), wxTE_MULTILINE);
    dealButton = new wxButton(this, ID_BJDEAL, "DEAL");

    // 1 to stretch up and down; wxEXPAND to stretch sideways
    gameSizer->Add(tempText, 1, wxEXPAND | wxALL, 10);
    buttonSizer->Add(dealButton, 0, wxALL, 10);

    gameSizer->Add(buttonSizer, 0, wxALIGN_CENTER); 

    SetSizerAndFit(gameSizer);
}

void BlackjackPanel::onDeal(wxCommandEvent& WXUNUSED(event)) {
    this->dealButton->Destroy();
}