#pragma once
#include "game.h"

class CasinoApp: public wxApp {
public:
  virtual bool OnInit() override;
};

DECLARE_APP(CasinoApp)
