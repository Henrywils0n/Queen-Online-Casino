#pragma once
#include "header.h"
#include "gameframe.h"


class OddsArePanel : public wxPanel {
public:
	OddsArePanel(GameFrame* parent);

	wxTextCtrl* m_textCtrl;

	DECLARE_EVENT_TABLE()
};
