#include "game.h";

class FrameOA : public wxFrame {
public:
	FrameOA();
	void OnQuit(wxCommandEvent& event);
	void OnReset(wxCommandEvent& event);

	wxTextCtrl* m_textCtrl;

private:
	wxDECLARE_DYNAMIC_CLASS(FrameOA);
	wxDECLARE_EVENT_TABLE();
};
