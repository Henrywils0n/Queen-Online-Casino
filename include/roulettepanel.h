#pragma once
#include "header.h"
#include "gameframe.h"

class RoulettePanel : public wxPanel {
public:
  RoulettePanel(GameFrame* parent);

  wxTextCtrl* m_textCtrl;

  DECLARE_EVENT_TABLE()
};
