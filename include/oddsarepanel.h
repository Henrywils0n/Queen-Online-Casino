#pragma once
#include "header.h"
#include "gameframe.h"
#include "imagebutton.h"

class OddsArePanel : public wxPanel {
public:
	OddsArePanel(GameFrame* par);

  wxStaticText* m_textCtrl;
  ImageButton* exit_button;

private:
	GameFrame* parent;
	void onExitOddsAre(wxCommandEvent &WXUNUSED(event));
	
	DECLARE_EVENT_TABLE()
};
