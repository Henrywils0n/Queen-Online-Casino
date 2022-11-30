#include "../include/imagebutton.h"

ImageButton::ImageButton(wxWindow* parent, wxWindowID wid, wxString label, wxString file, wxBitmapType format, int w, int h) : wxButton(parent, wid, wxEmptyString, wxDefaultPosition, wxSize(w, h)) {
  if (!image.LoadFile(file, format)) {
    wxLogError("Can't load PNG image.");
  }
  SetBitmap(wxBitmap(image.Scale(w,h)));
}

