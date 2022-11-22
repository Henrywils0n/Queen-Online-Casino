#include <wx/wxprec.h>

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include <wx/image.h>
#include <wx/file.h>
#include <wx/filename.h>
#include <wx/mstream.h>
#include <wx/wfstream.h>
#include <wx/quantize.h>
#include <wx/stopwatch.h>
#include <unistd.h>

class MyScreen: public wxPanel {
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
