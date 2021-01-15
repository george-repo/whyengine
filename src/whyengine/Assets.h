/// \brief The manager for all assets used in asset.h
/// \author George Jennings
/// \version 1.0
/// \date 15/1/21 Updated to include NCCA standards
/// Revision History :
/// Initial Version pre 01/12/20
/// \todo ...

#ifndef WHYENGINE_ASSETS_H
#define WHYENGINE_ASSETS_H

#include <vector>
#include <memory>
#include <string>

#include "Asset.h"

namespace whyengine
{
  struct Core;

  struct Assets
  {
    template <typename T>
    std::shared_ptr<T> load(const std::string& path)
    {
      std::shared_ptr<T> rtn;

      for(size_t i = 0; i < assets.size(); i++)
      {
        if(path == assets.at(i)->getPath())
        {
          rtn = std::dynamic_pointer_cast<T>(assets.at(i));
          if(!rtn) continue;
          return rtn;
        }
      }
      rtn = std::make_shared<T>();
      rtn->core = core;
      rtn->path = path;
      rtn->onLoad();
      assets.push_back(rtn);

      return rtn;
    }

    private:
    friend struct whyengine::Core;

    std::vector<std::shared_ptr<Asset>> assets;
    std::weak_ptr<Core> core;
  };
}

#endif // _ASSETS_H_