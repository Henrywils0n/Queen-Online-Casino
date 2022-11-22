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
#include <wx/sizer.h>
#include <unistd.h>

class wxImagePanel : public wxPanel
{
  wxImage image;
  wxBitmap resized;
  int w, h;
  
public:
  wxImagePanel(wxFrame* parent, wxString file, wxBitmapType format);
  
  void paintEvent(wxPaintEvent & evt);
  void paintNow();
  void OnSize(wxSizeEvent& event);
  void render(wxDC& dc);
  int getHeight();
  int getWidth();
  
  DECLARE_EVENT_TABLE()
};
