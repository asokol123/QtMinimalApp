#ifndef APPLICATIONIMPLEMENTATION_H
#define APPLICATIONIMPLEMENTATION_H
//---------------------------------------------------------------------------
// Include
//---------------------------------------------------------------------------

#include "ApplicationLocals.h"
//---------------------------------------------------------------------------

namespace NSApplication {
//---------------------------------------------------------------------------
// CApplicationImplementation Declaration
//---------------------------------------------------------------------------
// A part of the Application object
// Its purpose is to provide a public interface of the object
//---------------------------------------------------------------------------

class CApplicationImplementation : protected CApplicationLocals {
  using CBase = CApplicationLocals;
public:
  CApplicationImplementation();
};
//---------------------------------------------------------------------------
} // NSApplication
//---------------------------------------------------------------------------
#endif // APPLICATIONIMPLEMENTATION_H
