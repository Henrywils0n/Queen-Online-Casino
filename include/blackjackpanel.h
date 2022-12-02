#pragma once
#include "header.h"
#include "blackjack.h"
#include "gameframe.h"
#include "imagepanel.h"
#include "imagebutton.h"

class BlackjackPanel : public wxPanel {
public:
  BlackjackPanel(GameFrame* parent);

private:
	/**
	* Temporary until game object is fixed
	*/
	Player* p;
	BlackjackGame* game;


	/**
	* Main game sizer contains all others
	*/
	wxBoxSizer* masterSizer;

	wxBoxSizer* menuBox;

	wxBoxSizer* personsSizer;
	wxBoxSizer* dealerSizer;
	wxBoxSizer* playerSizer;

	/**
	* Options are held in sizer at the bottom of the gameSizer
	*/
	wxBoxSizer* buttonSizer;

	//ImagePanel* dlrPan1;

	/**
	* For now the game is run through text
	*/
	wxStaticText* dealerText;
	wxStaticText* playerText;
	wxTextCtrl* gameText;

	wxButton* dealButton;
	wxButton* resetBetButton;
	wxButton* betOneButton;
	wxButton* betFiveButton;
	wxButton* betTwentyFiveButton;
	wxButton* hitButton;
	wxButton* standButton;
	wxButton* againButton;

	/**
	* When Dealbutton is pressed game begins. deal button and betthing options to be detroyed 
	*/
	void onDeal(wxCommandEvent& event);
	void onBetOne(wxCommandEvent& event);
	void onBetFive(wxCommandEvent& event);
	void onBetTwentyFive(wxCommandEvent& event);
	void onResetBet(wxCommandEvent& event);
	void onHit(wxCommandEvent& event);
	void onStand(wxCommandEvent& event);
	void onAgain(wxCommandEvent& event);

	void reloadTxt();
	void loadTwo();
	void loadThree();

	wxStaticText* m_textCtrl;
	ImageButton* exit_button;

private:
  GameFrame* parent;
  void onQuitBlackjack(wxCommandEvent &WXUNUSED(event));

  DECLARE_EVENT_TABLE();
};
