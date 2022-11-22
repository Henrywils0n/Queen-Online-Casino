#include "imagepanel.h"

BEGIN_EVENT_TABLE(wxImagePanel, wxPanel)
  EVT_PAINT(wxImagePanel::paintEvent)
  EVT_SIZE(wxImagePanel::OnSize)
END_EVENT_TABLE()

wxImagePanel::wxImagePanel(wxFrame* parent, wxString file, wxBitmapType format) : wxPanel(parent) {
  if (!image.LoadFile(file, format)) {
    wxLogError("Can't load PNG image.");
  }
  w = -1;
  h = -1;
}

void wxImagePanel::paintEvent(wxPaintEvent & evt) {
  wxPaintDC dc(this);
  render(dc);
}

void wxImagePanel::render(wxDC&  dc) {
  int neww, newh;
  dc.GetSize(&neww, &newh);
  
  if(neww != w || newh != h) {
    resized = wxBitmap(image.Scale(neww, newh));
    w = neww;
    h = newh;
    dc.DrawBitmap(resized, 0, 0, false);
  }else{
    dc.DrawBitmap(resized, 0, 0, false);
  }
}

/*
 * Here we call refresh to tell the panel to draw itself again.
 * So when the user resizes the image panel the image should be resized too.
 */
void wxImagePanel::OnSize(wxSizeEvent& event){
  Refresh();
  event.Skip();
}


//
//class MyApp: public wxApp
//{
//
//    wxFrame *frame;
//    wxImagePanel * drawPane;
//public:
//    bool OnInit()
//    {
//        // make sure to call this first
//        wxInitAllImageHandlers();
//
//        wxBoxSizer* sizer = new wxBoxSizer(wxHORIZONTAL);
//        frame = new wxFrame(NULL, wxID_ANY, wxT("Hello wxDC"), wxPoint(50,50), wxSize(800,600));
//
//        // then simply create like this
//        drawPane = new wxImagePanel( frame, wxT("image.jpg"), wxBITMAP_TYPE_JPEG);
//        sizer->Add(drawPane, 1, wxEXPAND);
//
//        frame->SetSizer(sizer);
//
//        frame->Show();
//        return true;
//    }
//
//};
//
//IMPLEMENT_APP(MyApp)
