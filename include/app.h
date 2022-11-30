#pragma once
#include "header.h"

class CasinoApp: public wxApp {
public:
  virtual bool OnInit() override;
};

DECLARE_APP(CasinoApp)
