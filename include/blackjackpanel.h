#pragma once
#include "header.h"
#include "gameframe.h"

class BlackjackPanel : public wxPanel {
public:
  BlackjackPanel(GameFrame* parent);


private:
	/**
	* Main game sizer contains all others
	*/
	wxBoxSizer* gameSizer;

	/**
	* Options are held in sizer at the bottom of the gameSizer
	*/
	wxBoxSizer* buttonSizer;

	/**
	* For now the game is run through text
	*/
	wxTextCtrl* tempText;

	wxButton* dealButton;

	/**
	* When Dealbutton is pressed game begins. deal button and betthing options to be detroyed 
	*/
	void onDeal(wxCommandEvent& event);

  DECLARE_EVENT_TABLE()
};
