#pragma once
#include "header.h"

class ImageButton : public wxButton {
  wxImage image;
  
public:
  ImageButton(wxWindow* parent, wxWindowID wid, wxString label, wxString file, wxBitmapType format, int w, int h);
  
};
