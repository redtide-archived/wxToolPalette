#include "wx/wxprec.h"

#ifdef __BORLANDC__
    #pragma hdrstop
#endif

#include "wx/toolpalette.h"

#ifndef WX_PRECOMP
    
#endif

const char wxToolPaletteNameStr[] = "wxToolPalette";

class wxToolPaletteItem
{
public:
    wxToolPaletteItem(wxWindowID id, const wxString &label,
                      const wxBitmap &bitmap, wxItemKind kind = wxITEM_NORMAL,
                      const wxBitmap &bmpDisabled = wxNullBitmap);

    wxToolPaletteItem(wxWindowID id, wxWindow *control, long style=0);
    wxToolPaletteItem();
    ~wxToolPaletteItem();

    wxToolPaletteItem &SetHelp(const wxString &);
    wxToolPaletteItem &SetBitmap(const wxBitmap &);
    wxToolPaletteItem &SetDisabledBitmap(const wxBitmap &);
    wxToolPaletteItem &SetClientObject(wxClientData *);
    wxToolPaletteItem &SetClientData(void *);

    wxString           GetHelp() const;
    wxBitmap           GetBitmap() const;
    wxBitmap           GetDisabledBitmap() const;
    wxClientData *     GetClientObject() const;
    void *             GetClientData() const;

    wxWindow *GetControl();
    wxWindowID GetId();

    size_t              GetIndex();
    wxToolPalette      *GetPalette();
    wxToolPaletteGroup *GetGroup();
};

wxToolPalette::wxToolPalette()
{
}

wxToolPalette::~wxToolPalette()
{
}

// ============================================================================
// wxToolPaletteEvent implementation
// ============================================================================

wxIMPLEMENT_DYNAMIC_CLASS(wxToolPaletteEvent, wxNotifyEvent)

#define wxDEFINE_TOOLPALETTE_EVENT(name) \
    wxDEFINE_EVENT(wxEVT_COMMAND_TOOLPALETTE_##name, wxToolPaletteEvent)

wxDEFINE_TOOLPALETTE_EVENT(ITEM_BEGIN_DRAG);
wxDEFINE_TOOLPALETTE_EVENT(ITEM_END_DRAG);
wxDEFINE_TOOLPALETTE_EVENT(ITEM_EXPANDING);
wxDEFINE_TOOLPALETTE_EVENT(ITEM_EXPANDED);

#undef wxDEFINE_TREELIST_EVENT
