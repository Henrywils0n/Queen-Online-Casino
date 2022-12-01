#pragma once
#include "header.h"
#include "gameframe.h"
#include "imagepanel.h"

class BlackjackPanel : public wxPanel {
public:
  BlackjackPanel(GameFrame* parent);


private:
	/**
	* Main game sizer contains all others
	*/
	wxBoxSizer* masterSizer;

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


	/**
	* When Dealbutton is pressed game begins. deal button and betthing options to be detroyed 
	*/
	void onDeal(wxCommandEvent& event);
	void onBetOne(wxCommandEvent& event);
	void onBetFive(wxCommandEvent& event);
	void onBetTwentyFive(wxCommandEvent& event);
	void onResetBet(wxCommandEvent& event);

  DECLARE_EVENT_TABLE()
};
