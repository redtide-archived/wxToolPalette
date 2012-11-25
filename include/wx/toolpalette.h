#ifndef _WXTOOLPALETTE_GENERIC_H_
#define _WXTOOLPALETTE_GENERIC_H_

#include "toolpalette_defs.h" // Remove this when adding code in wx

#include <wx/control.h>
#include <wx/event.h>

// ============================================================================
// wxToolPaletteItem
// ============================================================================

class wxToolPaletteGroup;
class wxToolPalette;

class WXDLLIMPEXP_TOOLPALETTE wxToolPaletteItem
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

// ============================================================================
// wxToolPaletteGroup
// ============================================================================

class WXDLLIMPEXP_TOOLPALETTE wxToolPaletteGroup 
{
public:
    wxToolPaletteGroup(const wxString &label, bool exclusive = false,
                       bool expanded = false);

    ~wxToolPaletteGroup();

    wxString            GetLabel() const;
    wxToolPaletteGroup &SetLabel(const wxString &name);
    bool                IsExclusive() const;
    wxToolPaletteGroup &SetExclusive(bool exclusive = true);
    bool                IsExpanded() const;
    wxToolPaletteGroup &SetExpanded(bool expanded = true);

    wxToolPaletteItem *InsertItem(wxToolPaletteItem *item,
                                  const wxToolPaletteItem *successor = NULL);
    void               DeleteItem(wxToolPaletteItem *item);
    wxToolPaletteItem *FindItem(size_t index);
    wxToolPaletteItem *FindItem(wxWindowID id);
    size_t             GetItemCount() const;

    size_t         GetIndex() const;
    wxToolPalette *GetPalette();
};

// ============================================================================
// wxToolPalette
// ============================================================================

class WXDLLIMPEXP_TOOLPALETTE wxToolPalette : public wxControl
{
public:
    wxToolPalette() { Init(); }

    wxToolPalette(wxWindow *parent,
                  wxWindowID         id        = wxID_ANY,
                  const wxPoint&     pos       = wxDefaultPosition,
                  const wxSize&      size      = wxDefaultSize,
                  long               style     = 0,
                  const wxValidator& validator = wxDefaultValidator,
                  const wxString&    name      = "wxToolPalette")
    {
        Init();

        Create(parent, id, pos, size, style, validator, name);
    }

    virtual ~wxToolPalette();

    bool Create(wxWindow           *parent,
                wxWindowID         id        = wxID_ANY,
                const wxPoint&     pos       = wxDefaultPosition,
                const wxSize&      size      = wxDefaultSize,
                long               style     = 0,
                const wxValidator& validator = wxDefaultValidator,
                const wxString&    name      = "wxToolPalette");

    void Realize();

    wxToolPaletteGroup*  FindGroup(size_t index) const;
    wxToolPaletteGroup*  InsertGroup(wxToolPaletteGroup *group,
                                     const wxToolPaletteGroup *successor = NULL);
    void                 DeleteGroup(wxToolPaletteGroup *group);
    size_t               GetGroupCount() const;

    wxToolPaletteItem *  FindItem(wxWindowID id);

private:
    void Init();
};

// ============================================================================
// wxToolPaletteEvent
// ============================================================================

class WXDLLIMPEXP_TOOLPALETTE wxToolPaletteEvent : public wxNotifyEvent
{
public:
    wxToolPaletteEvent(wxEventType commandType = wxEVT_NULL, int id = 0)
    :
    wxNotifyEvent(commandType, id),
    m_group(NULL),
    m_item(NULL)
    {
    }

    wxToolPaletteEvent(wxEventType commandType, wxToolPalette *palette,
                       wxToolPaletteGroup *group = NULL,
                       wxToolPaletteItem  *item  = NULL)
    :
    wxNotifyEvent(commandType, palette->GetId()),
    m_group(group),
    m_item(item)
    {
        SetEventObject(palette);
    }

    wxToolPaletteEvent(const wxToolPaletteEvent& event)
    :
    wxNotifyEvent(event)
    {
        m_group = event.m_group;
        m_item  = event.m_item;
    }

    virtual wxEvent* Clone() const { return new wxToolPaletteEvent(*this); }

    wxToolPaletteGroup *GetGroup() const { return m_group; }
    wxToolPaletteItem  *GetItem()  const { return m_item; }

private:
    wxToolPaletteGroup *m_group;
    wxToolPaletteItem  *m_item;

    wxDECLARE_DYNAMIC_CLASS(wxToolPaletteEvent);
};

// ----------------------------------------------------------------------------
// Event types and event table macros.
// ----------------------------------------------------------------------------

typedef void (wxEvtHandler::*wxToolPaletteEventFunction)(wxToolPaletteEvent&);

#define wxToolPaletteEventHandler(func) \
    wxEVENT_HANDLER_CAST(wxToolPaletteEventFunction, func)

#define wxEVT_TOOLPALETTE_GENERIC(name, id, fn) \
    wx__DECLARE_EVT1(wxEVT_COMMAND_TOOLPALETTE_##name, id, wxToolPaletteEventHandler(fn))

#define wxDECLARE_TOOLPALETTE_EVENT(name) \
    wxDECLARE_EXPORTED_EVENT( WXDLLIMPEXP_TOOLPALETTE, \
                              wxEVT_COMMAND_TOOLPALETTE_##name, \
                              wxToolPaletteEvent)

wxDECLARE_TOOLPALETTE_EVENT(ITEM_BEGIN_DRAG);
#define EVT_TOOLPALETTE_ITEM_BEGIN_DRAG(id, fn) \
    wxEVT_TOOLPALETTE_GENERIC(ITEM_BEGIN_DRAG, id, fn)

wxDECLARE_TOOLPALETTE_EVENT(ITEM_END_DRAG);
#define EVT_TOOLPALETTE_ITEM_END_DRAG(id, fn) \
    wxEVT_TOOLPALETTE_GENERIC(ITEM_END_DRAG, id, fn)

wxDECLARE_TOOLPALETTE_EVENT(ITEM_EXPANDING);
#define EVT_TOOLPALETTE_ITEM_EXPANDING(id, fn) \
    wxEVT_TOOLPALETTE_GENERIC(ITEM_EXPANDING, id, fn)

wxDECLARE_TOOLPALETTE_EVENT(ITEM_EXPANDED);
#define EVT_TOOLPALETTE_ITEM_EXPANDED(id, fn) \
    wxEVT_TOOLPALETTE_GENERIC(ITEM_EXPANDED, id, fn)

#undef wxDECLARE_TOOLPALETTE_EVENT

#endif // _WXTOOLPALETTE_GENERIC_H_
