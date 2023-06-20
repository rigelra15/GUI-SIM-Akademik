#include <wx/wx.h>
#include <wx/image.h>
#include <wx/bitmap.h>
#include <wx/statbmp.h>
#include <wx/panel.h>
#include <wx/datetime.h>
#include <wx/stattext.h>
#include <wx/grid.h>
#include <wx/graphics.h>
#include <string>
#include "include/login.h"

using namespace std;

class Mahasiswa {
    public:
        string NRP = "5024221058";
        string name = "Rigel Ramadhani Waloni";
        string gender = "Laki-laki";
        string guardianLecturer = "Eko Pramunanto, S.T., M.T. (132125673)";
        string address = "Jl. Teknik Arsitektur H16, Keputih, Sukolilo, Kota Surabaya, Jawa Timur 60111";
        string phoneNumber = "085234115941";
        string email = "rigel8911@gmail.com";
        string homepage = "";
        string dateOfBirth = "15 Oktober 2004";
        string placeOfBirth = "Tungoi I";
        string religion = "Islam";
        string maritalStatus = "Belum Menikah";
        string nationality = "Indonesian";
        string bloodType = "A+";
        string access = "Mahasiswa";
};

class DateTime
{
    public:
    wxDateTime currentTime = wxDateTime::Now();
    int day = currentTime.GetDay();
    int mon = currentTime.GetMonth();
    int year = currentTime.GetYear();
    int hour = currentTime.GetHour();
    int minute = currentTime.GetMinute();
    int second = currentTime.GetSecond();

    std::string monthName[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
};

class DatePanel : public wxPanel
{
public:
    DatePanel(wxWindow* parent) : wxPanel(parent)
    {
        SetBackgroundColour(wxColour(255, 255, 255));
    }

    void OnPaint(wxPaintEvent& event)
    {
        DateTime dt;
        wxPaintDC dc(this);

        // Create a wxGraphicsContext from the device context
        wxGraphicsContext* gc = wxGraphicsContext::Create(dc);
        if (gc)
        {
            // Create gradient stops for the gradient fill
            wxGraphicsGradientStops gradientStops;
            gradientStops.Add(wxColour(36, 176, 253), 0.0);     // Start color at position 0
            gradientStops.Add(wxColour(17, 144, 233), 1.0);     // End color at position 1

            // Create a rectangle path
            wxGraphicsPath path = gc->CreatePath();
            path.AddRoundedRectangle(50, 50, 200, 150, 10);

            // Set the gradient brush using the graphics context
            wxGraphicsBrush brush = gc->CreateLinearGradientBrush(50, 50, 250, 150, gradientStops);
            gc->SetBrush(brush);

            // Draw the rounded rectangle with gradient fill
            gc->DrawPath(path);

            // Set color for the texts
            wxColour textColor(255, 255, 255); // White

            // Get the default system font and modify it to make it bold
            wxFont font = wxSystemSettings::GetFont(wxSYS_DEFAULT_GUI_FONT);
            font.SetWeight(wxFONTWEIGHT_BOLD);

            // Set the font properties for the first text with larger font size and bold style
            font.SetPointSize(40);
            font.SetWeight(wxFONTWEIGHT_BOLD);
            gc->SetFont(font, textColor);

            wxString text1 = wxString::Format("%d", dt.day);
            double textX1 = 47 + (100 - GetTextWidth(gc, text1)) / 2; // Center the text horizontally
            double textY1 = 90 + (100 - GetTextHeight(gc, text1)) / 2 - font.GetPointSize(); // Position above the center
            gc->DrawText(text1, textX1, textY1);

            // Set the font properties for the second text with smaller font size and bold style
            font.SetPointSize(11);
            font.SetWeight(wxFONTWEIGHT_BOLD);
            gc->SetFont(font, textColor);

            wxString text2 = dt.monthName[dt.mon];
            double textX2 = 68; // Center the text horizontally
            double textY2 = 80 + (100 - GetTextHeight(gc, text2)) / 2 + font.GetPointSize(); // Position below the center
            gc->DrawText(text2, textX2, textY2);

            font.SetPointSize(11);
            font.SetWeight(wxFONTWEIGHT_SEMIBOLD);
            gc->SetFont(font, textColor);

            wxString text3 = wxString::Format("%d", dt.year);
            double textX3 = 68; // Center the text horizontally
            double textY3 = 100 + (100 - GetTextHeight(gc, text3)) / 2 + font.GetPointSize(); // Position below the center
            gc->DrawText(text3, textX3, textY3);

            delete gc;
        }
    }

    double GetTextWidth(wxGraphicsContext* gc, const wxString& text)
    {
        double width, height;
        gc->GetTextExtent(text, &width, &height);
        return width;
    }

    double GetTextHeight(wxGraphicsContext* gc, const wxString& text)
    {
        double width, height;
        gc->GetTextExtent(text, &width, &height);
        return height;
    }

    wxDECLARE_EVENT_TABLE();
};

wxBEGIN_EVENT_TABLE(DatePanel, wxPanel)
    EVT_PAINT(DatePanel::OnPaint)
wxEND_EVENT_TABLE()

class DateFrame : public wxFrame
{
    public:
    DateFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title)
    {
        SetSize(400, 300);
        Centre();

        DatePanel* panel = new DatePanel(this);
    }
};

class TranskripPanel : public wxPanel
{
    public:
    TranskripPanel(wxWindow* parent) : wxPanel(parent, wxID_ANY)
    {
        wxStaticText* titleTranskrip = new wxStaticText(this, wxID_ANY, "Biodata Mahasiswa");
        wxFont titleTranskripBig(titleTranskrip->GetFont());
        titleTranskripBig.SetPointSize(20);
        titleTranskripBig.SetWeight(wxFONTWEIGHT_BOLD);
        titleTranskrip->SetForegroundColour("#0293db");
        titleTranskrip->SetFont(titleTranskripBig);

        wxPNGHandler* handler = new wxPNGHandler;
        wxImage::AddHandler(handler);
        wxStaticBitmap* imageTranskrip = new wxStaticBitmap(this, wxID_ANY, wxBitmap("transkrip.png", wxBITMAP_TYPE_PNG), wxDefaultPosition, wxDefaultSize);

        wxBoxSizer* transkripBox = new wxBoxSizer(wxVERTICAL);
        transkripBox->Add(titleTranskrip, wxSizerFlags().Center().Border(wxALL, 5));
        transkripBox->Add(imageTranskrip, wxSizerFlags().Center().Border(wxALL, 5));

        SetSizerAndFit(transkripBox);
    }
};

class TranskripFrame : public wxFrame
{
    public:
    TranskripFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title)
    {
        TranskripPanel* transkripPanel = new TranskripPanel(this);
        wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
        mainSizer->Add(transkripPanel, wxSizerFlags(1).Expand());

        SetSizerAndFit(mainSizer);
        Centre();
    }
};

class FRSPanel : public wxPanel
{
    public:
        FRSPanel(wxWindow* parent) : wxPanel(parent, wxID_ANY)
        {
            wxStaticText* titleFRS = new wxStaticText(this, wxID_ANY, "Biodata Mahasiswa");
            wxFont titleFRSBig(titleFRS->GetFont());
            titleFRSBig.SetPointSize(20);
            titleFRSBig.SetWeight(wxFONTWEIGHT_BOLD);
            titleFRS->SetForegroundColour("#0293db");
            titleFRS->SetFont(titleFRSBig);

            wxPNGHandler* handler = new wxPNGHandler;
            wxImage::AddHandler(handler);
            wxStaticBitmap* imageFRS = new wxStaticBitmap(this, wxID_ANY, wxBitmap("frs.png", wxBITMAP_TYPE_PNG), wxDefaultPosition, wxDefaultSize);

            wxBoxSizer* frsBox = new wxBoxSizer(wxVERTICAL);
            frsBox->Add(titleFRS, wxSizerFlags().Center().Border(wxALL, 5));
            frsBox->Add(imageFRS, wxSizerFlags().Center().Border(wxALL, 5));

            SetSizerAndFit(frsBox);
        }
};

class FRSFrame : public wxFrame
{
    public:
    FRSFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title)
    {
        FRSPanel* frsPanel = new FRSPanel(this);

        wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
        mainSizer->Add(frsPanel, wxSizerFlags(1).Expand());

        SetSizerAndFit(mainSizer);
        Centre();
    }
};


class BiodataMahasiswaPanel : public wxPanel
{
    public:
    BiodataMahasiswaPanel(wxWindow* parent) : wxPanel(parent, wxID_ANY)
    {
        Mahasiswa mhs;
        wxStaticText* titleBiodata = new wxStaticText(this, wxID_ANY, "Biodata Mahasiswa");
        wxFont titleBiodataBig(titleBiodata->GetFont());
        titleBiodataBig.SetPointSize(20);
        titleBiodataBig.SetWeight(wxFONTWEIGHT_BOLD);
        titleBiodata->SetForegroundColour("#0293db");
        titleBiodata->SetFont(titleBiodataBig);

        wxGrid* biodataGrid = new wxGrid(this, wxID_ANY);

        biodataGrid->CreateGrid(15, 1);

        biodataGrid->SetRowLabelValue(0, "NRP");
        biodataGrid->SetRowLabelValue(1, "Nama");
        biodataGrid->SetRowLabelValue(2, "Nama Lengkap");
        biodataGrid->SetRowLabelValue(3, "Jenis Kelamin");
        biodataGrid->SetRowLabelValue(4, "Dosen Wali");
        biodataGrid->SetRowLabelValue(5, "Alamat Tinggal");
        biodataGrid->SetRowLabelValue(6, "Telepon");
        biodataGrid->SetRowLabelValue(7, "Email");
        biodataGrid->SetRowLabelValue(8, "Homepage");
        biodataGrid->SetRowLabelValue(9, "Tanggal Lahir");
        biodataGrid->SetRowLabelValue(10, "Tempat Lahir");
        biodataGrid->SetRowLabelValue(11, "Agama");
        biodataGrid->SetRowLabelValue(12, "Status Nikah");
        biodataGrid->SetRowLabelValue(13, "Kewarganegaraan");
        biodataGrid->SetRowLabelValue(14, "Gol. Darah");

        biodataGrid->SetColLabelValue(0, "Biodata Mahasiswa");

        biodataGrid->SetCellValue(0, 0, mhs.NRP);
        biodataGrid->SetCellValue(1, 0, mhs.name);
        biodataGrid->SetCellValue(2, 0, mhs.name);
        biodataGrid->SetCellValue(3, 0, mhs.gender);
        biodataGrid->SetCellValue(4, 0, mhs.guardianLecturer);
        biodataGrid->SetCellValue(5, 0, mhs.address);
        biodataGrid->SetCellValue(6, 0, mhs.phoneNumber);
        biodataGrid->SetCellValue(7, 0, mhs.email);
        biodataGrid->SetCellValue(8, 0, mhs.homepage);
        biodataGrid->SetCellValue(9, 0, mhs.dateOfBirth);
        biodataGrid->SetCellValue(10, 0, mhs.placeOfBirth);
        biodataGrid->SetCellValue(11, 0, mhs.religion);
        biodataGrid->SetCellValue(12, 0, mhs.maritalStatus);
        biodataGrid->SetCellValue(13, 0, mhs.nationality);
        biodataGrid->SetCellValue(14, 0, mhs.bloodType);

        biodataGrid->AutoSizeColumns();

        wxJPEGHandler *handler = new wxJPEGHandler;
        wxImage::AddHandler(handler);
        wxStaticBitmap* imagePasFoto = new wxStaticBitmap(this, wxID_ANY, wxBitmap("pasfoto.jpg", wxBITMAP_TYPE_JPEG), wxDefaultPosition, wxDefaultSize);

        wxBoxSizer* biodataBox = new wxBoxSizer(wxHORIZONTAL);
        biodataBox->Add(biodataGrid, wxSizerFlags().Center().Border(wxALL, 5));
        biodataBox->Add(imagePasFoto, wxSizerFlags().Center().Border(wxALL, 5));

        wxBoxSizer* panelSizer = new wxBoxSizer(wxVERTICAL);
        panelSizer->AddSpacer(50);
        panelSizer->Add(titleBiodata, wxSizerFlags().Center().Border(wxALL, 5));
        panelSizer->Add(biodataBox, wxSizerFlags().Center().Border(wxALL, 5));

        SetSizerAndFit(panelSizer);
    }
};

class BiodataMahasiswaFrame : public wxFrame
{
    public:
    BiodataMahasiswaFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title)
    {
        BiodataMahasiswaPanel* biodataMahasiswaPanel = new BiodataMahasiswaPanel(this);

        wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
        mainSizer->Add(biodataMahasiswaPanel, wxSizerFlags(1).Expand());

        SetSizerAndFit(mainSizer);
        Centre();
    }
};

class MainPanel : public wxPanel
{
public:
    MainPanel(wxWindow* parent, LoginPage& loginPage) : wxPanel(parent, wxID_ANY)
    {
        string nama = loginPage.nama;
        string NRP = loginPage.NRP;
        wxButton* homeButton = new wxButton(this, wxID_ANY, "Home");
        wxButton* dataButton = new wxButton(this, wxID_ANY, "Data");
        wxButton* prosesButton = new wxButton(this, wxID_ANY, "Proses");
        wxButton* laporanButton = new wxButton(this, wxID_ANY, "Laporan");
        wxButton* lain_lainButton = new wxButton(this, wxID_ANY, "Lain-Lain");
        wxButton* ekivalensiButton = new wxButton(this, wxID_ANY, "Ekivalensi");
        wxButton* yudisiumButton = new wxButton(this, wxID_ANY, "Yudisium");
        wxButton* skpiButton = new wxButton(this, wxID_ANY, "SKPI");
        wxButton* biayaPendidikanButton = new wxButton(this, wxID_ANY, "Biaya Pendidikan");
        wxButton* suratMahasiswaButton = new wxButton(this, wxID_ANY, "Surat Mahasiswa");
        wxButton* signOutButton = new wxButton(this, wxID_ANY, "Keluar");
        signOutButton->SetBackgroundColour(*wxYELLOW);

        // ===== UNTUK BAR INFO =====
        wxDateTime currentTime = wxDateTime::Now();
        int day = currentTime.GetDay();
        int mon = currentTime.GetMonth() + 1;
        int year = currentTime.GetYear();
        int hour = currentTime.GetHour();
        int minute = currentTime.GetMinute();
        int second = currentTime.GetSecond();
        string semester;

        string addZeroHour, addZeroMinute, addZeroSecond;
        if (hour < 10)
        {
            addZeroHour = "0";
        }
        if (minute < 10)
        {
            addZeroMinute = "0";
        }
        if (second < 10)
        {
            addZeroSecond = "0";
        }

        if (mon>=1 && mon <=6)
        {
            semester = "Semester Genap";
        } else 
        {
            semester = "Semester Ganjil";
        }
        wxStaticText* timeNow = new wxStaticText(this, wxID_ANY, wxString::Format("Periode: %s %d/%d Tanggal: %d/%d/%d %s%d:%s%d:%s%d +0700                                                                                                                                                                                                                          User ID: %s, %s         ", semester, year-1, year, day, mon, year, addZeroHour, hour, addZeroMinute, minute, addZeroSecond, second, NRP, nama));
        timeNow->SetBackgroundColour("#ece9d8");

        wxStaticText* hakAksesText = new wxStaticText(this, wxID_ANY, "Hak Akses: ");
        wxFont hakAksesTextBold(hakAksesText->GetFont());
        hakAksesTextBold.SetWeight(wxFONTWEIGHT_BOLD);
        hakAksesText->SetFont(hakAksesTextBold);
        hakAksesText->SetBackgroundColour("#ece9d8");

        wxArrayString access;
        access.Add("- Pilih Hak Akses -");
        access.Add("Mahasiswa");
        access.Add("Dosen");
        access.Add("Tendik");

        wxChoice* hakAkses = new wxChoice(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, access);
        hakAkses->Select(1);

        wxArrayString faculty;
        faculty.Add("- Pilih Fakultas -");
        faculty.Add("CIVPLAN");
        faculty.Add("CREABIZ");
        faculty.Add("ELECTICS");
        faculty.Add("INDSYS");
        faculty.Add("MARTECH");
        faculty.Add("MEDICS");
        faculty.Add("SCIENTICS");
        faculty.Add("SIMT");
        faculty.Add("VOCATIONS");

        wxChoice* fakultas = new wxChoice(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, faculty);
        fakultas->Select(3);
        fakultas->SetBackgroundColour("#eeef66");

        wxArrayString studyProgram;
        studyProgram.Add("- Pilih Prodi -");
        studyProgram.Add("29100 - 07214000 - S-1 TEKNIK KOMPUTER");

        wxChoice* prodi = new wxChoice(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, studyProgram);
        prodi->Select(1);
        prodi->SetBackgroundColour("#ffcccc");
        // ==========================

        wxPNGHandler *handler = new wxPNGHandler;
        wxImage::AddHandler(handler);
        double aspectRatio1 = static_cast<double>(1022) / static_cast<double>(60);
        int desiredWidth1 = 900;
        int desiredHeight1 = static_cast<int>(desiredWidth1 / aspectRatio1);
        wxBitmap resizedBitmap1(wxBitmap("header.png", wxBITMAP_TYPE_PNG).ConvertToImage().Rescale(desiredWidth1, desiredHeight1));
        wxStaticBitmap* imageLogoSIAKAD = new wxStaticBitmap(this, wxID_ANY, resizedBitmap1, wxDefaultPosition, wxSize(desiredWidth1, desiredHeight1));
        // wxStaticBitmap* imageWelcome = new wxStaticBitmap(this, wxID_ANY, wxBitmap("welcome.png", wxBITMAP_TYPE_PNG), wxDefaultPosition, wxDefaultSize);

        wxStaticText* modulHeader = new wxStaticText(this, wxID_ANY, "Berikut modul-modul yang bisa Anda akses:", wxDefaultPosition, wxDefaultSize);
        wxFont boldFont(modulHeader->GetFont());
        boldFont.SetWeight(wxFONTWEIGHT_BOLD);
        boldFont.SetPointSize(15);
        modulHeader->SetFont(boldFont);

        wxStaticText* dataHeader = new wxStaticText(this, wxID_ANY, "Data", wxDefaultPosition, wxSize(3000, 20), wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        wxStaticText* prosesHeader = new wxStaticText(this, wxID_ANY, "Proses", wxDefaultPosition, wxSize(3000, 20), wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        wxStaticText* laporanHeader = new wxStaticText(this, wxID_ANY, "Laporan", wxDefaultPosition, wxSize(3000, 20), wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        wxStaticText* lain_lainHeader = new wxStaticText(this, wxID_ANY, "Lain-Lain", wxDefaultPosition, wxSize(3000, 20), wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        wxStaticText* ekivalensiHeader = new wxStaticText(this, wxID_ANY, "Ekivalensi", wxDefaultPosition, wxSize(3000, 20), wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        wxStaticText* yudisiumHeader = new wxStaticText(this, wxID_ANY, "Yudisium", wxDefaultPosition, wxSize(3000, 20), wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        wxStaticText* skpiHeader = new wxStaticText(this, wxID_ANY, "SKPI", wxDefaultPosition, wxSize(3000, 20), wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        wxStaticText* biayaHeader = new wxStaticText(this, wxID_ANY, "Biaya Pendidikan", wxDefaultPosition, wxSize(3000, 20), wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        wxStaticText* suratHeader = new wxStaticText(this, wxID_ANY, "Surat Mahasiswa", wxDefaultPosition, wxSize(3000, 20), wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        dataHeader->SetBackgroundColour("#dfe3eb");
        prosesHeader->SetBackgroundColour("#dfe3eb");
        laporanHeader->SetBackgroundColour("#dfe3eb");
        lain_lainHeader->SetBackgroundColour("#dfe3eb");
        ekivalensiHeader->SetBackgroundColour("#dfe3eb");
        yudisiumHeader->SetBackgroundColour("#dfe3eb");
        skpiHeader->SetBackgroundColour("#dfe3eb");
        biayaHeader->SetBackgroundColour("#dfe3eb");
        suratHeader->SetBackgroundColour("#dfe3eb");

        wxButton* verifikasiBiodataButton = new wxButton(this, wxID_ANY, "Verifikasi Biodata");
        wxButton* updateDataWisudaButton = new wxButton(this, wxID_ANY, "Update Data Wisuda");
        wxButton* ekivalensi2Button = new wxButton(this, wxID_ANY, "Ekivalensi");
        wxButton* kuisionerButton = new wxButton(this, wxID_ANY, "Kuesioner Dosen dan MK");
        kuisionerButton->Bind(wxEVT_BUTTON, &MainPanel::OnKuisionerButtonClicked, this);
        wxButton* kurikulumButton = new wxButton(this, wxID_ANY, "Kurikulum Semester");
        wxButton* frsButton = new wxButton(this, wxID_ANY, "Formulir Rencana Studi");
        frsButton->Bind(wxEVT_BUTTON, &MainPanel::OnFRSButtonClicked, this);
        wxButton* transkripButton = new wxButton(this, wxID_ANY, "Transkrip");
        transkripButton->Bind(wxEVT_BUTTON, &MainPanel::OnTranskripButtonClicked, this);
        wxButton* transkripSButton = new wxButton(this, wxID_ANY, "Transkrip Sementara");
        wxButton* akademikButton = new wxButton(this, wxID_ANY, "Akademik Mahasiswa");
        wxButton* ktmVirtualButton = new wxButton(this, wxID_ANY, "KTM Virtual");
        wxButton* biodataMahasiswaButton = new wxButton(this, wxID_ANY, "Biodata Mahasiswa");
        biodataMahasiswaButton->Bind(wxEVT_BUTTON, &MainPanel::OnBiodataMahasiswaButtonClicked, this);
        wxButton* perkuliahanButton = new wxButton(this, wxID_ANY, "Perkuliahan Mahasiswa");
        wxButton* daftarMnMButton = new wxButton(this, wxID_ANY, "Daftar Mahasiswa dan Matakuliah");
        wxButton* statusPerAngkatanButton = new wxButton(this, wxID_ANY, "Status Per Angkatan");
        wxButton* prasyaratButton = new wxButton(this, wxID_ANY, "Prasyarat Matakuliah");
        wxButton* jadwalKuliahButton = new wxButton(this, wxID_ANY, "Jadwal Kuliah Mahasiswa");
        wxButton* nilaiPerMhsButton = new wxButton(this, wxID_ANY, "Nilai Per Mahasiswa");
        wxButton* nilaiPerSmtButton = new wxButton(this, wxID_ANY, "Nilai Per Semester");
        wxButton* surveiKepuasanButton = new wxButton(this, wxID_ANY, "Survei Kepuasan Mahasiswa");
        wxButton* rekapEkivalensiButton = new wxButton(this, wxID_ANY, "Rekapitulasi Ekivalensi");
        wxButton* draftSKPIButton = new wxButton(this, wxID_ANY, "Draft SKPI");
        wxButton* guideBookButton = new wxButton(this, wxID_ANY, "Panduan Umum (pdf)");
        wxButton* sebagaiMhsButton = new wxButton(this, wxID_ANY, "Sebagai Mahasiswa (pdf)");
        wxButton* historisSPPButton = new wxButton(this, wxID_ANY, "Historis Pembayaran SPP");
        wxButton* tagihanSPPButton = new wxButton(this, wxID_ANY, "Tagihan Biaya Pendidikan");
        wxButton* tagihanWisudaButton = new wxButton(this, wxID_ANY, "Pembayaran Wisuda");
        wxButton* layananSuratButton = new wxButton(this, wxID_ANY, "Layanan Surat Mahasiswa");
        wxButton* suratMahasiswa2Button = new wxButton(this, wxID_ANY, "Panduan Layanan (PDF)");

        wxBoxSizer* dataBox = new wxBoxSizer(wxHORIZONTAL);
        dataBox->Add(verifikasiBiodataButton, wxSizerFlags().Center().Border(wxALL, 5));
        dataBox->Add(updateDataWisudaButton, wxSizerFlags().Center().Border(wxALL, 5));
        dataBox->Add(ekivalensi2Button, wxSizerFlags().Center().Border(wxALL, 5));

        wxBoxSizer* prosesBox = new wxBoxSizer(wxHORIZONTAL);
        prosesBox->Add(kuisionerButton, wxSizerFlags().Center().Border(wxALL, 5));
        prosesBox->Add(kurikulumButton, wxSizerFlags().Center().Border(wxALL, 5));
        prosesBox->Add(frsButton, wxSizerFlags().Center().Border(wxALL, 5));

        wxBoxSizer* laporanBox = new wxBoxSizer(wxHORIZONTAL);
        laporanBox->Add(transkripButton, wxSizerFlags().Center().Border(wxALL, 5));
        laporanBox->Add(transkripSButton, wxSizerFlags().Center().Border(wxALL, 5));
        laporanBox->Add(akademikButton, wxSizerFlags().Center().Border(wxALL, 5));
        laporanBox->Add(ktmVirtualButton, wxSizerFlags().Center().Border(wxALL, 5));
        laporanBox->Add(biodataMahasiswaButton, wxSizerFlags().Center().Border(wxALL, 5));
        laporanBox->Add(perkuliahanButton, wxSizerFlags().Center().Border(wxALL, 5));
        laporanBox->Add(daftarMnMButton, wxSizerFlags().Center().Border(wxALL, 5));
        laporanBox->Add(statusPerAngkatanButton, wxSizerFlags().Center().Border(wxALL, 5));
        laporanBox->Add(prasyaratButton, wxSizerFlags().Center().Border(wxALL, 5));
        laporanBox->Add(jadwalKuliahButton, wxSizerFlags().Center().Border(wxALL, 5));
        laporanBox->Add(nilaiPerMhsButton, wxSizerFlags().Center().Border(wxALL, 5));
        laporanBox->Add(nilaiPerSmtButton, wxSizerFlags().Center().Border(wxALL, 5));

        wxBoxSizer* lain_lainBox = new wxBoxSizer(wxHORIZONTAL);
        lain_lainBox->Add(surveiKepuasanButton, wxSizerFlags().Center().Border(wxALL, 5));

        wxBoxSizer* ekivalensiBox = new wxBoxSizer(wxHORIZONTAL);
        ekivalensiBox->Add(rekapEkivalensiButton, wxSizerFlags().Center().Border(wxALL, 5));

        wxBoxSizer* yudisiumBox = new wxBoxSizer(wxHORIZONTAL);

        wxBoxSizer* skpiBox = new wxBoxSizer(wxHORIZONTAL);
        skpiBox->Add(draftSKPIButton, wxSizerFlags().Center().Border(wxALL, 5));
        skpiBox->Add(guideBookButton, wxSizerFlags().Center().Border(wxALL, 5));
        skpiBox->Add(sebagaiMhsButton, wxSizerFlags().Center().Border(wxALL, 5));

        wxBoxSizer* biayaBox = new wxBoxSizer(wxHORIZONTAL);
        biayaBox->Add(historisSPPButton, wxSizerFlags().Center().Border(wxALL, 5));
        biayaBox->Add(tagihanSPPButton, wxSizerFlags().Center().Border(wxALL, 5));
        biayaBox->Add(tagihanWisudaButton, wxSizerFlags().Center().Border(wxALL, 5));

        wxBoxSizer* suratBox = new wxBoxSizer(wxHORIZONTAL);
        suratBox->Add(layananSuratButton, wxSizerFlags().Center().Border(wxALL, 5));
        suratBox->Add(suratMahasiswa2Button, wxSizerFlags().Center().Border(wxALL, 5));

        wxBoxSizer* logoSIAKADPos = new wxBoxSizer(wxHORIZONTAL);
        logoSIAKADPos->Add(imageLogoSIAKAD, wxSizerFlags().Left().Border(wxALL, 5));

        wxBoxSizer* navBar = new wxBoxSizer(wxHORIZONTAL);
        navBar->Add(homeButton, wxSizerFlags().Left().Border(wxALL, 5));
        navBar->Add(dataButton, wxSizerFlags().Left().Border(wxALL, 5));
        navBar->Add(prosesButton, wxSizerFlags().Left().Border(wxALL, 5));
        navBar->Add(laporanButton, wxSizerFlags().Left().Border(wxALL, 5));
        navBar->Add(lain_lainButton, wxSizerFlags().Left().Border(wxALL, 5));
        navBar->Add(ekivalensiButton, wxSizerFlags().Left().Border(wxALL, 5));
        navBar->Add(yudisiumButton, wxSizerFlags().Left().Border(wxALL, 5));
        navBar->Add(skpiButton, wxSizerFlags().Left().Border(wxALL, 5));
        navBar->Add(biayaPendidikanButton, wxSizerFlags().Left().Border(wxALL, 5));
        navBar->Add(suratMahasiswaButton, wxSizerFlags().Left().Border(wxALL, 5));
        navBar->Add(signOutButton, wxSizerFlags().Left().Border(wxALL, 5));

        wxBoxSizer* barInfo = new wxBoxSizer(wxHORIZONTAL);
        barInfo->Add(timeNow, wxSizerFlags().Border(wxALL, 5));
        barInfo->Add(hakAksesText, wxSizerFlags().Border(wxALL, 5));
        barInfo->Add(hakAkses, wxSizerFlags().Border(wxALL, 5));
        barInfo->Add(fakultas, wxSizerFlags().Border(wxALL, 5));
        barInfo->Add(prodi, wxSizerFlags().Border(wxALL, 5));

        wxBoxSizer* allMenu = new wxBoxSizer(wxVERTICAL);
        allMenu->Add(logoSIAKADPos, wxSizerFlags().Border(wxALL, 5));
        allMenu->Add(navBar, wxSizerFlags().Border(wxALL, 5));
        allMenu->Add(barInfo, wxSizerFlags().Border(wxALL, 5));

        allMenu->Add(modulHeader, wxSizerFlags().Center().Border(wxALL, 5));
        allMenu->AddSpacer(20);
        allMenu->Add(dataHeader, wxSizerFlags().Center().Border(wxALL, 5));
        allMenu->Add(dataBox, wxSizerFlags().Center().Border(wxALL, 5));
        allMenu->AddSpacer(20);
        allMenu->Add(prosesHeader, wxSizerFlags().Center().Border(wxALL, 5));
        allMenu->Add(prosesBox, wxSizerFlags().Center().Border(wxALL, 5));
        allMenu->AddSpacer(20);
        allMenu->Add(laporanHeader, wxSizerFlags().Center().Border(wxALL, 5));
        allMenu->Add(laporanBox, wxSizerFlags().Center().Border(wxALL, 5));
        allMenu->AddSpacer(20);
        allMenu->Add(lain_lainHeader, wxSizerFlags().Center().Border(wxALL, 5));
        allMenu->Add(lain_lainBox, wxSizerFlags().Center().Border(wxALL, 5));
        allMenu->AddSpacer(20);
        allMenu->Add(ekivalensiHeader, wxSizerFlags().Center().Border(wxALL, 5));
        allMenu->Add(ekivalensiBox, wxSizerFlags().Center().Border(wxALL, 5));
        allMenu->AddSpacer(20);
        allMenu->Add(yudisiumHeader, wxSizerFlags().Center().Border(wxALL, 5));
        allMenu->Add(yudisiumBox, wxSizerFlags().Center().Border(wxALL, 5));
        allMenu->AddSpacer(20);
        allMenu->Add(skpiHeader, wxSizerFlags().Center().Border(wxALL, 5));
        allMenu->Add(skpiBox, wxSizerFlags().Center().Border(wxALL, 5));
        allMenu->AddSpacer(20);
        allMenu->Add(biayaHeader, wxSizerFlags().Center().Border(wxALL, 5));
        allMenu->Add(biayaBox, wxSizerFlags().Center().Border(wxALL, 5));
        allMenu->AddSpacer(20);
        allMenu->Add(suratHeader, wxSizerFlags().Center().Border(wxALL, 5));
        allMenu->Add(suratBox, wxSizerFlags().Center().Border(wxALL, 5));

        SetSizerAndFit(allMenu);
    }

    void OnBiodataMahasiswaButtonClicked(wxCommandEvent& event)
    {
        BiodataMahasiswaFrame* biodataMahasiswaFrame = new BiodataMahasiswaFrame("Biodata Mahasiswa | SI Akademik");
        biodataMahasiswaFrame->SetClientSize(1600, 900);
        biodataMahasiswaFrame->Centre();
        biodataMahasiswaFrame->Show();
    }

    void OnFRSButtonClicked(wxCommandEvent& event)
    {
        FRSFrame* frsFrame = new FRSFrame("Formulir Rencana Studi | SI Akademik");
        frsFrame->SetClientSize(1600, 900);
        frsFrame->Centre();
        frsFrame->Show();
    }

    void OnTranskripButtonClicked(wxCommandEvent& event)
    {
        TranskripFrame* transkripFrame = new TranskripFrame("Formulir Rencana Studi | SI Akademik");
        transkripFrame->SetClientSize(1600, 900);
        transkripFrame->Centre();
        transkripFrame->Show();
    }

    void OnKuisionerButtonClicked(wxCommandEvent& event)
    {
        DateFrame* dateFrame = new DateFrame("Date Panel | SI Akademik");
        dateFrame->SetClientSize(1600, 900);
        dateFrame->Centre();
        dateFrame->Show();
    }
};

class MainMenuPanel : public wxPanel
{
    public:
        MainMenuPanel(wxWindow* parent) : wxPanel(parent, wxID_ANY)
        {
            LoginPage* loginPage = new LoginPage(this);
            loginPage->Hide();
            MainPanel* mainPanel = new MainPanel(this, *loginPage);

            wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
            mainSizer->Add(mainPanel, wxSizerFlags(1).Expand());

            SetSizerAndFit(mainSizer);
        }
};


class MainMenuFrame : public wxFrame
{
    public:
        MainMenuFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title)
        {
            MainMenuPanel* mainPanel = new MainMenuPanel(this);

            wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
            mainSizer->Add(mainPanel, wxSizerFlags(1).Expand());

            SetSizerAndFit(mainSizer);
        }
};

LoginPage::LoginPage(wxWindow* parent):wxPanel(parent, wxID_ANY)
{
    wxStaticText* userText = new wxStaticText(this, wxID_ANY, "MyITS ID:   ");
    wxStaticText* passText = new wxStaticText(this, wxID_ANY, "Password: ");

    wxButton* login = new wxButton(this, wxID_ANY, "Login");

    userBox = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER);
    passBox = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, wxTE_PASSWORD | wxTE_PROCESS_ENTER);
    login->Bind(wxEVT_BUTTON, &LoginPage::OnClickedLoginButton, this);
    
    wxPNGHandler *handler = new wxPNGHandler;
    wxImage::AddHandler(handler);

    double aspectRatio1 = static_cast<double>(300) / static_cast<double>(185);
    int desiredWidth1 = 100;
    int desiredHeight1 = static_cast<int>(desiredWidth1 / aspectRatio1);
    wxBitmap resizedBitmap1(wxBitmap("LogoITS.png", wxBITMAP_TYPE_PNG).ConvertToImage().Rescale(desiredWidth1, desiredHeight1));
    wxStaticBitmap* imageLogoITS = new wxStaticBitmap(this, wxID_ANY, resizedBitmap1, wxDefaultPosition, wxSize(desiredWidth1, desiredHeight1));

    double aspectRatio2 = static_cast<double>(3760) / static_cast<double>(1249);
    int desiredWidth2 = 100;
    int desiredHeight2 = static_cast<int>(desiredWidth2 / aspectRatio2);
    wxBitmap resizedBitmap2(wxBitmap("MyITS-SSO.png", wxBITMAP_TYPE_PNG).ConvertToImage().Rescale(desiredWidth2, desiredHeight2));
    wxStaticBitmap* imageMyITS_SSO = new wxStaticBitmap(this, wxID_ANY, resizedBitmap2, wxDefaultPosition, wxSize(desiredWidth2, desiredHeight2));

    wxBoxSizer* ITSlogo_MyITS_SSO = new wxBoxSizer(wxHORIZONTAL);
    ITSlogo_MyITS_SSO->Add(imageLogoITS, wxSizerFlags().Center().Border(wxALL, 5));
    ITSlogo_MyITS_SSO->Add(imageMyITS_SSO, wxSizerFlags().Center().Border(wxALL, 5));

    wxBoxSizer* loginButtonPos = new wxBoxSizer(wxHORIZONTAL);
    loginButtonPos->Add(login, wxSizerFlags().Center().Border(wxALL, 5));

    wxBoxSizer* userPos = new wxBoxSizer(wxHORIZONTAL);
    userPos->Add(userText, wxSizerFlags().Center().Border(wxALL, 5));
    userPos->Add(userBox, wxSizerFlags().Center().Border(wxALL, 5));

    wxBoxSizer* passPos = new wxBoxSizer(wxHORIZONTAL);
    passPos->Add(passText, wxSizerFlags().Center().Border(wxALL, 5));
    passPos->Add(passBox, wxSizerFlags().Center().Border(wxALL, 5));

    wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
    mainSizer->AddStretchSpacer();
    mainSizer->Add(ITSlogo_MyITS_SSO, wxSizerFlags().Center());
    mainSizer->AddSpacer(20);
    mainSizer->Add(userPos, wxSizerFlags().Center());
    mainSizer->Add(passPos, wxSizerFlags().Center());
    mainSizer->Add(loginButtonPos, wxSizerFlags().Center());
    mainSizer->AddStretchSpacer();

    SetSizerAndFit(mainSizer);
}

void LoginPage::OnClickedLoginButton(wxCommandEvent& event)
{
    wxString inputUsername = userBox->GetValue();
    wxString inputPassword = passBox->GetValue();

    if ((inputUsername == NRP) && (inputPassword == password))
    {
        wxMessageBox("Login Success! User FOUND! \nHi, Rigel R!", "Success", wxOK | wxICON_INFORMATION);

        wxFrame* parentFrame = dynamic_cast<wxFrame*>(GetParent());
        if (parentFrame)
        {
            parentFrame->Destroy();
        }

        MainMenuFrame* mainMenuFrame = new MainMenuFrame("Home | SI Akademik ITS");
        mainMenuFrame->SetClientSize(1600, 900);
        mainMenuFrame->Centre();
        mainMenuFrame->Show();
    } else
    {
        wxMessageBox("Login Failed!\nUsername or Password Incorrect!", "Failed", wxICON_ERROR);
    }
}

class MainFrame : public wxFrame
{
    private:
        LoginPage* loginPage;

    public:
        MainFrame(const wxString& title):wxFrame(nullptr, wxID_ANY, title), loginPage(nullptr)
        {
            loginPage = new LoginPage(this);

            wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
            mainSizer->Add(loginPage, wxSizerFlags(1).Expand());

            SetSizerAndFit(mainSizer);
            Centre();
        }
};

class App : public wxApp
{
    public:
        bool OnInit()
        {
            MainFrame* frame = new MainFrame("Sign In | myITS SSO");
            frame->SetClientSize(600, 300);
            frame->Centre();
            frame->Show();
            return true;
        }
};

wxIMPLEMENT_APP(App);

// #include <wx/wx.h>
// #include <wx/graphics.h>

// class DateTime
// {
//     public:
//     wxDateTime currentTime = wxDateTime::Now();
//     int day = currentTime.GetDay();
//     int mon = currentTime.GetMonth();
//     int year = currentTime.GetYear();
//     int hour = currentTime.GetHour();
//     int minute = currentTime.GetMinute();
//     int second = currentTime.GetSecond();

//     std::string monthName[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
// };

// class DatePanel : public wxPanel
// {
// public:
//     DatePanel(wxWindow* parent) : wxPanel(parent)
//     {
//         SetBackgroundColour(wxColour(255, 255, 255));
//     }

//     void OnPaint(wxPaintEvent& event)
//     {
//         DateTime dt;
//         wxPaintDC dc(this);

//         // Create a wxGraphicsContext from the device context
//         wxGraphicsContext* gc = wxGraphicsContext::Create(dc);
//         if (gc)
//         {
//             // Create gradient stops for the gradient fill
//             wxGraphicsGradientStops gradientStops;
//             gradientStops.Add(wxColour(36, 176, 253), 0.0);     // Start color at position 0
//             gradientStops.Add(wxColour(17, 144, 233), 1.0);     // End color at position 1

//             // Create a rectangle path
//             wxGraphicsPath path = gc->CreatePath();
//             path.AddRoundedRectangle(50, 50, 200, 150, 10);

//             // Set the gradient brush using the graphics context
//             wxGraphicsBrush brush = gc->CreateLinearGradientBrush(50, 50, 250, 150, gradientStops);
//             gc->SetBrush(brush);

//             // Draw the rounded rectangle with gradient fill
//             gc->DrawPath(path);

//             // Set color for the texts
//             wxColour textColor(255, 255, 255); // White

//             // Get the default system font and modify it to make it bold
//             wxFont font = wxSystemSettings::GetFont(wxSYS_DEFAULT_GUI_FONT);
//             font.SetWeight(wxFONTWEIGHT_BOLD);

//             // Set the font properties for the first text with larger font size and bold style
//             font.SetPointSize(40);
//             font.SetWeight(wxFONTWEIGHT_BOLD);
//             gc->SetFont(font, textColor);

//             wxString text1 = wxString::Format("%d", dt.day);
//             double textX1 = 47 + (100 - GetTextWidth(gc, text1)) / 2; // Center the text horizontally
//             double textY1 = 90 + (100 - GetTextHeight(gc, text1)) / 2 - font.GetPointSize(); // Position above the center
//             gc->DrawText(text1, textX1, textY1);

//             // Set the font properties for the second text with smaller font size and bold style
//             font.SetPointSize(11);
//             font.SetWeight(wxFONTWEIGHT_BOLD);
//             gc->SetFont(font, textColor);

//             wxString text2 = dt.monthName[dt.mon];
//             double textX2 = 68; // Center the text horizontally
//             double textY2 = 80 + (100 - GetTextHeight(gc, text2)) / 2 + font.GetPointSize(); // Position below the center
//             gc->DrawText(text2, textX2, textY2);

//             font.SetPointSize(11);
//             font.SetWeight(wxFONTWEIGHT_SEMIBOLD);
//             gc->SetFont(font, textColor);

//             wxString text3 = wxString::Format("%d", dt.year);
//             double textX3 = 68; // Center the text horizontally
//             double textY3 = 100 + (100 - GetTextHeight(gc, text3)) / 2 + font.GetPointSize(); // Position below the center
//             gc->DrawText(text3, textX3, textY3);

//             delete gc;
//         }
//     }

//     double GetTextWidth(wxGraphicsContext* gc, const wxString& text)
//     {
//         double width, height;
//         gc->GetTextExtent(text, &width, &height);
//         return width;
//     }

//     double GetTextHeight(wxGraphicsContext* gc, const wxString& text)
//     {
//         double width, height;
//         gc->GetTextExtent(text, &width, &height);
//         return height;
//     }

//     wxDECLARE_EVENT_TABLE();
// };

// wxBEGIN_EVENT_TABLE(DatePanel, wxPanel)
//     EVT_PAINT(DatePanel::OnPaint)
// wxEND_EVENT_TABLE()

// class DateFrame : public wxFrame
// {
//     public:
//     DateFrame() : wxFrame(NULL, wxID_ANY, "Panel Example")
//     {
//         SetSize(400, 300);
//         Centre();

//         DatePanel* panel = new DatePanel(this);
//     }
// };

// class MyApp : public wxApp
// {
// public:
//     bool OnInit()
//     {
//         DateFrame* frame = new DateFrame();
//         frame->Show(true);
//         return true;
//     }
// };

// wxIMPLEMENT_APP(MyApp);





