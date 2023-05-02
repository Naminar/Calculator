#include <wx/wx.h>
#include <wx/sizer.h>
#include <wx/defs.h>
#include "include/connection.hpp"
#include <string>


const int ID_BUT_1  = 1;
const int ID_BUT_2  = 2;
const int ID_BUT_3  = 3;
const int ID_BUT_4  = 4;
const int ID_BUT_5  = 5;
const int ID_BUT_6  = 6;
const int ID_BUT_7  = 7;
const int ID_BUT_8  = 8;
const int ID_BUT_9  = 9;
const int ID_BUT_10 = 10;
const int ID_BUT_11 = 11;
const int ID_BUT_12 = 12;
const int ID_BUT_13 = 13;
const int ID_BUT_14 = 14;
const int ID_BUT_15 = 15;
const int ID_BUT_16 = 16;
const int ID_BUT_17 = 17;
const int ID_BUT_18 = 18;
const int ID_BUT_19 = 19;
const int ID_BUT_20 = 20;
const int ID_BUT_21 = 21;
const int ID_BUT_22 = 22;
const int ID_BUT_23 = 23;
const int ID_BUT_24 = 24;
const int ID_BUT_25 = 25;
const int ID_BUT_26 = 26;
const int ID_BUT_27 = 27;
const int ID_BUT_28 = 28;
const int ID_BUT_29 = 29;
const int ID_BUT_30 = 30;
const int ID_BUT_31 = 31;
const int ID_BUT_32 = 32;
const int ID_BUT_33 = 33;
const int ID_BUT_34 = 34;
const int ID_BUT_35 = 35;
const int ID_BUT_36 = 36;
const int ID_BUT_37 = 37;
const int ID_BUT_38 = 38;
const int ID_BUT_39 = 39;
const int ID_BUT_40 = 40;
const int ID_BUT_41 = 41;
const int ID_BUT_42 = 42;
const int ID_BUT_43 = 43;
const int ID_BUT_44 = 44;
const int ID_BUT_45 = 45;
const int ID_BUT_46 = 46;
const int ID_BUT_47 = 47;
const int ID_BUT_48 = 48;
const int ID_BUT_49 = 49;
const int ID_BUT_50 = 50;
const int ID_BUT_51 = 51;
const int ID_BUT_52 = 52;
const int ID_BUT_53 = 53;
const int ID_BUT_54 = 54;
const int ID_BUT_55 = 55;
const int ID_BUT_56 = 56;
const int ID_BUT_57 = 57;
const int ID_BUT_58 = 58;
const int ID_BUT_59 = 59;
const int ID_BUT_60 = 60;
const int ID_BUT_61 = 61;
const int ID_BUT_62 = 62;
const int ID_BUT_63 = 63;
const int ID_BUT_64 = 64;
const int ID_BUT_65 = 65;
const int ID_BUT_66 = 66;
const int ID_BUT_67 = 67;
const int ID_BUT_68 = 68;
const int ID_BUT_69 = 69;
const int ID_BUT_70 = 70;
const int ID_BUT_71 = 71;
const int ID_BUT_72 = 72;
const int ID_BUT_73 = 73;
const int ID_BUT_74 = 74;
const int ID_BUT_75 = 75;
const int ID_BUT_76 = 76;
const int ID_BUT_77 = 77;
const int ID_BUT_78 = 78;
const int ID_BUT_79 = 79;
const int ID_BUT_80 = 80;
const int ID_BUT_81 = 81;
const int ID_BUT_82 = 82;
const int ID_BUT_83 = 83;
const int ID_BUT_84 = 84;
const int ID_BUT_85 = 85;
const int ID_BUT_86 = 86;
const int ID_BUT_87 = 87;
const int ID_BUT_88 = 88;
const int ID_BUT_89 = 89;
const int ID_BUT_90 = 90;
const int ID_BUT_91 = 91;
const int ID_BUT_92 = 92;
const int ID_BUT_93 = 93;
const int ID_BUT_94 = 94;
const int ID_BUT_95 = 95;
const int ID_BUT_96 = 96;
const int ID_BUT_97 = 97;
const int ID_BUT_98 = 98;
const int ID_BUT_99 = 99;
const int ID_BUT_100 = 100;
const int ID_BUT_101 = 101;

const int ID_BUT_102 = 102;


#define Create_Button(pict, file, n, x, y, ID_BUT) \
{ \
    wxImage pict(wxT(file), wxBITMAP_TYPE_PNG); \
    if (pict.IsOk()) \
    { \
        /*std::cout << "\nPicture " << file << " is load.\n"; */  \
        button[n] = new wxBitmapButton (drawPanel, ID_BUT,  \
                                        wxBitmap (pict.Scale (52, 52)), wxPoint (x, y)); \
        Connect (ID_BUT, wxEVT_COMMAND_BUTTON_CLICKED,  \
                 wxCommandEventHandler (CalcFrame::pressButton)); \
    } \
    else \
    { \
        wxMessageBox (wxString::Format(wxT("Picture %s is not loaded!"), file)); \
    } \
} \


class BackPanel : public wxPanel
{
    wxBitmap image;

public:
    BackPanel (wxFrame *parent, wxString file, wxBitmapType format);
    void paintEvent (wxPaintEvent &evt);
    void paintBack ();
    void setImage (wxDC &dc);
    void OnMouse (wxMouseEvent &event);
};

//class RegPanel : public wxPanel


class CalcFrame : public wxFrame
{
    Connection     back_end;
    int            flag_on_off;

    wxBoxSizer     *sizer_0, *sizer_1, *sizer_program;
    BackPanel      *drawPanel, *drawReg;
    wxPanel        *panel_program;
    wxBitmapButton *button[103];
    //wxTextCtrl     *scoreboard[8];
    wxTextCtrl     *scoreboard, *program[36], *registers[8], *circular_stack[6];
    wxStaticText   *label_program, *label_registers;
    wxGridSizer    *gs_program;

public:
    CalcFrame           (const wxString& title);
    ~CalcFrame          ();
    void pressButton    (wxCommandEvent &evt);
    void RefreshPicture ();
    void ClearAllFields ();
};


BackPanel::BackPanel (wxFrame *parent, wxString file, wxBitmapType format)
:wxPanel(parent)
{
    image.LoadFile (file, format);
    Connect (wxEVT_PAINT, wxPaintEventHandler (BackPanel::paintEvent));

    //Connect (wxEVT_LEFT_DOWN, wxMouseEventHandler (BackPanel::OnMouse));
}


void BackPanel::paintEvent (wxPaintEvent &evt)
{
    wxPaintDC dc(this);
    setImage (dc);
}

void BackPanel::setImage (wxDC &dc)
{
    dc.DrawBitmap (image, 0, 0, false);
}

void BackPanel::OnMouse (wxMouseEvent &evt)
{
    wxString answ;
    int x = evt.GetX();
    int y = evt.GetY();
    answ = answ.Format (wxT("(%d, %d)"), x, y);
    wxMessageBox (answ);
}


CalcFrame::CalcFrame (const wxString& title)
:wxFrame(NULL, wxID_ANY, title, wxPoint(50,50), wxSize(1436, 870))
{
    flag_on_off = 0;

    wxInitAllImageHandlers ();

    sizer_0 = new wxBoxSizer (wxHORIZONTAL);
    sizer_1 = new wxBoxSizer (wxVERTICAL);

    drawPanel     = new BackPanel (this, wxT("calcApp.png"), wxBITMAP_TYPE_PNG);
    drawReg       = new BackPanel (this, wxT("mem.png"),     wxBITMAP_TYPE_PNG);
    panel_program = new wxPanel   (this, wxID_ANY);



// -------- Create Buttons --------

    Create_Button(pict_96, "plus.png",  96, 370, 463, ID_BUT_96)
    Create_Button(pict_86, "minus.png", 86, 368, 561, ID_BUT_86)
    Create_Button(pict_26,   "mul.png", 26, 297, 463, ID_BUT_26)
    Create_Button(pict_36,   "div.png", 36, 295, 561, ID_BUT_36)
    Create_Button(pict_16,  "swap.png", 16, 296, 364, ID_BUT_16)
    Create_Button(pict_6 , "arrup.png", 6,  368, 362, ID_BUT_6)

    Create_Button(pict_14,    "k1.png", 14, 53,  558, ID_BUT_14)
    Create_Button(pict_24,    "k2.png", 22, 125, 558, ID_BUT_24)
    Create_Button(pict_34,    "k3.png", 34, 195, 558, ID_BUT_34)
    Create_Button(pict_44,    "k4.png", 44, 53,  463, ID_BUT_44)
    Create_Button(pict_54,    "k5.png", 54, 125, 463, ID_BUT_54)
    Create_Button(pict_64,    "k6.png", 64, 195, 463, ID_BUT_64)
    Create_Button(pict_74,    "k7.png", 74, 53,  364, ID_BUT_74)
    Create_Button(pict_84,    "k8.png", 84, 125, 364, ID_BUT_84)
    Create_Button(pict_94,    "k9.png", 94, 195, 364, ID_BUT_94)
    Create_Button(pict_4 ,    "k0.png", 4,  46,  674, ID_BUT_4)

    Create_Button(pict_46,   "pnt.png", 46, 136, 672, ID_BUT_46)
    Create_Button(pict_56,  "sign.png", 56, 229, 672, ID_BUT_56)
    Create_Button(pict_66,    "vp.png", 66, 318, 673, ID_BUT_66)
    Create_Button(pict_2,      "F.png", 2,  406, 673, ID_BUT_2)

    Create_Button(pict_76,    "cx.png", 76, 36,  263, ID_BUT_76)

    Create_Button(pict_1,      "p.png", 1,  141, 268, ID_BUT_1)
    Create_Button(pict_38,   "x^y.png", 38, 220, 268, ID_BUT_38)
    Create_Button(pict_58,    "bp.png", 58, 288, 268, ID_BUT_58)
    Create_Button(pict_68,    "pp.png", 68, 362, 268, ID_BUT_68)

    Create_Button(pict_100, "shgL.png", 101, 145, 172, ID_BUT_101)
    Create_Button(pict_101, "shgR.png", 100, 217, 172, ID_BUT_100)
    Create_Button(pict_48,    "vo.png", 48,  287, 172, ID_BUT_48)
    Create_Button(pict_78,    "sp.png", 78,  360, 172, ID_BUT_78)


    Create_Button(pict_102, "on_off.png", 102, 36, 172, ID_BUT_102)


// -------- Creat Pragram Area -----------

    gs_program = new wxGridSizer (6, 6, 3, 3);

    for (int j = 0; j < 36; j++)
    {
        int i = (j / 6) + (j % 6) * 6;    // converting strings to columns
        program[i] = new wxTextCtrl (panel_program, -1, wxT(""), wxPoint (-1, -1),
                                     wxSize(100, 40), wxTE_RIGHT);
        program[i]->SetFont (wxFontInfo(30));
        gs_program->Add (program[i], 0, wxEXPAND);
    }

    sizer_program = new wxBoxSizer (wxVERTICAL);
    sizer_program->Add (gs_program, 1, wxEXPAND, 10);
    panel_program->SetSizer (sizer_program);


// -------- Creat scoreboard ----------

    //for (int i = 0; i < 8; i++)
    //{
    //    scoreboard[i] = new wxTextCtrl (drawPanel, wxID_ANY, _(""),
    //                                    wxPoint (54 + i * 52, 25), wxSize (50, 60),
    //                                    wxTE_RIGHT);
    //    scoreboard[i]->SetFont (wxFontInfo(60));
    //}

    scoreboard = new wxTextCtrl (drawPanel, wxID_ANY, _(""),
                                 wxPoint (54, 25), wxSize (50 + 7 * 52, 60),
                                 wxTE_RIGHT);
    scoreboard->SetFont (wxFontInfo (60));
    scoreboard->SetBackgroundColour (*wxBLACK);

// -------- Creat Registers----------

    for (int i = 0; i < 8; i++)
    {
        registers[i] = new wxTextCtrl (drawReg, wxID_ANY, _(""),
                                       wxPoint (77, 263 - i * 37), wxSize (144, 35),
                                       wxTE_RIGHT);
        registers[i]->SetFont (wxFontInfo(30));
    }

// ------- Create Circular Stack ---

    circular_stack[0] = new wxTextCtrl (drawReg, wxID_ANY, _(""),
                                        wxPoint (275, 109), wxSize (144, 35),
                                        wxTE_RIGHT);
    circular_stack[0]->SetFont (wxFontInfo (30));

    circular_stack[1] = new wxTextCtrl (drawReg, wxID_ANY, _(""),
                                        wxPoint (275 + 144 + 26, 109), wxSize (144, 35),
                                        wxTE_RIGHT);
    circular_stack[1]->SetFont (wxFontInfo (30));

    circular_stack[2] = new wxTextCtrl (drawReg, wxID_ANY, _(""),
                                        wxPoint (275 + 2 * (144 + 25), 109), wxSize (144, 35),
                                        wxTE_RIGHT);
    circular_stack[2]->SetFont (wxFontInfo (30));

    circular_stack[5] = new wxTextCtrl (drawReg, wxID_ANY, _(""),
                                        wxPoint (275 + 19, 256), wxSize (144, 35),
                                        wxTE_RIGHT);
    circular_stack[5]->SetFont (wxFontInfo (30));

    circular_stack[4] = new wxTextCtrl (drawReg, wxID_ANY, _(""),
                                        wxPoint (275 + 19 + 144 + 26, 256), wxSize (144, 35),
                                        wxTE_RIGHT);
    circular_stack[4]->SetFont (wxFontInfo (30));

    circular_stack[3] = new wxTextCtrl (drawReg, wxID_ANY, _(""),
                                        wxPoint (275 + 19 + 2*(144+25), 256), wxSize (144, 35),
                                        wxTE_RIGHT);
    circular_stack[3]->SetFont (wxFontInfo (30));



// -------- CREATE ENVIRONMENT -----------

    sizer_0->Add (drawPanel, 1, wxEXPAND, 10);

// -------- Create Label for Program --------
//                                          |
    label_program = new wxStaticText (this, wxID_ANY, _("\n                  "
                                                        "EXECUTABLE PROGRAM"
                                                        "                    "
                                                        "                    "
                                                        "\n"));
    label_program->SetFont (wxFontInfo (30));
    sizer_1->Add (label_program);
//                                          |
// ------------------------------------------

    sizer_1->Add (panel_program);

// -------- Create Label for Registers ------
//                                          |
    label_registers = new wxStaticText (this, wxID_ANY, _("\n\n       "
                                                          "REGISTERS"
                                                          "\n"));
    label_registers->SetFont (wxFontInfo (30));
    sizer_1->Add (label_registers);
//                                          |
// ------------------------------------------

    sizer_1->Add (drawReg, 1, wxEXPAND, 10);

    sizer_0->Add (sizer_1, 1, wxEXPAND);

    SetSizer (sizer_0);
    Centre ();
}

CalcFrame::~CalcFrame()
{
    panel_program->Destroy ();
    drawPanel->Destroy ();
    drawReg->Destroy ();

    Close (true);
}

void CalcFrame::pressButton (wxCommandEvent &evt)
{
    int ID = evt.GetId();
    //wxMessageBox (wxString::Format(wxT("Press on button with ID: %d."), ID));

    if (flag_on_off == 0)
    {
        if (ID == 102)
        {
            flag_on_off = 1;
            back_end.create_tablo_information ();
            RefreshPicture ();
        }
    }
    else if (flag_on_off == 1)
    {
        if (ID == 102)
        {
            back_end.get_button_num (ID);
            flag_on_off = 0;
            ClearAllFields ();
        }
        else
        {
            back_end.get_button_num (ID);
            RefreshPicture ();
        }
    }
}

void CalcFrame::RefreshPicture ()
{
    scoreboard->Clear();
    *scoreboard << back_end.screen_data.tablo;

    for (int i = 0; i < 36; i++)
    {
        program[i]->Clear();
        *program[i] << back_end.screen_data.program_memory[i];
    }

    registers[0]->Clear();
    *registers[0] << back_end.screen_data.ball[0];
    for (int i = 1; i < 8; i++)
    {
        registers[i]->Clear();
        *registers[i] << back_end.screen_data.registers[i-1];
    }

    for (int i = 0; i < 6; i++)
    {
        circular_stack[i]->Clear();
        *circular_stack[i] << back_end.screen_data.ball[i+1];
    }
}

void CalcFrame::ClearAllFields ()
{
    scoreboard->Clear();

    for (int i = 0; i < 36; i++)
    {
        program[i]->Clear();
    }

    for (int i = 0; i < 8; i++)
    {
        registers[i]->Clear();
    }

    for (int i = 0; i < 6; i++)
    {
        circular_stack[i]->Clear();
    }
}



class CalcApp: public wxApp
{
    CalcFrame *frame;

public:
    bool OnInit ()
    {
        frame = new CalcFrame (wxT("Calc 2023"));
        frame->Show();

        SetTopWindow (frame);

        return true;
    }

    int OnExit ()
    {
        return 0;
    }
};
