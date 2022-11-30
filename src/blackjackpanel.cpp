#include "../include/blackjackpanel.h"

BEGIN_EVENT_TABLE(BlackjackPanel, wxPanel)
	EVT_BUTTON(ID_BJDEAL, BlackjackPanel::onDeal)
    EVT_BUTTON(ID_BJONECHIP, BlackjackPanel::onBetOne)
    EVT_BUTTON(ID_BJFIVECHIP, BlackjackPanel::onBetFive)
    EVT_BUTTON(ID_BJTWENTYFIVECHIP, BlackjackPanel::onBetTwentyFive)
END_EVENT_TABLE()

BlackjackPanel::BlackjackPanel(GameFrame* par) : wxPanel(par) {  

    // Declare sizers
    gameSizer = new wxBoxSizer(wxVERTICAL);
    dealerSizer = new wxBoxSizer(wxHORIZONTAL);
    playerSizer = new wxBoxSizer(wxHORIZONTAL);
    buttonSizer = new wxBoxSizer(wxHORIZONTAL);

    tempText = new wxTextCtrl(this, -1, "Dealer Hand", wxDefaultPosition, wxSize(500, 100), wxTE_MULTILINE);
    tempText2 = new wxTextCtrl(this, -1, "My Hand", wxDefaultPosition, wxSize(500, 100), wxTE_MULTILINE);

    dealButton = new wxButton(this, ID_BJDEAL, "DEAL");
    betOneButton = new wxButton(this, ID_BJONECHIP, "1$ CHIP");
    betFiveButton = new wxButton(this, ID_BJFIVECHIP, "5$ CHIP");
    betTwentyFiveButton = new wxButton(this, ID_BJTWENTYFIVECHIP, "25$ CHIP");

    // 1 to stretch up and down; wxEXPAND to stretch sideways
    //gameSizer->Add(tempText, 1, wxEXPAND | wxALL, 10);
    dealerSizer->Add(tempText, 0, wxEXPAND | wxALL, 10);
    playerSizer->Add(tempText2, 0, wxEXPAND | wxALL, 10);

    buttonSizer->Add(betOneButton, 0, wxALL, 10);
    buttonSizer->Add(betFiveButton, 0, wxALL, 10);
    buttonSizer->Add(betTwentyFiveButton, 0, wxALL, 10);
    buttonSizer->Add(dealButton, 0, wxALL, 10);

    gameSizer->Add(dealerSizer, wxEXPAND | wxALL, wxALIGN_CENTER);
    gameSizer->Add(playerSizer, wxEXPAND | wxALL, wxALIGN_CENTER);
    gameSizer->Add(buttonSizer, 0, wxALIGN_CENTER); 

    SetSizerAndFit(gameSizer);
}

void BlackjackPanel::onDeal(wxCommandEvent& WXUNUSED(event)) {
    this->dealButton->Destroy();
    this->betOneButton->Destroy();
    this->betFiveButton->Destroy();
    this->betTwentyFiveButton->Destroy();
}

void BlackjackPanel::onBetOne(wxCommandEvent& WXUNUSED(event)) {

}

void BlackjackPanel::onBetFive(wxCommandEvent& WXUNUSED(event)) {

}

void BlackjackPanel::onBetTwentyFive(wxCommandEvent& WXUNUSED(event)) {

}