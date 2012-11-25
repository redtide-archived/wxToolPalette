#include <wx/wxprec.h>

#ifdef __BORLANDC__
    #pragma hdrstop
#endif

#include <wx/defs.h>

#define wxUSE_TOOLPALETTE 1 // Remove this when adding code in wx

#if wxUSE_TOOLPALETTE

#include "wx/toolpalette.h"

#ifndef WX_PRECOMP
    #include <wx/bitmap.h>
    #include <wx/control.h>
#endif

const char wxToolPaletteNameStr[] = "wxToolPalette";

// ============================================================================
// wxToolPaletteItem implementation
// ============================================================================

wxToolPaletteItem::wxToolPaletteItem(wxWindowID id, const wxString &label,
                                     const wxBitmap &bitmap,
                                     wxItemKind kind,
                                     const wxBitmap &bmpDisabled)
{
    // TODO: Not implemented
}

wxToolPaletteItem::wxToolPaletteItem(wxWindowID id, wxWindow *control,
                                     long style)
{
    // TODO: Not implemented
}

wxToolPaletteItem::wxToolPaletteItem()
{
    // TODO: Not implemented
}

wxToolPaletteItem::~wxToolPaletteItem()
{
    // TODO: Not implemented
}

wxToolPaletteItem &wxToolPaletteItem::SetHelp(const wxString &help)
{
    // TODO: Not implemented
}

wxToolPaletteItem &wxToolPaletteItem::SetBitmap(const wxBitmap &bitmap)
{
    // TODO: Not implemented
}

wxToolPaletteItem &wxToolPaletteItem::SetDisabledBitmap(const wxBitmap &bitmap)
{
    // TODO: Not implemented
}

wxToolPaletteItem &wxToolPaletteItem::SetClientObject(wxClientData *clientData)
{
    // TODO: Not implemented
}

wxToolPaletteItem &wxToolPaletteItem::SetClientData(void *clientData)
{
    // TODO: Not implemented
}

wxString wxToolPaletteItem::GetHelp() const
{
    // TODO: Not implemented
    return wxString();
}

wxBitmap wxToolPaletteItem::GetBitmap() const
{
    // TODO: Not implemented
    return wxNullBitmap;
}

wxBitmap wxToolPaletteItem::GetDisabledBitmap() const
{
    // TODO: Not implemented
    return wxNullBitmap;
}

wxClientData *wxToolPaletteItem::GetClientObject() const
{
    // TODO: Not implemented
    return NULL;
}

void *wxToolPaletteItem::GetClientData() const
{
    // TODO: Not implemented
    return NULL;
}

wxWindow *wxToolPaletteItem::GetControl()
{
    // TODO: Not implemented
    return NULL;
}

wxWindowID wxToolPaletteItem::GetId()
{
    // TODO: Not implemented
    return 0;
}

size_t wxToolPaletteItem::GetIndex()
{
    // TODO: Not implemented
    return wxNOT_FOUND;
}

wxToolPalette *wxToolPaletteItem::GetPalette()
{
    // TODO: Not implemented
    return NULL;
}

wxToolPaletteGroup *wxToolPaletteItem::GetGroup()
{
    // TODO: Not implemented
    return NULL;
}

// ============================================================================
// wxToolPaletteGroup implementation
// ============================================================================

wxToolPaletteGroup::wxToolPaletteGroup(const wxString &label,
                                       bool exclusive, bool expanded)
{
    // TODO: Not implemented
}

wxToolPaletteGroup::~wxToolPaletteGroup()
{
    // TODO: Not implemented
}

wxString wxToolPaletteGroup::GetLabel() const
{
    // TODO: Not implemented
    return wxString();
}

wxToolPaletteGroup &SetLabel(const wxString & name)
{
    // TODO: Not implemented
    
}

bool wxToolPaletteGroup::IsExclusive() const
{
    // TODO: Not implemented
    return false;
}

wxToolPaletteGroup &wxToolPaletteGroup::SetExclusive(bool exclusive)
{
    // TODO: Not implemented
    
}

bool wxToolPaletteGroup::IsExpanded() const
{
    // TODO: Not implemented
    return false;
}

wxToolPaletteGroup &wxToolPaletteGroup::SetExpanded(bool expanded)
{
    // TODO: Not implemented
    
}

wxToolPaletteItem *
wxToolPaletteGroup::InsertItem(wxToolPaletteItem *item,
                               const wxToolPaletteItem *successor)
{
    // TODO: Not implemented
}

void wxToolPaletteGroup::DeleteItem(wxToolPaletteItem * item)
{
    // TODO: Not implemented
}

wxToolPaletteItem *wxToolPaletteGroup::FindItem(size_t index)
{
    // TODO: Not implemented
    return NULL;
}

wxToolPaletteItem *wxToolPaletteGroup::FindItem(wxWindowID id)
{
    // TODO: Not implemented
    return NULL;
}

size_t wxToolPaletteGroup::GetItemCount() const
{
    // TODO: Not implemented
    return 0;
}

size_t wxToolPaletteGroup::GetIndex() const
{
    // TODO: Not implemented
    return wxNOT_FOUND;
}

wxToolPalette *wxToolPaletteGroup::GetPalette()
{
    // TODO: Not implemented
    return NULL;
}

// ============================================================================
// wxToolPalette implementation
// ============================================================================

void wxToolPalette::Init()
{
    // TODO: Not implemented
}

wxToolPalette::~wxToolPalette()
{
    // TODO: Not implemented
}

bool wxToolPalette::Create( wxWindow *parent, wxWindowID id,
                            const wxPoint& pos, const wxSize& size,
                            long style, const wxValidator& validator,
                            const wxString& name )
{
    if ( !wxControl::Create(parent, id, pos, size, style, validator, name) )
        return false;

    // TODO: Not implemented

    return true;
}

void
wxToolPalette::Realize()
{
    // TODO: Not implemented
}

wxToolPaletteGroup *
wxToolPalette::InsertGroup(wxToolPaletteGroup *group,
                           const wxToolPaletteGroup *successor)
{
    // TODO: Not implemented
    return NULL;
}

void
wxToolPalette::DeleteGroup(wxToolPaletteGroup* group)
{
    // TODO: Not implemented
}

wxToolPaletteGroup *
wxToolPalette::FindGroup(size_t index) const
{
    // TODO: Not implemented
    return NULL;
}

size_t wxToolPalette::GetGroupCount() const
{
    // TODO: Not implemented
    return 0;
}

wxToolPaletteItem *wxToolPalette::FindItem(wxWindowID id)
{
    // TODO: Not implemented
    return NULL;
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

#undef wxDEFINE_TOOLPALETTE_EVENT

#endif // #if wxUSE_TOOLPALETTE
