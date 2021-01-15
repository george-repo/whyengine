/// \brief The "client" for individual assets used in conjunction with assets.h
/// \author George Jennings
/// \version 1.0
/// \date 15/1/21 Updated to include NCCA standards
/// Revision History :
/// Initial Version pre 01/12/20
/// \todo ...


#ifndef WHYENGINE_ASSET_H
#define WHYENGINE_ASSET_H

#include <string>
#include <memory>

namespace whyengine
{
  struct Core;
  struct Assets;

  struct Asset
  {
    virtual ~Asset();
    virtual void onLoad();

    std::string getPath();
    std::shared_ptr<Core> getCore();

  private:
    friend struct whyengine::Assets;

    std::string path;
    std::weak_ptr<Core> core;
  };
}

#endif // _ASSET_H_