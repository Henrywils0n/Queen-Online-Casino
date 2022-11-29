#include "frame.h"
#include "game.h"

class BlackjackFrame: public wxFrame {
public:
  BlackjackFrame();
  
  void OnAbout(wxCommandEvent &event);
  void OnQuit(wxCommandEvent &event);
  void setRouter(Game* router);
  
  wxImagePanel* m_title;
  wxButton* roulette_button;
  wxButton* blackjack_button;
  wxButton* oddsare_button;
  wxTextCtrl* m_textCtrl;
  
private:
  wxDECLARE_DYNAMIC_CLASS(BlackjackFrame);
  wxDECLARE_EVENT_TABLE();
  Game *router;
};

enum {
  ID_QUIT  = wxID_EXIT,
  ID_ABOUT = wxID_ABOUT,
};

