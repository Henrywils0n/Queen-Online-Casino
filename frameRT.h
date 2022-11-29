#include "game.h";

class FrameRT : public wxFrame {
public:
	FrameRT();
	void OnQuit(wxCommandEvent& event);
	void OnReset(wxCommandEvent& event);

	wxTextCtrl* m_textCtrl;

private:
	wxDECLARE_DYNAMIC_CLASS(FrameRT);
	wxDECLARE_EVENT_TABLE();
};
