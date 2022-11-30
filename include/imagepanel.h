#pragma once
#include "header.h"
#include "gameframe.h"

class ImagePanel : public wxPanel {
  wxImage image;
  wxBitmap resized;
  int w, h;
  
public:
  ImagePanel(wxWindow* parent, wxString file, wxBitmapType format);
  
  void paintEvent(wxPaintEvent & evt);
  void paintNow();
  void OnSize(wxSizeEvent& event);
  void render(wxDC& dc);
  int getHeight();
  int getWidth();
  
  DECLARE_EVENT_TABLE()
};
