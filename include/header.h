// Import every external library
#pragma once
#include <wx/wxprec.h>

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include <wx/image.h>
#include <wx/file.h>
#include <wx/filename.h>
#include <wx/mstream.h>
#include <wx/wfstream.h>
#include <wx/quantize.h>
#include <wx/stopwatch.h>
#include <wx/sizer.h>

// This is where all program enums should go, to maintain consistent formatting
enum {
  ID_QUIT  = wxID_EXIT,
  ID_ABOUT = wxID_ABOUT,
  ID_ROULETTE,
  ID_BLACKJACK,
  ID_ODDSARE,
  ID_RESETBAL,
  ID_OAQUIT,
  ID_OAGUESS,
  ID_RLQUIT,
  ID_BJQUIT,
  ID_MENUSCORE,
};
