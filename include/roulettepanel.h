#pragma once
#include "header.h"
#include "gameframe.h"
#include "roullette_game.h"

class RoulettePanel : public wxPanel {
public:
  RoulettePanel(GameFrame* parent);

  wxTextCtrl* m_textCtrl;

  DECLARE_EVENT_TABLE()
      private:
    GameFrame* parent;
    RouletteController* RouletteController;
	
// buttons 
	// roulette table buttons
		// outside bets
		void OnBetDoubleZero(wxCommand &event);
		void OnBetZero(wxCommand &event);
		void OnBetLoThird(wxCommand &event);
		void OnBetMidThird(wxCommand &event);
		void OnBetHiThird(wxCommand &event);
		void OnBetLoHalf(wxCommand &event);
		void OnBetHiHalf(wxCommand &event);
		void OnBetEven(wxCommand &event);
		void OnBetOdd(wxCommand &event);
		void OnBetRed(wxCommand &event);
		void OnBetBlack(wxCommand &event);
		void OnBetColumnOne(wxCommand &event);
		void OnBetColumnTwo(wxCommand &event);
		void OnBetColumnThree(wxCommand &event);
		void OnBetStreet1(wxCommand &event);
		void OnBetStreet4(wxCommand &event);
		void OnBetStreet7(wxCommand &event);
		void OnBetStreet10(wxCommand &event);
		void OnBetStreet13(wxCommand &event);
		void OnBetStreet16(wxCommand &event);
		void OnBetStreet19(wxCommand &event);
		void OnBetStreet22(wxCommand &event);
		void OnBetStreet25(wxCommand &event);
		void OnBetStreet28(wxCommand &event);
		void OnBetStreet31(wxCommand &event);
		void OnBetStreet34(wxCommand &event);
		// inside bets
		void OnBet1(wxCommand &event);
		void OnBet2(wxCommand &event);
		void OnBet3(wxCommand &event);
		void OnBet4(wxCommand &event);
		void OnBet5(wxCommand &event);
		void OnBet6(wxCommand &event);
		void OnBet7(wxCommand &event);
		void OnBet8(wxCommand &event);
		void OnBet9(wxCommand &event);
		void OnBet10(wxCommand &event);
		void OnBet11(wxCommand &event);
		void OnBet12(wxCommand &event);
		void OnBet13(wxCommand &event);
		void OnBet14(wxCommand &event);
		void OnBet15(wxCommand &event);
		void OnBet16(wxCommand &event);
		void OnBet17(wxCommand &event);
		void OnBet18(wxCommand &event);
		void OnBet19(wxCommand &event);
		void OnBet20(wxCommand &event);
		void OnBet21(wxCommand &event);
		void OnBet22(wxCommand &event);
		void OnBet23(wxCommand &event);
		void OnBet24(wxCommand &event);
		void OnBet25(wxCommand &event);
		void OnBet26(wxCommand &event);
		void OnBet27(wxCommand &event);
		void OnBet28(wxCommand &event);
		void OnBet29(wxCommand &event);
		void OnBet30(wxCommand &event);
		void OnBet31(wxCommand &event);
		void OnBet32(wxCommand &event);
		void OnBet33(wxCommand &event);
		void OnBet34(wxCommand &event);
		void OnBet35(wxCommand &event);
		void OnBet36(wxCommand &event);
		
	// functional buttons
		void OnSubmitBet(wxCommand &event);
		void OnSpinWheel(wxCommand &event);
		void OnInformation(wxCommand &event);
		void OnPlayAgain(wxCommand &event);
		void OnExit(wxCommand &event);
};
