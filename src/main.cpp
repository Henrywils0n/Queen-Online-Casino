#include "frame.h"

//-----------------------------------------------------------------------------
// MyApp
//-----------------------------------------------------------------------------

class MyApp: public wxApp {
public:
  virtual bool OnInit() override;
};

IMPLEMENT_APP(MyApp)

bool MyApp::OnInit() {
  if (!wxApp::OnInit()) {
    return false;
  }
  
  wxInitAllImageHandlers();
  
  wxFrame *frame = new MyFrame();
  frame->Show(true);

  return true;
}
