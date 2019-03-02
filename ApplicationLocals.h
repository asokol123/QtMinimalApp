#ifndef APPLICATIONLOCALS_H
#define APPLICATIONLOCALS_H
//---------------------------------------------------------------------------
// Include
//---------------------------------------------------------------------------

#include "ApplicationInterface.h"
//---------------------------------------------------------------------------

namespace NSApplication {
//---------------------------------------------------------------------------
// CApplicationLocals Declaration
//---------------------------------------------------------------------------
// A part of the Application object
// Its purpose is to manage all internal resources of the application
// for example, some data, internal logic etc.
//
// This internal resources use signals connected to interface handlers
// in order to interact with the UI.
//
// Local resources must not interact with Qt resources directly.
//
// The constructor of the class is responsible for establishing
// the connections between local objects and interface handlers
//---------------------------------------------------------------------------

class CApplicationLocals : protected CApplicationInterface {
  using CBase = CApplicationInterface;
public:
  CApplicationLocals();
private:
  //---------------------------------------------------------------------------
  // Local objects live here
  //---------------------------------------------------------------------------

};
//---------------------------------------------------------------------------
} // NSApplication
//---------------------------------------------------------------------------
#endif // APPLICATIONLOCALS_H
