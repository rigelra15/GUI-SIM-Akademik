#ifndef LOGIN_H
#define LOGIN_H

#include <wx/wx.h>
#include <wx/image.h>
#include <wx/bitmap.h>
#include <wx/statbmp.h>
#include <string>


class LoginPage : public wxPanel
{
    public:
        std::string nama = "Rigel Ramadhani Waloni";
        std::string NRP = "5024221058";
        std::string password = "test123";
        LoginPage(wxWindow* parent);
        void OnClickedLoginButton(wxCommandEvent& event);

    private:
        wxTextCtrl* userBox;
        wxTextCtrl* passBox;
};

#endif