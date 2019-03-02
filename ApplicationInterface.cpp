//---------------------------------------------------------------------------
// Include
//---------------------------------------------------------------------------

#include "ApplicationInterface.h"
// This one is required to complie CCentralWidgetHander
#include "Interface/CentralWidgetHandler.h"
// This one is required to complie accessUI method of the base class
#include "ui_CMainWindow.h"
//---------------------------------------------------------------------------

namespace NSApplication {
//---------------------------------------------------------------------------
// CApplicationInterface Definition
//---------------------------------------------------------------------------

CApplicationInterface::CApplicationInterface()
  : CentralWidgetHandler_(
      std::make_unique<CCentralWidgetHandler>(accessUI()->centralWidget)) {
}
//---------------------------------------------------------------------------

CApplicationInterface::~CApplicationInterface() {
  // I need an explicit destructor because the class contains
  // a unique_ptr to an incomplete type
}
//---------------------------------------------------------------------------
} // NSApplication
//---------------------------------------------------------------------------
