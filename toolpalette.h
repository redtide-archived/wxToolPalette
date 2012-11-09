#ifndef WXTOOLPALETTEBASE_H
#define WXTOOLPALETTEBASE_H

wxEVT_COMMAND_TOOL_PALETTE_BEGIN_DRAG   // An item is dragged out
wxEVT_COMMAND_TOOL_PALETTE_EXPAND       // A group is expanded/collapsed
wxEVT_COMMAND_TOOL_PALETTE_CLICKED      // A button tool is left clicked
wxEVT_COMMAND_TOOL_PALETTE_RCLICKED     // A button tool is right clicked

class wxToolPaletteEvent : public wxCommandEvent
{
public:
	wxToolPaletteEvent(wxEventType commandType, wxToolPaletteItem *, wxToolPaletteGroup *);
	wxToolPaletteItem *GetItem() const;
	wxToolPaletteGroup *GetGroup() const;
	
};

class wxToolPaletteItem
{
public:
	wxToolPaletteItem(wxWindowID id, const wxString &label, const wxBitmap &bitmap, wxItemKind kind = wxITEM_NORMAL, const wxBitmap &bmpDisabled = wxNullBitmap);
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



class wxToolPaletteGroup 
{
public:
	wxToolPaletteGroup(const wxString &label, bool exclusive = false, bool expanded = false);
	~wxToolPaletteGroup();
	
	wxString            GetLabel() const;
	wxToolPaletteGroup &SetLabel(const wxString &name);
	bool                IsExclusive() const;
	wxToolPaletteGroup &SetExclusive(bool exclusive = true);
	bool                IsExpanded() const;
	wxToolPaletteGroup &SetExpanded(bool expanded = true);

	wxToolPaletteItem *InsertItem(wxToolPaletteItem *item, const wxToolPaletteItem *successor = NULL);
	void               DeleteItem(wxToolPaletteItem *item);
	wxToolPaletteItem *FindItem(size_t index);
	wxToolPaletteItem *FindItem(wxWindowID id);
	size_t             GetItemCount() const;
	
	size_t         GetIndex() const;
	wxToolPalette *GetPalette();
	
};




class wxToolPalette : public wxControl
{
public:
	wxToolPalette(wxWindow *parent, wxWindowID id = wxID_ANY, const wxPoint &pos = wxDefaultPosition, const wxSize &size = wxDefaultSize, long style=0, const wxString &name = wxControlNameStr);
	~wxToolPalette();

	bool Create(wxWindow *parent, wxWindowID id = wxID_ANY, const wxPoint &pos = wxDefaultPosition, const wxSize &size = wxDefaultSize, long style=0, const wxString &name = wxControlNameStr);
	
	void Realize();
	
	wxToolPaletteGroup*  InsertGroup(wxToolPaletteGroup *group, const wxToolPaletteGroup *successor = NULL);
	void                 DeleteGroup(wxToolPaletteGroup *group);
	wxToolPaletteGroup*  FindGroup(size_t index) const;
	size_t               GetGroupCount() const;
	wxToolPaletteItem *  FindItem(wxWindowID id);	
	
};

#endif // WXTOOLPALETTEBASE_H
