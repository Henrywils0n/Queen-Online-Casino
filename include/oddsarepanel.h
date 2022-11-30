#pragma once
#include "header.h"
#include "gameframe.h"


class OddsArePanel : public wxPanel {
public:
	OddsArePanel(GameFrame* par);

	wxTextCtrl* m_textCtrl;
	wxButton* exit_button;
	
private:
	GameFrame* parent;
	void onExitOddsAre(wxCommandEvent &WXUNUSED(event));
	
	DECLARE_EVENT_TABLE()
};
