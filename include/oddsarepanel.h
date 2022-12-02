#pragma once
#include "header.h"
#include "gameframe.h"
#include "imagebutton.h"
#include "oddsare.h"

class OddsArePanel : public wxPanel {
public:
	OddsArePanel(GameFrame* par);

  wxStaticText* title_static;
  wxStaticText* range_static;
  wxStaticText* guess_static;
  wxStaticText* bet_static;
  wxTextCtrl* range_ctrl;
  wxTextCtrl* guess_ctrl;
  wxTextCtrl* bet_ctrl;
  wxStaticText* result_static;
  ImageButton* exit_button;
  wxButton* guess_button;

private:
	GameFrame* parent;
  OddsAre* oa;

	void onExitOddsAre(wxCommandEvent &WXUNUSED(event));
  void onGuess(wxCommandEvent &WXUNUSED(event));
	
	DECLARE_EVENT_TABLE()
};
