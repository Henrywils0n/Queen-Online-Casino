#include "../include/blackjackpanel.h"
#include "../include/blackjack.h"

BEGIN_EVENT_TABLE(BlackjackPanel, wxPanel)
	EVT_BUTTON(ID_BJDEAL, BlackjackPanel::onDeal)
    EVT_BUTTON(ID_BJONECHIP, BlackjackPanel::onBetOne)
    EVT_BUTTON(ID_BJFIVECHIP, BlackjackPanel::onBetFive)
    EVT_BUTTON(ID_BJTWENTYFIVECHIP, BlackjackPanel::onBetTwentyFive)
    EVT_BUTTON(ID_BJRESETBET, BlackjackPanel::onResetBet)
    EVT_BUTTON(ID_BJHIT, BlackjackPanel::onHit)
    EVT_BUTTON(ID_BJSTAND, BlackjackPanel::onStand)
    EVT_BUTTON(ID_BJAGAIN, BlackjackPanel::onAgain)
    //  EVT_SIZE(BlackjackPanel::OnSize)
    EVT_BUTTON(ID_BJQUIT, BlackjackPanel::onQuitBlackjack)
END_EVENT_TABLE()

BlackjackPanel::BlackjackPanel(GameFrame* par) : wxPanel(par) { 

    parent = par;
    wxString backpng = "../resources/back_button.png";

    // Temporary until game object is fixed
    p = new Player();
    //game = new BlackjackGame();
    // Declare sizers
    masterSizer = new wxBoxSizer(wxVERTICAL);

    menuBox = new wxBoxSizer(wxHORIZONTAL);

    personsSizer = new wxBoxSizer(wxVERTICAL);
    dealerSizer = new wxBoxSizer(wxHORIZONTAL);
    playerSizer = new wxBoxSizer(wxHORIZONTAL);

    buttonSizer = new wxBoxSizer(wxHORIZONTAL);

    // Filler for player and dealer hands
    dealerText = new wxStaticText(this, -1, "Dealer Hand", wxDefaultPosition, wxSize(5000, 100));
    playerText = new wxStaticText(this, -1, "My Hand", wxDefaultPosition, wxSize(5000, 100), wxTE_MULTILINE);
    gameText = new wxTextCtrl(this, -1, "Game\n", wxDefaultPosition, wxSize(5000, 100), wxTE_MULTILINE);

    // Attempt to use images failed
    //wxString nullCard = "../resources/Cards/red_joker.png";
    //dlrPan1 = new ImagePanel(this, nullCard, wxBITMAP_TYPE_PNG);
    //dealerSizer->Add(dlrPan1, 10, wxEXPAND);

    // Declare buttons
    exit_button = new ImageButton(this, ID_BJQUIT, "MENU", backpng, wxBITMAP_TYPE_PNG, 40, 40);
    dealButton = new wxButton(this, ID_BJDEAL, "DEAL");
    resetBetButton = new wxButton(this, ID_BJRESETBET, "RESET BET");
    
    betOneButton = new wxButton(this, ID_BJONECHIP, "1$ CHIP");
    betFiveButton = new wxButton(this, ID_BJFIVECHIP, "5$ CHIP");
    betTwentyFiveButton = new wxButton(this, ID_BJTWENTYFIVECHIP, "25$ CHIP");

    hitButton = new wxButton(this, ID_BJHIT, "HIT");
    standButton = new wxButton(this, ID_BJSTAND, "STAND");
    againButton = new wxButton(this, ID_BJAGAIN, "AGAIN");

    // Populate dealer and player sizers
    dealerSizer->Add(dealerText, 0, wxEXPAND | wxALL, 10);
    playerSizer->Add(playerText, 0, wxEXPAND | wxALL, 10);

    // Populate menue sizer
    menuBox->Add(exit_button, 1, wxSHAPED);

    // Populate button sizer    
    buttonSizer->Add(betOneButton, 0, wxALL, 10);
    buttonSizer->Add(betFiveButton, 0, wxALL, 10);
    buttonSizer->Add(betTwentyFiveButton, 0, wxALL, 10);

    buttonSizer->Add(resetBetButton, 0, wxALL, 10);
    buttonSizer->Add(dealButton, 0, wxALL, 10);

    buttonSizer->Add(hitButton, 0, wxALL, 10);
    buttonSizer->Add(standButton, 0, wxALL, 10);
    buttonSizer->Add(againButton, 0, wxALL, 10);
    hitButton->Hide();
    standButton->Hide();
    againButton->Hide();

    // Add text boxes
    personsSizer->Add(dealerSizer, wxEXPAND | wxALL, wxALIGN_CENTER);
    personsSizer->Add(playerSizer, wxEXPAND | wxALL, wxALIGN_CENTER);

    masterSizer->Add(menuBox, 7, wxEXPAND);

    masterSizer->Add(gameText, wxEXPAND | wxALL, wxALIGN_CENTER);

    // Add sub-sizers to masterSizer
    masterSizer->Add(personsSizer, 0, wxALIGN_CENTER);
    masterSizer->Add(buttonSizer, 0, wxALIGN_CENTER); 

    SetSizerAndFit(masterSizer);

    dealerSizer->SetSizeHints(this);

    gameText->AppendText("Place your bet.\n");
}

void BlackjackPanel::onDeal(wxCommandEvent& WXUNUSED(event)) {
    this->dealButton->Hide();
    this->resetBetButton->Hide();
    this->betOneButton->Hide();
    this->betFiveButton->Hide();
    this->betTwentyFiveButton->Hide();
    //this->betTwentyFiveButton->Destroy();

    //game->Play();
    //this->reloadTxt();
    loadTwo();
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

void BlackjackPanel::onHit(wxCommandEvent& event) {
    wxLogError("Wrong choice");
}

void BlackjackPanel::onStand(wxCommandEvent& event) {
    loadThree();
}

void BlackjackPanel::onAgain(wxCommandEvent& event) {
    wxLogError("Please no.");
}

void BlackjackPanel::reloadTxt() {
    wxString pTxt = "Player :\t";
    pTxt << "Current bet: " << p->getBet() << "\n";
    
    //string strCards;
    //for (Card* card : game->game_player->cards) {
        //pTxt << card->toString();
    //    strCards += card->toString() + "\n";
        //OutputDebugStringW(L"" + c);
   // }

    //OutputDebugStringW(L"" + strCards);

    // THIS WORKS WHY DOES IT NOT WORK LOOPED
    //OutputDebugStringW(L"" + game->game_player->cards.front()->toString());

    //for (Card* c : game->gma.getCards()) {
    //    gameText->AppendText(c->toString());
    //}

    playerText->SetLabel(pTxt);
}

void BlackjackPanel::loadTwo() {
    wxString pTxt = "Player :\t";
    pTxt << "Current bet: " << p->getBet() << "\n\n";
    pTxt << "Cards: \n\t";
    pTxt << "Queen of Spades\n\t";
    pTxt << "Eight of Diamonds";
    playerText->SetLabel(pTxt);

    wxString dTxt = "Dealer :\n";
    dTxt << "Cards: \n\t";
    dTxt << "Jack of Diamonds\n\t";
    dTxt << "Face down card";
    dealerText->SetLabel(dTxt);

    gameText->AppendText("Dealing cards...\n");
    hitButton->Show();
    standButton->Show();
}

void BlackjackPanel::loadThree() {
    gameText->AppendText("You stand.\nFlipping dealer card.\nDealer hits.\nDealer busts.");
    wxString dTxt = "Dealer :\n";
    dTxt << "Cards: \n\t";
    dTxt << "Jack of Diamonds\n\t";
    dTxt << "Four of Hearts\n\t";
    dTxt << "King of Hearts\nBUST!\n";
    gameText->AppendText("\nYou Win!\n\nPlay Again?");
    dealerText->SetLabel(dTxt);

    hitButton->Hide();
    standButton->Hide();
    againButton->Show();
}

//BlackjackPanel::BlackjackPanel(GameFrame* par) : wxPanel(par) {  
//  parent = par;
//  wxString backpng = "../resources/back_button.png";
//
//  m_textCtrl = new wxStaticText(this, wxID_ANY, "BLACKJACK", wxDefaultPosition, wxSize(100, wxDefaultCoord));
//  exit_button  = new ImageButton(this, ID_BJQUIT,  "MENU", backpng, wxBITMAP_TYPE_PNG, 40, 40);
//
//  wxBoxSizer* menuBox = new wxBoxSizer(wxHORIZONTAL);
//  wxBoxSizer* vertBox = new wxBoxSizer(wxVERTICAL);
//
//  menuBox->Add(exit_button, 1, wxSHAPED);
//  menuBox->Add(m_textCtrl,1, wxSTRETCH_NOT);
//  
//  vertBox->Add(menuBox, 7, wxEXPAND);
//  
//  SetSizer(vertBox);
//  vertBox->SetSizeHints(this);
//}

void BlackjackPanel::onQuitBlackjack(wxCommandEvent &WXUNUSED(event)){
  parent->returnToMenu();
}