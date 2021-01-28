/// \brief The "client" for individual assets used in conjunction with assets.h
/// \author George Jennings
/// \version 1.0
/// \date 15/1/21 Updated to include NCCA standards
/// Revision History :
/// Initial Version pre 01/12/20
/// \todo ...

#ifndef WHYENGINE_ASSET_H
#define WHYENGINE_ASSET_H

// system include
#include <string>
#include <memory>
#include <vector>

namespace whyengine // namespace
{
  // assets is a manager asset is the interface on a per asset basis
  struct Core;
  struct Assets;

  struct Asset
  {
    virtual ~Asset(); //  virtual destructor
    virtual void onLoad();  //  virtual onLoad function

    std::string getPath();  //  gets and returns the file path
    std::shared_ptr<Core> getCore();  //  gets the core for the asset

  private:
    friend struct whyengine::Assets;  //  friends with the manager

    std::string path; //  local values
    std::weak_ptr<Core> core;
  };
}

#endif // _ASSET_H_