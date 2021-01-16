/// \brief The manager for all assets used in asset.h
/// \author George Jennings
/// \version 1.0
/// \date 15/1/21 Updated to include NCCA standards
/// Revision History :
/// Initial Version pre 01/12/20
/// \todo ...

#ifndef WHYENGINE_ASSETS_H
#define WHYENGINE_ASSETS_H

//  system includes
#include <vector>
#include <memory>
#include <string>

//  header includes
#include "Asset.h"

namespace whyengine //  namespace
{
  struct Core;  // struct of core for accesibility

  struct Assets //  main struct of assets
  {
    // template function
    template <typename T>
    std::shared_ptr<T> load(const std::string& path)
    {
      std::shared_ptr<T> rtn; // shared ptr
      for(size_t i = 0; i < assets.size(); i++) // size of assets vector
      {
        if(path == assets.at(i)->getPath()) //  gets the file path
        {
          rtn = std::dynamic_pointer_cast<T>(assets.at(i));
          if(!rtn) continue;
          return rtn;
        }
      }

      rtn = std::make_shared<T>();  // made a shared ptr for template struct
      rtn->core = core; //  core = its self now 
      rtn->path = path; //  sets the path
      rtn->onLoad();  //  calling onload function
      assets.push_back(rtn);  // adds rtn to the back of assets 

      return rtn; // return rtn
    }

  private:
    friend struct whyengine::Core;  // friend of core for accessiblity to some local varibles of core

    std::vector<std::shared_ptr<Asset>> assets; //  local values for .cpp
    std::weak_ptr<Core> core;
  };
}

#endif // _ASSETS_H_