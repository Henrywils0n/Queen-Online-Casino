#include "imagepanel.h"

class MyFrame: public wxFrame {
public:
  MyFrame();
  
  void OnAbout(wxCommandEvent &event);
  void OnQuit(wxCommandEvent &event);
  void OnReset(wxCommandEvent &event);
  void OnPlayRoulette(wxCommandEvent &event);
  void OnPlayBlackjack(wxCommandEvent &event);
  void OnPlayOddsAre(wxCommandEvent &event);
  
  wxImagePanel* m_title;
  wxButton* roulette_button;
  wxButton* blackjack_button;
  wxButton* oddsare_button;
  wxTextCtrl* m_textCtrl;
  
private:
  wxDECLARE_DYNAMIC_CLASS(MyFrame);
  wxDECLARE_EVENT_TABLE();
  
  int balance;
};

enum {
  ID_QUIT  = wxID_EXIT,
  ID_ABOUT = wxID_ABOUT,
  ID_ROULETTE,
  ID_BLACKJACK,
  ID_ODDSARE,
  ID_RESETBAL,
};
