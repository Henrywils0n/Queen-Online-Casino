#pragma once
#include "../include/roulettepanel.h"
#include <wx/animate.h>

BEGIN_EVENT_TABLE(RoulettePanel, wxPanel)
    EVT_BUTTON(ID_00, RoulettePanel :: OnBetDoubleZero)
    EVT_BUTTON(ID_0, RoulettePanel :: OnBetZero)
    EVT_BUTTON(ID_1to12, RoulettePanel :: OnBetLoThird)
    EVT_BUTTON(ID_13to24, RoulettePanel :: OnBetMidThird)
    EVT_BUTTON(ID_25to36, RoulettePanel :: OnBetHiThird)
    EVT_BUTTON(ID_1to18, RoulettePanel :: OnBetLoHalf)
    EVT_BUTTON(ID_19to36, RoulettePanel :: OnBetHiHalf)
    EVT_BUTTON(ID_EVEN, RoulettePanel :: OnBetEven)
    EVT_BUTTON(ID_ODD, RoulettePanel :: OnBetOdd)
    EVT_BUTTON(ID_RED, RoulettePanel :: OnBetRed)
    EVT_BUTTON(ID_BLACK, RoulettePanel :: OnBetBlack)
    EVT_BUTTON(ID_C1, RoulettePanel :: OnBetColumnOne)
    EVT_BUTTON(ID_C2, RoulettePanel :: OnBetColumnTwo)
    EVT_BUTTON(ID_C3, RoulettePanel :: OnBetColumnThree)
    EVT_BUTTON(ID_S1, RoulettePanel :: OnBetStreet1)
    EVT_BUTTON(ID_S4, RoulettePanel :: OnBetStreet4)
    EVT_BUTTON(ID_S7, RoulettePanel :: OnBetStreet7)
    EVT_BUTTON(ID_S10, RoulettePanel :: OnBetStreet10)
    EVT_BUTTON(ID_S13, RoulettePanel :: OnBetStreet13)
    EVT_BUTTON(ID_S16, RoulettePanel :: OnBetStreet16)
    EVT_BUTTON(ID_S19, RoulettePanel :: OnBetStreet19)
    EVT_BUTTON(ID_S22, RoulettePanel :: OnBetStreet22)
    EVT_BUTTON(ID_S25, RoulettePanel :: OnBetStreet25)
    EVT_BUTTON(ID_S28, RoulettePanel :: OnBetStreet28)
    EVT_BUTTON(ID_S31, RoulettePanel :: OnBetStreet31)
    EVT_BUTTON(ID_S34, RoulettePanel :: OnBetStreet34)
    EVT_BUTTON(ID_1, RoulettePanel::OnBet1)
    EVT_BUTTON(ID_2, RoulettePanel::OnBet2)
    EVT_BUTTON(ID_3, RoulettePanel :: OnBet3)
    EVT_BUTTON(ID_4, RoulettePanel :: OnBet4)
    EVT_BUTTON(ID_5, RoulettePanel :: OnBet5)
    EVT_BUTTON(ID_6, RoulettePanel :: OnBet6)
    EVT_BUTTON(ID_7, RoulettePanel :: OnBet7)
    EVT_BUTTON(ID_8, RoulettePanel :: OnBet8)
    EVT_BUTTON(ID_9, RoulettePanel :: OnBet9)
    EVT_BUTTON(ID_10, RoulettePanel :: OnBet10)
    EVT_BUTTON(ID_11, RoulettePanel :: OnBet11)
    EVT_BUTTON(ID_12, RoulettePanel :: OnBet12)
    EVT_BUTTON(ID_13, RoulettePanel :: OnBet13)
    EVT_BUTTON(ID_14, RoulettePanel :: OnBet14)
    EVT_BUTTON(ID_15, RoulettePanel :: OnBet15)
    EVT_BUTTON(ID_16, RoulettePanel :: OnBet16)
    EVT_BUTTON(ID_17, RoulettePanel :: OnBet17)
    EVT_BUTTON(ID_18, RoulettePanel :: OnBet18)
    EVT_BUTTON(ID_19, RoulettePanel :: OnBet19)
    EVT_BUTTON(ID_20, RoulettePanel :: OnBet20)
    EVT_BUTTON(ID_21, RoulettePanel :: OnBet21)
    EVT_BUTTON(ID_22, RoulettePanel :: OnBet22)
    EVT_BUTTON(ID_23, RoulettePanel :: OnBet23)
    EVT_BUTTON(ID_24, RoulettePanel :: OnBet24)
    EVT_BUTTON(ID_25, RoulettePanel :: OnBet25)
    EVT_BUTTON(ID_26, RoulettePanel :: OnBet26)
    EVT_BUTTON(ID_27, RoulettePanel :: OnBet27)
    EVT_BUTTON(ID_28, RoulettePanel :: OnBet28)
    EVT_BUTTON(ID_29, RoulettePanel :: OnBet29)
    EVT_BUTTON(ID_30, RoulettePanel :: OnBet30)
    EVT_BUTTON(ID_31, RoulettePanel :: OnBet31)
    EVT_BUTTON(ID_32, RoulettePanel :: OnBet32)
    EVT_BUTTON(ID_33, RoulettePanel :: OnBet33)
    EVT_BUTTON(ID_34, RoulettePanel :: OnBet34)
    EVT_BUTTON(ID_35, RoulettePanel :: OnBet35)
    EVT_BUTTON(ID_36, RoulettePanel :: OnBet36)
    EVT_BUTTON(ID_SUBMITROULETTEBET, RoulettePanel :: OnSubmitBet)
    EVT_BUTTON(ID_SPINWHEEL, RoulettePanel :: OnSpinWheel)
    EVT_BUTTON(ID_ROULETTEINFORMATION, RoulettePanel :: OnInformation)
    EVT_BUTTON(ID_PLAYROULETTEAGAIN, RoulettePanel :: OnPlayAgain)
    EVT_BUTTON(ID_EXITROULETTE, RoulettePanel :: OnExit)
    EVT_BUTTON(ID_RLQUIT, RoulettePanel::onQuitRoulette)
END_EVENT_TABLE()

RoulettePanel::RoulettePanel(GameFrame* par) : wxPanel(par) {
    parent = par;
    wxString backpng = "../resources/back_button.png";

    m_textCtrl = new wxStaticText(this, wxID_ANY, "ROULETTE", wxDefaultPosition, wxSize(100, wxDefaultCoord));
    exit_button  = new ImageButton(this, ID_RLQUIT,  "MENU", backpng, wxBITMAP_TYPE_PNG, 40, 40);
  
    wxBoxSizer* menuBox = new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer* vertBox = new wxBoxSizer(wxVERTICAL);
    

    menuBox->Add(exit_button, 1, wxSTRETCH_NOT);
    menuBox->Add(m_textCtrl, 1, wxSTRETCH_NOT);

    vertBox->Add(menuBox, 1, wxEXPAND);
    controller = new RouletteController();
    wxButton* button_00 = new wxButton(this, ID_00, "00");
    button_00->SetBackgroundColour(*wxGREEN);
    wxButton* button_0 = new wxButton(this, ID_0, "0");
    button_0->SetBackgroundColour(*wxGREEN);
    wxButton* button_1to12 = new wxButton(this, ID_1to12, "1 to 12");
    wxButton* button_13to24 = new wxButton(this, ID_13to24, "13 to 24");
    wxButton* button_25to36 = new wxButton(this, ID_25to36, "25 to 36");
    wxButton* button_1to18 = new wxButton(this, ID_1to18, "1 to 18");
    wxButton* button_19to36 = new wxButton(this, ID_19to36, "19 to 36");
    wxButton* button_even = new wxButton(this, ID_EVEN, "EVEN");
    wxButton* button_odd = new wxButton(this, ID_ODD, "ODD");
    wxButton* button_red = new wxButton(this, ID_RED, "RED");
    wxButton* button_black = new wxButton(this, ID_BLACK, "BLACK");
    wxButton* button_c1 = new wxButton(this, ID_C1, "COLUMN 1");
    wxButton* button_c2 = new wxButton(this, ID_C2, "COLUMN 2");
    wxButton* button_c3 = new wxButton(this, ID_C3, "COLUMN 3");
    wxButton* button_s1 = new wxButton(this, ID_S1, "STREET 1");
    wxButton* button_s4 = new wxButton(this, ID_S4, "STREET 4");
    wxButton* button_s7 = new wxButton(this, ID_S7, "STREET 7");
    wxButton* button_s10 = new wxButton(this, ID_S10, "STREET 10");
    wxButton* button_s13 = new wxButton(this, ID_S13, "STREET 13");
    wxButton* button_s16 = new wxButton(this, ID_S16, "STREET 16");
    wxButton* button_s19 = new wxButton(this, ID_S19, "STREET 19");
    wxButton* button_s22 = new wxButton(this, ID_S22, "STREET 22");
    wxButton* button_s25 = new wxButton(this, ID_S25, "STREET 25");
    wxButton* button_s28 = new wxButton(this, ID_S28, "STREET 28");
    wxButton* button_s31 = new wxButton(this, ID_S31, "STREET 31");
    wxButton* button_s34 = new wxButton(this, ID_S34, "STREET 34");
    wxButton* button_1 = new wxButton(this, ID_1, "1");
    button_1->SetBackgroundColour(*wxRED);
    wxButton* button_2 = new wxButton(this, ID_2, "2");
    button_2->SetBackgroundColour(*wxBLACK);
    button_2->SetForegroundColour(*wxRED);
    wxButton* button_3 = new wxButton(this, ID_3, "3");
    button_3->SetBackgroundColour(*wxRED);
    wxButton* button_4 = new wxButton(this, ID_4, "4");
    button_4->SetBackgroundColour(*wxBLACK);
    button_4->SetForegroundColour(*wxRED);
    wxButton* button_5 = new wxButton(this, ID_5, "5");
    button_5->SetBackgroundColour(*wxRED);
    wxButton* button_6 = new wxButton(this, ID_6, "6");
    button_6->SetBackgroundColour(*wxBLACK);
    button_6->SetForegroundColour(*wxRED);
    wxButton* button_7 = new wxButton(this, ID_7, "7");
    button_7->SetBackgroundColour(*wxRED);
    wxButton* button_8 = new wxButton(this, ID_8, "8");
    button_8->SetBackgroundColour(*wxBLACK);
    button_8->SetForegroundColour(*wxRED);
    wxButton* button_9 = new wxButton(this, ID_9, "9");
    button_9->SetBackgroundColour(*wxRED);
    wxButton* button_10 = new wxButton(this, ID_10, "10");
    button_10->SetBackgroundColour(*wxBLACK);
    button_10->SetForegroundColour(*wxRED);
    wxButton* button_11 = new wxButton(this, ID_11, "11");
    button_11->SetBackgroundColour(*wxBLACK);
    button_11->SetForegroundColour(*wxRED);
    wxButton* button_12 = new wxButton(this, ID_12, "12");
    button_12->SetBackgroundColour(*wxRED);
    wxButton* button_13 = new wxButton(this, ID_13, "13");
    button_13->SetBackgroundColour(*wxBLACK);
    button_13->SetForegroundColour(*wxRED);
    wxButton* button_14 = new wxButton(this, ID_14, "14");
    button_14->SetBackgroundColour(*wxRED);
    wxButton* button_15 = new wxButton(this, ID_15, "15");
    button_15->SetBackgroundColour(*wxBLACK);
    button_15->SetForegroundColour(*wxRED);
    wxButton* button_16 = new wxButton(this, ID_16, "16");
    button_16->SetBackgroundColour(*wxRED);
    wxButton* button_17 = new wxButton(this, ID_17, "17");
    button_17->SetBackgroundColour(*wxBLACK);
    button_17->SetForegroundColour(*wxRED);
    wxButton* button_18 = new wxButton(this, ID_18, "18");
    button_18->SetBackgroundColour(*wxRED);
    wxButton* button_19 = new wxButton(this, ID_19, "19");
    button_19->SetBackgroundColour(*wxRED);
    wxButton* button_20 = new wxButton(this, ID_20, "20");
    button_20->SetBackgroundColour(*wxBLACK);
    button_20->SetForegroundColour(*wxRED);
    wxButton* button_21 = new wxButton(this, ID_21, "21");
    button_21->SetBackgroundColour(*wxRED);
    wxButton* button_22 = new wxButton(this, ID_22, "22");
    button_22->SetBackgroundColour(*wxBLACK);
    button_22->SetForegroundColour(*wxRED);
    wxButton* button_23 = new wxButton(this, ID_23, "23");
    button_23->SetBackgroundColour(*wxRED);
    wxButton* button_24 = new wxButton(this, ID_24, "24");
    button_24->SetBackgroundColour(*wxBLACK);
    button_24->SetForegroundColour(*wxRED);
    wxButton* button_25 = new wxButton(this, ID_25, "25");
    button_25->SetBackgroundColour(*wxRED);
    wxButton* button_26 = new wxButton(this, ID_26, "26");
    button_26->SetBackgroundColour(*wxBLACK);
    button_26->SetForegroundColour(*wxRED);
    wxButton* button_27 = new wxButton(this, ID_27, "27");
    button_27->SetBackgroundColour(*wxRED);
    wxButton* button_28 = new wxButton(this, ID_28, "28");
    button_28->SetBackgroundColour(*wxBLACK);
    button_28->SetForegroundColour(*wxRED);
    wxButton* button_29 = new wxButton(this, ID_29, "29");
    button_29->SetBackgroundColour(*wxBLACK);
    button_29->SetForegroundColour(*wxRED);
    wxButton* button_30 = new wxButton(this, ID_30, "30");
    button_30->SetBackgroundColour(*wxRED);
    wxButton* button_31 = new wxButton(this, ID_31, "31");
    button_31->SetBackgroundColour(*wxBLACK);
    button_31->SetForegroundColour(*wxRED);
    wxButton* button_32 = new wxButton(this, ID_32, "32");
    button_32->SetBackgroundColour(*wxRED);
    wxButton* button_33 = new wxButton(this, ID_33, "33");
    button_33->SetBackgroundColour(*wxBLACK);
    button_33->SetForegroundColour(*wxRED);
    wxButton* button_34 = new wxButton(this, ID_34, "34");
    button_34->SetBackgroundColour(*wxRED);
    wxButton* button_35 = new wxButton(this, ID_35, "35");
    button_35->SetBackgroundColour(*wxBLACK);
    button_35->SetForegroundColour(*wxRED);
    wxButton* button_36 = new wxButton(this, ID_36, "36");
    button_36->SetBackgroundColour(*wxRED);
    wxButton* button_nothing = new wxButton(this, ID_NOTHING, " ");

    wxAnimationCtrl* m_animationCtrl = new wxAnimationCtrl(this, wxID_ANY);
    if (m_animationCtrl->LoadFile("../resources/roulette.gif")) m_animationCtrl->Play();


    // create array for inside bets
    wxBoxSizer* mainBox = new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer* topBox = new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer* midBox = new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer* badBox = new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer* bottomBox = new wxBoxSizer(wxHORIZONTAL);
    topBox->Add(button_s1, wxEXPAND);
    topBox->Add(button_s4, wxEXPAND);
    topBox->Add(button_s7, wxEXPAND);
    topBox->Add(button_s10, wxEXPAND);
    topBox->Add(button_s13, wxEXPAND);
    topBox->Add(button_s16, wxEXPAND);
    topBox->Add(button_s19, wxEXPAND);
    topBox->Add(button_s22, wxEXPAND);
    topBox->Add(button_s25, wxEXPAND);
    topBox->Add(button_s28, wxEXPAND);
    topBox->Add(button_s31, wxEXPAND);
    topBox->Add(button_s34, wxEXPAND); 
    topBox->Add(button_nothing, wxEXPAND); 
    midBox->Add(button_3, wxEXPAND);
    midBox->Add(button_6, wxEXPAND);
    midBox->Add(button_9, wxEXPAND);
    midBox->Add(button_12, wxEXPAND);
    midBox->Add(button_15, wxEXPAND);
    midBox->Add(button_18, wxEXPAND);
    midBox->Add(button_21, wxEXPAND);
    midBox->Add(button_24, wxEXPAND);
    midBox->Add(button_27, wxEXPAND);
    midBox->Add(button_30, wxEXPAND);
    midBox->Add(button_33, wxEXPAND);
    midBox->Add(button_36, wxEXPAND);
    midBox->Add(button_c3, wxEXPAND);
    badBox->Add(button_2, wxEXPAND);
    badBox->Add(button_5, wxEXPAND);
    badBox->Add(button_8, wxEXPAND);
    badBox->Add(button_11, wxEXPAND);
    badBox->Add(button_14, wxEXPAND);
    badBox->Add(button_17, wxEXPAND);
    badBox->Add(button_20, wxEXPAND);
    badBox->Add(button_23, wxEXPAND);
    badBox->Add(button_26, wxEXPAND);
    badBox->Add(button_29, wxEXPAND);
    badBox->Add(button_32, wxEXPAND);
    badBox->Add(button_35, wxEXPAND);
    badBox->Add(button_c2, wxEXPAND);
    bottomBox->Add(button_1, wxEXPAND);
    bottomBox->Add(button_4, wxEXPAND);
    bottomBox->Add(button_7, wxEXPAND);
    bottomBox->Add(button_10, wxEXPAND);
    bottomBox->Add(button_13, wxEXPAND);
    bottomBox->Add(button_16, wxEXPAND);
    bottomBox->Add(button_19, wxEXPAND);
    bottomBox->Add(button_22, wxEXPAND);
    bottomBox->Add(button_25, wxEXPAND);
    bottomBox->Add(button_28, wxEXPAND);
    bottomBox->Add(button_31, wxEXPAND);
    bottomBox->Add(button_34, wxEXPAND);
    bottomBox->Add(button_c1, wxEXPAND);
    
    vertBox->Add(m_animationCtrl);
    vertBox->Add(topBox, 0, wxEXPAND);
    vertBox->Add(midBox, 0, wxEXPAND);
    vertBox->Add(badBox, 0, wxEXPAND);
    vertBox->Add(bottomBox, 0, wxEXPAND);


    // create array of buttons for right side outside bets (0, 00)
    int const numColsOR = 1;
    int const numRowsOR = 2;
    wxFlexGridSizer *fgs1 = new wxFlexGridSizer( numRowsOR, numColsOR, 5, 7.5);
    fgs1->Add(button_00, wxEXPAND);
    fgs1->Add(button_0, wxEXPAND);

    // create array of buttons for lower bottom side outside bets (third bets)
    wxBoxSizer* thirdsBox = new wxBoxSizer(wxHORIZONTAL);
    thirdsBox->Add(button_1to12, 1);
    thirdsBox->Add(button_13to24, 1);
    thirdsBox->Add(button_25to36, 1);

    wxBoxSizer* specialBox = new wxBoxSizer(wxHORIZONTAL);
    specialBox->Add(button_1to18, 1);
    specialBox->Add(button_even, 1);
    specialBox->Add(button_red, 1);
    specialBox->Add(button_black, 1);
    specialBox->Add(button_odd, 1);
    specialBox->Add(button_19to36, 1);
    
    vertBox->AddSpacer(5);
    vertBox->Add(thirdsBox, 0, wxEXPAND);
    vertBox->Add(specialBox, 0, wxEXPAND);
    vertBox->AddSpacer(15);

    // fgs->Show(true);
    // fgs1->Show(true);
    // fgs2->Show(true);
    // fgs3->Show(true);

    SetSizer(vertBox);

    vertBox->SetSizeHints(this);

}

// button implementation
void RoulettePanel::OnBetDoubleZero(wxCommandEvent &WXUNUSED(event)) {
    controller->storeBets(table->doubleZero, moneyBet);
}
void RoulettePanel :: OnBetZero(wxCommandEvent &WXUNUSED(event)) {
    controller->storeBets(table->zero, moneyBet);
}
void RoulettePanel :: OnBetLoThird(wxCommandEvent &WXUNUSED(event)) {
    controller->storeBets(table->loThird, moneyBet);
}
void RoulettePanel :: OnBetMidThird(wxCommandEvent &WXUNUSED(event)) {
    controller->storeBets(table->midThird, moneyBet);
}
void RoulettePanel :: OnBetHiThird(wxCommandEvent &WXUNUSED(event)) {
    controller->storeBets(table->hiThird, moneyBet);
}
void RoulettePanel :: OnBetLoHalf(wxCommandEvent &WXUNUSED(event)) {
    controller->storeBets(table->loHalf, moneyBet);
}
void RoulettePanel :: OnBetHiHalf(wxCommandEvent &WXUNUSED(event)) {
    controller->storeBets(table->hiHalf, moneyBet);
}
void RoulettePanel :: OnBetEven(wxCommandEvent &WXUNUSED(event)) {
    controller->storeBets(table->even, moneyBet);
}
void RoulettePanel :: OnBetOdd(wxCommandEvent &WXUNUSED(event)) {
    controller->storeBets(table->odd, moneyBet);
}
void RoulettePanel :: OnBetRed(wxCommandEvent &WXUNUSED(event)) {
    controller->storeBets(table->red, moneyBet);
}
void RoulettePanel :: OnBetBlack(wxCommandEvent &WXUNUSED(event)) {
    controller->storeBets(table->black, moneyBet);
}
void RoulettePanel :: OnBetColumnOne(wxCommandEvent &WXUNUSED(event)) {
    controller->storeBets(table->col1, moneyBet);
}
void RoulettePanel :: OnBetColumnTwo(wxCommandEvent &WXUNUSED(event)) {
    controller->storeBets(table->col2, moneyBet);
}
void RoulettePanel :: OnBetColumnThree(wxCommandEvent &WXUNUSED(event)) {
    controller->storeBets(table->col3, moneyBet);
}
void RoulettePanel :: OnBetStreet1(wxCommandEvent &WXUNUSED(event)) {
    controller->storeBets(table->street1, moneyBet);
}
void RoulettePanel :: OnBetStreet4(wxCommandEvent &WXUNUSED(event)) {
    controller->storeBets(table->street4, moneyBet);
}
void RoulettePanel :: OnBetStreet7(wxCommandEvent &WXUNUSED(event)) {
    controller->storeBets(table->street7, moneyBet);
}
void RoulettePanel :: OnBetStreet10(wxCommandEvent &WXUNUSED(event)) {
    controller->storeBets(table->street10, moneyBet);
}
void RoulettePanel :: OnBetStreet13(wxCommandEvent &WXUNUSED(event)) {
    controller->storeBets(table->street13, moneyBet);
}
void RoulettePanel :: OnBetStreet16(wxCommandEvent &WXUNUSED(event)) {
    controller->storeBets(table->street16, moneyBet);
}
void RoulettePanel :: OnBetStreet19(wxCommandEvent &WXUNUSED(event)) {
    controller->storeBets(table->street19, moneyBet);
}
void RoulettePanel :: OnBetStreet22(wxCommandEvent &WXUNUSED(event)) {
    controller->storeBets(table->street22, moneyBet);
}
void RoulettePanel :: OnBetStreet25(wxCommandEvent &WXUNUSED(event)) {
    controller->storeBets(table->street25, moneyBet);
}
void RoulettePanel :: OnBetStreet28(wxCommandEvent &WXUNUSED(event)) {
    controller->storeBets(table->street28, moneyBet);
}
void RoulettePanel :: OnBetStreet31(wxCommandEvent &WXUNUSED(event)) {
    controller->storeBets(table->street31, moneyBet);
}
void RoulettePanel :: OnBetStreet34(wxCommandEvent &WXUNUSED(event)) {
    controller->storeBets(table->street34, moneyBet);
}

		// inside bets
void RoulettePanel :: OnBet1(wxCommandEvent &WXUNUSED(event)) {
    vector<int> bet = {1};
    controller->storeBets(bet, moneyBet);
}
void RoulettePanel :: OnBet2(wxCommandEvent &WXUNUSED(event)) {
    vector<int> bet = {2};
    controller->storeBets(bet, moneyBet);
}
void RoulettePanel :: OnBet3(wxCommandEvent &WXUNUSED(event)) {
    vector<int> bet = {3};
    controller->storeBets(bet, moneyBet);
}
void RoulettePanel :: OnBet4(wxCommandEvent &WXUNUSED(event)) {
    vector<int> bet = {4};
    controller->storeBets(bet, moneyBet);
}
void RoulettePanel :: OnBet5(wxCommandEvent &WXUNUSED(event)) {
    vector<int> bet = {5};
    controller->storeBets(bet, moneyBet);
}
void RoulettePanel :: OnBet6(wxCommandEvent &WXUNUSED(event)) {
    vector<int> bet = {6};
    controller->storeBets(bet, moneyBet);
}
void RoulettePanel :: OnBet7(wxCommandEvent &WXUNUSED(event)) {
    vector<int> bet = {7};
    controller->storeBets(bet, moneyBet);
}
void RoulettePanel :: OnBet8(wxCommandEvent &WXUNUSED(event)) {
    vector<int> bet = {8};
    controller->storeBets(bet, moneyBet);
}
void RoulettePanel :: OnBet9(wxCommandEvent &WXUNUSED(event)) {
    vector<int> bet = {9};
    controller->storeBets(bet, moneyBet);
}
void RoulettePanel :: OnBet10(wxCommandEvent &WXUNUSED(event)) {
    vector<int> bet = {10};
    controller->storeBets(bet, moneyBet);
}
void RoulettePanel :: OnBet11(wxCommandEvent &WXUNUSED(event)) {
    vector<int> bet = {11};
    controller->storeBets(bet, moneyBet);
}
void RoulettePanel :: OnBet12(wxCommandEvent &WXUNUSED(event)) {
    vector<int> bet = {12};
    controller->storeBets(bet, moneyBet);
}
void RoulettePanel :: OnBet13(wxCommandEvent &WXUNUSED(event)) {
    vector<int> bet = {13};
    controller->storeBets(bet, moneyBet);
}
void RoulettePanel :: OnBet14(wxCommandEvent &WXUNUSED(event)) {
    vector<int> bet = {14};
    controller->storeBets(bet, moneyBet);
}
void RoulettePanel :: OnBet15(wxCommandEvent &WXUNUSED(event)) {
    vector<int> bet = {15};
    controller->storeBets(bet, moneyBet);
}
void RoulettePanel :: OnBet16(wxCommandEvent &WXUNUSED(event)) {
    vector<int> bet = {16};
    controller->storeBets(bet, moneyBet);
}
void RoulettePanel :: OnBet17(wxCommandEvent &WXUNUSED(event)) {
    vector<int> bet = {17};
    controller->storeBets(bet, moneyBet);
}
void RoulettePanel :: OnBet18(wxCommandEvent &WXUNUSED(event)) {
    vector<int> bet = {18};
    controller->storeBets(bet, moneyBet);
}
void RoulettePanel :: OnBet19(wxCommandEvent &WXUNUSED(event)) {
    vector<int> bet = {19};
    controller->storeBets(bet, moneyBet);
}
void RoulettePanel :: OnBet20(wxCommandEvent &WXUNUSED(event)) {
    vector<int> bet = {20};
    controller->storeBets(bet, moneyBet);
}
void RoulettePanel :: OnBet21(wxCommandEvent &WXUNUSED(event)) {
    vector<int> bet = {21};
    controller->storeBets(bet, moneyBet);
}
void RoulettePanel :: OnBet22(wxCommandEvent &WXUNUSED(event)) {
    vector<int> bet = {22};
    controller->storeBets(bet, moneyBet);
}
void RoulettePanel :: OnBet23(wxCommandEvent &WXUNUSED(event)) {
    vector<int> bet = {23};
    controller->storeBets(bet, moneyBet);
}
void RoulettePanel :: OnBet24(wxCommandEvent &WXUNUSED(event)) {
    vector<int> bet = {24};
    controller->storeBets(bet, moneyBet);
}
void RoulettePanel :: OnBet25(wxCommandEvent &WXUNUSED(event)) {
    vector<int> bet = {25};
    controller->storeBets(bet, moneyBet);
}
void RoulettePanel :: OnBet26(wxCommandEvent &WXUNUSED(event)) {
    vector<int> bet = {26};
    controller->storeBets(bet, moneyBet);
}
void RoulettePanel :: OnBet27(wxCommandEvent &WXUNUSED(event)) {
    vector<int> bet = {27};
    controller->storeBets(bet, moneyBet);
}
void RoulettePanel :: OnBet28(wxCommandEvent &WXUNUSED(event)) {
    vector<int> bet = {28};
    controller->storeBets(bet, moneyBet);
}
void RoulettePanel :: OnBet29(wxCommandEvent &WXUNUSED(event)) {
    vector<int> bet = {29};
    controller->storeBets(bet, moneyBet);
}
void RoulettePanel :: OnBet30(wxCommandEvent &WXUNUSED(event)) {
    vector<int> bet = {30};
    controller->storeBets(bet, moneyBet);
}
void RoulettePanel :: OnBet31(wxCommandEvent &WXUNUSED(event)) {
    vector<int> bet = {31};
    controller->storeBets(bet, moneyBet);
}
void RoulettePanel :: OnBet32(wxCommandEvent &WXUNUSED(event)) {
    vector<int> bet = {32};
    controller->storeBets(bet, moneyBet);
}
void RoulettePanel :: OnBet33(wxCommandEvent &WXUNUSED(event)) {
    vector<int> bet = {33};
    controller->storeBets(bet, moneyBet);
}
void RoulettePanel :: OnBet34(wxCommandEvent &WXUNUSED(event)) {
    vector<int> bet = {34};
    controller->storeBets(bet, moneyBet);
}
void RoulettePanel :: OnBet35(wxCommandEvent &WXUNUSED(event)) {
    vector<int> bet = {35};
    controller->storeBets(bet, moneyBet);
}
void RoulettePanel :: OnBet36(wxCommandEvent &WXUNUSED(event)) {
    vector<int> bet = {36};
    controller->storeBets(bet, moneyBet);
}
	// functional buttons
void RoulettePanel :: OnSubmitBet(wxCommandEvent &WXUNUSED(event)) {
    controller->checkBets();
}
void RoulettePanel :: OnSpinWheel(wxCommandEvent &WXUNUSED(event)) {
    controller->spinBall();
    controller->ballOnWheel();
}
void RoulettePanel :: OnInformation(wxCommandEvent &WXUNUSED(event)) {
}
void RoulettePanel :: OnPlayAgain(wxCommandEvent &WXUNUSED(event)) {  
}
void RoulettePanel :: OnExit(wxCommandEvent &WXUNUSED(event)) {
}
void RoulettePanel::onQuitRoulette(wxCommandEvent &WXUNUSED(event)){
  parent->returnToMenu();

}
