#ifndef APPLICATION_H
#define APPLICATION_H
//---------------------------------------------------------------------------
// Include
//---------------------------------------------------------------------------

// I use precompiled headers for STL library
#include <memory> // pch
//---------------------------------------------------------------------------

namespace NSApplication {
//---------------------------------------------------------------------------
// CApplicationImplementation Forward Declaration
//---------------------------------------------------------------------------

class CApplicationImplementation;
//---------------------------------------------------------------------------
// CApplication Declaration
//---------------------------------------------------------------------------
// The Application object
// Its purpose is to create all application related resources on the heap
// The resources it-self are determined by CApplicationImplementation
//---------------------------------------------------------------------------

class CApplication {
public:
  CApplication();
  ~CApplication();
private:
  std::unique_ptr<CApplicationImplementation> AppImpl_;
};
//---------------------------------------------------------------------------
} // NSApplication
//---------------------------------------------------------------------------
#endif // APPLICATION_H
