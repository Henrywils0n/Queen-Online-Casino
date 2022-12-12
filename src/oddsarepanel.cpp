#include "../include/oddsarepanel.h"
#include <stdexcept>

BEGIN_EVENT_TABLE(OddsArePanel, wxPanel)
  EVT_BUTTON(ID_OAQUIT, OddsArePanel::onExitOddsAre)
  EVT_BUTTON(ID_OAGUESS, OddsArePanel::onGuess)
END_EVENT_TABLE()

OddsArePanel::OddsArePanel(GameFrame* par) : wxPanel(par) {
  parent = par;
  oa = new OddsAre(parent->getBalance());
  wxString backpng = "../resources/back_button.png";
  
  title_static = new wxStaticText(this, wxID_ANY, "ODDS ARE", wxDefaultPosition, wxSize(100, wxDefaultCoord));
  exit_button  = new ImageButton(this, ID_OAQUIT,  "MENU", backpng, wxBITMAP_TYPE_PNG, 40, 40);
  
  range_static = new wxStaticText(this, wxID_ANY, "Enter an upper limit (>1):", wxDefaultPosition, wxSize(200, wxDefaultCoord));
  guess_static= new wxStaticText(this, wxID_ANY, "Enter your guess:", wxDefaultPosition, wxSize(200, wxDefaultCoord));
  bet_static = new wxStaticText(this, wxID_ANY, "Enter your bet:", wxDefaultPosition, wxSize(200, wxDefaultCoord));
  
  range_ctrl = new wxTextCtrl(this, wxID_ANY, " ", wxDefaultPosition, wxSize(200, wxDefaultCoord));
  guess_ctrl = new wxTextCtrl(this, wxID_ANY, " ", wxDefaultPosition, wxSize(200, wxDefaultCoord));
  bet_ctrl = new wxTextCtrl(this, wxID_ANY, " ", wxDefaultPosition, wxSize(200, wxDefaultCoord));
  
  guess_button = new wxButton(this, ID_OAGUESS, "PLAY");
  
  wxBoxSizer* menuBox = new wxBoxSizer(wxHORIZONTAL);
  wxBoxSizer* vertBox = new wxBoxSizer(wxVERTICAL);
  wxBoxSizer* gameBox = new wxBoxSizer(wxHORIZONTAL);
  wxFlexGridSizer* inputBox = new wxFlexGridSizer(7, 1, 3, 3);

  menuBox->Add(exit_button, 1, wxSHAPED | wxSTRETCH_NOT);
  menuBox->Add(title_static, 1, wxSTRETCH_NOT);
  
  inputBox->Add(range_static, wxEXPAND);
  inputBox->Add(range_ctrl, wxEXPAND);
  inputBox->Add(guess_static, wxEXPAND);
  inputBox->Add(guess_ctrl, wxEXPAND);
  inputBox->Add(bet_static, wxEXPAND);
  inputBox->Add(bet_ctrl, wxEXPAND);
  
  gameBox->Add(inputBox, wxEXPAND);
  gameBox->Add(guess_button, wxEXPAND);

  vertBox->Add(menuBox, 0, wxSTRETCH_NOT);
  vertBox->Add(gameBox, 20, wxEXPAND);
  
  SetSizer(vertBox);
  vertBox->SetSizeHints(this);
}

void OddsArePanel::onExitOddsAre(wxCommandEvent &WXUNUSED(event)) {
  parent->returnToMenu();
}

void OddsArePanel::onGuess(wxCommandEvent &WXUNUSED(event)) {
  wxString range = range_ctrl->GetLineText(0);
  wxString guess = guess_ctrl->GetLineText(0);
  wxString bet = bet_ctrl->GetLineText(0);
  
  try {
    int rin = std::stoi(range.ToUTF8().data());
    int gin = std::stoi(range.ToUTF8().data());
    int bin = std::stoi(range.ToUTF8().data());
    
    int ret = oa->playGame(rin,gin,bin);
    parent->setBalance(parent->getBalance() + ret);
    if (ret > 0) {
      wxArrayString array;
      
      array.Add("YOU WIN!!!");
      array.Add("Your new balance is:");
      array.Add(wxString::Format(wxT("%i"),parent->getBalance()));
      (void)wxMessageBox(wxJoin(array, '\n'), "Result", wxICON_INFORMATION | wxOK );
    }
    else {
      wxArrayString array;
      
      array.Add("You lose.");
      array.Add("Your new balance is:");
      array.Add(wxString::Format(wxT("%i"),parent->getBalance()));
      (void)wxMessageBox(wxJoin(array, '\n'), "Result", wxICON_INFORMATION | wxOK );
    }
  }
  catch (std::exception &e) {
    wxArrayString array;
    
    array.Add("ERROR:");
    array.Add(e.what());
    (void)wxMessageBox(wxJoin(array, '\n'), "Error Message", wxICON_INFORMATION | wxOK );
  }
}