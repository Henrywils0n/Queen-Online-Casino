#include "frame.h"
#include <sstream>

wxIMPLEMENT_DYNAMIC_CLASS(MyFrame, wxFrame);
wxBEGIN_EVENT_TABLE(MyFrame, wxFrame)
EVT_MENU(ID_ABOUT, MyFrame::OnAbout)
EVT_MENU(ID_QUIT,  MyFrame::OnQuit)
EVT_BUTTON(ID_ROULETTE,  MyFrame::OnPlayRoulette)
EVT_BUTTON(ID_BLACKJACK,  MyFrame::OnPlayBlackjack)
EVT_BUTTON(ID_ODDSARE,  MyFrame::OnPlayOddsAre)
wxEND_EVENT_TABLE()

MyFrame::MyFrame() : wxFrame( nullptr, wxID_ANY, "Casino Game", wxPoint(20, 20), wxSize(950, 700)) {
  wxMenuBar *menu_bar = new wxMenuBar();
  
  wxMenu *menuImage = new wxMenu;
  menuImage->Append( ID_ABOUT, "&About\tF1");
  menuImage->AppendSeparator();
  menuImage->Append( ID_QUIT, "&Exit\tCtrl-Q");
  menu_bar->Append(menuImage, "&Menu");
  SetMenuBar(menu_bar);
  
  clickCount = 0;
  
  //m_screen = new MyScreen(this, wxID_ANY, wxPoint(0,0), wxSize(10,10), wxTAB_TRAVERSAL, "Casino Game");
  
  char buf[1024];
  getcwd(buf, 1024);
  wxString dir = strcat(buf,"/gametitle.png");
  
  m_title = new wxImagePanel(this, dir, wxBITMAP_TYPE_PNG);
  
  roulette_button  = new wxButton(this, ID_ROULETTE,  "PLAY ROULETTE");
  blackjack_button = new wxButton(this, ID_BLACKJACK, "PLAY BLACKJACK");
  oddsare_button   = new wxButton(this, ID_ODDSARE,   "PLAY ODDS ARE");

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
}

void MyFrame::OnQuit(wxCommandEvent &WXUNUSED(event)) {
  Close(true);
}

void MyFrame::OnAbout(wxCommandEvent &WXUNUSED(event)) {
  wxArrayString array;
  
  array.Add("Casino Game");
  array.Add("(c) Team 23 Montreal 2022");
  array.Add(wxEmptyString);
  array.Add("Version of libraries used:");
  
  array.Add(wxPNGHandler::GetLibraryVersionInfo().ToString());
  
  (void)wxMessageBox(wxJoin(array, '\n'), "About Game", wxICON_INFORMATION | wxOK );
}

void MyFrame::OnPlayRoulette(wxCommandEvent &WXUNUSED(event)) {
  clickCount++;
  if (m_textCtrl) {
    std::wstringstream contents;
    contents << L"Button has been clicked " << clickCount << " times";
    m_textCtrl->SetValue(contents.str());
  }
}

void MyFrame::OnPlayBlackjack(wxCommandEvent &WXUNUSED(event)) {
  clickCount++;
  if (m_textCtrl) {
    std::wstringstream contents;
    contents << L"Button has been clicked " << clickCount << " times";
    m_textCtrl->SetValue(contents.str());
  }
}

void MyFrame::OnPlayOddsAre(wxCommandEvent &WXUNUSED(event)) {
  clickCount++;
  if (m_textCtrl) {
    std::wstringstream contents;
    contents << L"Button has been clicked " << clickCount << " times";
    m_textCtrl->SetValue(contents.str());
  }
}


