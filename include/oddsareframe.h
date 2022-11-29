#pragma once
#include "game.h"

class OddsAreFrame : public wxFrame {
public:
	OddsAreFrame();
  void setRouter(Game* router);
	void OnQuit(wxCommandEvent& event);
	void OnAbout(wxCommandEvent& event);

	wxTextCtrl* m_textCtrl;

private:
	wxDECLARE_DYNAMIC_CLASS(OddsAreFrame);
	wxDECLARE_EVENT_TABLE();
    Game* router;
};

enum {
  ID_OAQUIT,
  ID_OAABOUT,
};
