#include "frameOA.h"
#include "game.h"
#include <sstream>

wxIMPLEMENT_DYNAMIC_CLASS(OddsAreFrame, wxFrame);
wxBEGIN_EVENT_TABLE(OddsAreFrame, wxFrame)
  EVT_MENU(ID_ABOUT, OddsAreFrame::OnAbout)
  EVT_MENU(ID_QUIT,  OddsAreFrame::OnQuit)
wxEND_EVENT_TABLE()

OddsAreFrame::OddsAreFrame() : wxFrame( nullptr, wxID_ANY, "Balckjack", wxPoint(30, 30), wxSize(1000, 700)) {
  
  wxMenuBar *menu_bar = new wxMenuBar();
  
  wxMenu *menu = new wxMenu;
  menu->Append( ID_ABOUT, "&About\tF1");
  menu->AppendSeparator();
  menu->Append( ID_QUIT, "&Exit\tCtrl-Q");
  menu_bar->Append(menu, "&Menu");
  SetMenuBar(menu_bar);

  // I am leaving this here for you to see how spacing works. Imagine a document object model (HTML)

  /*
  m_textCtrl = new wxTextCtrl(this, wxID_ANY, "Button has never been clicked.", wxDefaultPosition, wxSize(200, wxDefaultCoord));
  
  // Set up the sizers
  wxBoxSizer* inputBox = new wxBoxSizer(wxHORIZONTAL);
  wxBoxSizer* vertBox = new wxBoxSizer(wxVERTICAL);
  
  inputBox->Add(roulette_button,  1, wxEXPAND);
  inputBox->Add(blackjack_button, 1, wxEXPAND);
  inputBox->Add(oddsare_button,   1, wxEXPAND);
  
  vertBox->Add(m_title, 10, wxEXPAND);
  vertBox->Add(inputBox, 1, wxEXPAND);
  vertBox->Add(m_textCtrl, 1, wxEXPAND);
  
  SetSizer(vertBox);
  */
}

void setRouter(Game* router){
    router = router;
}

void OddsAreFrame::OnQuit(wxCommandEvent &WXUNUSED(event)) {
  router->returnToMenu();
}

void OddsAreFrame::OnAbout(wxCommandEvent &WXUNUSED(event)) {
  wxArrayString array;
  
  array.Add("Odds Are Game");
  array.Add("(c) Team 23 Montreal 2022");
  array.Add(wxEmptyString);
  array.Add("Version of libraries used:");
  
  array.Add(wxPNGHandler::GetLibraryVersionInfo().ToString());
  
  (void)wxMessageBox(wxJoin(array, '\n'), "About Game", wxICON_INFORMATION | wxOK );
}