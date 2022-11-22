#include <wx/panel.h>
//wxPanel (wxWindow *parent, wxWindowID id=wxID_ANY, const wxPoint &pos=wxDefaultPosition, const wxSize &size=wxDefaultSize, long style=wxTAB_TRAVERSAL, const wxString &name=wxPanelNameStr)

class MyScreen: public wxPanel
{
public:
  MyScreen(wxWindow *parent, wxWindowID, const wxPoint &pos, const wxSize &size, long style, const wxString &name);
  //~MyScreen();
  
  void OnPaint(wxPaintEvent &event);
  void CreateAntiAliasedBitmap();
  
  wxBitmap  title_png;
  wxBitmap  my_test;
  wxBitmap  my_anti;
  
  int m_ani_images;
  
private:

  wxDECLARE_EVENT_TABLE();
};
