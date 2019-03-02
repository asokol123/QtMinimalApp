//---------------------------------------------------------------------------
// Include
//---------------------------------------------------------------------------

#include "Application.h"
#include "ApplicationImplementation.h"
//---------------------------------------------------------------------------

namespace NSApplication {
//---------------------------------------------------------------------------
// CApplication Definition
//---------------------------------------------------------------------------

CApplication::CApplication()
  : AppImpl_(std::make_unique<CApplicationImplementation>()) {
}
//---------------------------------------------------------------------------

CApplication::~CApplication() {
  // I need an explicit destructor because the class contains
  // a unique_ptr to an incomplete type
}
//---------------------------------------------------------------------------
} // NSApplication
//---------------------------------------------------------------------------
