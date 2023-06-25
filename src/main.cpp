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

wxSize screenSize = wxGetDisplaySize();
int desiredWidth = screenSize.GetWidth();
int desiredHeight = screenSize.GetHeight();

wxDateTime currentTime = wxDateTime::Now();
int day = currentTime.GetDay();
int mon = currentTime.GetMonth() + 1;
int year = currentTime.GetYear();
int hour = currentTime.GetHour();
int minute = currentTime.GetMinute();
int second = currentTime.GetSecond();
string semester;

string addZeroHour, addZeroMinute, addZeroSecond;

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

    std::string monthName[12] = {"Januari", "Februari", "Maret", "April", "Mei", "Juni", "Juli", "Agustus", "September", "Oktober", "November", "Desember"};
};

class KurikulumPanel : public wxPanel
{
private:
    wxGrid* semester1Grid2022;
    wxGrid* semester2Grid2022;
    wxGrid* semester3Grid2022;
    wxGrid* semester4Grid2022;
    wxGrid* semester5Grid2022;
    wxGrid* semester6Grid2022;
    wxGrid* semester7Grid2022;
    wxGrid* semester8Grid2022;

public:
    KurikulumPanel(wxWindow* parent) : wxPanel(parent, wxID_ANY)
    {
        wxArrayString choicesSemester;
        choicesSemester.Add("Semester 1");
        choicesSemester.Add("Semester 2");
        choicesSemester.Add("Semester 3");
        choicesSemester.Add("Semester 4");
        choicesSemester.Add("Semester 5");
        choicesSemester.Add("Semester 6");
        choicesSemester.Add("Semester 7");
        choicesSemester.Add("Semester 8");
        wxChoice* choicesCtrlSemester = new wxChoice(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, choicesSemester);

        semester1Grid2022 = new wxGrid(this, wxID_ANY);
        semester2Grid2022 = new wxGrid(this, wxID_ANY);
        semester3Grid2022 = new wxGrid(this, wxID_ANY);
        semester4Grid2022 = new wxGrid(this, wxID_ANY);
        semester5Grid2022 = new wxGrid(this, wxID_ANY);
        semester6Grid2022 = new wxGrid(this, wxID_ANY);
        semester7Grid2022 = new wxGrid(this, wxID_ANY);
        semester8Grid2022 = new wxGrid(this, wxID_ANY);

        semester1Grid2022->CreateGrid(7, 2);
        semester1Grid2022->SetRowLabelValue(0, "EC224102");
        semester1Grid2022->SetRowLabelValue(1, "EC224101");
        semester1Grid2022->SetRowLabelValue(2, "SF224103");
        semester1Grid2022->SetRowLabelValue(3, "SM224101");
        semester1Grid2022->SetRowLabelValue(4, "EW224101");
        semester1Grid2022->SetRowLabelValue(5, "EC224103");
        semester1Grid2022->SetRowLabelValue(6, "");
        semester1Grid2022->SetColLabelValue(0, "Mata Kuliah / Inggris");
        semester1Grid2022->SetColLabelValue(1, "SKS");
        semester1Grid2022->SetCellValue(0, 0, "Aljabar Linear / Linear Algebra");
        semester1Grid2022->SetCellValue(1, 0, "Dasar Pemrograman / Basic Programming");
        semester1Grid2022->SetCellValue(2, 0, "Fisika Mekanika / Mechanics Physics");
        semester1Grid2022->SetCellValue(3, 0, "Kalkulus 1 / Calculus 1");
        semester1Grid2022->SetCellValue(4, 0, "Pengantar Teknologi Elektro / Introduction to Electrical Technology");
        semester1Grid2022->SetCellValue(5, 0, "Probabilitas dan Statistik / Probability and Statistics");
        semester1Grid2022->SetCellValue(6, 0, "Total SKS");
        semester1Grid2022->SetCellValue(0, 1, "3");
        semester1Grid2022->SetCellValue(1, 1, "3");
        semester1Grid2022->SetCellValue(2, 1, "3");
        semester1Grid2022->SetCellValue(3, 1, "3");
        semester1Grid2022->SetCellValue(4, 1, "2");
        semester1Grid2022->SetCellValue(5, 1, "3");
        semester1Grid2022->SetCellValue(6, 1, "17");
        semester1Grid2022->AutoSizeColumns();

        semester1Grid2022->SetCellFont(6, 0, wxFont(wxFontInfo(10).Bold()));
        semester1Grid2022->SetCellFont(6, 1, wxFont(wxFontInfo(10).Bold()));
        semester1Grid2022->SetCellBackgroundColour(6, 0, wxColour(255, 255, 0));
        semester1Grid2022->SetCellBackgroundColour(6, 1, wxColour(255, 255, 0));

        semester2Grid2022->CreateGrid(8, 2);
        semester2Grid2022->SetRowLabelValue(0, "EC224204");
        semester2Grid2022->SetRowLabelValue(1, "SF224203");
        semester2Grid2022->SetRowLabelValue(2, "SM224201");
        semester2Grid2022->SetRowLabelValue(3, "EC224203");
        semester2Grid2022->SetRowLabelValue(4, "EC224202");
        semester2Grid2022->SetRowLabelValue(5, "EC224201");
        semester2Grid2022->SetRowLabelValue(6, "EW224003");
        semester2Grid2022->SetRowLabelValue(7, "");
        semester2Grid2022->SetColLabelValue(0, "Mata Kuliah / Inggris");
        semester2Grid2022->SetColLabelValue(1, "SKS");
        semester2Grid2022->SetCellValue(0, 0, "Desain dan Rekayasa Sistem / Systems Design and Engineering");
        semester2Grid2022->SetCellValue(1, 0, "Fisika Listrik dan Magnet / Physics of Electricity and Magnetism");
        semester2Grid2022->SetCellValue(2, 0, "Kalkulus 2 / Calculus 2");
        semester2Grid2022->SetCellValue(3, 0, "Matematika Diskrit / Discrete Mathematics");
        semester2Grid2022->SetCellValue(4, 0, "Metode Numerik / Numerical Methods");
        semester2Grid2022->SetCellValue(5, 0, "Pemrograman Lanjut / Advanced Programming");
        semester2Grid2022->SetCellValue(6, 0, "Rangkaian Listrik / Electric Circuits");
        semester2Grid2022->SetCellValue(7, 0, "Total SKS");
        semester2Grid2022->SetCellValue(0, 1, "2");
        semester2Grid2022->SetCellValue(1, 1, "3");
        semester2Grid2022->SetCellValue(2, 1, "3");
        semester2Grid2022->SetCellValue(3, 1, "3");
        semester2Grid2022->SetCellValue(4, 1, "3");
        semester2Grid2022->SetCellValue(5, 1, "3");
        semester2Grid2022->SetCellValue(6, 1, "2");
        semester2Grid2022->SetCellValue(7, 1, "19");
        semester2Grid2022->AutoSizeColumns();

        semester2Grid2022->SetCellFont(7, 0, wxFont(wxFontInfo(10).Bold()));
        semester2Grid2022->SetCellFont(7, 1, wxFont(wxFontInfo(10).Bold()));
        semester2Grid2022->SetCellBackgroundColour(7, 0, wxColour(255, 255, 0));
        semester2Grid2022->SetCellBackgroundColour(7, 1, wxColour(255, 255, 0));

        semester3Grid2022->CreateGrid(7, 2);
        semester3Grid2022->SetRowLabelValue(0, "EC224305");
        semester3Grid2022->SetRowLabelValue(1, "EC224304");
        semester3Grid2022->SetRowLabelValue(2, "EC224302");
        semester3Grid2022->SetRowLabelValue(3, "EC224301");
        semester3Grid2022->SetRowLabelValue(4, "EW224306");
        semester3Grid2022->SetRowLabelValue(5, "EC224303");
        semester3Grid2022->SetRowLabelValue(6, "");
        semester3Grid2022->SetColLabelValue(0, "Mata Kuliah / Inggris");
        semester3Grid2022->SetColLabelValue(1, "SKS");
        semester3Grid2022->SetCellValue(0, 0, "Kalkulus Peubah Banyak / Multivariable Calculus");
        semester3Grid2022->SetCellValue(1, 0, "Pengolahan Sinyal Digital / Digital Signal Processing");
        semester3Grid2022->SetCellValue(2, 0, "Persamaan Differensial dan Deret / Differential Equations and Series");
        semester3Grid2022->SetCellValue(3, 0, "Rangkaian Digital / Digital Circuits");
        semester3Grid2022->SetCellValue(4, 0, "Rangkaian Elektronika / Electronic Circuits");
        semester3Grid2022->SetCellValue(5, 0, "	Struktur Data dan Analisa Algoritma / Data Structure and Algorithm Analysis");
        semester3Grid2022->SetCellValue(6, 0, "Total SKS");
        semester3Grid2022->SetCellValue(0, 1, "4");
        semester3Grid2022->SetCellValue(1, 1, "3");
        semester3Grid2022->SetCellValue(2, 1, "4");
        semester3Grid2022->SetCellValue(3, 1, "3");
        semester3Grid2022->SetCellValue(4, 1, "3");
        semester3Grid2022->SetCellValue(5, 1, "3");
        semester3Grid2022->SetCellValue(6, 1, "20");
        semester3Grid2022->AutoSizeColumns();

        semester3Grid2022->SetCellFont(6, 0, wxFont(wxFontInfo(10).Bold()));
        semester3Grid2022->SetCellFont(6, 1, wxFont(wxFontInfo(10).Bold()));
        semester3Grid2022->SetCellBackgroundColour(6, 0, wxColour(255, 255, 0));
        semester3Grid2022->SetCellBackgroundColour(6, 1, wxColour(255, 255, 0));

        semester4Grid2022->CreateGrid(8, 2);
        semester4Grid2022->SetRowLabelValue(0, "EC224402");
        semester4Grid2022->SetRowLabelValue(1, "EC224403");
        semester4Grid2022->SetRowLabelValue(2, "EC224404");
        semester4Grid2022->SetRowLabelValue(3, "EC224407");
        semester4Grid2022->SetRowLabelValue(4, "EC224401");
        semester4Grid2022->SetRowLabelValue(5, "EC224406");
        semester4Grid2022->SetRowLabelValue(6, "EC224405");
        semester4Grid2022->SetRowLabelValue(7, "");
        semester4Grid2022->SetColLabelValue(0, "Mata Kuliah / Inggris");
        semester4Grid2022->SetColLabelValue(1, "SKS");
        semester4Grid2022->SetCellValue(0, 0, "Arsitektur dan Organisasi Sistem Komputer / Computer System Architecture and Organization");
        semester4Grid2022->SetCellValue(1, 0, "Jaringan Komputer / 	Computer Network");
        semester4Grid2022->SetCellValue(2, 0, "Kompetensi Teknologi Elektro / Electrical Technology Competencies");
        semester4Grid2022->SetCellValue(3, 0, "Pengantar Robotika / Introduction to Robotics");
        semester4Grid2022->SetCellValue(4, 0, "Sistem Manajemen Basis Data / Database Management System");
        semester4Grid2022->SetCellValue(5, 0, "Sistem Mikroprosesor dan Mikrokontroller / Microprocessor Systems and Microcontrollers");
        semester4Grid2022->SetCellValue(6, 0, "Sistem Operasi / Operating Systems");
        semester4Grid2022->SetCellValue(7, 0, "Total SKS");
        semester4Grid2022->SetCellValue(0, 1, "3");
        semester4Grid2022->SetCellValue(1, 1, "3");
        semester4Grid2022->SetCellValue(2, 1, "2");
        semester4Grid2022->SetCellValue(3, 1, "3");
        semester4Grid2022->SetCellValue(4, 1, "3");
        semester4Grid2022->SetCellValue(5, 1, "3");
        semester4Grid2022->SetCellValue(6, 1, "3");
        semester4Grid2022->SetCellValue(7, 1, "20");
        semester4Grid2022->AutoSizeColumns();

        semester4Grid2022->SetCellFont(7, 0, wxFont(wxFontInfo(10).Bold()));
        semester4Grid2022->SetCellFont(7, 1, wxFont(wxFontInfo(10).Bold()));
        semester4Grid2022->SetCellBackgroundColour(7, 0, wxColour(255, 255, 0));
        semester4Grid2022->SetCellBackgroundColour(7, 1, wxColour(255, 255, 0));

        semester5Grid2022->CreateGrid(12, 2);
        semester5Grid2022->SetRowLabelValue(0, "EC224505");
        semester5Grid2022->SetRowLabelValue(1, "EC224531");
        semester5Grid2022->SetRowLabelValue(2, "EC224532");
        semester5Grid2022->SetRowLabelValue(3, "EC224523");
        semester5Grid2022->SetRowLabelValue(4, "EC224542");
        semester5Grid2022->SetRowLabelValue(5, "EC224501");
        semester5Grid2022->SetRowLabelValue(6, "EC224503");
        semester5Grid2022->SetRowLabelValue(7, "EC224502");
        semester5Grid2022->SetRowLabelValue(8, "EC224541");
        semester5Grid2022->SetRowLabelValue(9, "EC224504");
        semester5Grid2022->SetRowLabelValue(10, "EC224522");
        semester5Grid2022->SetRowLabelValue(11, "");
        semester5Grid2022->SetColLabelValue(0, "Mata Kuliah / Inggris");
        semester5Grid2022->SetColLabelValue(1, "SKS");
        semester5Grid2022->SetCellValue(0, 0, "Desain dan Aplikasi Internet of Things / Design and Application of Internet of Things");
        semester5Grid2022->SetCellValue(1, 0, "Jaringan Komputer Lanjut / Advanced Computer Networks");
        semester5Grid2022->SetCellValue(2, 0, "Komputasi Bergerak / Mobile Programming");
        semester5Grid2022->SetCellValue(3, 0, "Layanan & Aplikasi Internet / Service and Internet Application");
        semester5Grid2022->SetCellValue(4, 0, "Mobile Robot / Mobile Robot");
        semester5Grid2022->SetCellValue(5, 0, "Pembelajaran Mesin / Machine Learning");
        semester5Grid2022->SetCellValue(6, 0, "Pengolahan Citra dan Video / Digital Image and Video Processing");
        semester5Grid2022->SetCellValue(7, 0, "Sekuriti Sistem Komputer (Pengayaan) / Computer System Security (Enrichment)");
        semester5Grid2022->SetCellValue(8, 0, "Sistem Konkurens Waktu Nyata / Real-Time Concurrence Systems");
        semester5Grid2022->SetCellValue(9, 0, "Sistem Tertanam / Embedded Systems");
        semester5Grid2022->SetCellValue(10, 0, "Teknologi Cloud dan Edge / Cloud and Edge Technology");
        semester5Grid2022->SetCellValue(11, 0, "Total SKS");
        semester5Grid2022->SetCellValue(0, 1, "3");
        semester5Grid2022->SetCellValue(1, 1, "3");
        semester5Grid2022->SetCellValue(2, 1, "3");
        semester5Grid2022->SetCellValue(3, 1, "3");
        semester5Grid2022->SetCellValue(4, 1, "3");
        semester5Grid2022->SetCellValue(5, 1, "3");
        semester5Grid2022->SetCellValue(6, 1, "3");
        semester5Grid2022->SetCellValue(7, 1, "3");
        semester5Grid2022->SetCellValue(8, 1, "3");
        semester5Grid2022->SetCellValue(9, 1, "3");
        semester5Grid2022->SetCellValue(10, 1, "3");
        semester5Grid2022->SetCellValue(11, 1, "33");
        semester5Grid2022->AutoSizeColumns();

        semester5Grid2022->SetCellFont(11, 0, wxFont(wxFontInfo(10).Bold()));
        semester5Grid2022->SetCellFont(11, 1, wxFont(wxFontInfo(10).Bold()));
        semester5Grid2022->SetCellBackgroundColour(11, 0, wxColour(255, 255, 0));
        semester5Grid2022->SetCellBackgroundColour(11, 1, wxColour(255, 255, 0));

        semester6Grid2022->CreateGrid(23, 2);
        semester6Grid2022->SetRowLabelValue(0, "UG224905");
        semester6Grid2022->SetRowLabelValue(1, "UG224904");
        semester6Grid2022->SetRowLabelValue(2, "UG224901");
        semester6Grid2022->SetRowLabelValue(3, "UG224903");
        semester6Grid2022->SetRowLabelValue(4, "UG224906");
        semester6Grid2022->SetRowLabelValue(5, "UG224902");
        semester6Grid2022->SetRowLabelValue(6, "UG224916");
        semester6Grid2022->SetRowLabelValue(7, "UG224914");
        semester6Grid2022->SetRowLabelValue(8, "EC224622");
        semester6Grid2022->SetRowLabelValue(9, "EC224623");
        semester6Grid2022->SetRowLabelValue(10, "EC224642");
        semester6Grid2022->SetRowLabelValue(11, "EC224621");
        semester6Grid2022->SetRowLabelValue(12, "UG224913");
        semester6Grid2022->SetRowLabelValue(13, "EC224602");
        semester6Grid2022->SetRowLabelValue(14, "EC224672");
        semester6Grid2022->SetRowLabelValue(15, "EC224671");
        semester6Grid2022->SetRowLabelValue(16, "EC224632");
        semester6Grid2022->SetRowLabelValue(17, "EC224641");
        semester6Grid2022->SetRowLabelValue(18, "EC224601");
        semester6Grid2022->SetRowLabelValue(19, "EC224624");
        semester6Grid2022->SetRowLabelValue(20, "UG224915");
        semester6Grid2022->SetRowLabelValue(21, "EC224631");
        semester6Grid2022->SetRowLabelValue(22, "");
        semester6Grid2022->SetColLabelValue(0, "Mata Kuliah / Inggris");
        semester6Grid2022->SetColLabelValue(1, "SKS");
        semester6Grid2022->SetCellValue(0, 0, "Agama Buddha / Buddhism Studies");
        semester6Grid2022->SetCellValue(1, 0, "Agama Hindu / Hinduism Studies");
        semester6Grid2022->SetCellValue(2, 0, "Agama Islam / Islamic Studies");
        semester6Grid2022->SetCellValue(3, 0, "Agama Katolik / Catholic Studies");
        semester6Grid2022->SetCellValue(4, 0, "Agama Khonghucu / Khonghucu Studies");
        semester6Grid2022->SetCellValue(5, 0, "Agama Kristen / Christian Studies");
        semester6Grid2022->SetCellValue(6, 0, "Aplikasi Teknologi & Transformasi Digital /Technology Application and Digital Transformation");
        semester6Grid2022->SetCellValue(7, 0, "Bahasa Inggris / English");
        semester6Grid2022->SetCellValue(8, 0, "Deep Learning untuk Multimedia / Deep Learning for Multimedia");
        semester6Grid2022->SetCellValue(9, 0, "Interaksi Komputer Manusia / Human-Computer Interaction");
        semester6Grid2022->SetCellValue(10, 0, "Interaksi Manusia-Robot / Human-Robot Interaction");
        semester6Grid2022->SetCellValue(11, 0, "Kecerdasan Bisnis / Business Intelligence");
        semester6Grid2022->SetCellValue(12, 0, "Kewarganegaraan / Civics");
        semester6Grid2022->SetCellValue(13, 0, "Kompetensi Teknik Komputer I / Computer Engineering Competencies 1");
        semester6Grid2022->SetCellValue(14, 0, "Kredensial Mikro A / Microcredensial A");
        semester6Grid2022->SetCellValue(15, 0, "Magang Bersertifikat A / Certified Internship A");
        semester6Grid2022->SetCellValue(16, 0, "Pemrograman Sistem dan Jaringan / Network and System Programming");
        semester6Grid2022->SetCellValue(17, 0, "Persepsi Robot / Robot Perception");
        semester6Grid2022->SetCellValue(18, 0, "Proyek Telematika / Projects of Telematics");
        semester6Grid2022->SetCellValue(19, 0, "Teknologi Bahasa / Language Technology");
        semester6Grid2022->SetCellValue(20, 0, "Teknopreneur / Technopreneurship");
        semester6Grid2022->SetCellValue(21, 0, "Visi Komputer / Computer Vision");
        semester6Grid2022->SetCellValue(22, 0, "Total SKS");
        semester6Grid2022->SetCellValue(0, 1, "2");
        semester6Grid2022->SetCellValue(1, 1, "2");
        semester6Grid2022->SetCellValue(2, 1, "2");
        semester6Grid2022->SetCellValue(3, 1, "2");
        semester6Grid2022->SetCellValue(4, 1, "2");
        semester6Grid2022->SetCellValue(5, 1, "2");
        semester6Grid2022->SetCellValue(6, 1, "3");
        semester6Grid2022->SetCellValue(7, 1, "2");
        semester6Grid2022->SetCellValue(8, 1, "3");
        semester6Grid2022->SetCellValue(9, 1, "3");
        semester6Grid2022->SetCellValue(10, 1, "3");
        semester6Grid2022->SetCellValue(11, 1, "3");
        semester6Grid2022->SetCellValue(12, 1, "2");
        semester6Grid2022->SetCellValue(13, 1, "2");
        semester6Grid2022->SetCellValue(14, 1, "3");
        semester6Grid2022->SetCellValue(15, 1, "3");
        semester6Grid2022->SetCellValue(16, 1, "3");
        semester6Grid2022->SetCellValue(17, 1, "3");
        semester6Grid2022->SetCellValue(18, 1, "4");
        semester6Grid2022->SetCellValue(19, 1, "3");
        semester6Grid2022->SetCellValue(20, 1, "2");
        semester6Grid2022->SetCellValue(21, 1, "3");
        semester6Grid2022->SetCellValue(22, 1, "57");
        semester6Grid2022->AutoSizeColumns();

        semester6Grid2022->SetCellFont(22, 0, wxFont(wxFontInfo(10).Bold()));
        semester6Grid2022->SetCellFont(22, 1, wxFont(wxFontInfo(10).Bold()));
        semester6Grid2022->SetCellBackgroundColour(22, 0, wxColour(255, 255, 0));
        semester6Grid2022->SetCellBackgroundColour(22, 1, wxColour(255, 255, 0));

        semester7Grid2022->CreateGrid(23, 2);
        semester7Grid2022->SetRowLabelValue(0, "UG224912");
        semester7Grid2022->SetRowLabelValue(1, "EC224743");
        semester7Grid2022->SetRowLabelValue(2, "EC224725");
        semester7Grid2022->SetRowLabelValue(3, "EC224731");
        semester7Grid2022->SetRowLabelValue(4, "EC224732");
        semester7Grid2022->SetRowLabelValue(5, "EC224703");
        semester7Grid2022->SetRowLabelValue(6, "EC224733");
        semester7Grid2022->SetRowLabelValue(7, "EC224721");
        semester7Grid2022->SetRowLabelValue(8, "EC224673");
        semester7Grid2022->SetRowLabelValue(9, "EC224674");
        semester7Grid2022->SetRowLabelValue(10, "UG224917");
        semester7Grid2022->SetRowLabelValue(11, "EC224702");
        semester7Grid2022->SetRowLabelValue(12, "EC224771");
        semester7Grid2022->SetRowLabelValue(13, "EC224772");
        semester7Grid2022->SetRowLabelValue(14, "EC224722");
        semester7Grid2022->SetRowLabelValue(15, "UG224911");
        semester7Grid2022->SetRowLabelValue(16, "EC224724");
        semester7Grid2022->SetRowLabelValue(17, "EC224723");
        semester7Grid2022->SetRowLabelValue(18, "EC224701");
        semester7Grid2022->SetRowLabelValue(19, "EC224742");
        semester7Grid2022->SetRowLabelValue(20, "EC224741");
        semester7Grid2022->SetRowLabelValue(21, "EC224799");
        semester7Grid2022->SetRowLabelValue(22, "");
        semester7Grid2022->SetColLabelValue(0, "Mata Kuliah / Inggris");
        semester7Grid2022->SetColLabelValue(1, "SKS");
        semester7Grid2022->SetCellValue(0, 0, "Bahasa Indonesia / Indonesian");
        semester7Grid2022->SetCellValue(1, 0, "Capstone Robotika / Robotics Capstone");
        semester7Grid2022->SetCellValue(2, 0, "Desain dan Pemrograman Game (Pengayaan) / Game Design and Programming (Enrichment)");
        semester7Grid2022->SetCellValue(3, 0, "Jaringan Sensor Nirkabel / Wireless Sensor Network");
        semester7Grid2022->SetCellValue(4, 0, "Kecerdasan Web dan Big Data / Intelligent Web and Big Data");
        semester7Grid2022->SetCellValue(5, 0, "Kompetensi Teknik Komputer II / Computer Engineering Competencies 2");
        semester7Grid2022->SetCellValue(6, 0, "Komputasi Edge / Edge Computing");
        semester7Grid2022->SetCellValue(7, 0, "Komputasi Ubiquitous / Ubiquitous Computing");
        semester7Grid2022->SetCellValue(8, 0, "Kredensial Mikro B / Microcredensial B");
        semester7Grid2022->SetCellValue(9, 0, "Kredensial Mikro C / Microcredensial C");
        semester7Grid2022->SetCellValue(10, 0, "Kuliah Kerja Nyata Tematik (Pengayaan) / Community Outreach Program (Enrichment)");
        semester7Grid2022->SetCellValue(11, 0, "Magang / Internship");
        semester7Grid2022->SetCellValue(12, 0, "Magang Bersertifikat B / Certified Internship B");
        semester7Grid2022->SetCellValue(13, 0, "Magang Bersertifikat C / Certified Internship C");
        semester7Grid2022->SetCellValue(14, 0, "Multimedia Cerdas untuk Game / Intelligent Multimedia for Game");
        semester7Grid2022->SetCellValue(15, 0, "Pancasila / Pancasila");
        semester7Grid2022->SetCellValue(16, 0, "Pembelajaran Mesin dalam Informatika Kesehatan / Machine Learning in Health Informatics");
        semester7Grid2022->SetCellValue(17, 0, "Pengolahan Citra Medis / Biomedical Imaging");
        semester7Grid2022->SetCellValue(18, 0, "Pra Tugas Akhir / Pre Final Project");
        semester7Grid2022->SetCellValue(19, 0, "Robotika Kreatif (Pengayaan) / Creative Robotics (Enrichment)");
        semester7Grid2022->SetCellValue(20, 0, "Robotika Lanjut / Advanced Robotic");
        semester7Grid2022->SetCellValue(21, 0, "Topik Khusus Teknik Komputer / Computer Engineering Special Topics");
        semester7Grid2022->SetCellValue(22, 0, "Total SKS");
        semester7Grid2022->SetCellValue(0, 1, "2");
        semester7Grid2022->SetCellValue(1, 1, "3");
        semester7Grid2022->SetCellValue(2, 1, "3");
        semester7Grid2022->SetCellValue(3, 1, "3");
        semester7Grid2022->SetCellValue(4, 1, "3");
        semester7Grid2022->SetCellValue(5, 1, "2");
        semester7Grid2022->SetCellValue(6, 1, "3");
        semester7Grid2022->SetCellValue(7, 1, "3");
        semester7Grid2022->SetCellValue(8, 1, "3");
        semester7Grid2022->SetCellValue(9, 1, "3");
        semester7Grid2022->SetCellValue(10, 1, "3");
        semester7Grid2022->SetCellValue(11, 1, "4");
        semester7Grid2022->SetCellValue(12, 1, "3");
        semester7Grid2022->SetCellValue(13, 1, "3");
        semester7Grid2022->SetCellValue(14, 1, "3");
        semester7Grid2022->SetCellValue(15, 1, "2");
        semester7Grid2022->SetCellValue(16, 1, "3");
        semester7Grid2022->SetCellValue(17, 1, "3");
        semester7Grid2022->SetCellValue(18, 1, "2");
        semester7Grid2022->SetCellValue(19, 1, "3");
        semester7Grid2022->SetCellValue(20, 1, "3");
        semester7Grid2022->SetCellValue(21, 1, "3");
        semester7Grid2022->SetCellValue(22, 1, "63");
        semester7Grid2022->AutoSizeColumns();

        semester7Grid2022->SetCellFont(22, 0, wxFont(wxFontInfo(10).Bold()));
        semester7Grid2022->SetCellFont(22, 1, wxFont(wxFontInfo(10).Bold()));
        semester7Grid2022->SetCellBackgroundColour(22, 0, wxColour(255, 255, 0));
        semester7Grid2022->SetCellBackgroundColour(22, 1, wxColour(255, 255, 0));

        semester8Grid2022->CreateGrid(2, 2);
        semester8Grid2022->SetRowLabelValue(0, "EC224801");
        semester8Grid2022->SetRowLabelValue(1, "");
        semester8Grid2022->SetColLabelValue(0, "Mata Kuliah / Inggris");
        semester8Grid2022->SetColLabelValue(1, "SKS");
        semester8Grid2022->SetCellValue(0, 0, "Tugas Akhir / Final Project");
        semester8Grid2022->SetCellValue(1, 0, "Total SKS");
        semester8Grid2022->SetCellValue(0, 1, "6");
        semester8Grid2022->SetCellValue(1, 1, "6");
        semester8Grid2022->AutoSizeColumns();

        semester8Grid2022->SetCellFont(1, 0, wxFont(wxFontInfo(10).Bold()));
        semester8Grid2022->SetCellFont(1, 1, wxFont(wxFontInfo(10).Bold()));
        semester8Grid2022->SetCellBackgroundColour(1, 0, wxColour(255, 255, 0));
        semester8Grid2022->SetCellBackgroundColour(1, 1, wxColour(255, 255, 0));

        semester1Grid2022->Hide();
        semester2Grid2022->Hide();
        semester3Grid2022->Hide();
        semester4Grid2022->Hide();
        semester5Grid2022->Hide();
        semester6Grid2022->Hide();
        semester7Grid2022->Hide();
        semester8Grid2022->Hide();

        choicesCtrlSemester->Bind(wxEVT_CHOICE, &KurikulumPanel::OnChoicesSemesterSelect, this);

        wxBoxSizer* sizerKurikulum = new wxBoxSizer(wxVERTICAL);
        sizerKurikulum->Add(choicesCtrlSemester, wxSizerFlags().Center().Border(wxALL, 5));
        sizerKurikulum->Add(semester1Grid2022, wxSizerFlags().Center().Border(wxALL, 5));
        sizerKurikulum->Add(semester2Grid2022, wxSizerFlags().Center().Border(wxALL, 5));
        sizerKurikulum->Add(semester3Grid2022, wxSizerFlags().Center().Border(wxALL, 5));
        sizerKurikulum->Add(semester4Grid2022, wxSizerFlags().Center().Border(wxALL, 5));
        sizerKurikulum->Add(semester5Grid2022, wxSizerFlags().Center().Border(wxALL, 5));
        sizerKurikulum->Add(semester6Grid2022, wxSizerFlags().Center().Border(wxALL, 5));
        sizerKurikulum->Add(semester7Grid2022, wxSizerFlags().Center().Border(wxALL, 5));
        sizerKurikulum->Add(semester8Grid2022, wxSizerFlags().Center().Border(wxALL, 5));

        SetSizerAndFit(sizerKurikulum);
    }

private:
    void OnChoicesSemesterSelect(wxCommandEvent& event)
    {
        int choiceIndex = event.GetSelection();

        if (semester1Grid2022 && semester2Grid2022 && semester3Grid2022 && semester4Grid2022 && semester5Grid2022 && semester6Grid2022)
        {
            if (choiceIndex == 0)
            {
                semester1Grid2022->Show();
                semester2Grid2022->Hide();
                semester3Grid2022->Hide();
                semester4Grid2022->Hide();
                semester5Grid2022->Hide();
                semester6Grid2022->Hide();
                semester7Grid2022->Hide();
                semester8Grid2022->Hide();
            }
            else if (choiceIndex == 1)
            {
                semester1Grid2022->Hide();
                semester2Grid2022->Show();
                semester3Grid2022->Hide();
                semester4Grid2022->Hide();
                semester5Grid2022->Hide();
                semester6Grid2022->Hide();
                semester7Grid2022->Hide();
                semester8Grid2022->Hide();
            }
            else if (choiceIndex == 2)
            {
                semester1Grid2022->Hide();
                semester2Grid2022->Hide();
                semester3Grid2022->Show();
                semester4Grid2022->Hide();
                semester5Grid2022->Hide();
                semester6Grid2022->Hide();
                semester7Grid2022->Hide();
                semester8Grid2022->Hide();
            }
            else if (choiceIndex == 3)
            {
                semester1Grid2022->Hide();
                semester2Grid2022->Hide();
                semester3Grid2022->Hide();
                semester4Grid2022->Show();
                semester5Grid2022->Hide();
                semester6Grid2022->Hide();
                semester7Grid2022->Hide();
                semester8Grid2022->Hide();
            }
            else if (choiceIndex == 4)
            {
                semester1Grid2022->Hide();
                semester2Grid2022->Hide();
                semester3Grid2022->Hide();
                semester4Grid2022->Hide();
                semester5Grid2022->Show();
                semester6Grid2022->Hide();
                semester7Grid2022->Hide();
                semester8Grid2022->Hide();
            }
            else if (choiceIndex == 5)
            {
                semester1Grid2022->Hide();
                semester2Grid2022->Hide();
                semester3Grid2022->Hide();
                semester4Grid2022->Hide();
                semester5Grid2022->Hide();
                semester6Grid2022->Show();
                semester7Grid2022->Hide();
                semester8Grid2022->Hide();
            }
            else if (choiceIndex == 6)
            {
                semester1Grid2022->Hide();
                semester2Grid2022->Hide();
                semester3Grid2022->Hide();
                semester4Grid2022->Hide();
                semester5Grid2022->Hide();
                semester6Grid2022->Hide();
                semester7Grid2022->Show();
                semester8Grid2022->Hide();
            }
            else if (choiceIndex == 7)
            {
                semester1Grid2022->Hide();
                semester2Grid2022->Hide();
                semester3Grid2022->Hide();
                semester4Grid2022->Hide();
                semester5Grid2022->Hide();
                semester6Grid2022->Hide();
                semester7Grid2022->Hide();
                semester8Grid2022->Show();
            }

            Layout();
        }
    }

    void OnClose(wxCloseEvent& event)
    {
        // event.Skip();
    }

    wxDECLARE_EVENT_TABLE();
};

wxBEGIN_EVENT_TABLE(KurikulumPanel, wxPanel)
    EVT_CLOSE(KurikulumPanel::OnClose)
wxEND_EVENT_TABLE()

class KurikulumFrame : public wxFrame
{
    public:
    KurikulumFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title)
    {
        KurikulumPanel* transkripPanel = new KurikulumPanel(this);
        wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
        mainSizer->Add(transkripPanel, wxSizerFlags(1).Expand());

        SetSizerAndFit(mainSizer);
        Centre();
    }
};

class TranskripPanel : public wxPanel
{
    public:
    TranskripPanel(wxWindow* parent) : wxPanel(parent, wxID_ANY)
    {
        wxStaticText* titleTranskrip = new wxStaticText(this, wxID_ANY, "Transkrip");
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
            wxStaticText* titleFRS = new wxStaticText(this, wxID_ANY, "Formulir Rencana Studi");
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
        Mahasiswa mhs;
        string nama = mhs.name;
        string NRP = mhs.NRP;

        wxMessageBox("Menu yang bisa digunakan adalah sebagai berikut:\n- Biodata Mahasiswa\n- Formulir Rencana Studi\n- Transkrip");

        if (hour >= 10)
        {
            addZeroHour = "";
        }
        if (hour < 10)
        {
            addZeroHour = "0";
        }
        if (minute >= 10)
        {
            addZeroMinute = "";
        }
        if (minute < 10)
        {
            addZeroMinute = "0";
        }
        if (second >= 10)
        {
            addZeroSecond = "";
        }
        if (second < 10)
        {
            addZeroSecond = "0";
        }

        timeNow = new wxStaticText(this, wxID_ANY, wxString::Format("%s%d:%s%d:%s%d", addZeroHour, hour, addZeroMinute, minute, addZeroSecond, second), wxPoint(1642, 202));
        timeNow->SetBackgroundColour("#002B5B");
        timeNow->SetForegroundColour("#fff");
        wxFont timeNowBold(timeNow->GetFont());
        timeNowBold.SetWeight(wxFONTWEIGHT_EXTRABOLD);
        timeNowBold.SetPointSize(24);
        timeNow->SetFont(timeNowBold);

        wxTimer* timer = new wxTimer(this, wxID_ANY);
        timer->Start(1000); // 1000 milliseconds = 1 second
        Bind(wxEVT_TIMER, &MainPanel::OnTimer, this);

        wxPNGHandler* imageFC = new wxPNGHandler;
        wxImage::AddHandler(imageFC);
        wxStaticBitmap* imageFotoProfile = new wxStaticBitmap(this, wxID_ANY, wxBitmap("fotoCircle1.png", wxBITMAP_TYPE_PNG), wxPoint(1750, 37), wxDefaultSize);
        imageFotoProfile->SetBackgroundColour("#fff");

        wxArrayString access;
        access.Add("- Pilih Hak Akses -");
        access.Add("Mahasiswa");
        access.Add("Dosen");
        access.Add("Tendik");

        wxChoice* hakAkses = new wxChoice(this, wxID_ANY, wxPoint(0,0), wxDefaultSize, access);
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

        wxChoice* fakultas = new wxChoice(this, wxID_ANY, wxPoint(135, 0), wxDefaultSize, faculty);
        fakultas->Select(3);
        fakultas->SetBackgroundColour("#eeef66");

        wxArrayString studyProgram;
        studyProgram.Add("- Pilih Prodi -");
        studyProgram.Add("29100 - 07214000 - S-1 TEKNIK KOMPUTER");

        wxChoice* prodi = new wxChoice(this, wxID_ANY, wxPoint(260, 0), wxDefaultSize, studyProgram);
        prodi->Select(1);
        prodi->SetBackgroundColour("#ffcccc");
        // ==========================
        wxPNGHandler *handler = new wxPNGHandler;
        wxImage::AddHandler(handler);
        double aspectRatio1 = static_cast<double>(1022) / static_cast<double>(60);
        int desiredWidth1 = 900;
        int desiredHeight1 = static_cast<int>(desiredWidth1 / aspectRatio1);
        wxBitmap resizedBitmap1(wxBitmap("header.png", wxBITMAP_TYPE_PNG).ConvertToImage().Rescale(desiredWidth1, desiredHeight1));
        wxStaticBitmap* imageLogoSIAKAD = new wxStaticBitmap(this, wxID_ANY, resizedBitmap1, wxPoint(300, 40), wxSize(desiredWidth1, desiredHeight1));
        imageLogoSIAKAD->SetBackgroundColour("#fff");

        wxStaticText* modulHeader = new wxStaticText(this, wxID_ANY, "Berikut modul-modul yang bisa Anda akses:", wxPoint(400, 120), wxDefaultSize);
        modulHeader->SetBackgroundColour("#fff");
        wxFont boldFont(modulHeader->GetFont());
        boldFont.SetWeight(wxFONTWEIGHT_BOLD);
        boldFont.SetPointSize(15);
        modulHeader->SetFont(boldFont);

        wxStaticText* dataHeader = new wxStaticText(this, wxID_ANY, "DATA", wxPoint(55, 175), wxSize(370,30), wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        dataHeader->SetBackgroundColour("#0A62A9");
        dataHeader->SetForegroundColour("#fff");
        wxFont dataHeaderFont(dataHeader->GetFont());
        dataHeaderFont.SetWeight(wxFONTWEIGHT_BOLD);
        dataHeaderFont.SetPointSize(15);
        dataHeader->SetFont(dataHeaderFont);

        wxStaticText* prosesHeader = new wxStaticText(this, wxID_ANY, "PROSES", wxPoint(485, 175), wxSize(370,30), wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        prosesHeader->SetBackgroundColour("#0A62A9");
        prosesHeader->SetForegroundColour("#fff");
        wxFont prosesHeaderFont(prosesHeader->GetFont());
        prosesHeaderFont.SetWeight(wxFONTWEIGHT_BOLD);
        prosesHeaderFont.SetPointSize(15);
        prosesHeader->SetFont(prosesHeaderFont);

        wxStaticText* laporanHeader = new wxStaticText(this, wxID_ANY, "LAPORAN", wxPoint(55, 565), wxSize(1230,30), wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        laporanHeader->SetBackgroundColour("#0A62A9");
        laporanHeader->SetForegroundColour("#fff");
        wxFont laporanHeaderFont(laporanHeader->GetFont());
        laporanHeaderFont.SetWeight(wxFONTWEIGHT_BOLD);
        laporanHeaderFont.SetPointSize(15);
        laporanHeader->SetFont(laporanHeaderFont);

        wxStaticText* lain_lainHeader = new wxStaticText(this, wxID_ANY, "LAIN-LAIN", wxPoint(915, 175), wxSize(370,30), wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        lain_lainHeader->SetBackgroundColour("#0A62A9");
        lain_lainHeader->SetForegroundColour("#fff");
        wxFont lain_lainHeaderFont(lain_lainHeader->GetFont());
        lain_lainHeaderFont.SetWeight(wxFONTWEIGHT_BOLD);
        lain_lainHeaderFont.SetPointSize(15);
        lain_lainHeader->SetFont(lain_lainHeaderFont);

        wxStaticText* ekivalensiHeader = new wxStaticText(this, wxID_ANY, "EKIVALENSI", wxPoint(55, 305), wxSize(370,30), wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        ekivalensiHeader->SetBackgroundColour("#0A62A9");
        ekivalensiHeader->SetForegroundColour("#fff");
        wxFont ekivalensiHeaderFont(ekivalensiHeader->GetFont());
        ekivalensiHeaderFont.SetWeight(wxFONTWEIGHT_BOLD);
        ekivalensiHeaderFont.SetPointSize(15);
        ekivalensiHeader->SetFont(ekivalensiHeaderFont);

        wxStaticText* yudisiumHeader = new wxStaticText(this, wxID_ANY, "YUDISIUM", wxPoint(485, 305), wxSize(370,30), wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        yudisiumHeader->SetBackgroundColour("#0A62A9");
        yudisiumHeader->SetForegroundColour("#fff");
        wxFont yudisiumHeaderFont(yudisiumHeader->GetFont());
        yudisiumHeaderFont.SetWeight(wxFONTWEIGHT_BOLD);
        yudisiumHeaderFont.SetPointSize(15);
        yudisiumHeader->SetFont(yudisiumHeaderFont);

        wxStaticText* skpiHeader = new wxStaticText(this, wxID_ANY, "SKPI", wxPoint(700, 435), wxSize(585,30), wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        skpiHeader->SetBackgroundColour("#0A62A9");
        skpiHeader->SetForegroundColour("#fff");
        wxFont skpiHeaderFont(skpiHeader->GetFont());
        skpiHeaderFont.SetWeight(wxFONTWEIGHT_BOLD);
        skpiHeaderFont.SetPointSize(15);
        skpiHeader->SetFont(skpiHeaderFont);

        wxStaticText* biayaHeader = new wxStaticText(this, wxID_ANY, "BIAYA PENDIDIKAN", wxPoint(55, 435), wxSize(585,30), wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        biayaHeader->SetBackgroundColour("#0A62A9");
        biayaHeader->SetForegroundColour("#fff");
        wxFont biayaHeaderFont(biayaHeader->GetFont());
        biayaHeaderFont.SetWeight(wxFONTWEIGHT_BOLD);
        biayaHeaderFont.SetPointSize(15);
        biayaHeader->SetFont(biayaHeaderFont);

        wxStaticText* suratHeader = new wxStaticText(this, wxID_ANY, "SURAT MAHASISWA", wxPoint(915, 305), wxSize(370,30), wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        suratHeader->SetBackgroundColour("#0A62A9");
        suratHeader->SetForegroundColour("#fff");
        wxFont suratHeaderFont(suratHeader->GetFont());
        suratHeaderFont.SetWeight(wxFONTWEIGHT_BOLD);
        suratHeaderFont.SetPointSize(15);
        suratHeader->SetFont(suratHeaderFont);
        
        wxStaticText* pengumumanNilaiMasukHeader = new wxStaticText(this, wxID_ANY, "PENGUMUMAN NILAI MASUK", wxPoint(1375, 305), wxSize(445, 30), wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        pengumumanNilaiMasukHeader->SetBackgroundColour("#CEE9FF");
        pengumumanNilaiMasukHeader->SetForegroundColour("#0A62A9");
        wxFont pengumumanNilaiMasukHeaderFont(pengumumanNilaiMasukHeader->GetFont());
        pengumumanNilaiMasukHeaderFont.SetWeight(wxFONTWEIGHT_BOLD);
        pengumumanNilaiMasukHeaderFont.SetPointSize(12);
        pengumumanNilaiMasukHeader->SetFont(pengumumanNilaiMasukHeaderFont);
        
        wxStaticText* pengumumanNilaiMasukContent = new wxStaticText(this, wxID_ANY, "Mulai semester genap 2018 diberlakukan rentang nilai yang\nbaru sesuai Peraturan Akademik 2018 yaitu:\n - Nilai angka (86-100) : Nilai A / Istimewa\n - Nilai angka (76-85) : Nilai AB / Baik Sekali\n - Nilai angka (66-75) : Nilai B / Baik\n - Nilai angka (61-65) : Nilai BC / Cukup Baik\n - Nilai angka (56-60) : Nilai C / Cukup\n - Nilai angka (41-55) : Nilai D / Kurang\n - Nilai angka (0-40) : Nilai E / Kurang Sekali", wxPoint(1400, 340), wxDefaultSize);
        pengumumanNilaiMasukContent->SetBackgroundColour("#CEE9FF");
        pengumumanNilaiMasukContent->SetForegroundColour("#0A62A9");
        wxFont pengumumanNilaiMasukContentFont(pengumumanNilaiMasukContent->GetFont());
        pengumumanNilaiMasukContentFont.SetPointSize(11);
        pengumumanNilaiMasukContent->SetFont(pengumumanNilaiMasukContentFont);

        wxStaticText* pengumumanIPDHeader = new wxStaticText(this, wxID_ANY, "IPD SEMESTER GENAP 2022/2023", wxPoint(1375, 540), wxSize(445, 30), wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        pengumumanIPDHeader->SetBackgroundColour("#CEE9FF");
        pengumumanIPDHeader->SetForegroundColour("#0A62A9");
        wxFont pengumumanIPDHeaderFont(pengumumanIPDHeader->GetFont());
        pengumumanIPDHeaderFont.SetWeight(wxFONTWEIGHT_BOLD);
        pengumumanIPDHeaderFont.SetPointSize(12);
        pengumumanIPDHeader->SetFont(pengumumanIPDHeaderFont);

        wxStaticText* pengumumanIPDContent = new wxStaticText(this, wxID_ANY, "- Diumumkan kepada Mahasiswa S3, S2, S1, Diploma Empat,\n   dan Diploma Tiga diwajibkan mengisi Kuesioner Index Pe-\n   ngajaran Dosen (IPD) semester Genap 2022/2023 secara\n   online melalui SIM Akademik untuk semua matakuliah\n   yang diikuti kecuali Kerja Praktek/TA/Tesis/Disertasi.\n- Pengisian kuesioner dimulai tanggal 5 Juni 2023 sampai\n   dengan 23 Juni 2023 pukul 23.59 WIB.\n- Mahasiswa yang masih punya tanggungan pengisian\n   semester sebelumnya dapat mengisi dalam periode\n   sekarang dengan mengubah setting tahun dan semester\n   serta kurikulumnya. Pengubahan kurikulum ada pada menu\n   Proses >> Kurikulum Semester\n- Untuk memastikan kuesioner telah selesai, periksa\n   Riwayat IPD, apabila masih ada yang belum terisi/kurang\n   akan ditunjukkan sisi mana yang belum/kurang.\n- Ada baiknya anda simpan Riwayat IPD dalam\n   tangkapan layar sebagai bukti anda telah selesai.", wxPoint(1400, 575), wxDefaultSize);
        pengumumanIPDContent->SetBackgroundColour("#CEE9FF");
        pengumumanIPDContent->SetForegroundColour("#0A62A9");
        wxFont pengumumanIPDContentFont(pengumumanIPDContent->GetFont());
        pengumumanIPDContentFont.SetPointSize(11);
        pengumumanIPDContent->SetFont(pengumumanIPDContentFont);


        wxButton* verifikasiBiodataButton = new wxButton(this, wxID_ANY, "Verifikasi Biodata", wxPoint(60, 230));
        wxButton* updateDataWisudaButton = new wxButton(this, wxID_ANY, "Update Data Wisuda", wxPoint(190, 230));
        wxButton* ekivalensi2Button = new wxButton(this, wxID_ANY, "Ekivalensi", wxPoint(340, 230));
        wxButton* kuisionerButton = new wxButton(this, wxID_ANY, "Kuesioner Dosen dan MK", wxPoint(510, 230));
        wxButton* kurikulumButton = new wxButton(this, wxID_ANY, "Kurikulum Semester", wxPoint(610, 260));
        kurikulumButton->Bind(wxEVT_BUTTON, &MainPanel::OnKurikulumButtonClicked, this);
        wxButton* frsButton = new wxButton(this, wxID_ANY, "Formulir Rencana Studi", wxPoint(690, 230));
        frsButton->SetBackgroundColour("#CEE9FF");
        frsButton->Bind(wxEVT_BUTTON, &MainPanel::OnFRSButtonClicked, this);
        wxButton* transkripButton = new wxButton(this, wxID_ANY, "Transkrip", wxPoint(120, 620));
        transkripButton->SetBackgroundColour("#CEE9FF");
        transkripButton->Bind(wxEVT_BUTTON, &MainPanel::OnTranskripButtonClicked, this);
        wxButton* transkripSButton = new wxButton(this, wxID_ANY, "Transkrip Sementara", wxPoint(210, 620));
        wxButton* akademikButton = new wxButton(this, wxID_ANY, "Akademik Mahasiswa", wxPoint(350, 620));
        wxButton* ktmVirtualButton = new wxButton(this, wxID_ANY, "KTM Virtual", wxPoint(500, 620));
        wxButton* biodataMahasiswaButton = new wxButton(this, wxID_ANY, "Biodata Mahasiswa", wxPoint(600, 620));
        biodataMahasiswaButton->SetBackgroundColour("#CEE9FF");
        biodataMahasiswaButton->Bind(wxEVT_BUTTON, &MainPanel::OnBiodataMahasiswaButtonClicked, this);
        wxButton* perkuliahanButton = new wxButton(this, wxID_ANY, "Perkuliahan Mahasiswa", wxPoint(735, 620));
        wxButton* daftarMnMButton = new wxButton(this, wxID_ANY, "Daftar Mahasiswa dan Matakuliah", wxPoint(890, 620));
        wxButton* statusPerAngkatanButton = new wxButton(this, wxID_ANY, "Status Per Angkatan", wxPoint(1100, 620));
        wxButton* prasyaratButton = new wxButton(this, wxID_ANY, "Prasyarat Matakuliah", wxPoint(370, 660));
        wxButton* jadwalKuliahButton = new wxButton(this, wxID_ANY, "Jadwal Kuliah Mahasiswa", wxPoint(530, 660));
        wxButton* nilaiPerMhsButton = new wxButton(this, wxID_ANY, "Nilai Per Mahasiswa", wxPoint(710, 660));
        wxButton* nilaiPerSmtButton = new wxButton(this, wxID_ANY, "Nilai Per Semester", wxPoint(860, 660));
        wxButton* surveiKepuasanButton = new wxButton(this, wxID_ANY, "Survei Kepuasan Mahasiswa", wxPoint(1015, 230));
        wxButton* rekapEkivalensiButton = new wxButton(this, wxID_ANY, "Rekapitulasi Ekivalensi", wxPoint(170, 360));
        wxButton* draftSKPIButton = new wxButton(this, wxID_ANY, "Draft SKPI", wxPoint(755, 490));
        wxButton* guideBookButton = new wxButton(this, wxID_ANY, "Panduan Umum (pdf)", wxPoint(890, 490));
        wxButton* sebagaiMhsButton = new wxButton(this, wxID_ANY, "Sebagai Mahasiswa (pdf)", wxPoint(1080, 490));
        wxButton* historisSPPButton = new wxButton(this, wxID_ANY, "Historis Pembayaran SPP", wxPoint(90, 490));
        wxButton* tagihanSPPButton = new wxButton(this, wxID_ANY, "Tagihan Biaya Pendidikan", wxPoint(280 , 490));
        wxButton* tagihanWisudaButton = new wxButton(this, wxID_ANY, "Pembayaran Wisuda", wxPoint(470, 490));
        wxButton* layananSuratButton = new wxButton(this, wxID_ANY, "Layanan Surat Mahasiswa", wxPoint(935, 360));
        wxButton* suratMahasiswa2Button = new wxButton(this, wxID_ANY, "Panduan Layanan (PDF)", wxPoint(1125, 360));
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

    void OnKurikulumButtonClicked(wxCommandEvent& event)
    {
        KurikulumFrame* kurikulumFrame = new KurikulumFrame("Kurikulum Semester | SI Akademik");
        kurikulumFrame->SetClientSize(1000, 600);
        kurikulumFrame->Centre();
        kurikulumFrame->Show();
    }

    void OnPaint(wxPaintEvent& event)
    {
        Mahasiswa mhs;
        DateTime dt;
        wxPaintDC dc(this);

        wxGraphicsContext* gc = wxGraphicsContext::Create(dc);
        if (gc)
        {
            // ========== Create Rounded Rectangle for Profile ==========
            wxColour solidColorBackground(255, 255, 255);

            wxGraphicsPath pathBackground = gc->CreatePath();
            pathBackground.AddRoundedRectangle(0, 0, 1850, 975, 0);

            wxGraphicsBrush brushBackground = gc->CreateBrush(wxBrush(solidColorBackground));
            gc->SetBrush(brushBackground);
            gc->DrawPath(pathBackground);
            gc->SetPen(wxNullGraphicsPen);
            // =======================================================

            // ========== Create Rounded Rectangle for Profile ==========
            wxColour solidColorProfile(255, 255, 255);

            wxGraphicsPath pathProfile = gc->CreatePath();
            pathProfile.AddRoundedRectangle(1375, 20, 445, 85, 10);

            // Create a pen for the outline
            wxGraphicsPen penProfile = gc->CreatePen(wxPen(wxColour(0, 0, 0), 1.5));
            gc->SetPen(penProfile);

            // Create a brush for filling the rounded rectangle (optional)
            wxGraphicsBrush brushProfile = gc->CreateBrush(wxBrush(solidColorProfile));
            gc->SetBrush(brushProfile);

            gc->DrawPath(pathProfile);
            gc->SetPen(wxNullGraphicsPen);

            // =======================================================

            // ========== Create Rounded Rectangle for Date ==========
            wxColour solidColorDate(17, 144, 233);

            wxGraphicsPath pathDate = gc->CreatePath();
            pathDate.AddRoundedRectangle(1375, 120, 200, 150, 10);

            wxGraphicsBrush brushDate = gc->CreateBrush(wxBrush(solidColorDate));
            gc->SetBrush(brushDate);
            gc->DrawPath(pathDate);
            gc->SetPen(wxNullGraphicsPen);
            // =======================================================

            // ========== Create Rounded Rectangle for Semester ==========
            wxColour solidColorSemester(10, 98, 169);     // End color at position 1

            wxGraphicsPath pathSemester = gc->CreatePath();
            pathSemester.AddRoundedRectangle(1590, 120, 230, 50, 10);

            wxGraphicsBrush brushSemester = gc->CreateBrush(wxBrush(solidColorSemester));
            gc->SetBrush(brushSemester);
            gc->DrawPath(pathSemester);
            gc->SetPen(wxNullGraphicsPen);
            // =======================================================

            // ========== Create Rounded Rectangle for Time ==========
            wxColour solidColorTime(0, 43, 91);     // End color at position 1   // End color at position 1

            wxGraphicsPath pathTime = gc->CreatePath();
            pathTime.AddRoundedRectangle(1590, 185, 230, 85, 10);

            wxGraphicsBrush brushTime = gc->CreateBrush(wxBrush(solidColorTime));
            gc->SetBrush(brushTime);
            gc->DrawPath(pathTime);
            gc->SetPen(wxNullGraphicsPen);
            // =======================================================

            // ========== Create Rounded Rectangle for Announcement ==========
            wxColour solidColorAnnouncement(206, 233, 255);     // End color at position 1

            wxGraphicsPath pathAnnouncement = gc->CreatePath();
            pathAnnouncement.AddRoundedRectangle(1375, 285, 445, 660, 10);

            wxGraphicsBrush brushAnnouncement = gc->CreateBrush(wxBrush(solidColorAnnouncement));
            gc->SetBrush(brushAnnouncement);
            gc->DrawPath(pathAnnouncement);
            gc->SetPen(wxNullGraphicsPen);
            // =======================================================

            // ========== Create Rounded Rectangle for Data ==========
            wxColour solidColorData(10, 98, 169);     // End color at position 1

            wxGraphicsPath pathData = gc->CreatePath();
            pathData.AddRoundedRectangle(50, 170, 380, 40, 10);

            wxGraphicsBrush brushData = gc->CreateBrush(wxBrush(solidColorData));
            gc->SetBrush(brushData);
            gc->DrawPath(pathData);
            gc->SetPen(wxNullGraphicsPen);
            // =======================================================

            // ========== Create Rounded Rectangle for Proses ==========
            wxColour solidColorProses(10, 98, 169);     // End color at position 1

            wxGraphicsPath pathProses = gc->CreatePath();
            pathProses.AddRoundedRectangle(480, 170, 380, 40, 10);

            wxGraphicsBrush brushProses = gc->CreateBrush(wxBrush(solidColorProses));
            gc->SetBrush(brushProses);
            gc->DrawPath(pathProses);
            gc->SetPen(wxNullGraphicsPen);
            // =======================================================

            // ========== Create Rounded Rectangle for Lain_Lain ==========
            wxColour solidColorLain_Lain(10, 98, 169);     // End color at position 1

            wxGraphicsPath pathLain_Lain = gc->CreatePath();
            pathLain_Lain.AddRoundedRectangle(910, 170, 380, 40, 10);

            wxGraphicsBrush brushLain_Lain = gc->CreateBrush(wxBrush(solidColorLain_Lain));
            gc->SetBrush(brushLain_Lain);
            gc->DrawPath(pathLain_Lain);
            gc->SetPen(wxNullGraphicsPen);
            // =======================================================

            // ========== Create Rounded Rectangle for Ekivalensi ==========
            wxColour solidColorEkivalensi(10, 98, 169);     // End color at position 1

            wxGraphicsPath pathEkivalensi = gc->CreatePath();
            pathEkivalensi.AddRoundedRectangle(50, 300, 380, 40, 10);

            wxGraphicsBrush brushEkivalensi = gc->CreateBrush(wxBrush(solidColorEkivalensi));
            gc->SetBrush(brushEkivalensi);
            gc->DrawPath(pathEkivalensi);
            gc->SetPen(wxNullGraphicsPen);
            // =======================================================

            // ========== Create Rounded Rectangle for Yudisium ==========
            wxColour solidColorYudisium(10, 98, 169);     // End color at position 1

            wxGraphicsPath pathYudisium = gc->CreatePath();
            pathYudisium.AddRoundedRectangle(480, 300, 380, 40, 10);

            wxGraphicsBrush brushYudisium = gc->CreateBrush(wxBrush(solidColorYudisium));
            gc->SetBrush(brushYudisium);
            gc->DrawPath(pathYudisium);
            gc->SetPen(wxNullGraphicsPen);
            // =======================================================

            // ========== Create Rounded Rectangle for Surat Mahasiswa ==========
            wxColour solidColorSurat_Mahasiswa(10, 98, 169);     // End color at position 1

            wxGraphicsPath pathSurat_Mahasiswa = gc->CreatePath();
            pathSurat_Mahasiswa.AddRoundedRectangle(910, 300, 380, 40, 10);

            wxGraphicsBrush brushSurat_Mahasiswa = gc->CreateBrush(wxBrush(solidColorSurat_Mahasiswa));
            gc->SetBrush(brushSurat_Mahasiswa);
            gc->DrawPath(pathSurat_Mahasiswa);
            gc->SetPen(wxNullGraphicsPen);
            // =======================================================

            // ========== Create Rounded Rectangle for Biaya Pendidikan ==========
            wxColour solidColorBiayaPendidikan(10, 98, 169);     // End color at position 1

            wxGraphicsPath pathBiayaPendidikan = gc->CreatePath();
            pathBiayaPendidikan.AddRoundedRectangle(50, 430, 595, 40, 10);

            wxGraphicsBrush brushBiayaPendidikan = gc->CreateBrush(wxBrush(solidColorBiayaPendidikan));
            gc->SetBrush(brushBiayaPendidikan);
            gc->DrawPath(pathBiayaPendidikan);
            gc->SetPen(wxNullGraphicsPen);
            // =======================================================

            // ========== Create Rounded Rectangle for SKPI ==========
            wxColour solidColorSKPI(10, 98, 169);     // End color at position 1

            wxGraphicsPath pathSKPI = gc->CreatePath();
            pathSKPI.AddRoundedRectangle(695, 430, 595, 40, 10);

            wxGraphicsBrush brushSKPI = gc->CreateBrush(wxBrush(solidColorSKPI));
            gc->SetBrush(brushSKPI);
            gc->DrawPath(pathSKPI);
            gc->SetPen(wxNullGraphicsPen);
            // =======================================================

            // ========== Create Rounded Rectangle for Laporan ==========
            wxColour solidColorLaporan(10, 98, 169);     // End color at position 1

            wxGraphicsPath pathLaporan = gc->CreatePath();
            pathLaporan.AddRoundedRectangle(50, 560, 1240, 40, 10);

            wxGraphicsBrush brushLaporan = gc->CreateBrush(wxBrush(solidColorLaporan));
            gc->SetBrush(brushLaporan);
            gc->DrawPath(pathLaporan);
            gc->SetPen(wxNullGraphicsPen);
            // =======================================================

            

            wxColour textColor(255, 255, 255);
            wxColour textColorName(0, 0, 0); // White
            wxColour textColorNRP(128, 128, 128);

            wxFont font = wxSystemSettings::GetFont(wxSYS_DEFAULT_GUI_FONT);
            font.SetWeight(wxFONTWEIGHT_BOLD);

            // Set the font properties for the first text with larger font size and bold style
            font.SetPointSize(15);
            font.SetWeight(wxFONTWEIGHT_BOLD);
            gc->SetFont(font, textColorName);

            wxString text0 = wxString::Format("%s", mhs.name);
            double textX0 = 1395;
            double textY0 = 33;
            gc->DrawText(text0, textX0, textY0);

            font.SetPointSize(12);
            font.SetWeight(wxFONTWEIGHT_SEMIBOLD);
            gc->SetFont(font, textColorNRP);

            wxString text1 = wxString::Format("%s", mhs.NRP);
            double textX1 = 1395;
            double textY1 = 67;
            gc->DrawText(text1, textX1, textY1);

            font.SetPointSize(40);
            font.SetWeight(wxFONTWEIGHT_BOLD);
            gc->SetFont(font, textColor);

            wxString text2 = wxString::Format("%d", dt.day);
            double textX2 = 1395;
            double textY2 = 130;
            gc->DrawText(text2, textX2, textY2);

            font.SetPointSize(11);
            font.SetWeight(wxFONTWEIGHT_BOLD);
            gc->SetFont(font, textColor);

            wxString text3 = dt.monthName[dt.mon];
            double textX3 = 1395;
            double textY3 = 200;
            gc->DrawText(text3, textX3, textY3);

            font.SetPointSize(11);
            font.SetWeight(wxFONTWEIGHT_SEMIBOLD);
            gc->SetFont(font, textColor);

            wxString text4 = wxString::Format("%d", dt.year);
            double textX4 = 1395;
            double textY4 = 223;
            gc->DrawText(text4, textX4, textY4);

            if (mon>=1 && mon <=6)
            {
                semester = "Semester Genap";
            } else 
            {
                semester = "Semester Ganjil";
                year +=1;
            };

            font.SetPointSize(11);
            font.SetWeight(wxFONTWEIGHT_BOLD);
            gc->SetFont(font, textColor);

            wxString semesterPeriod = wxString::Format("%s %d/%d", semester, year-1, year);
            double semesterPeriodX5 = 1610;
            double semesterPeriodY5 = 133;
            gc->DrawText(semesterPeriod, semesterPeriodX5, semesterPeriodY5);

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

    private:
        wxStaticText* timeNow;

        void OnTimer(wxTimerEvent& event)
        {
            Mahasiswa mhs;
            string nama = mhs.name;
            string NRP = mhs.NRP;

            // Get the current time
            wxDateTime now = wxDateTime::Now();
            
            if (now.GetHour() >= 10)
            {
                addZeroHour = "";
            }
            if (now.GetHour() < 10)
            {
                addZeroHour = "0";
            }
            if (now.GetMinute() >= 10)
            {
                addZeroMinute = "";
            }
            if (now.GetMinute() < 10)
            {
                addZeroMinute = "0";
            }
            if (now.GetSecond() >= 10)
            {
                addZeroSecond = "";
            }
            if (now.GetSecond() < 10)
            {
                addZeroSecond = "0";
            }

            // Update the time label
            timeNow->SetLabelText(wxString::Format("%s%d:%s%d:%s%d", addZeroHour, now.GetHour(), addZeroMinute, now.GetMinute(), addZeroSecond, now.GetSecond()));
        }
};

wxBEGIN_EVENT_TABLE(MainPanel, wxPanel)
    EVT_PAINT(MainPanel::OnPaint)
wxEND_EVENT_TABLE()

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

            wxMenuBar* menuBar = new wxMenuBar();
            wxMenu* home = new wxMenu();
            wxMenu* data = new wxMenu();
            wxMenu* proses = new wxMenu();
            wxMenu* laporan = new wxMenu();
            wxMenu* lain_lain = new wxMenu();
            wxMenu* ekivalensi = new wxMenu();
            wxMenu* yudisium = new wxMenu();
            wxMenu* skpi = new wxMenu();
            wxMenu* biayapendidikan = new wxMenu();
            wxMenu* suratmahasiswa = new wxMenu();
            wxMenu* keluar = new wxMenu();

            data->Append(1, "Biodata", "", false);
            data->Append(2, "Update Data Wisuda", "Test", false);
            data->Append(3, "Lain-lain", "", false);

            proses->Append(1, "Kuesioner Dosen dan MK", "", false);
            proses->Append(2, "Kurikulum Semester", "", false);
            proses->Append(3, "Formulir Rencana Studi", "", false);

            laporan->Append(1, "Transkrip", "", false);
            laporan->Append(2, "Mahasiswa", "", false);
            laporan->Append(3, "Prasyarat Matakuliah", "", false);
            laporan->Append(4, "Jadwal Kuliah Mahasiswa", "", false);
            laporan->Append(5, "Nilai", "", false);

            lain_lain->Append(1, "Survei Kepuasan Mahasiswa", "", false);

            ekivalensi->Append(1, "Rekapitulasi Ekivalensi", "", false);

            skpi->Append(1, "Draft SKPI", "", false);
            skpi->Append(2, "Panduan Pengguna", "", false);

            biayapendidikan->Append(1, "Historis Pembayaran SPP", "", false);
            biayapendidikan->Append(2, "Tagihan Biaya Pendidikan", "", false);
            biayapendidikan->Append(3, "Pembayaran Wisuda", "", false);

            suratmahasiswa->Append(1, "Layanan Surat Mahasiswa", "", false);
            suratmahasiswa->Append(2, "Panduan Layanan (PDF)", "", false);

            keluar->Append(1, "Kembali ke MyITS Portal", "", false);
            keluar->Append(2, "Log Out", "", false);

            menuBar->Append(home, "Home");
            menuBar->Append(data, "Data");
            menuBar->Append(proses, "Proses");
            menuBar->Append(laporan, "Laporan");
            menuBar->Append(lain_lain, "Lain-lain");
            menuBar->Append(ekivalensi, "Ekivalensi");
            menuBar->Append(yudisium, "Yudisium");
            menuBar->Append(skpi, "SKPI");
            menuBar->Append(biayapendidikan, "Biaya Pendidikan");
            menuBar->Append(suratmahasiswa, "Surat Mahasiswa");
            menuBar->Append(keluar, "Keluar");

            SetMenuBar(menuBar);

            wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
            mainSizer->Add(mainPanel, wxSizerFlags(1).Expand());

            SetSizerAndFit(mainSizer);
        }
};

LoginPage::LoginPage(wxWindow* parent):wxPanel(parent, wxID_ANY)
{
    wxStaticText* userText = new wxStaticText(this, wxID_ANY, "Username");
    wxStaticText* passText = new wxStaticText(this, wxID_ANY, "Password");

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
        mainMenuFrame->SetClientSize(1850, 970);
        mainMenuFrame->Centre();
        mainMenuFrame->Show();
    } else
    {
        wxMessageBox("Login Failed!\nUsername or Password Incorrect!", "Failed", wxICON_ERROR);
    }
};

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
