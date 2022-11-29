#pragma once
#include "game.h"

class RouletteFrame : public wxFrame {
public:
	RouletteFrame();
  void setRouter(Game* router);
	void OnQuit(wxCommandEvent& event);
	void OnAbout(wxCommandEvent& event);

	wxTextCtrl* m_textCtrl;

private:
	wxDECLARE_DYNAMIC_CLASS(RouletteFrame);
	wxDECLARE_EVENT_TABLE();
    Game* router;
};

enum {
  ID_RTQUIT,
  ID_RTABOUT,
};
