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
	wxBoxSizer* gameSizer;

	wxBoxSizer* dealerSizer;
	wxBoxSizer* playerSizer;

	/**
	* Options are held in sizer at the bottom of the gameSizer
	*/
	wxBoxSizer* buttonSizer;

	ImagePanel* dlrPan1;

	/**
	* For now the game is run through text
	*/
	//wxTextCtrl* tempText;
	wxTextCtrl* tempText2;

	wxButton* dealButton;
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

  DECLARE_EVENT_TABLE()
};
