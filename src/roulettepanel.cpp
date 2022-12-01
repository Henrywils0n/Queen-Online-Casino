#include "../include/roulettepanel.h"

BEGIN_EVENT_TABLE(RoulettePanel, wxPanel)
//  EVT_BUTTON(RoulettePanel::paintEvent)
//  EVT_BUTTON(RoulettePanel::OnSize)
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
    EVT_BUTTON(ID_BALCK, RoulettePanel :: OnBetBlack)
    EVT_BUTTON(ID_C1, RoulettePanel :: OnBetColOne)
    EVT_BUTTON(ID_C2, RoulettePanel :: OnBetColTwo)
    EVT_BUTTON(ID_C3, RoulettePanel :: OnBetColThree)
    EVT_BUTTON(ID_S1, RoulettePanel :: OnBetStreet1)
    EVT_BUTTON(ID_S4, RoulettePanel :: OnBetStreet4)
    EVT_BUTTON(ID_S7, RoulettePanel :: OnBetStreet7)
    EVT_BUTTON(ID_S10, RoulettePanel :: OnBetStreet11)
    EVT_BUTTON(ID_S13, RoulettePanel :: OnBetStreet13)
    EVT_BUTTON(ID_S16, RoulettePanel :: OnBetStreet16)
    EVT_BUTTON(ID_S19, RoulettePanel :: OnBetStreet19)
    EVT_BUTTON(ID_S22, RoulettePanel :: OnBetStreet22)
    EVT_BUTTON(ID_S25, RoulettePanel :: OnBetStreet25)
    EVT_BUTTON(ID_S28, RoulettePanel :: OnBetStreet28)
    EVT_BUTTON(ID_S31, RoulettePanel :: OnBetStreet31)
    EVT_BUTTON(ID_S34, RoulettePanel :: OnBetStreet34)
    EVT_BUTTON(ID_1, RoulettePanel :: OnBet1)
    EVT_BUTTON(ID_2, RoulettePanel :: OnBet2)
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
END_EVENT_TABLE()

RoulettePanel::RoulettePanel(GameFrame* parent) : wxPanel(parent) {
    RouletteController = new RouletteController();
    button_00 = new wxButton(this, ID_00, "00");
    button_0 = new wxButton(this, ID_0, "0");
    button_1to12 = new wxButton(this, ID_1to12, "1 to 12");
    button_13to24 = new wxButton(this, IC_13to24, "13 to 24");
    button_25to36 = new wxButton(this, ID_25to36, "25 to 36");
    button_1to18 = new wxButton(this, ID_1to18, "1 to 18");
    button_19to36 = new wxButton(this, ID_19to36, "19 to 36");
    button_even = new wxButton(this, ID_EVEN, "EVEN");
    button_odd = new wxButton(this, ID_ODD, "ODD");
    button_red = new wxButton(this, ID_RED, "RED");
    button_black = new wxButton(this, ID_BLACK, "BLACK");
    button_c1 = new wxButton(this, ID_C1, "COLUMN 1");
    button_c2 = new wxButton(this, ID_C2, "COLUMN 2");
    button_c3 = new wxButton(this, ID_C3, "COLUMN 3");
    button_s1 = new wxButton(this, ID_S1, "STREET 1");
    button_s4 = new wxButton(this, ID_S4, "STREET 4");
    button_s7 = new wxButton(this, ID_S7, "STREET 7");
    button_s10 = new wxButton(this, ID_S10, "STREET 10");
    button_s13 = new wxButton(this, ID_S13, "STREET 13");
    button_s16 = new wxButton(this, ID_S16, "STREET 16");
    button_s19 = new wxButton(this, ID_S19, "STREET 19");
    button_s22 = new wxButton(this, ID_S22, "STREET 22");
    button_s25 = new wxButton(this, ID_S25, "STREET 25");
    button_s28 = new wxButton(this, ID_S28, "STREET 28");
    button_s31 = new wxButton(this, ID_S31, "STREET 31");
    button_s34 = new wxButton(this, ID_S34, "STREET 34");
    button_1 = new wxButton(this, ID_1, "1");
    button_2 = new wxButton(this, ID_2, "2");
    button_3 = new wxButton(this, ID_3, "3");
    button_4 = new wxButton(this, ID_4, "4");
    button_5 = new wxButton(this, ID_5, "5");
    button_6 = new wxButton(this, ID_6, "6");
    button_7 = new wxButton(this, ID_7, "7");
    button_8 = new wxButton(this, ID_8, "8");
    button_9 = new wxButton(this, ID_9, "9");
    button_10 = new wxButton(this, ID_10, "10");
    button_11 = new wxButton(this, ID_11, "11");
    button_12 = new wxButton(this, ID_12, "12");
    button_13 = new wxButton(this, ID_13, "13");
    button_14 = new wxButton(this, ID_14, "14");
    button_15 = new wxButton(this, ID_15, "15");
    button_16 = new wxButton(this, ID_16, "16");
    button_17 = new wxButton(this, ID_17, "17");
    button_18 = new wxButton(this, ID_18, "18");
    button_19 = new wxButton(this, ID_19, "19");
    button_20 = new wxButton(this, ID_20, "20");
    button_21 = new wxButton(this, ID_21, "21");
    button_22 = new wxButton(this, ID_22, "22");
    button_23 = new wxButton(this, ID_23, "23");
    button_24 = new wxButton(this, ID_24, "24");
    button_25 = new wxButton(this, ID_25, "25");
    button_26 = new wxButton(this, ID_26, "26");
    button_27 = new wxButton(this, ID_27, "27");
    button_28 = new wxButton(this, ID_28, "28");
    button_29 = new wxButton(this, ID_29, "29");
    button_30 = new wxButton(this, ID_30, "30");
    button_31 = new wxButton(this, ID_31, "31");
    button_32 = new wxButton(this, ID_32, "32");
    button_33 = new wxButton(this, ID_33, "33");
    button_34 = new wxButton(this, ID_34, "34");
    button_35 = new wxButton(this, ID_35, "35");
    button_36 = new wxButton(this, ID_36, "36");
    
    
  m_textCtrl = new wxTextCtrl(this, wxID_ANY, "ROULETTE", wxDefaultPosition, wxSize(200, wxDefaultCoord));
  
    // Set up sizers
  wxBoxSizer* vertBox = new wxBoxSizer(wxVERTICAL);
  vertBox->Add(m_textCtrl, 1, wxEXPAND);
    
    inputBox->AddSpacer(30);
    inputBox->Add()
    
  
  SetSizer(vertBox);
  
  vertBox->SetSizeHints(this);
}

// button implementation
void RoulettePanel :: OnBetDoubleZero(wxCommandEvent &WXUNUSED(event)) {
    RouletteController->storeBets(string "doubleZero", int moneyBet);
}
void RoulettePanel :: OnBetZero(wxCommandEvent &WXUNUSED(event)) {
    RouletteController->storeBets(string "zero", int moneyBet);
}
void RoulettePanel :: OnBetLoThird(wxCommandEvent &WXUNUSED(event))) {
    RouletteController->storeBets(string "loThird", int moneyTotal);
}
void RoulettePanel :: OnBetMidThird(wxCommandEvent &WXUNUSED(event)) {
    RouletteController->storeBets(string "midThird", int moneyBet);
}
void RoulettePanel :: OnBetHiThird(wxCommandEvent &WXUNUSED(event)) {
    RouletteController->storeBets(string "hiThird", int moneyBet);
}
void RoulettePanel :: OnBetLoHalf(wxCommandEvent &WXUNUSED(event)) {
    RouletteController->storeBets(string "loHalf", int moneyBet);
}
void RoulettePanel :: OnBetHiHalf(wxCommandEvent &WXUNUSED(event)) {
    RouletteController->storeBets(string "hiHalf", int moneyBet);
}
void RoulettePanel :: OnBetEven(wxCommandEvent &WXUNUSED(event)) {
    RouletteController->storeBets(string "even", int moneyBet);
}
void RoulettePanel :: OnBetOdd(wxCommandEvent &WXUNUSED(event)) {
    RouletteController->storeBets(string "odd", int moneyBet);
}
void RoulettePanel :: OnBetRed(wxCommandEvent &WXUNUSED(event)) {
    RouletteController->storeBets(string "red", int moneyBet);
}
void RoulettePanel :: OnBetBlack(wxCommandEvent &WXUNUSED(event)) {
    RouletteController->storeBets(string "black", int moneyBet);
}
void RoulettePanel :: OnBetColumnOne(wxCommandEvent &WXUNUSED(event)) {
    RouletteController->storeBets(string "col1", int moneyBet);
}
void RoulettePanel :: OnBetColumnTwo(wxCommandEvent &WXUNUSED(event)) {
    RouletteController->storeBets(string "col2", int moneyBet);
}
void RoulettePanel :: OnBetColumnThree(wxCommandEvent &WXUNUSED(event)) {
    RouletteController->storeBets(string "col3", int moneyBet);
}
void RoulettePanel :: OnBetStreet1(wxCommandEvent &WXUNUSED(event)) {
    RouletteController->storeBets(string "street1", int moneyBet);
}
void RoulettePanel :: OnBetStreet4(wxCommandEvent &WXUNUSED(event)) {
    RouletteController->storeBets(string "street4", int moneyBet);
}
void RoulettePanel :: OnBetStreet7(wxCommandEvent &WXUNUSED(event)) {
    RouletteController->storeBets(string "street7", int moneyBet);
}
void RoulettePanel :: OnBetStreet10(wxCommandEvent &WXUNUSED(event)) {
    RouletteController->storeBets(string "street10", int moneyBet);
}
void RoulettePanel :: OnBetStreet13(wxCommandEvent &WXUNUSED(event)) {
    RouletteController->storeBets(string "street13", int moneyBet);
}
void RoulettePanel :: OnBetStreet16(wxCommandEvent &WXUNUSED(event)) {
    RouletteController->storeBets(string "street16", int moneyBet);
}
void RoulettePanel :: OnBetStreet19(wxCommandEvent &WXUNUSED(event)) {
    RouletteController->storeBets(string "street19", int moneyBet);
}
void RoulettePanel :: OnBetStreet22(wxCommandEvent &WXUNUSED(event)) {
    RouletteController->storeBets(string "street22", int moneyBet);
}
void RoulettePanel :: OnBetStreet25(wxCommandEvent &WXUNUSED(event)) {
    RouletteController->storeBets(string "street25", int moneyBet);
}
void RoulettePanel :: OnBetStreet28(wxCommandEvent &WXUNUSED(event)) {
    RouletteController->storeBets(string "street28", int moneyBet);
}
void RoulettePanel :: OnBetStreet31(wxCommandEvent &WXUNUSED(event)) {
    RouletteController->storeBets(string "street31", int moneyBet);
}
void RoulettePanel :: OnBetStreet34(wxCommandEvent &WXUNUSED(event)) {
    RouletteController->storeBets(string "street34", int moneyBet);
}

		// inside bets
void RoulettePanel :: OnBet1(wxCommandEvent &WXUNUSED(event)) {
    RouletteController->storeBets(string "single", int moneyBet);
}
void RoulettePanel :: OnBet2(wxCommandEvent &WXUNUSED(event)) {
    RouletteController->storeBets(string "single", int moneyBet);
}
void RoulettePanel :: OnBet3(wxCommandEvent &WXUNUSED(event)) {
    RouletteController->storeBets(string "single", int moneyBet);
}
void RoulettePanel :: OnBet4(wxCommandEvent &WXUNUSED(event)) {
    RouletteController->storeBets(string "single", int moneyBet);
}
void RoulettePanel :: OnBet5(wxCommandEvent &WXUNUSED(event)) {
    RouletteController->storeBets(string "single", int moneyBet);
}
void RoulettePanel :: OnBet6(wxCommandEvent &WXUNUSED(event)) {
    RouletteController->storeBets(string "single", int moneyBet);
}
void RoulettePanel :: OnBet7(wxCommandEvent &WXUNUSED(event)) {
    RouletteController->storeBets(string "single", int moneyBet);
}
void RoulettePanel :: OnBet8(wxCommandEvent &WXUNUSED(event)) {
    RouletteController->storeBets(string "single", int moneyBet);
}
void RoulettePanel :: OnBet9(wxCommandEvent &WXUNUSED(event)) {
    RouletteController->storeBets(string "single", int moneyBet);
}
void RoulettePanel :: OnBet10(wxCommandEvent &WXUNUSED(event)) {
    RouletteController->storeBets(string "single", int moneyBet);
}
void RoulettePanel :: OnBet11(wxCommandEvent &WXUNUSED(event)) {
    RouletteController->storeBets(string "single", int moneyBet);
}
void RoulettePanel :: OnBet12(wxCommandEvent &WXUNUSED(event)) {
    RouletteController->storeBets(string "single", int moneyBet);
}
void RoulettePanel :: OnBet13(wxCommandEvent &WXUNUSED(event)) {
    RouletteController->storeBets(string "single", int moneyBet);
}
void RoulettePanel :: OnBet14(wxCommandEvent &WXUNUSED(event)) {
    RouletteController->storeBets(string "single", int moneyBet);
}
void RoulettePanel :: OnBet15(wxCommandEvent &WXUNUSED(event)) {
    RouletteController->storeBets(string "single", int moneyBet);
}
void RoulettePanel :: OnBet16(wxCommandEvent &WXUNUSED(event)) {
    RouletteController->storeBets(string "single", int moneyBet);
}
void RoulettePanel :: OnBet17(wxCommandEvent &WXUNUSED(event)) {
    RouletteController->storeBets(string "single", int moneyBet);
}
void RoulettePanel :: OnBet18(wxCommandEvent &WXUNUSED(event)) {
    RouletteController->storeBets(string "single", int moneyBet);
}
void RoulettePanel :: OnBet19(wxCommandEvent &WXUNUSED(event)) {
    RouletteController->storeBets(string "single", int moneyBet);
}
void RoulettePanel :: OnBet20(wxCommandEvent &WXUNUSED(event)) {
    RouletteController->storeBets(string "single", int moneyBet);
}
void RoulettePanel :: OnBet21(wxCommandEvent &WXUNUSED(event)) {
    RouletteController->storeBets(string "single", int moneyBet);
}
void RoulettePanel :: OnBet22(wxCommandEvent &WXUNUSED(event)) {
    RouletteController->storeBets(string "single", int moneyBet);
}
void RoulettePanel :: OnBet23(wxCommandEvent &WXUNUSED(event)) {
    RouletteController->storeBets(string "single", int moneyBet);
}
void RoulettePanel :: OnBet24(wxCommandEvent &WXUNUSED(event)) {
    RouletteController->storeBets(string "single", int moneyBet);
}
void RoulettePanel :: OnBet25(wxCommandEvent &WXUNUSED(event)) {
    RouletteController->storeBets(string "single", int moneyBet);
}
void RoulettePanel :: OnBet26(wxCommandEvent &WXUNUSED(event)) {
    RouletteController->storeBets(string "single", int moneyBet);
}
void RoulettePanel :: OnBet27(wxCommandEvent &WXUNUSED(event)) {
    RouletteController->storeBets(string "single", int moneyBet);
}
void RoulettePanel :: OnBet28(wxCommandEvent &WXUNUSED(event)) {
    RouletteController->storeBets(string "single", int moneyBet);
}
void RoulettePanel :: OnBet29(wxCommandEvent &WXUNUSED(event)) {
    RouletteController->storeBets(string "single", int moneyBet);
}
void RoulettePanel :: OnBet30(wxCommandEvent &WXUNUSED(event)) {
    RouletteController->storeBets(string "single", int moneyBet);
}
void RoulettePanel :: OnBet31(wxCommandEvent &WXUNUSED(event)) {
    RouletteController->storeBets(string "single", int moneyBet);
}
void RoulettePanel :: OnBet32(wxCommandEvent &WXUNUSED(event)) {
    RouletteController->storeBets(string "single", int moneyBet);
}
void RoulettePanel :: OnBet33(wxCommandEvent &WXUNUSED(event)) {
    RouletteController->storeBets(string "single", int moneyBet);
}
void RoulettePanel :: OnBet34(wxCommandEvent &WXUNUSED(event)) {
    RouletteController->storeBets(string "single", int moneyBet);
}
void RoulettePanel :: OnBet35(wxCommandEvent &WXUNUSED(event)) {
    RouletteController->storeBets(string "single", int moneyBet);
}
void RoulettePanel :: OnBet36(wxCommandEvent &WXUNUSED(event)) {
    RouletteController->storeBets(string "single", int moneyBet);
}
	// functional buttons
void RoulettePanel :: OnSubmitBet(wxCommandEvent &WXUNUSED(event)) {
    RouletteController->checkBets(vector<Bet> placedBets);
}
void RoulettePanel :: OnSpinWheel(wxCommandEvent &WXUNUSED(event)) {
    RouletteController->spinBall();
    RouletteController->ballOnWheel();
}
void RoulettePanel :: OnInformation(wxCommandEvent &WXUNUSED(event)) {
}
void RoulettePanel :: OnPlayAgain(wxCommandEvent &WXUNUSED(event)) {
    placedBets.clear()
    RouletteController->
}
void RoulettePanel :: OnExit(wxCommandEvent &WXUNUSED(event)) {
    RouletteController->
}
