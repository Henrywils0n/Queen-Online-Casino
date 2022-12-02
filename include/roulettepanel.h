#pragma once
#include "header.h"
#include "gameframe.h"
#include "roullette_game.h"
#include "imagebutton.h"


class RoulettePanel : public wxPanel {
public:
  RoulettePanel(GameFrame* parent);

  wxStaticText* m_textCtrl;
  ImageButton* exit_button;
  DECLARE_EVENT_TABLE();
private:
	wxAnimationCtrl* gif;
    GameFrame* parent;
    RouletteController* controller;
	Table* table = new Table();
	int moneyBet;

	
	// buttons 
	// roulette table buttons
	// outside bets
	void OnBetDoubleZero(wxCommandEvent &event);
	void OnBetZero(wxCommandEvent &event);
	void OnBetLoThird(wxCommandEvent &event);
	void OnBetMidThird(wxCommandEvent &event);
	void OnBetHiThird(wxCommandEvent &event);
	void OnBetLoHalf(wxCommandEvent &event);
	void OnBetHiHalf(wxCommandEvent &event);
	void OnBetEven(wxCommandEvent &event);
	void OnBetOdd(wxCommandEvent &event);
	void OnBetRed(wxCommandEvent &event);
	void OnBetBlack(wxCommandEvent &event);
	void OnBetColumnOne(wxCommandEvent &event);
	void OnBetColumnTwo(wxCommandEvent &event);
	void OnBetColumnThree(wxCommandEvent &event);
	void OnBetStreet1(wxCommandEvent &event);
	void OnBetStreet4(wxCommandEvent &event);
	void OnBetStreet7(wxCommandEvent &event);
	void OnBetStreet10(wxCommandEvent &event);
	void OnBetStreet13(wxCommandEvent &event);
	void OnBetStreet16(wxCommandEvent &event);
	void OnBetStreet19(wxCommandEvent &event);
	void OnBetStreet22(wxCommandEvent &event);
	void OnBetStreet25(wxCommandEvent &event);
	void OnBetStreet28(wxCommandEvent &event);
	void OnBetStreet31(wxCommandEvent &event);
	void OnBetStreet34(wxCommandEvent &event);
	// inside bets
	void OnBet1(wxCommandEvent &event);
	void OnBet2(wxCommandEvent &event);
	void OnBet3(wxCommandEvent &event);
	void OnBet4(wxCommandEvent &event);
	void OnBet5(wxCommandEvent &event);
	void OnBet6(wxCommandEvent &event);
	void OnBet7(wxCommandEvent &event);
	void OnBet8(wxCommandEvent &event);
	void OnBet9(wxCommandEvent &event);
	void OnBet10(wxCommandEvent &event);
	void OnBet11(wxCommandEvent &event);
	void OnBet12(wxCommandEvent &event);
	void OnBet13(wxCommandEvent &event);
	void OnBet14(wxCommandEvent &event);
	void OnBet15(wxCommandEvent &event);
	void OnBet16(wxCommandEvent &event);
	void OnBet17(wxCommandEvent &event);
	void OnBet18(wxCommandEvent &event);
	void OnBet19(wxCommandEvent &event);
	void OnBet20(wxCommandEvent &event);
	void OnBet21(wxCommandEvent &event);
	void OnBet22(wxCommandEvent &event);
	void OnBet23(wxCommandEvent &event);
	void OnBet24(wxCommandEvent &event);
	void OnBet25(wxCommandEvent &event);
	void OnBet26(wxCommandEvent &event);
	void OnBet27(wxCommandEvent &event);
	void OnBet28(wxCommandEvent &event);
	void OnBet29(wxCommandEvent &event);
	void OnBet30(wxCommandEvent &event);
	void OnBet31(wxCommandEvent &event);
	void OnBet32(wxCommandEvent &event);
	void OnBet33(wxCommandEvent &event);
	void OnBet34(wxCommandEvent &event);
	void OnBet35(wxCommandEvent &event);
	void OnBet36(wxCommandEvent &event);
		
	// functional buttons
	void OnSubmitBet(wxCommandEvent &event);
	void OnSpinWheel(wxCommandEvent &event);
	void OnInformation(wxCommandEvent &event);
	void OnPlayAgain(wxCommandEvent &event);
	void OnExit(wxCommandEvent &event);
	void onQuitRoulette(wxCommandEvent &WXUNUSED(event));
};
