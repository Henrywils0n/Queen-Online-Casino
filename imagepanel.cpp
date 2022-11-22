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
  
  // Grab photo ratio to use in scaling.
  w = image.GetWidth();
  h = image.GetHeight();
  resized = wxBitmap(image.Scale(w, h));

  if(neww != w || newh != h) {
    int temph = round(neww*((double) h/ (double) w));
    int tempw = round(newh*((double) w/ (double) h));
    temph = (temph > newh) ? newh : temph;
    tempw = (tempw > neww) ? neww : tempw;
    resized = wxBitmap(image.Scale(tempw, temph));
    dc.DrawBitmap(resized, 0, 0, false);
  }else{
    dc.DrawBitmap(resized, 0, 0, false);
  }
}

void wxImagePanel::OnSize(wxSizeEvent& event) {
  Refresh();
  event.Skip();
}

int wxImagePanel::getWidth() {
  return w;
}

int wxImagePanel::getHeight() {
  return w;
}
