#include "../include/blackjackpanel.h"
#include "../include/blackjack.h"

BEGIN_EVENT_TABLE(BlackjackPanel, wxPanel)
	EVT_BUTTON(ID_BJDEAL, BlackjackPanel::onDeal)
    EVT_BUTTON(ID_BJONECHIP, BlackjackPanel::onBetOne)
    EVT_BUTTON(ID_BJFIVECHIP, BlackjackPanel::onBetFive)
    EVT_BUTTON(ID_BJTWENTYFIVECHIP, BlackjackPanel::onBetTwentyFive)
    EVT_BUTTON(ID_BJRESETBET, BlackjackPanel::onResetBet)
END_EVENT_TABLE()

BlackjackPanel::BlackjackPanel(GameFrame* par) : wxPanel(par) { 

    // Temporary until game object is fixed
    p = new Player();
    game = new BlackjackGame(p);
    // Declare sizers
    masterSizer = new wxBoxSizer(wxVERTICAL);

    personsSizer = new wxBoxSizer(wxVERTICAL);
    dealerSizer = new wxBoxSizer(wxHORIZONTAL);
    playerSizer = new wxBoxSizer(wxHORIZONTAL);

    buttonSizer = new wxBoxSizer(wxHORIZONTAL);

    // Filler for player and dealer hands
    dealerText = new wxStaticText(this, -1, "Dealer Hand", wxDefaultPosition, wxSize(5000, 100));
    playerText = new wxStaticText(this, -1, "My Hand", wxDefaultPosition, wxSize(5000, 100), wxTE_MULTILINE);
    gameText = new wxTextCtrl(this, -1, "Game", wxDefaultPosition, wxSize(5000, 100), wxTE_MULTILINE);

    // Attempt to use images failed
    //wxString nullCard = "../resources/Cards/red_joker.png";
    //dlrPan1 = new ImagePanel(this, nullCard, wxBITMAP_TYPE_PNG);
    //dealerSizer->Add(dlrPan1, 10, wxEXPAND);

    // Declare buttons
    dealButton = new wxButton(this, ID_BJDEAL, "DEAL");
    resetBetButton = new wxButton(this, ID_BJRESETBET, "RESET BET");
    
    betOneButton = new wxButton(this, ID_BJONECHIP, "1$ CHIP");
    betFiveButton = new wxButton(this, ID_BJFIVECHIP, "5$ CHIP");
    betTwentyFiveButton = new wxButton(this, ID_BJTWENTYFIVECHIP, "25$ CHIP");

    // Populate dealer and player sizers
    dealerSizer->Add(dealerText, 0, wxEXPAND | wxALL, 10);
    playerSizer->Add(playerText, 0, wxEXPAND | wxALL, 10);

    // Populate button sizer    
    buttonSizer->Add(betOneButton, 0, wxALL, 10);
    buttonSizer->Add(betFiveButton, 0, wxALL, 10);
    buttonSizer->Add(betTwentyFiveButton, 0, wxALL, 10);

    buttonSizer->Add(resetBetButton, 0, wxALL, 10);
    buttonSizer->Add(dealButton, 0, wxALL, 10);

    // Add text boxes
    personsSizer->Add(dealerSizer, wxEXPAND | wxALL, wxALIGN_CENTER);
    personsSizer->Add(playerSizer, wxEXPAND | wxALL, wxALIGN_CENTER);
    masterSizer->Add(gameText, wxEXPAND | wxALL, wxALIGN_CENTER);

    // Add sub-sizers to masterSizer
    masterSizer->Add(personsSizer, 0, wxALIGN_CENTER);
    masterSizer->Add(buttonSizer, 0, wxALIGN_CENTER); 

    SetSizerAndFit(masterSizer);

    dealerSizer->SetSizeHints(this);
}

void BlackjackPanel::onDeal(wxCommandEvent& WXUNUSED(event)) {
    this->dealButton->Destroy();
    this->resetBetButton->Destroy();
    this->betOneButton->Destroy();
    this->betFiveButton->Destroy();
    this->betTwentyFiveButton->Destroy();

    game->Play();
}

void BlackjackPanel::onBetOne(wxCommandEvent& WXUNUSED(event)) {
    p->setBet(p->getBet() + 1);
    this->reloadTxt();
}

void BlackjackPanel::onBetFive(wxCommandEvent& WXUNUSED(event)) {
    p->setBet(p->getBet() + 5);
    this->reloadTxt();
}

void BlackjackPanel::onBetTwentyFive(wxCommandEvent& WXUNUSED(event)) {
    p->setBet(p->getBet() + 25);
    this->reloadTxt();
}

void BlackjackPanel::onResetBet(wxCommandEvent& event) {
    p->setBet(0);
    this->reloadTxt();
}

void BlackjackPanel::reloadTxt() {
    wxString pTxt = "Player :\n";
    pTxt << "Current bet: " << p->getBet();
    playerText->SetLabel(pTxt);
}