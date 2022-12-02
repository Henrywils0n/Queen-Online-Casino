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
  ID_OAABOUT,
  ID_RLQUIT,
  ID_BJQUIT,
};

enum {
  ID_00,
  ID_0,
  ID_1,
  ID_2,
  ID_3,
  ID_4,
  ID_5,
  ID_6,
  ID_7,
  ID_8,
  ID_9,
  ID_10,
  ID_11,
  ID_12,
  ID_13,
  ID_14,
  ID_15,
  ID_16,
  ID_17,
  ID_18,
  ID_19,
  ID_20,
  ID_21,
  ID_22,
  ID_23,
  ID_24,
  ID_25,
  ID_26,
  ID_27,
  ID_28,
  ID_29,
  ID_30,
  ID_31,
  ID_32,
  ID_33,
  ID_34,
  ID_35,
  ID_36,
  ID_SUBMITROULETTEBET,
  ID_SPINWHEEL,
  ID_ROULETTEINFORMATION,
  ID_PLAYROULETTEAGAIN,
  ID_EXITROULETTE,
  ID_1to12,
  ID_13to24,
  ID_25to36,
  ID_1to18,
  ID_19to36,
  ID_EVEN,
  ID_ODD,
  ID_RED,
  ID_BLACK,
  ID_C1,
  ID_C2,
  ID_C3,
  ID_S1,
  ID_S4,
  ID_S7,
  ID_S10,
  ID_S13,
  ID_S16,
  ID_S19,
  ID_S22,
  ID_S25,
  ID_S28,
  ID_S31,
  ID_S34,
  ID_NOTHING,
};
