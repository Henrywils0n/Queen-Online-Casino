#include "frame.h"

class RouletteFrame: public wxFrame {
public:
  RouletteFrame();
  
  void OnAbout(wxCommandEvent &event);
  void OnQuit(wxCommandEvent &event);
  void OnReset(wxCommandEvent &event);
  
  wxImagePanel* m_title;
  wxButton* roulette_button;
  wxButton* blackjack_button;
  wxButton* oddsare_button;
  wxTextCtrl* m_textCtrl;
  
private:
  wxDECLARE_DYNAMIC_CLASS(RouletteFrame);
  wxDECLARE_EVENT_TABLE();
};

enum {
  ID_QUIT  = wxID_EXIT,
  ID_ABOUT = wxID_ABOUT,
};

