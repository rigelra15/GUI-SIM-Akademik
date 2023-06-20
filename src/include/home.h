#ifndef HOME_H
#define HOME_H

#include <wx/wx.h>
#include <wx/image.h>
#include <wx/bitmap.h>
#include <wx/statbmp.h>


class MainMenuPage : public wxPanel
{
    public:
        MainMenuPage(wxWindow* parent);
        void OnButtonClicked(wxCommandEvent& event);

    private:
        wxTextCtrl* userBox;
        wxTextCtrl* passBox;
};

#endif // LOGIN_H