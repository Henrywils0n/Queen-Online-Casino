#include "screen.h"

class MyFrame: public wxFrame {
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
  //    ID_QUIT  = wxID_EXIT,
  //    ID_ABOUT = wxID_ABOUT,
  ID_QUIT,
  ID_ABOUT,
};
