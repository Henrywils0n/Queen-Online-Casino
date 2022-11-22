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

#if wxUSE_CLIPBOARD
#include <wx/dataobj.h>
#include <wx/clipbrd.h>
#endif // wxUSE_CLIPBOARD

#include "screen.h"
#include <unistd.h>


wxBEGIN_EVENT_TABLE(MyScreen, wxPanel)
EVT_PAINT(MyScreen::OnPaint)
wxEND_EVENT_TABLE()
//wxPanel (wxWindow *parent, wxWindowID id=wxID_ANY, const wxPoint &pos=wxDefaultPosition, const wxSize &size=wxDefaultSize, long style=wxTAB_TRAVERSAL, const wxString &name=wxPanelNameStr)
MyScreen::MyScreen(wxWindow *parent, wxWindowID id,
                   const wxPoint &pos, const wxSize &size,
                   long style, const wxString &name) : wxPanel(parent) {
  m_ani_images = 0;
  
  SetBackgroundColour(*wxWHITE);
  
  wxBitmap bitmap( 100, 100 );
  
  wxMemoryDC dc;
  dc.SelectObject( bitmap );
  dc.SetBrush( wxBrush( "orange" ) );
  dc.SetPen( *wxBLACK_PEN );
  dc.DrawRectangle( 0, 0, 100, 100 );
  dc.SetBrush( *wxWHITE_BRUSH );
  dc.DrawRectangle( 20, 20, 60, 60 );
  dc.SelectObject( wxNullBitmap );
  
  char buf[1024];
  getcwd(buf, 1024);
  wxString dir = strcat(buf,"/");
  
  if (!wxFile::Exists(strcat(buf,"/gametitle.png"))) {
    wxLogWarning("Can't find image files in either '.' or '..'!");
  }
  wxImage image = bitmap.ConvertToImage();
  
  if (!image.SaveFile( dir + "test.png", wxBITMAP_TYPE_PNG)) {
    wxLogError("Can't save file");
  }
  image.Destroy();
  
  if(image.LoadFile(dir + "test.png")) {
    my_test = wxBitmap(image);
  }
  
  image.Destroy();
  
  if (!image.LoadFile(dir + "gametitle.png")) {
    wxLogError("Can't load PNG image");
  }
  else {
    title_png = wxBitmap(image);
  }
  
  //  my_toucan_flipped_horiz = wxBitmap(image.Mirror(true));
  //  my_toucan_flipped_vert = wxBitmap(image.Mirror(false));
  //  my_toucan_flipped_both = wxBitmap(image.Mirror(true).Mirror(false));
  //  my_toucan_grey = wxBitmap(image.ConvertToGreyscale());
  //  my_toucan_head = wxBitmap(image.GetSubImage(wxRect(40, 7, 80, 60)));
  //  my_toucan_scaled_normal = wxBitmap(image.Scale(110,90,wxIMAGE_QUALITY_NORMAL));
  //  my_toucan_scaled_high = wxBitmap(image.Scale(110,90,wxIMAGE_QUALITY_HIGH));
  //  my_toucan_blur = wxBitmap(image.Blur(10));
  
  CreateAntiAliasedBitmap();
}

void MyScreen::OnPaint(wxPaintEvent &WXUNUSED(event)) {
  wxPaintDC dc(this);
  PrepareDC(dc);
  
  dc.DrawText( "Loaded image", 30, 10 );
  if (my_test.IsOk())
    dc.DrawBitmap( my_test, 30, 30 );
  
  dc.DrawText( "Drawn directly", 150, 10 );
  dc.SetBrush( wxBrush( "orange" ) );
  dc.SetPen( *wxBLACK_PEN );
  dc.DrawRectangle( 150, 30, 100, 100 );
  dc.SetBrush( *wxWHITE_BRUSH );
  dc.DrawRectangle( 170, 50, 60, 60 );
  
  if (my_anti.IsOk())
    dc.DrawBitmap( my_anti, 280, 30 );
  
  dc.DrawText( "PNG handler", 30, 135 );
  if (title_png.IsOk())
  {
    dc.DrawBitmap( title_png, 30, 150 );
    wxRect rect(0,0,100,100);
    wxBitmap sub( title_png.GetSubBitmap(rect) );
    dc.DrawText( "GetSubBitmap()", 280, 175 );
    dc.DrawBitmap( sub, 280, 195 );
  }
  
  wxBitmap mono( 60,50,1 );
  wxMemoryDC memdc;
  memdc.SelectObject( mono );
  memdc.SetPen( *wxBLACK_PEN );
  memdc.SetBrush( *wxWHITE_BRUSH );
  memdc.DrawRectangle( 0,0,60,50 );
  memdc.SetTextForeground( *wxBLACK );
  
}

void MyScreen::CreateAntiAliasedBitmap() {
  wxBitmap bitmap(300, 300);
  
  {
    wxMemoryDC dc(bitmap);
    
    dc.Clear();
    
    dc.SetFont(wxFontInfo(24).Family(wxFONTFAMILY_DECORATIVE));
    dc.SetTextForeground("RED");
    dc.DrawText("This is anti-aliased Text.", 20, 5);
    dc.DrawText("And a Rectangle.", 20, 45);
    
    dc.SetBrush(*wxRED_BRUSH);
    dc.SetPen(*wxTRANSPARENT_PEN);
    dc.DrawRoundedRectangle(20, 85, 200, 180, 20);
  }
  
  wxImage original = bitmap.ConvertToImage();
  wxImage anti(150, 150);
  
  /* This is quite slow, but safe. Use wxImage::GetData() for speed instead. */
  
  for (int y = 1; y < 149; y++)
    for (int x = 1; x < 149; x++)
    {
      int red = original.GetRed( x*2, y*2 ) +
      original.GetRed( x*2-1, y*2 ) +
      original.GetRed( x*2, y*2+1 ) +
      original.GetRed( x*2+1, y*2+1 );
      red = red/4;
      
      int green = original.GetGreen( x*2, y*2 ) +
      original.GetGreen( x*2-1, y*2 ) +
      original.GetGreen( x*2, y*2+1 ) +
      original.GetGreen( x*2+1, y*2+1 );
      green = green/4;
      
      int blue = original.GetBlue( x*2, y*2 ) +
      original.GetBlue( x*2-1, y*2 ) +
      original.GetBlue( x*2, y*2+1 ) +
      original.GetBlue( x*2+1, y*2+1 );
      blue = blue/4;
      anti.SetRGB( x, y, (unsigned char)red, (unsigned char)green, (unsigned char)blue );
    }
  
  my_anti = wxBitmap(anti);
}

//-----------------------------------------------------------------------------
// MyApp
//-----------------------------------------------------------------------------

class MyApp: public wxApp {
public:
  virtual bool OnInit() override;
};

// ----------------------------------------------------------------------------
// MyFrame
// ----------------------------------------------------------------------------

class MyFrame: public wxFrame
{
public:
    MyFrame();

    void OnAbout(wxCommandEvent &event);
    void OnQuit(wxCommandEvent &event);

    MyScreen *m_screen;

private:
    wxDECLARE_DYNAMIC_CLASS(MyFrame);
    wxDECLARE_EVENT_TABLE();
};

enum {
    ID_ROTATE_LEFT = wxID_HIGHEST,
    ID_ROTATE_RIGHT,
    ID_RESIZE,
    ID_ZOOM_x2,
    ID_ZOOM_DC,
    ID_ZOOM_NEAREST,
    ID_ZOOM_BILINEAR,
    ID_ZOOM_BICUBIC,
    ID_ZOOM_BOX_AVERAGE,
    ID_PAINT_BG,
    ID_QUIT  = wxID_EXIT,
    ID_ABOUT = wxID_ABOUT,
};

wxIMPLEMENT_DYNAMIC_CLASS(MyFrame, wxFrame);
wxBEGIN_EVENT_TABLE(MyFrame, wxFrame)
    EVT_MENU    (ID_ABOUT, MyFrame::OnAbout)
    EVT_MENU    (ID_QUIT,  MyFrame::OnQuit)
wxEND_EVENT_TABLE()

MyFrame::MyFrame()
    : wxFrame( nullptr, wxID_ANY, "wxImage sample",
              wxPoint(20, 20), wxSize(950, 700) )
{
  
  wxMenuBar *menu_bar = new wxMenuBar();
  
  wxMenu *menuImage = new wxMenu;
  menuImage->Append( ID_ABOUT, "&About\tF1");
  menuImage->AppendSeparator();
  menuImage->Append( ID_QUIT, "&Exit\tCtrl-Q");
  
  SetMenuBar(menu_bar);
  
#if wxUSE_STATUSBAR
  CreateStatusBar(2);
  int widths[] = { -1, 100 };
  SetStatusWidths(2, widths);
#endif // wxUSE_STATUSBAR
  
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

IMPLEMENT_APP(MyApp)

bool MyApp::OnInit()
{
  if (!wxApp::OnInit()) {
    return false;
  }
  
  wxInitAllImageHandlers();
  
  wxFrame *frame = new MyFrame();
  frame->Show(true);

  return true;
}
