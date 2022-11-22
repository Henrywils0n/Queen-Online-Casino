#include "frame.h"

wxIMPLEMENT_DYNAMIC_CLASS(MyFrame, wxFrame);
wxBEGIN_EVENT_TABLE(MyFrame, wxFrame)
  EVT_MENU(ID_ABOUT, MyFrame::OnAbout)
  EVT_MENU(ID_QUIT,  MyFrame::OnQuit)
wxEND_EVENT_TABLE()

MyFrame::MyFrame() : wxFrame( nullptr, wxID_ANY, "Casino Game", wxPoint(20, 20), wxSize(950, 700)) {
  wxMenuBar *menu_bar = new wxMenuBar();
  
  wxMenu *menuImage = new wxMenu;
  menuImage->Append( ID_ABOUT, "&About\tF1");
  menuImage->AppendSeparator();
  menuImage->Append( ID_QUIT, "&Exit\tCtrl-Q");
  menu_bar->Append(menuImage, "&Menu");
  SetMenuBar(menu_bar);
  
  m_screen = new MyScreen(this, wxID_ANY, wxPoint(0,0), wxSize(10,10), wxTAB_TRAVERSAL, "Casino Game");
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
