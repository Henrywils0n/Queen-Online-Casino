#pragma once
#include "header.h"
#include "gameframe.h"

class BlackjackPanel : public wxPanel {
public:
  BlackjackPanel(GameFrame* parent);

  wxTextCtrl* m_textCtrl;

  DECLARE_EVENT_TABLE()
};
